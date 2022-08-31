#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    long long n, x, y;
    cin >> n >> x >> y;
    if (n > y) {
        cout << "-1\n";
        return 0;
    }
    long long d = n - 1;
    long long m = y - d;
    if (m * m + d < x) {
        cout << "-1\n";
    } else {
        cout << m << '\n';
        for (int i = 0; i < n - 1; ++i) {
            cout << 1 << '\n';
        }
    }

    return 0;
}