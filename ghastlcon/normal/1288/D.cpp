#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 300020
#define M 8
using namespace std;

int n, m;
int a[N][M];
int f[1 << M | 1];

bool Solve(int x, bool c)
{
    int i, j, v;

    memset(f, -1, sizeof(f));
    for(i = 0; i < n; i ++)
    {
        for(j = v = 0; j < m; j ++)
            if(a[i][j] >= x)
                v |= 1 << j;
        f[v] = i;
    }

    for(i = 0; i < (1 << m); i ++)
        for(j = 0; j < (1 << m); j ++)
            if((i | j) == (1 << m) - 1 && f[i] != -1 && f[j] != -1)
            {
                if(c)
                    printf("%d %d\n", f[i] + 1, f[j] + 1);

                return true;
            }

    return false;
}

int Scan(void)
{
    int c, s;

    for(s = 0; (c = getchar()) < '0' || c > '9'; )
        ;
    do
        s = s * 10 + (c & 15);
    while((c = getchar()) >= '0' && c <= '9');

    return s;
}

int main(void)
{
    int i, j, l, r;

    n = Scan();
    m = Scan();
    for(i = 0; i < n; i ++)
        for(j = 0; j < m; j ++)
            a[i][j] = Scan();

    for(l = 0, r = 1000000001; l + 1 < r; )
        if(Solve((l + r) >> 1, false))
            l = (l + r) >> 1;
        else
            r = (l + r) >> 1;
    Solve(l, true);

    return 0;
}