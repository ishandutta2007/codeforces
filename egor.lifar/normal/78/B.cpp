#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;



int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n / 7; i++){
        printf("ROYGBIV");
    }
    if(n % 7 == 6){
        printf("GBIVYG");
    }
    if(n % 7 == 1){
        printf("G");
    }
    if(n % 7 == 2) {
        printf("GB");
    }
    if(n % 7 == 4){
        printf("GBIV");
    }
    if(n % 7 == 3){
        printf("GBI");
    }
    if(n % 7 == 5){
        printf("GBIVG");
    }
    return 0;
}