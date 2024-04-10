#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n + 1);
    vector<tuple<int, int, int>> vt(m);
    for (auto& [a, b, w] : vt) {
        cin >> a >> b >> w;
        G[a].emplace_back(b, w);
        G[b].emplace_back(a, w);
    }
    vector p(30, vector<int>(n + 1));
    for (int i = 0; i < 30; i += 1) {
        for (int j = 1; j <= n; j += 1) if (not p[i][j]) {
            queue<int> q;
            q.push(j);
            p[i][j] = j;
            while (not q.empty()) {
                int u = q.front();
                q.pop();
                for (auto [v, w] : G[u]) if ((w >> i) & 1) {
                    if (not p[i][v]) {
                        q.push(v);
                        p[i][v] = j;
                    }
                }
            }
        }
    }
    vector<int> ans(n + 1), e;
    for (auto [a, b, w] : vt)
        if (w % 2 == 0) {
            if (not ans[a]) e.push_back(a);
            if (not ans[b]) e.push_back(b);
            ans[a] = ans[b] = 1;
        }
    for (int i = 1; i < 30; i += 1) {
        vector<int> tmp(n + 1);
        for (int k : e)
                tmp[p[i][k]] = 1;
        for (int j = 1; j <= n; j += 1)
            ans[j] |= tmp[p[i][j]];
    }
    int q;
    cin >> q;
    for (int i = 0, u, v; i < q; i += 1) {
        cin >> u >> v;
        int ok = 0;
        for (int j = 0; j < 30; j += 1)
            if (p[j][u] == p[j][v])
                ok = 1;
        if (ok) cout << "0\n";
        else if (ans[u]) cout << "1\n";
        else cout << "2\n";
    }
}