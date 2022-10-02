#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;

int a, b, c;

int main() {    
    cin >> a >> c >> b;
    if (b == 0) {
        if (a == c) {
            cout << "YES" << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }
    if ((c - a) % b == 0) {
        if (b >= 0 && c - a >= 0) {
            cout << "YES" << endl;
            return 0;
        }
        if (b <= 0 && c - a <= 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}