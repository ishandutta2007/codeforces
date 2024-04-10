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


int n, k, a, b, c, d;


int main() {
    cin >> n >> k >> a >> b >> c >> d;
    if (n == 4) {
        cout << -1 << endl;
        return 0;
    }
    if (k < n + 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << a << ' ' << c;
    for (int i = 1; i <= n; i++) {
        if (i != b && i != d && i != a && i != c) {
            cout << ' ' << i;
        }
    }
    cout << ' ' << d << ' ' << b << endl;
    cout << c << ' ' << a;
    for (int i = 1; i <= n; i++) {
        if (i != b && i != d && i != a && i != c) {
            cout << ' ' << i;
        }
    }
    cout << ' ' << b << ' ' << d << endl;
    return 0;
}