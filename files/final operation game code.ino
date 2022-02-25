
#include <LiquidCrystal_I2C.h>
#define BUTTON_PIN 6

//define I2C address......
LiquidCrystal_I2C lcd(0x27,16,2);
/* 
  state 0 - start
    1 - wrench
    2 - wishbone
    3 - heart
    4 - bone
    5 - butterfly
    6 - pencil
    7 - horse
    8 - bucket
*/

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("start");
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Press button");

  lcd.setCursor(4,1);
  lcd.print("to start.");
}

// functions 

int state = 0;

void decode(int = state) {
  if (state == 0) {
    //state 0 
    lcd.clear();  
    lcd.setCursor(3,0);
    lcd.print("Thank you");

    lcd.setCursor(2,1);
    lcd.print("for playing.");
    return;
  }  
  if (state == 1) {
    //state 0 
    lcd.clear();  
    lcd.setCursor(1,0);
    lcd.print("Please remove:");

    lcd.setCursor(1,1);
    lcd.print("Wrenched ankle");

    return;
  }
  if (state == 2) {
    //state 0 
    lcd.clear();  
    lcd.setCursor(1,0);
    lcd.print("Please remove:");

    lcd.setCursor(3,1);
    lcd.print("Wish Bone");

    return;
  }
  if (state == 3) {
    //state 1 
    lcd.clear();  
    lcd.setCursor(1,0);
    lcd.print("Please remove:");

    lcd.setCursor(2,1);
    lcd.print("Broken heart");
    return;
  }  
  if (state == 4) {
    //state 2
    lcd.clear();  
    lcd.setCursor(1,0);
    lcd.print("Please remove:");

    lcd.setCursor(3,1);
    lcd.print("Funny Bone");

    return;
  }
  if (state == 5) {
    //state 2
    lcd.clear();  
    lcd.setCursor(1,0);
    lcd.print("Please remove:");

    lcd.setCursor(2,1);
    lcd.print("Butterflies");
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("              ");
    delay(500);
    lcd.setCursor(3,1);
    lcd.print("in Stomach");


    return;
  }
  if (state == 6) {
    //state 2
    lcd.clear();  
    lcd.setCursor(1,0);
    lcd.print("Please remove:");

    lcd.setCursor(1,1);
    lcd.print("Writer's Cramp");

    return;
  }
  if (state == 7) {
    //state 2
    lcd.clear();  
    lcd.setCursor(1,0);
    lcd.print("Please remove:");

    lcd.setCursor(1,1);
    lcd.print("Charley Horse");

    return;
  }
  if (state == 8) {
    //state 2
    lcd.clear();  
    lcd.setCursor(1,0);
    lcd.print("Please remove:");

    lcd.setCursor(4,1);
    lcd.print("Water on");
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("              ");
    delay(500);
    lcd.setCursor(4,1);
    lcd.print("the Knee");

    return;
  }
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    state = state+1;
    if (state >= 9){
      state = 0;
    }
    decode(state);
    Serial.println("button pressed");
    delay(1000); // helps with button bouncing

    delay(100);
  }
  else {
  }

}