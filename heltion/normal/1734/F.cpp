#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, m;
        cin >> n >> m;
        m -= 1;
        vector f(2, vector(2, vector<LL>(2)));
        f[0][0][0] = f[0][1][1] = 1;
        for (int i = 63; i >= 0; i -= 1) {
            int a = (m >> i) & 1, b = (n >> i) & 1;
            vector g(2, vector(2, vector<LL>(2)));
            for (int c = 0; c < 2; c += 1)
                for (int d = 0; d < 2; d += 1)
                    for (int e = 0; e < 2; e += 1)
                        for (int x = 0; x < 2; x += 1)
                            for (int y = 0; y < 2; y += 1) {
                                if (c == 0 and x > a) continue;
                                int nc = c or x < a;
                                if ((x + b + y) / 2 != d) continue;
                                int nd = y;
                                int ne = e ^ y;
                                g[nc][nd][ne] += f[c][d][e];
                            }
            f.swap(g);
            if(0) for (int c = 0; c < 2; c += 1)
                for (int d = 0; d < 2; d += 1)
                    for (int e = 0; e < 2; e += 1)
                        cout << i << " " << c << " " << d << " " << e << " " << f[c][d][e] << "\n";
        }
        int p = __builtin_parityll(n) ^ 1;
        cout << f[0][0][p] + f[1][0][p] << "\n";
    }
}