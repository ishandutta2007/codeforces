//
#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 220
#define M 1020
#define MOD 1000000007
using namespace std;

int a[N];
int f[N][N][M];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

inline void Modadd(int &x, int y)
{
    x = Mod(x + y - MOD);

    return;
}

int main(void)
{
    int n, m;
    int i, j, k;

    cin >> n >> m;
    for(i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    f[0][0][0] = 1;
    for(i = 1; i <= n; i ++)
        for(j = 0; j <= n; j ++)
            for(k = 0; k <= m; k ++)
            {
                if(j && k >= (j - 1) * (a[i] - a[i - 1]))
                    Modadd(f[i][j][k], f[i - 1][j - 1][k - (j - 1) * (a[i] - a[i - 1])]);
                if(k >= (j + 1) * (a[i] - a[i - 1]))
                    Modadd(f[i][j][k], (long long)f[i - 1][j + 1][k - (j + 1) * (a[i] - a[i - 1])] * (j + 1) % MOD);
                if(k >= j * (a[i] - a[i - 1]))
                    Modadd(f[i][j][k], (long long)f[i - 1][j][k - j * (a[i] - a[i - 1])] * (j + 1) % MOD);
                // printf("at prev %d, group %d, sum %d : %d\n", i, j, k, f[i][j][k]);
            }

    for(i = k = 0; i <= m; i ++)
        Modadd(k, f[n][0][i]);
    cout << k << endl;

    return 0;
}