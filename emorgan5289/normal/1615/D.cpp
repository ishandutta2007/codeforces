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

vector<vector<array<ll, 2>>> adj, e;
vector<ll> vis, c;

bool dfs(ll i) {
    vis[i] = 1;
    for (auto& [w, j] : e[i]) {
        if (vis[j]) {
            if ((c[i]^w) != c[j]) {
                debug(i, j, c);
                return 1;
            }
        } else {
            c[j] = c[i]^w;
            if (dfs(j)) return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        adj.assign(n, {});
        e.assign(n, {});
        vis.assign(n, 0);
        c.assign(n, 0);
        for (int i = 0; i < n-1; i++) {
            ll x, y, w; cin >> x >> y >> w; x--, y--;
            adj[x].pb({w, y}), adj[y].pb({w, x});
            if (w != -1) {
                w = __builtin_popcountll(w)%2;
                e[x].pb({w, y}), e[y].pb({w, x});
            }
        }
        debug(e);
        for (int i = 0; i < m; i++) {
            ll x, y, w; cin >> x >> y >> w; x--, y--;
            e[x].pb({w, y}), e[y].pb({w, x});
        }
        bool ok = 1;
        for (int i = 0; i < n; i++)
            if (!vis[i])
                if (dfs(i))
                    ok = 0;
        if (!ok)
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                for (auto& [w, j] : adj[i])
                    if (i < j) {
                        if (w != -1) assert((c[i]^c[j]) == (__builtin_popcountll(w)%2));
                        cout << i+1 << " " << j+1 << " " << (w == -1 ? c[i]^c[j] : w) << "\n";
                    }
        }
    }
}