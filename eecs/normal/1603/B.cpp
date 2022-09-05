#include <bits/stdc++.h>
using namespace std;

int T, x, y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x, &y);
        if (x == y) {
            printf("%d\n", x);
        } else if (x < y) {
            int q = y / x, r = y % x / 2;
            printf("%lld\n", 1LL * q * x + r);
        } else {
            printf("%d\n", x + y);
        }
    }
    return 0;
}