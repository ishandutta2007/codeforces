#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;

const int N = 2001;
ll cost[N][N][2], bul[N][N][2];

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<array<ll, 3>> a(n);
    for (auto &[l, r, x] : a) cin >> l >> r >> x;

    vector<ll> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i][2];
    }

    memset(cost, inf, sizeof cost);
    ***cost = 0;
    ***bul = k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int off = 0; off < 2; off++) if (cost[i][j][off] != inf) {
                ll t = (a[i][2] - bul[i][j][off] + k - 1) / k;
                ll end_t = a[i][0] + (a[i][0] == a[j][0] && off) + t;
                if (end_t > a[i][1]) continue;

                bool equal_next = i < n - 1 && end_t == a[i + 1][0];

                bul[i + 1][j][off] = (bul[i][j][off] - a[i][2]) % k;
                if (bul[i + 1][j][off] < 0) bul[i + 1][j][off] += k;

                cost[i + 1][j][off] = min(
                    cost[i][j][off] + a[i][2],
                    cost[i + 1][j][off]
                );

                bul[i + 1][i + 1][equal_next] = k;

                cost[i + 1][i + 1][equal_next] = min(
                    cost[i][j][off] + a[i][2] + bul[i + 1][j][off],
                    cost[i + 1][i + 1][equal_next]
                );
            }
        }
    }

    ll ans = inf;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(cost[n][i][j], ans);
        }
    }

    if (ans == inf) cout << -1;
    else cout << ans;
}