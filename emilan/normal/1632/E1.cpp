#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n);
    auto dfs0 = [&](auto &self, int u, int p) -> void {
        for (int v : adj[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            self(self, v, u);
        }
    };
    dfs0(dfs0, 0, -1);

    vector<int> depth_distr0(n);
    for (int u = 0; u < n; u++) {
        depth_distr0[depth[u]]++;
    }

    int depth_max0 = *max_element(depth.begin(), depth.end());
    vector<int> ans(n + 1, depth_max0);
    for (int s = 1; s < n; s++) {
        vector<int> depth_distr = depth_distr0;
        int depth_max = depth_max0;

        vector<int> dist(n, -1);
        dist[s] = 0;
        int dist_max = 0;

        queue<int> q;
        q.push(s);

        for (int w = depth[s] - 1; w >= 1; w--) {
            queue<int> q_tmp;
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                if (dist[u] + w >= depth[u]) {
                    q_tmp.push(u);
                    continue;
                }

                depth_distr[depth[u]]--;
                dist_max = max(dist_max, dist[u]);

                for (int v : adj[u]) if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            q.swap(q_tmp);

            while (depth_max > 0 && depth_distr[depth_max] == 0) depth_max--;

            ans[w] = min(ans[w], max(depth_max, dist_max + w));
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}