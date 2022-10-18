#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            g[x].push_back(y);
            g[y].push_back(x);
            ++deg[x];
            ++deg[y];
        }
        queue<pii> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] <= 1) {
                q.emplace(i, 1);
            }
        }
        vector<int> was(n);
        while (!q.empty()) {
            auto [v, dist] = q.front();
            q.pop();
            if (was[v] || deg[v] > 1) continue;
            was[v] = dist++;
            for (int to : g[v]) {
                if (--deg[to] <= 1)
                    q.emplace(to, dist);
            }
        }
        vector<int> sum(n);
        for (int i = 0; i < n; ++i) {
            ++sum[was[i] - 1];
        }
        partial_sum(all(sum), sum.begin());
        k = min(k, n) - 1;
        cout << n - sum[k] << '\n';
    }
}