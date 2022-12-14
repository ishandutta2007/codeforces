#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> c(n + 1);
    c[0] = n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        cin >> c[i];
    }

    vector<vector<int>> chi(n + 1);

    auto dfs = [&](int u, auto &f) -> void {
        for (int v : adj[u]) {
            f(v, f);

            chi[u].insert(chi[u].end(), chi[v].begin(), chi[v].end());
        }

        if (c[u] > int(chi[u].size())) {
            cout << "NO";
            exit(0);
        }

        chi[u].insert(chi[u].begin() + c[u], u);
    };

    dfs(0, dfs);

    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        ans[chi[0][i]] = i + 1;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}