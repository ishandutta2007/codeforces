#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <utility>
#include <tuple>
#define N 80
using namespace std;

pair<int, int> a[N];
tuple<int, int, int> b[N];
int f[N][N][N];
tuple<int, int, int> g[N][N][N];

bool Checkmax(int &x, int y)
{
    if(x < y)
    {
        x = y;

        return true;
    }

    return false;
}

int main(void)
{
    int t, n, m;
    int i, j, k, p;
    vector<int> x, y, o;
    tuple<int, int, int> q;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; i ++)
        {
            scanf("%d %d", &a[i].second, &a[i].first);
            b[i] = make_tuple(a[i].first, a[i].second, i);
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        for(i = 0; i < N; i ++)
            for(j = 0; j < N; j ++)
                for(k = 0; k < N; k ++)
                    f[i][j][k] = INT_MIN >> 2;
        f[0][0][0] = 0;
        for(i = 0; i < n; i ++)
            for(j = 0; j < m; j ++)
                for(k = 0; k <= n; k ++)
                {
                    if(Checkmax(f[i + 1][j][a[i + 1].second > a[k].second ? i + 1 : k], f[i][j][k] + a[i + 1].first * (m - 1) + max(a[i + 1].second - a[k].second, 0)))
                        g[i + 1][j][a[i + 1].second > a[k].second ? i + 1 : k] = make_tuple(i, j, k);
                    if(j + 1 < m && Checkmax(f[i + 1][j + 1][k], f[i][j][k] + a[i + 1].second + a[i + 1].first * j))
                        g[i + 1][j + 1][k] = make_tuple(i, j, k);
                }

        p = (int)(max_element(f[n][m - 1] + 1, f[n][m - 1] + n + 1) - f[n][m - 1]);
        x.clear();
        y.clear();
        for(i = n, j = m - 1, k = p; i > 0; )
        {
            q = g[i][j][k];
            if(get<1>(q) == j)
                y.push_back(i);
            else
                x.push_back(i);
            i = get<0>(q);
            j = get<1>(q);
            k = get<2>(q);
        }

        o.clear();
        for(i = (signed)x.size() - 1; i > -1; i --)
            o.push_back(get<2>(b[x[i]]));
        for(i = 0; i < (signed)y.size(); i ++)
            if(y[i] != p)
            {
                o.push_back(get<2>(b[y[i]]));
                o.push_back(-get<2>(b[y[i]]));
            }
        o.push_back(get<2>(b[p]));

        printf("%d\n", (int)o.size());
        for(i = 0; i < (signed)o.size(); i ++)
            printf("%d%c", o[i], " \n"[i == (signed)o.size() - 1]);
    }

    return 0;
}