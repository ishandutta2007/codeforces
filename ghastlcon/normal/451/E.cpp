#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 20
#define MOD 1000000007
using namespace std;

long long a[N];

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

int C(long long n, int m)
{
    static int c;

    int i, o;

    if(n < m)
        return 0;

    if(!c)
        for(i = c = 1; i <= m; i ++)
            c = (long long)c * Power(i, MOD - 2) % MOD;
    for(i = 1, o = c; i <= m; i ++)
        o = (long long)o * ((n - i + 1) % MOD) % MOD;

    return o;
}

int main(void)
{
    int n;
    long long m;
    int i, j, o;
    long long s;

    cin >> n >> m;
    for(i = 0; i < n; i ++)
        cin >> a[i];

    for(i = o = 0; i < (1 << n); i ++)
    {
        for(j = 0, s = m; j < n; j ++)
            if(i & (1 << j))
                s -= a[j] + 1;
        // printf("%lld %d\n", s, n - 1);
        // cout<<i<<' '<<__builtin_parity(i)<<endl;
        o = (o + (__builtin_parity(i) ? -1 : 1) * C(s + n - 1, n - 1)) % MOD;
    }
    printf("%d\n", (o + MOD) % MOD);

    return 0;
}