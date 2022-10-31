#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 3020
using namespace std;

int r, c;
int x[N], y[N];
vector<int> v[N];
int s[N][N], t[N];
int f[2][N], g[N];

inline int Sum(int x, int y, int p, int q)
{
    return s[p][q] - s[p][y - 1] - s[x - 1][q] + s[x - 1][y - 1];
}

int Reduce(int p, int k)
{
    int i, j, o;

    for(i = j = 1, o = 0; i <= c; i ++)
    {
        for(; j <= c && Sum(1, i, p, j) < k; j ++)
            ;
        o += c - j + 1;
    }

    return o;
}

void Remove(int p, int k, int &e)
{
    int l, r;
    int i, j, v, t;

    l = r = N >> 1;
    for(t = p, v = 0; v <= k && t; t = f[0][t])
    {
        // printf("%d\n",t);
        g[l --] = t;
        v += ::t[t];
    }
    for(t = p, v = 0; v <= k && t <= c; t = f[1][t])
    {
        // printf("%d\n",t);
        g[r ++] = t;
        v += ::t[t];
    }

    g[l --] = 0;
    g[r ++] = c + 1;
    // printf("size %d\n",s.size());

    // for(int xx:s)cout<<xx<<' ';cout<<endl;
    for(i = j = l + 2, v = 0; i < r - 1; i ++)
    {
        for(; j < r - 1 && v < k; j ++)
            v += ::t[g[j]];
        // printf("%d-%d : %d (%d)\n",i,j,v, (g[i] - g[i - 1]) * (g[j] - g[j - 1]));
        if(v == k && g[i] <= p && g[j - 1] >= p)
        {
            // printf("minus %d\n", (g[i] - g[i - 1]) * (g[j] - g[j - 1]));
            // if(j == g.size()) throw;
            e -= (g[i] - g[i - 1]) * (g[j] - g[j - 1]);
        }
        v -= ::t[g[i]];
    }
    if(!-- ::t[p])
    {
        f[0][f[1][p]] = f[0][p];
        f[1][f[0][p]] = f[1][p];
    }

    return;
}

int main(void)
{
    int n, k;
    int i, j, p, e;
    long long o;

    scanf("%d %d %d %d", &r, &c, &n, &k);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d %d", &x[i], &y[i]);
        s[x[i]][y[i]] ++;
        v[x[i]].push_back(i);
    }
    for(i = 1; i <= r; i ++)
        for(j = 1; j <= c; j ++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    for(i = 1, o = 0; i <= r; i ++)
    {
        e = Reduce(i, k);
        o += e;
        // printf("row %d, init %d\n", i, e);

        for(j = 1; j <= n; j ++)
            if(x[j] <= i)
                t[y[j]] ++;
        for(j = 1; j <= c; j ++)
            f[0][j] = t[j - 1] ? j - 1 : f[0][j - 1];
        f[1][c + 1] = c + 1;
        for(j = c; j >= 1; j --)
            f[1][j] = t[j + 1] ? j + 1 : f[1][j + 1];

        for(j = 1; j <= i; j ++)
        {
            for(p = 0; p < (signed)v[j].size(); p ++)
                Remove(y[v[j][p]], k, e);
            // if(e < 0)
            //     printf("??? %d\n", e);
            // printf("row %d, remove prev %d : %d\n", i, j, e);
            o += e;
        }
    }
    printf("%lld\n", o);

    return 0;
}