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
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    bool ok;
    if (d == 0) {
        ok = false;
    } else {
        if (c == 0 && d > 0) {
            ok = true;
        } else {
            if (b == 0) {
                ok = false;
            } else {
                if (a == 0 && b > 0) {
                    ok = true;
                } else {
                    ok = a * c * e < b * d * f;
                }
            }
        }
    }

    if (ok) {
        cout << "Ron\n";
    } else {
        cout << "Hermione\n";
    }

    return 0;
}