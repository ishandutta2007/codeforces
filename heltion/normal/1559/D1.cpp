#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> p1(n + 1), p2(n + 1);
    for (int i = 1; i <= n; i += 1) p1[i] = p2[i] = i;
    function<int(vector<int>&, int)> f = [&](vector<int>& p, int u) {
        return p[u] == u ? u : p[u] = f(p, p[u]);
    };
    for (int i = 1; i <= m1; i += 1) {
        int u, v;
        cin >> u >> v;
        p1[f(p1, u)] = f(p1, v);
    }
    for (int i = 1; i <= m2; i += 1) {
        int u, v;
        cin >> u >> v;
        p2[f(p2, u)] = f(p2, v);
    }
    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; i += 1)
        for (int j = 1; j <= n; j += 1) {
            int i1 = f(p1, i), j1 = f(p1, j);
            int i2 = f(p2, i), j2 = f(p2, j);
            if (i1 != j1 and i2 != j2) {
                vp.push_back({i, j});
                p1[i1] = j1;
                p2[i2] = j2;
            }
        }
    cout << vp.size() << "\n";
    for (auto [x, y] : vp) cout << x << " " << y << "\n";
    return 0;
}