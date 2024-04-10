#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 0; u < n; u++) {
        sort(adj[u].begin(), adj[u].end());
    }

    list<int> yet(n);
    iota(yet.begin(), yet.end(), 0);

    int ans = -1;
    while (!yet.empty()) {
        int s = yet.front();
        yet.erase(yet.begin());

        vector<int> check{s};
        while (!check.empty()) {
            int u = check.back();
            check.pop_back();

            int i = 0;
            int k = adj[u].size();
            vector<decltype(yet.begin())> rm;
            for (auto it = yet.begin(); it != yet.end(); it++) {
                while (i < k && *it > adj[u][i]) i++;
                if (i == k || *it < adj[u][i]) {
                    rm.push_back(it);
                    check.push_back(*it);
                }
            }
            for (auto it : rm) yet.erase(it);
        }

        ans++;
    }

    cout << ans << "\n";
}