#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int T, n;
ll x[maxn], y[maxn], z[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);
        }
        if (n == 1) {
            printf("%lld %lld %lld\n", x[1], y[1], z[1]); continue;
        }
        ll px = 0, py = 0, pz = 0;
        auto solve = [&]() {
            ll t = 0;
            for (int i = 1; i <= n; i++) t = max(t, abs(px - x[i]) + abs(py -
                y[i]) + abs(pz - z[i]));
            return t;
        };
        ll ans = solve();
        for (ll d = 1e18; d; ) {
            for (ll x : {-d, 0LL, d}) for (ll y : {-d, 0LL, d}) {
                for (ll z : {-d, 0LL, d}) {
                    px += x, py += y, pz += z;
                    ll t = solve();
                    if (t < ans) { ans = t; goto nxt; }
                    px -= x, py -= y, pz -= z;
                }
            }
            d >>= 1;
            nxt:;
        }
        printf("%lld %lld %lld\n", px, py, pz);
    }
    return 0;
}