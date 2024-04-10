#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        vector<int> ans;
        int res = INT_MAX;
        for (int i = 0; i <= n; i += 1) if (i == n or a[i]) {
            auto b = a;
            int pres = 0;
            if (i < n) {
                b[i] -= 1;
                pres += 1;
            }
            vector<int> p(n + 1);
            for (int j = 0; j <= n; j += 1) p[j] = j;
            function<int(int)> fp = [&](int u) {
                return u == p[u] ? u : p[u] = fp(p[u]);
            };
            vector<vector<int>> G(30);
            for (int i = 0; i < n; i += 1)
                for (int j = 0; j < 30; j += 1)
                    if ((b[i] >> j) & 1) G[j].push_back(i);
            int c = n;
            for (int i = 0; i < 30; i += 1)
                for (int j = 1; j < G[i].size(); j += 1) {
                    int x = fp(G[i][0]), y = fp(G[i][j]);
                    if (x != y) {
                        p[x] = y;
                        c -= 1;
                    }
                }
            if (c > 1) {
                c += 1;
                for (int x : G[0]) {
                    x = fp(x);
                    if (x != n) {
                        p[x] = n;
                        c -= 1;
                    }
                }
                for (int i = 0; i < n; i += 1) {
                    int x = fp(i);
                    if (x != n) {
                        p[x] = n;
                        c -= 1;
                        pres += 1;
                        b[i] += 1;
                    }
                }
            }
            if (pres < res) {
                res = pres;
                ans.swap(b);
            }
        }
        cout << res << "\n";
        for (int ansi : ans) cout << ansi << " ";
        cout << "\n";
    }
    return 0;
}