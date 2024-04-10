#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#define N 120
using namespace std;

long long a[N][N], f[N][N];

long long BFS(int n, int m, long long w)
{
    int i, j;

    if(a[0][0] < w)
        return LLONG_MAX;

    for(i = 0; i < n; i ++)
        fill(f[i], f[i] + m, LLONG_MAX >> 2);
    f[0][0] = a[0][0] - w;
    for(i = 0; i < n; i ++)
        for(j = 0; j < m; j ++)
            if((i || j) && a[i][j] >= w)
            {
                if(i)
                    f[i][j] = min(f[i][j], f[i - 1][j] + a[i][j] - w);
                if(j)
                    f[i][j] = min(f[i][j], f[i][j - 1] + a[i][j] - w);
            }
    // cout<<"f "<<w<<' '<<f[n-1][m-1]<<endl;

    return f[n - 1][m - 1];
}

int main(void)
{
    int t, n, m;
    int i, j;
    long long o;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i ++)
            for(j = 0; j < m; j ++)
            {
                scanf("%I64d", &a[i][j]);
                a[i][j] -= i + j;
            }

        o = LLONG_MAX;
        for(i = 0; i < n; i ++)
            for(j = 0; j < m; j ++)
                o = min(o, BFS(n, m, a[i][j]));
        printf("%I64d\n", o);
    }

    return 0;
}