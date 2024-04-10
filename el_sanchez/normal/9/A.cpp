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

int a, b;

int main() {

    cin >> a >> b;
    a = max(a, b);
    switch(a) {
        case 1: {cout << "1/1" << endl; break;}
        case 2: {cout << "5/6" << endl; break;}
        case 3: {cout << "2/3" << endl; break;}
        case 4: {cout << "1/2" << endl; break;}
        case 5: {cout << "1/3" << endl; break;}
        case 6: {cout << "1/6" << endl; break;}
    }
    
}