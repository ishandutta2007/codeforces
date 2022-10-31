#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 520
using namespace std;

int a[N];
int f[N][N], g[N];

int main(void)
{
    int n;
    int i, j, k, l;

    memset(f, -1, sizeof(f));
    cin >> n;
    for(i = 1; i <= n; i ++)
    {
        cin >> a[i];
        f[i][i] = a[i];
    }

    for(l = 2; l <= n; l ++)
        for(i = 1; i <= n - l + 1; i ++)
        {
            j = i + l - 1;
            for(k = i; k < j; k ++)
                if(f[i][k] != -1 && f[k + 1][j] != -1 && f[i][k] == f[k + 1][j])
                {
                    f[i][j] = f[i][k] + 1;
                    break;
                }
            // printf("%d-%d : %d\n", i, j, f[i][j]);
        }

    for(i = 1; i <= n; i ++)
        for(j = 0, g[i] = n; j < i; j ++)
            if(f[j + 1][i] != -1)
                g[i] = min(g[i], g[j] + 1);
    cout << g[n] << endl;

    return 0;
}