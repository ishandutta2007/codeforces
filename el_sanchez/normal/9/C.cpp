#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++) 

int n, l, pw;
string s;

int main() {

    cin >> s;
    l = s.size();
    int i = 0;
    while (i < l) { 
        if (s[i] >= '2') 
            while (i < l) {
                s[i] = '1';
                i++;
            }
        i++;    
    }  
    
    i = l-1;
    pw = 1;
    while (i >= 0) {
        n += pw * (s[i] == '1');
        pw *= 2;
        i--;
    }
    
    cout << n << endl;
}