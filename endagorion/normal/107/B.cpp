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
    int n, m, h;
    cin >> n >> m >> h;
    --h;

    int s = 0, q = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        s += x;
        if (i == h) {
            q = x;
        }
    }

    long double res;
    if (s < n) {
        res = -1.0;
    } else {
        if (n - 1 > s - q) {
            res = 1.0;
        } else {
            res = 1.0;
            for (int i = 0; s - 1 - i > s - q; ++i) {
                res *= 1.0 * (s - n - i) / (s - 1 - i);
            }
            res = 1.0 - res;
        }
    }

    printf("%.9lf\n", res);
    return 0;
}