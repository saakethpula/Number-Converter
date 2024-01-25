// Created by Saaketh Pula on 9/12/23.

#include <string>
#include <iostream>
#include <math.h>
using namespace std;

string revto_string(int n) {
    if (n == 0) {
        return "1";
    } else if (n == 1) {
        return "0";
    }
}
string basetobi(void) {

    cout << "Enter an integer between -2147483648 and 2147483647: " << endl;
    int n;
    cin >> n;
    string bians = "";
    string hexans = "";
    char digits[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; // Arrary to define the 16 digits of hex
    bool neg = false;
    if (n < 0){ // Checks to see if the number is negative
        neg = true;
        n = -n;
        n--;

    }
    while (n > 0) { // Loops through the number to convert it to binary after checking if it is negative
        if (neg == false) {
            bians = (to_string(n % 2)) + bians;
            n /= 2;
        } else {
            bians = (revto_string(n % 2)) + bians;
            n /= 2;
        }
    }
    while (bians.length() < 32) { // Adds zeros or ones to the left of the binary number depending on if it is negative or not if it is less than 32 bits
        if (neg){
            bians = "1" + bians;
        } else {
            bians = "0" + bians;
        }
    }

    for (int i = 0; i < bians.length(); i = i+4) { // Changes the binary number into a hex number by checking 4 bits at a time to match to a hex number
        if (bians.substr(i,4) == "0000") {
            hexans += digits[0] ;
        }
        if (bians.substr(i,4) == "0001") {
            hexans += digits[1] ;
        }
        if (bians.substr(i,4) == "0010") {
            hexans += digits[2];
        }
        if (bians.substr(i,4) == "0011") {
            hexans +=digits[3] ;
        }
        if (bians.substr(i,4) == "0100") {
            hexans +=digits[4] ;
        }
        if (bians.substr(i,4) == "0101") {
            hexans +=digits[5] ;
        }
        if (bians.substr(i,4) == "0110") {
            hexans +=digits[6];
        }
        if (bians.substr(i,4) == "0111") {
            hexans += digits[7] ;
        }
        if (bians.substr(i,4) == "1000") {
            hexans +=digits[8] ;
        }
        if (bians.substr(i,4) == "1001") {
            hexans +=digits[9];
        }
        if (bians.substr(i,4) == "1010") {
            hexans +=digits[10] ;
        }
        if (bians.substr(i,4) == "1011") {
            hexans +=digits[11];
        }
        if (bians.substr(i,4) == "1100") {
            hexans +=digits[12];
        }
        if (bians.substr(i,4) == "1101") {
            hexans +=digits[13];
        }
        if (bians.substr(i,4) == "1110") {
            hexans +=digits[14];
        }
        if (bians.substr(i,4) == "1111") {
            hexans += digits[15];
        }
    }
    return "Binary: " + bians + "\n" + "Hexadecimal: " + hexans + "\n"; // Prints out the binary and hexadecimal number representation of the decimal number
}
int hextodec(void) {
    cout << "Enter a 32 bit hexadecimal number: " << endl;
    int decimal;
    string hex;
    cin >> (hex);
    char digits[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; // Arrary to define the 16 digits of hex
    for (int i = 0; i < hex.length(); i++) {
        for (int j = 0; j < 16; j++) {
            if (hex[i] == digits[j]) {
                decimal += pow(16, hex.length()-i-1)*j; // Takes the power of 16 to the index and adds it to the decimal number
            }
        }
    }
    if (hex == "7FFFFFFF"){ // Accounts for the case where the number is 2147483647
        decimal +=1;
    }
    return decimal - 1;
}