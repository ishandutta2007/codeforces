#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
using namespace std;
const int N = 4001;
const int mod = 998244353;
int a[N * 100], b[N * 100];
int f[N][N], g[N][N];
int n, m;
long long s[2];
int ni[N * 2];
long long calc(long long x, long long y) {
    long long z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod, y/= 2;
    }
    return z;
}
long long frac(long long x, long long y) {
    return ((x % mod + mod) % mod) * ni[y - s[0] - s[1] + N] % mod;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n ; i ++)
        s[a[i]] += b[i];
    for (int i = -3000; i <= 3000; i ++)
        ni[i + N] = calc(i + s[0] + s[1], mod - 2);
    for (int all = m; all >= 0; all --) {
        for (int i = all; i >= 0; i--){
            int j = all - i;
            if (j > s[0]) continue;
                if (i + j == m) g[i][j] = f[i][j] = 1;
                else {
                    f[i][j] = (1ll * frac(s[1] + i + 1, s[1] + s[0] + i - j) * f[i + 1][j] +
                               1ll * frac(s[0] - j, s[0] + s[1] + i - j) * f[i][j + 1]) % mod;
                    g[i][j] = (1ll * frac(s[1] + i, s[1] + s[0] + i - j) * g[i + 1][j] +
                               1ll * frac(s[0] - j - 1, s[0] + s[1] + i - j) * g[i][j + 1]) % mod;
                }
            }
    }
    for (int i = 1; i <= n ; i ++)if (a[i]) printf("%lld\n", 1ll * f[0][0] * b[i] % mod); else printf("%lld\n", 1ll * g[0][0] * b[i] % mod);
    return 0;
}