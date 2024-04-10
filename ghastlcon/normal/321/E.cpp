#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#define N 4020
#pragma GCC optimize("O3")
using namespace std;

class Data
{
public:
    long long x;
    int y;

    Data(long long _x = 0, int _y = 0) : x(_x), y(_y)
    {
        return;
    }

    Data operator+(const Data &that) const
    {
        return Data(this -> x + that.x, this -> y + that.y);
    }

    bool operator<(const Data &that) const
    {
        return this -> x != that.x ? this -> x < that.x : this -> y < that.y;
    }
};

int a[N][N];
long long f[N][N];
Data g[N];

int Scan(void)
{
    int c, s;

    for(s = 0; (c = getchar()) < '0' || c > '9'; )
        ;
    do
        s = s * 10 + c - 48;
    while((c = getchar()) >= '0' && c <= '9');

    return s;
}

void DP(int n, int v)
{
    int i, j;

    for(i = 1; i <= n; i ++)
        for(j = 0, g[i] = Data(LLONG_MAX, 0); j < i; j ++)
            g[i] = min(g[i], Data(g[j].x + v + (f[i][i] >> 1) + (f[j][j] >> 1) - f[i][j], g[j].y + 1));

    return;
}

int main(void)
{
    int n, k;
    int i, j;
    int l, m, r;

    n = Scan();
    k = Scan();
    for(i = 1, r = 0; i <= n; i ++)
        for(j = 1; j <= n; j ++)
        {
            a[i][j] = Scan();
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
            // printf("prev %d %d : %d\n", i, j, f[i][j]);
        }

    for(l = -f[n][n] - 1, r = f[n][n]; l + 1 < r; )
    {
        m = (l + r) >> 1;
        DP(n, m);
        // printf("%lld %lld\n",g[n].x,g[n].y);
        if(g[n].y <= k)
            r = m;
        else
            l = m;
    }

    DP(n, r);
    printf("%lld\n", g[n].x - (long long)k * r);

    return 0;
}