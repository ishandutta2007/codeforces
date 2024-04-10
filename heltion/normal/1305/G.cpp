#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    LL ans = 0;
    vector<int> a(n), p(n + 1, -1);
    for (int& ai : a) {
        cin >> ai;
        ans -= ai;
    }
    a.push_back(0);
    int c = n + 1;
    function<int(int)> fp = [&](int u) {
        return p[u] < 0 ? u : p[u] = fp(p[u]);
    };
    auto _union = [&](int u, int v) {
        int pu = fp(u), pv = fp(v);
        if (pu == pv) return;
        c -= 1;
        ans += a[u] + a[v];
        if (p[pu] < p[pv]) swap(pu, pv);
        p[pv] += p[pu];
        p[pu] = pv;
    };
    while (c > 1) {
        vector<int> f(1 << 18, -1), g(1 << 18, -1);
        auto update = [&](int i, int j) {
            if (j == -1) return;
            if (f[i] == -1) f[i] = j;
            else if (a[j] > a[f[i]]) {
                if (fp(j) == fp(f[i])) f[i] = j;
                else {
                    g[i] = f[i];
                    f[i] = j;
                }
            }
            else if (g[i] == -1 or a[j] > a[g[i]]) {
                if (fp(j) != fp(f[i])) g[i] = j;
            }
        };
        for (int i = 0; i <= n; i += 1)
            update(a[i], i);
        for (int i = 0; i < (1 << 18); i += 1)
            for (int j = 0; j < 18; j += 1)
                if (not ((i >> j) & 1)) {
                    update(i ^ (1 << j), f[i]);
                    update(i ^ (1 << j), g[i]);
                }
        vector<pair<int, int>> vp(n + 1, {-1, -1});
        for (int i = 0; i <= n; i += 1) {
            int p = fp(i), j = (1 << 18) - 1 - a[i];
            pair<int, int> cur = {-1, 1};
            if (fp(f[j]) == p) cur = {g[j], i};
            else cur = {f[j], i};
            if (cur.first != -1) {
                if (vp[p].first == -1 or a[vp[p].first] + a[vp[p].second] < a[cur.first] + a[cur.second])
                    vp[p] = cur;
            }
        }
        for (auto [u, v] : vp)
            if (u != -1)
                _union(u, v);
    }
    cout << ans << "\n";
    return 0;
}