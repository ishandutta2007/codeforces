#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


bool prostoe(int x) {
    bool b = true;
    for (int i = 2; i <= (int)sqrt(x); i++) {
        if (x % i == 0) {
            b = false;
        }
    } 
    return b;
}

bool prosto(int x) {
    int s = 0;
    for (int i = 2; i <= x; i++) {
        if (x % i == 0 && prostoe(i)) {
            s++;
        }
    }
    return s == 2; 
}

int main() {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (prosto(i)) {
            s++;
        }
    }
    cout << s << endl;
    // if (prosto(5)){
    //     cout << "kk";
    //     return 0;
    // }
    return 0;
}