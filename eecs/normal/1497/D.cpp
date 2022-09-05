#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5010;
int T, n, tag[maxn], w[maxn];
ll f[maxn], g[maxn], h[maxn], cur[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &tag[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &w[i]);
        }
        memset(h, -0x3f, sizeof(h));
        memset(cur, -0x3f, sizeof(cur));
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(f, -0x3f, sizeof(f)), f[i] = 0;
            memset(g, -0x3f, sizeof(g));
            ll foo = -1e18;
            for (int j = i; j; j--) {
                if (tag[i] ^ tag[j]) {
                    f[j] = max(f[j], h[j] + abs(w[i] - w[j]));
                    f[j] = max(f[j], cur[j] + abs(w[i] - w[j]));
                    g[j] = max(g[j], foo + abs(w[i] - w[j]));
                }
                cur[j] = max(cur[j], g[j]);
                foo = max(foo, f[j]);
                ans = max({ans, f[j], g[j]});
            }
            h[i] = foo;
        }
        printf("%lld\n", ans);
    }
    return 0;
}