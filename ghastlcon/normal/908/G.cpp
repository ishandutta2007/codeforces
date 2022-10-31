#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 720
#define MOD 1000000007
using namespace std;

char a[N];
int f[N][N][2];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

inline void Modadd(int &x, int y)
{
    x = Mod(x + y - MOD);

    return;
}

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
    int n;
    int i, j, k, t, o;

    scanf("%s", a);
    n = (int)strlen(a);
    for(k = 1, o = 0; k < 10; k ++)
    {
        memset(f, 0, sizeof(f));
        f[0][0][1] = 1;
        for(i = 0; i < n; i ++)
            for(j = 0; j <= n; j ++)
                for(t = 0; t < 10; t ++)
                {
                    Modadd(f[i + 1][j + (t >= k)][0], f[i][j][0]);
                    if(t < a[i] - 48)
                        Modadd(f[i + 1][j + (t >= k)][0], f[i][j][1]);
                    else if(t == a[i] - 48)
                        Modadd(f[i + 1][j + (t >= k)][1], f[i][j][1]);
                }

        for(i = t = 1; i <= n; i ++, t = ((long long)t * 10 + 1) % MOD)
            Modadd(o, (long long)Mod(f[n][i][0] + f[n][i][1] - MOD) * t % MOD);
    }
    printf("%d\n", o);

    return 0;
}