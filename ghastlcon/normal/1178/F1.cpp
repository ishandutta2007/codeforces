#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 520
#define MOD 998244353
using namespace std;

int a[N];
int f[N][N];

int DP(int l, int r)
{
    int i, m;
    int x, y;

    if(l > r)
        return 1;
    if(f[l][r] != -1)
        return f[l][r];
    m = min_element(a + l, a + r + 1) - a;

    for(i = m, x = 0; i >= l; i --)
        x = (x + (long long)DP(i, m - 1) * DP(l, i - 1) % MOD) % MOD;
    for(i = m, y = 0; i <= r; i ++)
        y = (y + (long long)DP(m + 1, i) * DP(i + 1, r) % MOD) % MOD;

    return f[l][r] = (long long)x * y % MOD;
}

int main(void)
{
    int n;
    int i;

    memset(f, -1, sizeof(f));
    scanf("%d %*d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    printf("%d\n", DP(1, n));

    return 0;
}