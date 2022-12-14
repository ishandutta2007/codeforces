#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n + 1), a(m);
    vector<vector<int>> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p[x] = i;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a[i] = p[x];
        pos[p[x]].push_back(i);
    }

    vector<vector<int>> par(m);
    for (int s = 0; s < m; s++) if (par[s].empty()) {
        for (int u = s;;) {
            int nxt = a[u] == n ? 1 : a[u] + 1;

            auto it = upper_bound(pos[nxt].begin(), pos[nxt].end(), u);
            if (it == pos[nxt].end()) break;

            int v = *it;
            par[v].push_back(u);
            if (par[v].size() > 1) break;
            u = v;
        }
    }

    vector<int> ac(m, m);
    vector<int> vis(m);
    vector<int> path;

    auto dfs = [&](int u, auto &&f) -> void {
        vis[u] = true;
        path.push_back(u);

        if (int(path.size()) >= n) {
            ac[u] = path[int(path.size()) - n];
        }

        for (int v : par[u]) if (!vis[v]) {
            f(v, f);
        }

        path.pop_back();
    };

    for (int s = m - 1; s >= 0; s--) if (!vis[s]) {
        dfs(s, dfs);
    }

    for (int i = m - 2; i >= 0; i--) {
        ac[i] = min(ac[i], ac[i + 1]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (r >= ac[l]) cout << '1';
        else cout << '0';
    }
}