#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
int t;
const int m = 60;
int n;
ll a[500010];
int cnt[65];
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) for (int j = 0; j < m; j++) cnt[j] += (a[i] >> j) & 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll x = 0, y = 0;
        for (int j = 0; j < m; j++) {
            ll cur = (1ll << j) % mod;
            if ((a[i] >> j) & 1) x = (x + cur * n) % mod, y = (y + cur * cnt[j]) % mod;
            else x = (x + cur * cnt[j]) % mod;
        }
        ans = (ans + x * y) % mod;
    }
    printf("%lld\n", ans);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}