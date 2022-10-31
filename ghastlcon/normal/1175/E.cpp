#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 500020
#define M 19
#pragma GCC optimize("O3")
using namespace std;

int f[M][N];

int main(void)
{
    int n, m, l, r;
    int i, j, o;

    scanf("%d %d", &n, &m);
    memset(f, -1, sizeof(f));
    for(i = 0; i < n; i ++)
    {
        scanf("%d %d", &l, &r);
        f[0][l] = max(f[0][l], r);
    }

    for(i = 1; i < N; i ++)
        f[0][i] = max(f[0][i], f[0][i - 1]);
    for(i = 1; i < M; i ++)
        for(j = 0; j < N; j ++)
            f[i][j] = f[i - 1][f[i - 1][j]];

    while(m --)
    {
        scanf("%d %d", &l, &r);
        for(i = M - 1, o = 0; i > -1; i --)
            if(f[i][l] < r)
            {
                o |= 1 << i;
                l = f[i][l];
            }
        printf("%d\n", o == ((1 << M) - 1) ? -1 : o + 1);
    }

    return 0;
}