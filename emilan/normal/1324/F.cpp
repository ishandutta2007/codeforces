#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vector<map<int, int>> adj(n);
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x][y] = -1;
        adj[y][x] = -1;
    }

    vii dp(n, {-1, 0});

    function<int(int, int)> solve = [&](int x, int p) {
        if (dp[x].fi == -1) {
            int ret = a[x] * 2 - 1;
            for (auto& j : adj[x]) {
                if (j.fi == p) continue;

                j.se = solve(j.fi, x);
                ret += j.se;
            }
            dp[x] = {p, ret};
            return max(0, ret);
        } else if (dp[x].fi != -2) {
            if (dp[x].fi != p) {
                adj[x][dp[x].fi] = solve(dp[x].fi, x);
                dp[x] = {-2, max(0, dp[x].se + adj[x][dp[x].fi])};
                return max(0, dp[x].se - adj[x][p]);
            } else return max(0, dp[x].se);
        } else return max(0, dp[x].se - adj[x][p]);
    };

    rep(i, n) {
        int ans = a[i] * 2 - 1;

        for (auto& j : adj[i]) {
            ans += solve(j.fi, i);
        }

        cout << ans << ' ';
    }

    return 0;
}