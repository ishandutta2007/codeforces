#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 202;
int n, sm[N], c[N][N], f[N][N], g[N][N];
inline int Calc(int x, int y, int u, int v){
    if (x > u || y > v) return 0;
    return c[u][v] - c[x - 1][v] - c[u][y - 1] + c[x - 1][y - 1];
}
int fa[N];
inline void Solve(int l, int r, int ff) {
    if (l > r) return;
    if (l == r) { fa[l] = ff; return; }
    int m = g[l][r];
    fa[m] = ff;
    Solve(l, m - 1, m); Solve(m + 1, r, m);
}
signed main() {
    scanf("%lld", &n);
    for (int i = 1, x; i <= n; ++i) {
        sm[i] = sm[i - 1];
        for (int j = 1; j <= n; ++j) {
            scanf("%lld", &x);
            sm[i] += x;
            c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1] + x;
        }
    }
    for (int i = n; i >= 1; --i)
        for (int j = i + 1; j <= n; ++j) {
            f[i][j] = 1e18;
            for (int k = i; k <= j; ++k) {
                int nf = f[i][k - 1] + f[k + 1][j] + sm[k - 1] - sm[i - 1] + sm[j] - sm[k] - Calc(i, i, k - 1, k - 1) - Calc(k + 1, k + 1, j, j);
                // printf("%lld %lld %lld %lld\n", i, j, k, nf);
                if (nf < f[i][j]) f[i][j] = nf, g[i][j] = k;
            }
        }
    Solve(1, n, 0);
    // printf("%lld\n", f[1][4]);
    for (int i = 1; i <= n; ++i) printf("%lld ", fa[i]);
    puts("");
    return 0;
}