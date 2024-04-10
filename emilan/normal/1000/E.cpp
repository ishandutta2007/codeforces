#include <bits/stdc++.h>

using namespace std;

pair<int, vector<int>>
two_ecc(int n, const vector<pair<int, int>> &edges) {
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < int(size(edges)); i++) {
        auto [u, v] = edges[i];
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    vector<int> tin(n, -1), low(n);
    int t = 0;
    stack<int> st;
    vector<int> ecc_id(n, -1);
    int ecc_cnt = 0;
    auto dfs = [&](auto &self, int u, int pi) -> void {
        tin[u] = low[u] = t++;
        st.push(u);
        for (auto [v, i] : adj[u]) if (i != pi) {
            if (tin[v] == -1) self(self, v, i);
            low[u] = min(low[u], low[v]);
        }

        if (low[u] == tin[u]) {
            int v;
            do {
                v = st.top();
                st.pop();
                ecc_id[v] = ecc_cnt;
            } while (v != u);
            ecc_cnt++;
        }
    };
    for (int s = 0; s < n; s++) if (tin[s] == -1) {
        dfs(dfs, s, -1);
    }

    return {ecc_cnt, ecc_id};
}

pair<int, int> farthest(const vector<vector<int>> &adj, int s) {
    int n = int(size(adj));

    vector<int> dist(n, -1);
    dist[s] = 0;

    queue<int> que({s});
    while (!empty(que)) {
        int u = que.front();
        que.pop();

        for (int v : adj[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            que.push(v);
        }
    }

    int t = int(max_element(begin(dist), end(dist)) - begin(dist));
    return {t, dist[t]};
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[u, v] : edges) {
        cin >> u >> v;
        u--, v--;
    }

    auto [ecc_cnt, ecc_id] = two_ecc(n, edges);

    vector<vector<int>> adj_ecc(ecc_cnt);
    for (auto [u, v] : edges) {
        int eu = ecc_id[u];
        int ev = ecc_id[v];
        if (eu != ev) {
            adj_ecc[eu].push_back(ev);
            adj_ecc[ev].push_back(eu);
        }
    }

    int s = farthest(adj_ecc, 0).first;
    auto [t, d] = farthest(adj_ecc, s);

    cout << d << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}