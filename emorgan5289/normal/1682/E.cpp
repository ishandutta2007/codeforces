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

// Accepts an adjacency list. Assumes that the graph is connected and acyclic.
// Runs in O(V+E).

vector<int> toposort(vector<vector<int>> adj) {
    vector<int> out, stk, in(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
        for (int j : adj[i]) in[j]++;
    for (int i = 0; i < adj.size(); i++)
        if (!in[i]) stk.push_back(i);
    while (!stk.empty()) {
        out.push_back(stk.back()); stk.pop_back();
        for (int j : adj[out.back()])
            if (!--in[j]) stk.push_back(j);
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    vector<array<int, 2>> e;
    vector<vector<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb({i, y});
        adj[y].pb({i, x});
        e.pb({x, y});
    }
    debug(p);
    vector<int> r(n, -1);
    for (int i = 0; i < n; i++)
        if (r[i] == -1)
            for (int x = i, c = 0; r[x] == -1; x = p[x])
                r[x] = c++;
    debug(r);
    vector<vector<int>> ord(m);
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]), [&](auto x, auto y){
            return (r[x[1]]-r[i]+n)%n < (r[y[1]]-r[i]+n)%n;
        });
        for (int j = 0; j+1 < adj[i].size(); j++)
            ord[adj[i][j][0]].pb(adj[i][j+1][0]);
    }
    debug(ord);
    auto ans = toposort(ord);
    for (int i = 0; i < m; i++)
        cout << ans[i]+1 << " \n"[i == m-1];
    for (int i : ans)
        swap(p[e[i][0]], p[e[i][1]]);
    debug(p);
    assert(is_sorted(all(p)));
}