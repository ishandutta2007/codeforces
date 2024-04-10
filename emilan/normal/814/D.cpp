#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

ll sqr(ll x) { return x * x; }

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (auto &[r, x, y] : a) cin >> x >> y >> r;

    sort(RALL(a));

    vector<int> start;
    vector<vector<int>> chi(n);
    for (int v = 0; v < n; v++) {
        auto [v_r, v_x, v_y] = a[v];

        int p = -1;
        for (int u = v - 1; u >= 0; u--) {
            auto [u_r, u_x, u_y] = a[u];
            if (sqr(u_x - v_x) + sqr(u_y - v_y) <= sqr(u_r - v_r)) {
                p = u;
                break;
            }
        }
        if (p == -1) start.push_back(v);
        else chi[p].push_back(v);
    }

    vector<array<ll, 3>> dp(n);
    auto dfs = [&](auto &self, int u) -> void {
        array<ll, 3> chi_dp = {};
        for (int v : chi[u]) {
            self(self, v);
            for (int i = 0; i < 3; i++) {
                chi_dp[i] += dp[v][i];
            }
        }

        ll area = sqr(a[u][0]);
        dp[u][0] = area + chi_dp[1];
        dp[u][1] = max(area + chi_dp[2], -area + chi_dp[0]);
        dp[u][2] = -area + chi_dp[1];
    };

    ll ans = 0;
    for (int s : start) {
        dfs(dfs, s);
        ans += dp[s][0];
    }

    cout << setprecision(10) << fixed;
    cout << acosl(-1.0L) * ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}