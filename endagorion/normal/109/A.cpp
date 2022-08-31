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
    int n;
    cin >> n;
    bool ok = false;
    int q4, q7;
    for (int k = 0; k < 7; ++k) {
        if ((4 * k <= n) && ((n - 4 * k) % 7 == 0)) {
            ok = true;
            q4 = k;
            q7 = (n - 4 * q4) / 7;
        }
    }

    if (!ok) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < q4; ++i) {
            cout << 4;
        }
        for (int i = 0; i < q7; ++i) {
            cout << 7;
        }
        cout << '\n';
    }

    return 0;
}