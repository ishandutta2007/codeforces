#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 5020
#define MOD 998244353
using namespace std;

int a[N];
int f[N][N], g[N];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

int main(void)
{
    int n, x;
    int i, j, o;

    for(i = 2, g[1] = 1; i < N; i ++)
        g[i] = (long long)Mod(-MOD / i) * g[MOD % i] % MOD;

    cin >> n;
    for(i = 1; i <= n; i ++)
    {
        cin >> x;
        a[x] ++;
    }

    for(i = 0; i <= n; i ++)
        f[0][i] = 1;
    for(i = 1, o = 0; i <= n; i ++)
        for(j = 1; j <= n; j ++)
        {
            f[i][j] = f[i][j - 1];
            if(a[j])
            {
                f[i][j] = (f[i][j] + (long long)f[i - 1][j - 1] * a[j] % MOD * g[n - i + 1]) % MOD;
                if(a[j] > 1)
                    o = (o + (long long)Mod(f[i][j] - f[i][j - 1]) * (a[j] - 1) % MOD * g[n - i]) % MOD;
            }
        }
    // for(i=1;i<=n;i++){for(j=1;j<=n;j++)printf("select %d,max %d:%d\n",i,j,f[i][j]);}
    cout << o << endl;

    return 0;
}