#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <random>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    while (true) {
        if (a == 0 || b == 0) break;
        if (a >= 2 * b) {
            a %= 2 * b;
            continue;
        }
        else {
            if (b >= 2 * a) {
                b %= 2 * a;
                continue;
            }
            else {
                break;
            }
        }
    }

    cout << a << ' ' << b << '\n';
    return 0;
}