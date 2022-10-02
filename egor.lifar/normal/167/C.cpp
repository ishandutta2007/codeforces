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
#include <unordered_map>


using namespace std;


int t;


bool get(long long a, long long b) {
    if (a == 0LL || b == 0LL) {
        return 0;
    }
    if (a > b) {
        swap(a, b);
    }
    if (!get(a, b % a)) {
        return 1;
    }
    if (a % 2LL == 1LL) {
        if ((b / a - 1LL) % 2LL == 1LL) {
            return 1;
        }
    } else {
        if ((b / a - 1LL) % (a + 1LL) == a || ((b / a - 1LL) % (a + 1LL)) % 2LL == 1LL) {
            return 1;
        }
    }
    return 0;
}


int main() {
    cin >> t;
    for (int k = 0; k < t; k++) {
        long long a, b;
        cin >> a >> b;
        if (get(a, b)) {
            cout << "First" << endl; 
        } else {
            cout << "Second" << endl;
        }
    }
    return 0;
}