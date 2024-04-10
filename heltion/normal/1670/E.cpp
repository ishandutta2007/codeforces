#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int p;
        cin >> p;
        int n = (1 << p);
        vector<pair<int, int>> e(n);
        vector<vector<int>> G(n + 1);
        for (int i = 1; i < n; i += 1) {
            cin >> e[i].first >> e[i].second;
            G[e[i].first].push_back(i);
            G[e[i].second].push_back(i);
        }
        vector<int> ans(2 * n);
        int t = 0;
        ans[1] = n;
        function<void(int, int, int)> DFS = [&](int u, int p, int x) {
            for (int i : G[u]) {
                int v = e[i].first ^ e[i].second ^ u;
                if (v != p) {
                    t += 1;
                    if (x) {
                        ans[n + i] = t;
                        ans[v] = t + n;
                    }
                    else {
                        ans[n + i] = t + n;
                        ans[v] = t;
                    }
                    DFS(v, u, x ^ 1);
                }
            }
        };
        DFS(1, 0, 0);
        cout << "1\n";
        for (int i = 1; i < 2 * n; i += 1)
            cout << ans[i] << " ";
        cout << "\n";
    }
}