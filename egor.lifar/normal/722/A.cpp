#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>


using namespace std;
    

int main() {
    int x;
    string s;
    cin >> x >> s;
    if (s[3] > '5') {
        s[3] = '0';
    }
    int dv = (10 * (s[0] - '0') + (s[1] - '0'));
    if (x == 12 && (dv < 1 || dv > 12)) {
        if (s[1] != '0') {
            s[0] = '0';
        } else {
            s[0] = '1';
        }
    } else {
        if (x == 24 && dv > 23) {
            s[0] = '1';
        }
    }
    cout << s << endl;
    return 0;
}