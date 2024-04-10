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
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<ll> a(n), b(n);
        for (int i = 1; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
            cin >> b[i];
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x].pb(y), adj[y].pb(x);
        }

        auto solve = [&](ll s) {

            vector<ll> vis(n, 0);
            vis[0] = 1;
            while (1) {
                // debug(vis);
                vector<ll> sub_vis(vis), par(n, -1), val(n, 0);
                vector<ll> stk, cyc;
                for (int i = 0; i < n; i++)
                    if (vis[i]) stk.pb(i), val[i] = s;

                auto get_path = [&](int i) {
                    while (!vis[i])
                        cyc.pb(i), i = par[i];
                };

                while (!stk.empty()) {
                    int i = stk.back(); stk.pop_back();
                    debug(i, val[i]);
                    for (int j : adj[i])
                        if (j != par[i] && val[i] > a[j] && (!vis[i] || !vis[j])) {
                            // debug(i, j);
                            if (!vis[j]) {
                                if (sub_vis[j]) {
                                    get_path(i), get_path(j);
                                    goto done;
                                } else {
                                    stk.pb(j);
                                    sub_vis[j] = 1;
                                    par[j] = i;
                                    val[j] = val[i]+b[j];
                                }
                            } else {
                                get_path(i);
                                goto done;
                            }
                        }
                }

                done:;
                debug(s, cyc);
                if (cyc.empty()) break;
                for (int i : cyc) {
                    if (!vis[i])
                        vis[i] = 1, s += b[i];
                }
            }
            debug("done");
            return *min_element(all(vis)) != 0;
        };

        ll x = 0;
        for (ll i = 1ll<<40; i > 0; i /= 2)
            if (!solve(x+i)) x += i;
        debug();
        solve(x+1);
        cout << x+1 << "\n";
    }
}