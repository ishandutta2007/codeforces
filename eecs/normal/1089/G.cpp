#include <bits/stdc++.h>
using namespace std;

int T, K, a[7];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &K);
        for (int i = 0; i < 7; i++) {
            scanf("%d", &a[i]);
        }
        int all = accumulate(a, a + 7, 0);
        int ans = (K / all - 1) * 7;
        K -= (K / all - 1) * all;
        int mn = INT_MAX;
        for (int i = 0; i < 7; i++) {
            for (int j = i, s = 0, k = 1; j < 7; ++j %= 7, k++) {
                if ((s += a[j]) >= K) { mn = min(mn, k); break; }
            }
        }
        printf("%d\n", ans + mn);
    }
    return 0;
}