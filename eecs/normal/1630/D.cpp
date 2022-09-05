#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000010;
int T, n, m, a[maxn], b[maxn], pre[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int g = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &b[i]), g = __gcd(g, b[i]);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += abs(a[i]);
        }
        if (g > 1) {
            ans = LLONG_MIN;
            for (int op : {0, 1}) {
                long long sum = 0;
                for (int i = 1; i <= g; i++) {
                    long long foo = 0, bar = -1e18;
                    for (int j = i; j <= n; j += g) {
                        long long c, d;
                        c = max(foo + a[j], bar - a[j]);
                        d = max(foo - a[j], bar + a[j]);
                        foo = c, bar = d;
                        if (j + g - 1 >= n) {
                            if (!op) bar = -1e18;
                            else foo = -1e18;
                        }
                    }
                    sum += max(foo, bar);
                }
                ans = max(ans, sum);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}