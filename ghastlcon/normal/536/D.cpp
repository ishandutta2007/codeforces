#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <utility>
#define N 2020
using namespace std;

int a[N];
long long d[2][N];
vector<pair<int, int> > e[N];
long long f[2], g[N << 1][N << 1], h[N << 1][N << 1][2];
int c[N << 1][N << 1], k[N << 1][2];

void Dijkstra(int s, int n, long long *d)
{
    static bool u[N];
    int i, p;

    fill(u, u + N, false);
    fill(d, d + N, LLONG_MAX >> 2);
    d[s] = 0;

    while(true)
    {
        for(i = 1, p = -1; i <= n; i ++)
            if(!u[i] && (p == -1 || d[p] > d[i]))
                p = i;
        if(p == -1)
            break;

        u[p] = true;
        for(i = 0; i < (signed)e[p].size(); i ++)
            d[e[p][i].first] = min(d[e[p][i].first], d[p] + e[p][i].second);
    }

    return;
}

int main(void)
{
    int n, m, s, t, u, v, w;
    int i, j;
    vector<long long> b;

    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    while(m --)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }

    Dijkstra(s, n, d[0]);
    Dijkstra(t, n, d[1]);
    for(i = 1; i <= n; i ++)
    {
        b.push_back(d[0][i]);
        b.push_back(d[1][i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    m = (int)b.size();
    for(i = 1; i <= n; i ++)
    {
        d[0][i] = (int)(lower_bound(b.begin(), b.end(), d[0][i]) - b.begin());
        d[1][i] = (int)(lower_bound(b.begin(), b.end(), d[1][i]) - b.begin());
        c[d[0][i]][d[1][i]] ++;
        g[d[0][i]][d[1][i]] += a[i];
    }

    for(i = m; i >= 0; i --)
        for(j = m; j >= 0; j --)
        {
            c[i][j] += c[i + 1][j] + c[i][j + 1] - c[i + 1][j + 1];
            g[i][j] += g[i + 1][j] + g[i][j + 1] - g[i + 1][j + 1];
        }
    for(i = 0; i < (N << 1); i ++)
    {
        k[i][0] = k[i][1] = 1;
        for(j = 0; j < (N << 1); j ++)
            h[i][j][0] = h[i][j][1] = LLONG_MAX >> 2;
    }

    for(i = m; i >= 0; i --)
        for(j = m; j >= 0; j --)
            if(c[i][j])
            {
                for(; k[i][0] < c[i][j]; k[i][0] ++)
                    h[i][k[i][0]][0] = min(h[i][k[i][0]][0], h[i][k[i][0] - 1][0]);
                for(; k[j][1] < c[i][j]; k[j][1] ++)
                    h[k[j][1]][j][1] = min(h[k[j][1]][j][1], h[k[j][1] - 1][j][1]);
                f[0] = g[i][j] - h[c[i][j] - 1][j][1];
                f[1] = g[i][j] - h[i][c[i][j] - 1][0];

                h[i][c[i][j]][0] = min(h[i][c[i][j]][0], f[0]);
                h[c[i][j]][j][1] = min(h[c[i][j]][j][1], f[1]);
            }
            else
                h[i][0][0] = h[0][j][1] = 0;
    // cout<<f[0][0][0]<<' '<<g[0][0]<<endl;
    printf("%s\n", f[0] * 2 - g[0][0] > 0 ? "Break a heart" : f[0] * 2 == g[0][0] ? "Flowers" : "Cry");

    return 0;
}