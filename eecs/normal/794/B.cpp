#include <bits/stdc++.h>
using namespace std;

int n, h;

int main() {
    scanf("%d %d", &n, &h);
    double lst = 0;
    for (int i = 1; i < n; i++) {
        double l = lst, r = h;
        while (r - l > 1e-9) {
            double mid = (l + r) / 2;
            if (1.0 * mid * mid / h <= 1.0 * h * i / n) l = mid;
            else r = mid;
        }
        printf("%.7f ", lst = l);
    }
    return 0;
}