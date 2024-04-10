#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, k[maxn], h[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &k[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &h[i]);
        }
        for (int i = n - 1; i; i--) {
            h[i] = max(h[i], h[i + 1] - (k[i + 1] - k[i]));
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (k[i] - k[i - 1] >= h[i]) {
                ans += 1LL * h[i] * (h[i] + 1) / 2;
            } else {
                int m = k[i] - k[i - 1];
                ans += 1LL * (h[i - 1] + 1 + h[i - 1] + m) * m / 2;
                h[i] = h[i - 1] + m;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}