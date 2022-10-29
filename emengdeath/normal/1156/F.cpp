#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 5001;
const int mod = 998244353;
long long f[N][N], g[N][N], ans, ni[N];
int n, a[N], sum[N];
long long calc(long long x, long long y)
{
    long long z = 1;
    while (y)
    {
        if (y & 1) (z *= x) %= mod;
        (x *= x) %= mod, y >>= 1;
    }
    return z;
}
int main()
{
    scanf("%d", &n);
    ni[0] = 1;
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]), ni[i] = calc(i, mod - 2);
    sort(a + 1, a + n + 1);
    int x = n;
    n = 0;
    for (int i = 1; i <= x ; i ++) {
        if (a[i] != a[n])
            a[++ n] = a[i];
        sum[n] ++;
    }
    for (int i = 1; i <= n ; i ++)
        sum[i] += sum[i - 1];
    f[0][0] = 1;
    g[0][0] = 1;
    for (int i = 1; i <= n ;  i++)
        for (int j = 0; j <= sum[i]; j ++) {
            if (j && g[i - 1][j - 1]) {
                f[i][j] = g[i - 1][j - 1] * ni[sum[n] - j + 1] % mod * (sum[i] - sum[i - 1]) % mod;
                if (sum[i] - sum[i - 1] >= 2) {
                    ans += f[i][j] * ni[sum[n] - j] % mod * (sum[i] - sum[i - 1] - 1) % mod;
                    if (ans >= mod) ans -= mod;
                }
            }
            g[i][j] = f[i][j] + g[i - 1][j];
            if (g[i][j] >= mod) g[i][j] -= mod;
        }
    printf("%d\n", ans);
    return 0;
}