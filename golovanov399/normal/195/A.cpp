#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    
    int a, b, c;
    cin >> a >> b >> c;
    if (((a - b) * c) % b == 0) cout << (a - b) * c / b; else
    cout << (a - b) * c / b + 1;
    
    return 0;
}