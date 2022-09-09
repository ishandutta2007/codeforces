#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    LL ans = 0;
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 1, u, v, w; i < n; i += 1) {
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        ans += w * 2;
    }
    vector<int> p(n + 1), pw(n + 1);
    vector<LL> fup(n + 1), gup(n + 1), fdown(n + 1), gdown(n + 1);
    function<void(int)> DFS = [&](int u) {
        vector<LL> fs;
        for (auto [v, w] : G[u]) if (v != p[u]) {
            pw[v] = w;
            p[v] = u;
            DFS(v);
            fs.push_back(fup[v] + w);
            gup[u] = max(gup[u], gup[v]);
        }
        ranges::sort(fs, greater<LL>());
        if (fs.size() >= 1) {
            fup[u] = fs[0];
            gup[u] = max(gup[u], fs[0] + (fs.size() > 1 ? fs[1] : 0));
        }
    };
    function<void(int)> DFS1 = [&](int u) {
        vector<LL> fs = {fdown[u]};
        for (auto [v, w] : G[u]) if (v != p[u])
            fs.push_back(fup[v] + w);
        ranges::sort(fs, greater<LL>());
        for (auto [v, w] : G[u]) if (v != p[u]) {
            LL cur = fup[v] + w;
            gdown[v] = max(gdown[u], fdown[u]);
            if (fs[0] == cur) {
                fdown[v] = fs[1] + w;
                gdown[v] = max(gdown[v], fs[1] + (2 < fs.size() ? fs[2] : 0));
            }
            else {
                fdown[v] = fs[0] + w;
                if (fs[1] == cur)
                    gdown[v] = max(gdown[v], fs[0] + (2 < fs.size() ? fs[2] : 0));
                else gdown[v] = max(gdown[v], fs[0] + fs[1]);
            }
            
        }
        for (auto [v, w] : G[u]) if (v != p[u])
            DFS1(v);
    };
    DFS(1);
    DFS1(1);
    LL dans = 0; 
    for (int i = 1; i <= n; i += 1) {
        LL pans = 0;
        vector<LL> fs = {fdown[i]};
        for (auto [v, w] : G[i]) if (p[i] != v) {
            fs.push_back(fup[v] + w);
        }
        ranges::sort(fs, greater<LL>());
        for (int i = 0; i < 4 and i < fs.size(); i += 1)
            pans += fs[i];
        dans = max(dans, pans);
    }
    for (int i = 2; i <= n; i += 1)
        dans = max(dans, gdown[i] + gup[i] + 2 * pw[i]);
    cout << ans - dans;
}