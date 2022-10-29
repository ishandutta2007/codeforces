#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int N = 5011;
const int mod = 998244353;
int n, k, l;
long long C[N][N];
long long a[N], b[N], help[N], v[N];
long long calc(long long x,long long y)
{
    long long z = 1;
    while (y)
    {
        if (y & 1) (z *= x) %= mod;
        (x *= x) %= mod, y /= 2;
    }
    return z;
}
long long ni(long long x)
{
    return calc(x, mod - 2);
}
int main(){
    scanf("%d %d %d", &n, &k, &l);
    C[0][0] = 1;
    for (int i = 1; i < N ; i ++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i ; j ++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    for (int i = k; i <= n ; i ++)
    {
        long long V = C[n][i] % mod * calc(mod -1, i )% mod ;
        long long l2_2 = ni(2) * l % mod * l % mod;
        for (int j = 0; j <= n -  i ; j ++)
        {
            v[j + i] += C[n - i][j] * calc(l2_2, n - i - j) % mod * V % mod;
            if (v[j + i] >= mod)
                v[j + i] -= mod;
        }
    }
    b[0] = 1;
    for (int i = 0; i <= n; i ++)
    {
        for (int j = 0; j <= n * 2; j ++)
            (a[j] += v[i]  * b[j]) %= mod;
        for (int j = 0; j <= n * 2 ; j ++)
        {
            (help[j + 1] += (mod - l) *b[j] % mod) %= mod;
            (help[j + 2] += b[j]) %= mod;
        }
        for (int j = 0; j <= n * 2 + 10; j ++)
            b[j] = help[j], help[j] = 0;
    }
    for (int i = 0; i <= n * 2 ; i ++)
        help[i + 1] = a[i] * ni(i + 1) % mod;
    long long ans = 0;
    for (int i = 0; i <= 2 * n + 1; i ++)
        (ans += help[i] * calc(l, i)) %=mod;

    printf("%d\n", ans * ni(calc(l, 2 * n)) % mod * calc(2, n) % mod);
    return 0;
}