#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1000020
#define MOD 1000000007
using namespace std;

int a[N], b[N];
int f[N];

int Power(int x, int y)
{
    int o;

    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % MOD;
        x = (long long)x * x % MOD;
    }

    return o;
}

int main(void)
{
    int n, m;
    int i, j;

    scanf("%d", &n);
    for(i = 1, m = 0; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        m = max(m, a[i]);
        b[a[i]] ++;
    }

    for(i = 1; i <= m; i ++)
        for(j = 1; i * j <= m; j ++)
            f[i] += b[i * j];
    // for(i=1;i<=m;i++)cout<<f[i]<<' ';cout<<endl;

    for(i = 1; i <= m; i ++)
        if(f[i])
            f[i] = (long long)Power(2, f[i] - 1) * f[i] % MOD;
    // for(i=1;i<=m;i++)cout<<f[i]<<' ';cout<<endl;
    for(i = m; i >= 1; i --)
        for(j = 2; i * j <= m; j ++)
            f[i] = (f[i] - f[i * j]) % MOD;
    // for(i=1;i<=m;i++)cout<<f[i]<<' ';cout<<endl;

    for(i = 2; i <= m; i ++)
        f[0] = (f[0] + (long long)i * f[i] % MOD) % MOD;
    printf("%d\n", f[0]);


    return 0;
}