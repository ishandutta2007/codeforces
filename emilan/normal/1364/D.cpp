#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vt<set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    if (m == n - 1) {
        vt<int> w, b;
        function<void(int, int)> dfs = [&](int u, int c) {
            if (c) w.push_back(u);
            else b.push_back(u);

            decltype(adj[u].begin()) it;
            while ((it = adj[u].begin()) != adj[u].end()) {
                int v = *it;

                adj[v].erase(u);
                adj[u].erase(it);

                dfs(v, c ^ 1);
            }
        };
        dfs(0, 0);

        vt<int>& v = sz(w) > sz(b) ? w : b;
        cout << "1\n";
        for (int i = 0; i < (k + 1) / 2; i++) {
            cout << v.back() + 1 << ' ';
            v.pop_back();
        }

        return 0;
    }

    vt<int> dist(n), par(n, -1);

    function<void(int, int)> dfs;

    int len = 1 << 30;
    auto findCycle = [&](int u) {
        vt<int> cycle;
        for (int i = 0; i < len; i++) {
            int p = par[u];
            dfs(u, dist[u]);
            cycle.push_back(u);
            u = p;
        }

        if (sz(cycle) > k) {
            cout << "1\n";
            while (k--) {
                if (~k & 1) cout << cycle.back() + 1 << ' ';
                cycle.pop_back();
            }
        } else {
            cout << "2\n" << sz(cycle) << '\n';
            while (!cycle.empty()) {
                cout << cycle.back() + 1 << ' ';
                cycle.pop_back();
            }
        }

        exit(0);
    };

    dfs = [&](int u, int d) {
        dist[u] = d;

        decltype(adj[u].begin()) it;
        while ((it = adj[u].begin()) != adj[u].end()) {
            int v = *it;

            adj[v].erase(u);
            adj[u].erase(it);

            if (par[v] != -1) {
                int curLen = abs(dist[v] - dist[u]) + 1;
                if (curLen < len) {
                    par[v] = u;
                    len = curLen;
                    findCycle(u);
                }
            } else {
                par[v] = u;
                dfs(v, d + 1);
            }
        }
    };

    par[0] = 0;
    dfs(0, 0);
}