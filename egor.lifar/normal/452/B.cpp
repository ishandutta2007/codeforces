#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n, m;


int main() {
    cin >> n >> m;
    if (n == 0) {
        cout << 0 << ' ' << 1 << endl;
        cout << 0 << ' ' << m << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << 0 << ' ' << m - 1 << endl;
        return 0;
    }
    if (m == 0) {
        cout << 1 << ' ' << 0 << endl;
        cout << n << ' ' << 0 << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << n - 1 << ' ' << 0 << endl;
        return 0;
    }
    if (n <= 3 || m <= 3) {
        cout << n << ' ' << m << endl;
        cout << 0 << ' ' << 0 << endl;
        if (n > m) {
            cout << n << ' ' << 0 << endl;
            cout << 0 << ' ' << m << endl;
        } else {
            cout << 0 << ' ' << m << endl;
            cout << n << ' ' << 0 << endl;
        }
        return 0;
    }
    if (n <= m) {
        cout << n - 1 << ' ' << m << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << n << ' ' << m << endl;
        cout << 1 << ' ' << 0 << endl;
    } else {
        cout << 0 << ' ' << 1 << endl;
        cout << n << ' ' << m << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << n << ' ' << m - 1 << endl;
    }
    return 0;
}