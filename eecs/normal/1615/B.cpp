#include <bits/stdc++.h>
using namespace std;

int T, l, r;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &l, &r);
        int mn = INT_MAX;
        for (int k = 1; k <= 1e6; k <<= 1) {
            auto calc = [&](int x) {
                return x / (2 * k) * k + max(0, x % (2 * k) - k);
            };
            int num = calc(r + 1) - calc(l);
            if (num) mn = min(mn, r - l + 1 - num);
        }
        printf("%d\n", mn);
    }
    return 0;
}