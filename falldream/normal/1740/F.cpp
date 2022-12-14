#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MN 2000
#define mod 998244353
using namespace std;
int n, num[MN + 5], s[MN + 5], f[2][MN + 5][MN + 5], g[MN + 5], ans;
int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        ++num[x];
    }
    for (int i = 1;i <= n; ++i) {
        for (int j = 1; j <= num[i]; ++j) {
            ++s[j];
        }
    }
    f[0][n][0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i > 1) memset(g, 0, sizeof(g));
        int lim = n / i, plim = n / max(1, i - 1), C = (i & 1), P = 1 - C;
        for (int j = plim; j; --j) {
            for (int k = 0; k <= n; ++k) {
                g[k] = (g[k] + f[P][j][k]) % mod;
                f[P][j][k] = 0;
            }
            if (j <= lim) {
                for (int k = max(0, s[i] - j); k <= n; ++k) {
                    if (j + k - s[i] <= n) f[C][j][k] = g[j + k - s[i]];
                }
            }
        }
        if (s[i + 1] == 0) {
            for (int j = 1; j <= n; ++j) {
                ans = (ans + f[C][j][0]) % mod;
            }
        }
    }
    cout << ans;
    return 0;
}