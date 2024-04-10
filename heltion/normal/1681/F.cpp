#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 1; i < n; i += 1) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<int> size(n + 1), dfn(n + 1), rev(n + 1), c(n + 1);
    int t = 0;
    vector<int> p;
    function<void(int)> DFS = [&](int u) {
        size[u] = 1;
        rev[dfn[u] = t += 1] = u;
        for (auto [v, w] : G[u]) if (not dfn[v]) {
            c[v] = w;
            DFS(v);
            size[u] += size[v];
        }
        p.push_back(u);
    };
    DFS(1);
    vector<vector<int>> mp(n + 1);
    for (int i : p)
        mp[c[i]].push_back(i);
    LL ans = 0;
    for (int i = 1; i <= n; i += 1) {
        map<int, int> f;
        map<int, int> p;
        set<int> s;
        for (int j : mp[i]) {
            f[j] = size[j];
            vector<int> ss;
            for (auto it = s.lower_bound(dfn[j]);
                it != s.end() and *it < dfn[j] + size[j];
                it = s.erase(it)) {
                ss.push_back(rev[*it]);
                f[j] -= size[rev[*it]];
            }
            for (int k : ss) p[k] = f[j];
            s.insert(dfn[j]);
        }
        int m = n;
        for (int j : s) m -= size[rev[j]];
        for (int j : s) p[rev[j]] = m;
        for (auto [x, y] : f) {
            assert(p.contains(x));
            ans += (LL)y * p[x];
        }
    }
    cout << ans;
    return 0;
}