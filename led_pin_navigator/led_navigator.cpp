#include <iostream>
#include <wiringPi.h>
#include <vector>

void clearTerminal()
{
    system("clear");
}

std::vector<int> pins = {0,1,2,3,4,5,6,8,9,10};

size_t next_prev;

int current_pin = 0;

void reset_pins(){
    for(int i=0;i<10;i++){       
            pinMode(pins[i], OUTPUT); //set led pins' mode as output
            digitalWrite(pins[i],HIGH);
        }
}

int initialize(){ //make led pins' mode is output / check for wiringpi initialization
    if(wiringPiSetup() == -1){ //when initialize wiring failed,print message to screen
            std::cout << "setup wiringPi failed !" << std::endl;
            return 1;
        }

        reset_pins();
        
        return 0;
}

void interface(){
    digitalWrite(pins[0],LOW);
    
    
    
    while(1){
        std::cout << "1: Prev || 2: Next" << std::endl;
        std::cin >> next_prev;
        
        reset_pins();

        if(next_prev == 1){
                current_pin -= 1;

                if(current_pin < 0){
                    current_pin = 9;
                }

                digitalWrite(pins[current_pin],LOW);
                //std::cout << current_pin << std::endl;
        }
        else if(next_prev == 2){
                current_pin += 1;

                if(current_pin > 9){
                    current_pin = -1;
                }

                digitalWrite(pins[current_pin],LOW);
                //std::cout << current_pin << std::endl;    
        }
        else if(next_prev != 1 || next_prev != 2){
                
                //std::cout << "current_pin" << std::endl;   
                digitalWrite(pins[current_pin],LOW); 
        }
        clearTerminal();
    }
}


int main()
{

    clearTerminal();
    initialize();
    interface();

    
    return 0;
}