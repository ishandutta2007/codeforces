#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 998244353;
int n, ans, a[maxn], f[maxn][210][2], g[maxn][210], h[maxn][210];

void red(int &x) { x += x >> 31 & P; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    auto init = [&](int i) {
        for (int j = 1; j <= 200; j++) {
            g[i][j] = g[i][j - 1], h[i][j] = h[i][j - 1];
            red(g[i][j] += f[i][j][0] - P);
            red(h[i][j] += f[i][j][1] - P);
        }
    };
    if (!~a[1]) {
        for (int i = 1; i <= 200; i++) f[1][i][0] = 1;
    } else {
        f[1][a[1]][0] = 1;
    }
    init(1);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 200; j++) {
            if (~a[i] && a[i] != j) continue;
            red(f[i][j][0] += g[i - 1][j - 1] - P);
            red(f[i][j][0] += h[i - 1][j - 1] - P);

            red(f[i][j][1] += f[i - 1][j][0] - P);
            red(f[i][j][1] += h[i - 1][200] - P);
            red(f[i][j][1] -= h[i - 1][j - 1]);
        }
        init(i);
    }
    for (int i = 1; i <= 200; i++) {
        red(ans += f[n][i][1] - P);
    }
    printf("%d\n", ans);
    return 0;
}