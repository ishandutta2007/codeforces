#include <bits/stdc++.h>
using namespace std;

const int maxn = 2100, P = 998244353;
int n, m, ans, C[maxn << 1][maxn], suf[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n + m; i++) {
        for (int j = C[i][0] = 1; j <= min(i, max(n, m)); j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
        }
    }
    auto solve = [&](bool flag) {
        for (int c = 1; c < m; c++) {
            suf[n + 1] = 0;
            for (int lb = n; lb; lb--) {
                // (n, m + 1) -> (lb, c + 1); (lb, c + 2) -> (1, m + 1)
                suf[lb] = (suf[lb + 1] + 1LL * C[n - lb + m - c][n - lb] % P * C[lb - 1 + m - c - 1][lb - 1]) % P;
            }
            for (int ra = 1; ra < n; ra++) {
                // (1, 0) -> (ra, c); (ra, c - 1) -> (n, 0)
                ans = (ans + 1LL * C[ra - 1 + c][ra - 1] * C[n - ra + c - 1][n - ra] % P * suf[ra + 1 + flag]) % P;
            }
        }
    };
    solve(0), swap(n, m), solve(1);
    printf("%d\n", (ans << 1) % P);
    return 0;
}