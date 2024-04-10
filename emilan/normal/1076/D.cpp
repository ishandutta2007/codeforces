#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const ll inf = 1ll << 60;

struct Edge {
    int v, w, i;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vt<vt<Edge>> adj(n);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
    }

    vt<ll> d(n, inf);
    vt<int> par(n);
    vt<int> p_edge(n);
    priority_queue<pli> q;
    d[0] = 0;
    q.emplace(0, 0);

    while (!q.empty()) {
        int u = q.top().se;
        ll cur_d = -q.top().fi;
        q.pop();

        if (cur_d != d[u]) continue;

        for (Edge &e : adj[u]) {
            ll new_d = cur_d + e.w;
            if (new_d < d[e.v]) {
                d[e.v] = new_d;
                par[e.v] = u;
                p_edge[e.v] = e.i;
                q.emplace(-new_d, e.v);
            }
        }
    }

    set<int> ans(1 + all(p_edge));
    vt<vt<pii>> chi(n);
    for (int i = 1; i < n; i++) {
        chi[par[i]].emplace_back(i, p_edge[i]);
    }

    auto dfs = [&](int u, int e, auto &f) -> void {
        for (pii v : chi[u]) f(v.fi, v.se, f);
        if (sz(ans) > k) ans.erase(e);
    };
    dfs(0, -1, dfs);

    cout << sz(ans) << '\n';
    for (int x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}