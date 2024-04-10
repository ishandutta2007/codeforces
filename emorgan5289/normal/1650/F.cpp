#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        ll n, m; cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<array<ll, 3>>> x(n);
        debug(n, m, a);
        for (int i = 0; i < m; i++) {
            ll e, t, p; cin >> e >> t >> p;
            debug(e, t, p);
            x[e-1].pb({t, p, i+1});
        }
        ll sum_t = 0;
        vector<ll> ans;
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            vector<vector<ll>> dp(x[i].size()+1, vector<ll>(200, inf_ll));
            vector<vector<int>> u(x[i].size()+1, vector<int>(200, -1));
            dp[0][0] = 0;
            for (int j = 0; j < x[i].size(); j++) {
                auto& [t, p, _] = x[i][j];
                dp[j+1] = dp[j];
                for (int k = 199; k >= p; k--) {
                    if (dp[j][k-p]+t < dp[j+1][k]) {
                        dp[j+1][k] = dp[j][k-p]+t;
                        u[j+1][k] = j;
                    }
                }
            }
            ll r = 100;
            for (int j = 100; j < 200; j++)
                if (dp[x[i].size()][j] < dp[x[i].size()][r]) r = j;
            if (dp[x[i].size()][r] == inf_ll) {
                ok = 0; break;
            }
            for (int k = x[i].size(); k > 0; k--) {
                if (u[k][r] == -1) continue;
                sum_t += x[i][u[k][r]][0];
                ans.pb(x[i][u[k][r]][2]);
                r -= x[i][u[k][r]][1];
            }
            if (sum_t > a[i]) {
                ok = 0; break;
            }
        }
        if (ok) {
            cout << ans.size() << "\n";
            for (int i : ans)
                cout << i << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}