#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bitset>
#include <tuple>
#define N 150
using namespace std;

class Matrix
{
public:
    bitset<N> a[N];

    Matrix(void)
    {
        return;
    }

    Matrix operator*(Matrix that)
    {
        static bitset<N> t[N];
        int i, j;
        Matrix o;

        for(i = 0; i < N; i ++)
            for(j = 0; j < N; j ++)
                t[i][j] = that.a[j][i];
        for(i = 0; i < N; i ++)
            for(j = 0; j < N; j ++)
                o.a[i][j] = (a[i] & t[j]).any();

        return o;
    }

    Matrix operator^(int y)
    {
        int i;
        Matrix o, x;
    
        for(i = 0; i < N; i ++)
            o.a[i][i] = true;
        for(x = *this; y; y >>= 1)
        {
            if(y & 1)
                o = o * x;
            x = x * x;
        }

        return o;
    }
};

tuple<int, int, int> e[N];
Matrix f, g, h;

int BSFind(int n, int w)
{
    int l, m, r;

    for(l = -1, r = w; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if((f * (g ^ m)).a[0][n - 1])
            r = m;
        else
            l = m;
    }

    return r;
}

int main(void)
{
    int n, m, u, v, w;
    int i;

    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[i] = make_tuple(w, -- u, -- v);
    }

    sort(e, e + m);
    for(i = 0; i < N; i ++)
        f.a[i][i] = true;
    g.a[n - 1][n - 1] = true;

    for(i = 0; i < m; i ++)
    {
        tie(w, u, v) = e[i];
        w -= (i ? get<0>(e[i - 1]) : 0);
        h = f * (g ^ w);
        if(h.a[0][n - 1])
        {
            printf("%d\n", BSFind(n, w) + (i ? get<0>(e[i - 1]) : 0));

            return 0;
        }
        f = h;
        g.a[u][v] = true;
    }

    h = f * (g ^ n);
    if(h.a[0][n - 1])
        printf("%d\n", BSFind(n, n) + get<0>(e[m - 1]));
    else
        printf("Impossible\n");

    return 0;
}