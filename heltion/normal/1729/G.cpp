#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1000000007;
void add(LL& x, LL y) {
    if ((x += y) >= mod)
        x -= mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size(), r = -1;
        vector<int> p(n);
        for (int i = 0; i < n; i += 1) {
            if (s.substr(i, m) == t) {
                p[i] = 1;
                r = i;
            }
        }
        if (r == -1) {
            cout << "0 1\n";
            continue;
        }
        vector f(n, vector<int>(n + 1));
        vector g(n, vector<LL>(n + 1));
        for (int i = 0; i < n; i += 1)
            if (p[i]) {
                int st = -1;
                for (int j = 0; j <= i - m ; j += 1)
                    if (p[j])
                        st = j;
                if (st == -1) {
                    f[i][1] = 1;
                    add(g[i][1], 1);
                }
                else {
                    for (int j = 0; j <= st; j += 1)
                        if (p[j] and j + m - 1 >= st)
                            for (int k = 1; k < n; k += 1)
                                if (f[j][k]) {
                                    f[i][k + 1] = 1;
                                    add(g[i][k + 1], g[j][k]);
                                }
                }
            }
        LL x = n + 1, y = 0;
        for (int j = 0; j <= r; j += 1)
            if (p[j] and j + m - 1 >= r)
                for (int k = 1; k <= n; k += 1) if (f[j][k]) {
                    if (k < x) {
                        x = k;
                        y = 0;
                    }
                    if (k == x)
                        add(y, g[j][k]);
                }
        cout << x << " " << y << "\n";
    }
}