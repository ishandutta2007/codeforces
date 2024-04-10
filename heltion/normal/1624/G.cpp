#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int, int, int>> vt(m);
        for (auto& [u, v, w] : vt) cin >> u >> v >> w;
        int x = (1 << 30) - 1;
        for (int i = 29; i >= 0; i -= 1) {
            int y = x ^ (1 << i);
            vector<int> p(n + 1, -1);
            function<int(int)> fp = [&](int u) {
                return p[u] < 0 ? u : p[u] = fp(p[u]);
            };
            int c = n;
            for (auto [u, v, w] : vt) if ((y & w) == w) {
                int pu = fp(u), pv = fp(v);
                if (pu != pv) {
                    c -= 1;
                    if (p[pu] < p[pv]) swap(pu, pv);
                    p[pv] += p[pu];
                    p[pu] = pv;
                }
            }
            if (c == 1) x = y;
        }
        cout << x << "\n";
    }
}