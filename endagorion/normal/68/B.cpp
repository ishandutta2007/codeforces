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
    int n, k;
    cin >> n >> k;
    vector< int > a(n);
    double l = 0.0, r = 0.0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        r = max(r, 1.0 * a[i]);
    }
    while (r - l > 1e-8) {
        double m = 0.5 * (l + r);
        double bal = 0.0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > m) {
                bal += (a[i] - m) * (1.0 - 0.01 * k);
            } else {
                bal -= (m - a[i]);
            }
        }
        if (bal > 0) {
            l = m;
        } else {
            r = m;
        }
    }

    printf("%.10lf\n", l);

    return 0;
}