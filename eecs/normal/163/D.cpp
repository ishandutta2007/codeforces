#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T, K, a[100];
ll p[100], suf[100], pw[100][100];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &K);
        for (int i = 1; i <= K; i++) {
            scanf("%lld %d", &p[i], &a[i]);
            for (int j = pw[i][0] = 1; j <= a[i]; j++) pw[i][j] = pw[i][j - 1] * p[i];
        }
        suf[K + 1] = 1;
        for (int i = K; i; i--) {
            suf[i] = pw[i][a[i]] * suf[i + 1];
        }
        ll n = suf[1];
        array<ll, 4> ans{LLONG_MAX};
        auto chk = [&](ll a, ll b) {
            ll c = n / a / b;
            ans = min(ans, {a * b + a * c + b * c, a, b, c});
        };
        ll lim = pow(n, 1 / 3.0);
        while ((lim + 1) * (lim + 1) * (lim + 1) <= n) lim++;
        function<void(int, ll)> dfs = [&](int cur, ll x) {
            if (x > lim) return;
            if (cur > K) {
                ll m = n / x, lim2 = sqrt(m);
                if (m + 2 * x * (ll)sqrt(m) >= ans[0]) return;
                while ((lim2 + 1) * (lim2 + 1) <= m) lim2++;
                function<void(int, ll)> dfs2 = [&](int cur, ll y) {
                    if (y * suf[cur] < x) return;
                    if (cur > K) return chk(x, y);
                    for (int i = 0; i <= a[cur]; i++, y *= p[cur]) {
                        if (m % y || y > lim2) break;
                        dfs2(cur + 1, y);
                    }
                };
                dfs2(1, 1); return;
            }
            for (int i = a[cur]; ~i; i--) {
                dfs(cur + 1, x * pw[cur][i]);
            }
        };
        dfs(1, 1);
        printf("%lld %lld %lld %lld\n", ans[0] * 2, ans[1], ans[2], ans[3]);
    }
    return 0;
}