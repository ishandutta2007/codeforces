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

auto bfs(vector<vector<int>>& adj, int x) {
    queue<int> q; q.push(x);
    vector<int> d(adj.size(), -1);
    d[x] = 0;
    while (!q.empty()) {
        x = q.front(); q.pop();
        for (int i : adj[x])
            if (d[i] == -1)
                d[i] = d[x]+1, q.push(i);
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<array<ll, 3>> e(m);
        for (int i = 0; i < m; i++) {
            ll x, y, w; cin >> x >> y >> w; x--, y--;
            adj[x].pb(y), adj[y].pb(x);
            e[i] = {x, y, w};
        }
        auto l = bfs(adj, 0);
        auto r = bfs(adj, n-1);

        vector<ll> c(n, -1);
        vector<vector<int>> g(2*n);
        for (int i = 0; i < n; i++)
            g[l[i]+r[i]].pb(i);
        for (int i = 0; i < 2*n; i++) {
            for (int x : g[i])
                if (c[x] == -1) {
                    c[x] = i;
                    for (int j : adj[x])
                        g[i+1].pb(j);
                }
            debug(i, g[i]);
        }

        debug(c);

        ll ans = inf_ll;
        for (auto& [x, y, w] : e) {
            cmin(ans, (1+l[x]+r[y])*w);
            cmin(ans, (1+r[x]+l[y])*w);
            cmin(ans, (2+c[x])*w);
            cmin(ans, (2+c[y])*w);
        }
        cout << ans << "\n";
    }
}