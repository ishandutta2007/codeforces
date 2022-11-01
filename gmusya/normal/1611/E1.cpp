#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(k);
        for (int i = 0; i < k; ++i) {
            cin >> x[i];
            --x[i];
        }
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q;
        vector<int> d1(n, n);
        for (int v : x) {
            q.push(v);
            d1[v] = 0;
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : g[v]) {
                if (d1[v] + 1 < d1[u]) {
                    d1[u] = d1[v] + 1;
                    q.push(u);
                }
            }
        }
        q.push(0);
        vector<int> d2(n, n);
        d2[0] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : g[v]) {
                if (d2[v] + 1 < d2[u]) {
                    d2[u] = d2[v] + 1;
                    q.push(u);
                }
            }
        }
        bool can = false;
        for (int v = 1; v < n; ++v) {
            if (g[v].size() == 1 && d2[v] < d1[v]) {
                can = true;
            }
        }
        if (can) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}