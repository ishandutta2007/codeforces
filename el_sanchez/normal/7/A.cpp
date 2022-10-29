#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int a = 0, n = 8;
    string w[8];
    forn(i, n) cin >> w[i];
    
    forn(i, n) {
        bool f = 1;
        forn(j, n) 
            if (w[i][j] == 'W') 
                f = 0;
        if (f) a++;        
    }
    forn(j, n) {
        bool f = 1;
        forn(i, n) 
            if (w[i][j] == 'W') 
                f = 0;
        if (f) a++;        
    }
    if (a == 16) a = 8;
    cout << a << endl;
}