#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int T, f[32][2][2][2], g[32][2][2][2];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d", &T);
    auto query = [&](int X, int Y, int k) {
        if (X < 0 || Y < 0) return 0;
        memset(f, -1, sizeof(f));
        function<void(int, bool, bool, bool)> dfs = [&](int i, bool ux, bool uy, bool uk) {
            if (i < 0 || ~f[i][ux][uy][uk]) return;
            f[i][ux][uy][uk] = g[i][ux][uy][uk] = 0;
            int cx = X >> i & 1, cy = Y >> i & 1, ck = k >> i & 1;
            for (int x : {0, 1}) for (int y : {0, 1}) {
                if (!ux && x > cx) continue;
                if (!uy && y > cy) continue;
                if (!uk && (x ^ y) > ck) continue;
                bool _ux = ux | (x < cx);
                bool _uy = uy || (y < cy);
                bool _uk = uk || ((x ^ y) < ck);
                dfs(i - 1, _ux, _uy, _uk);
                int _f = !i ? 1 : f[i - 1][_ux][_uy][_uk];
                int _g = !i ? 0 : g[i - 1][_ux][_uy][_uk];
                red(f[i][ux][uy][uk] += _f - P);
                red(g[i][ux][uy][uk] += _g - P);
                if (x ^ y) red(g[i][ux][uy][uk] += (1LL << i) * _f % P - P);
            }
        };
        dfs(31, 0, 0, 0);
        return (f[31][0][0][0] + g[31][0][0][0]) % P;
    };
    while (T--) {
        int x1, y1, x2, y2, k;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        x1--, y1--, x2--, y2--, k--;
        int ans = query(x2, y2, k) - query(x1 - 1, y2, k) - query(x2, y1 - 1, k)
            + query(x1 - 1, y1 - 1, k);
        printf("%d\n", (ans % P + P) % P);
    }
    return 0;
}