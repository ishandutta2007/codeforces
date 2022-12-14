#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        while (m--) {
            int u, v;
            cin >> u >> v;
            if (u != v) adj[--u].push_back(--v);
        }

        int seq = 1;
        vector<int> tin(n), low(n), jury;
        stack<int> st;

        auto dfs = [&](int u, auto &&f) -> void {
            tin[u] = low[u] = seq++;
            st.push(u);

            for (int v : adj[u]) {
                if (!tin[v]) f(v, f);

                low[u] = min(low[v], low[u]);
            }

            if (!jury.empty()) return;

            if (low[u] == tin[u]) {
                int v;
                do {
                    v = st.top();
                    st.pop();

                    jury.push_back(v);
                } while (v != u);
            }
        };

        dfs(0, dfs);

        int k = jury.size();
        if (k == n) cout << "No\n";
        else {
            cout << "Yes\n";
            cout << k << ' ' << n - k << '\n';

            vector<bool> cats(n, true);
            for (int u : jury) {
                cats[u] = false;
                cout << u + 1 << ' ';
            }
            cout << '\n';

            for (int u = 0; u < n; u++) if (cats[u]) {
                cout << u + 1 << ' ';
            }
            cout << '\n';
        }
    }
}