#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <cmath>
#include <vector>

#define x first
#define y second
 
using namespace std;

int main(){
    
    string s, t;
    cin >> s >> t;
    int k = 0;
    for (int i = 0; i < s.length(); i += 2){
        if ((s[i] == '8' && t[i] == '[') || (s[i] == '[' && t[i] == '(') || (s[i] == '(' && t[i] == '8')) k++; else
        if ((t[i] == '8' && s[i] == '[') || (t[i] == '[' && s[i] == '(') || (t[i] == '(' && s[i] == '8')) k--;
    }
    
    if (k > 0) cout << "TEAM 1 WINS\n"; else
    if (k < 0) cout << "TEAM 2 WINS\n"; else
    cout << "TIE\n";
    
    return 0;
}