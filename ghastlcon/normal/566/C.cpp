#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <utility>
#define N 200020
using namespace std;

extern vector<pair<int, int> > e[N];
extern bool u[N];

namespace G
{
    int f[N], g[N];
    vector<int> v;

    void DFS(int x, int p)
    {
        int i;

        f[x] = 1;
        g[x] = 0;
        v.push_back(x);
        for(i = 0; i < (signed)e[x].size(); i ++)
            if(e[x][i].first != p && !u[e[x][i].first])
            {
                DFS(e[x][i].first, x);
                f[x] += f[e[x][i].first];
                g[x] = max(g[x], f[e[x][i].first]);
            }

        return;
    }

    int G(int x)
    {
        int i, o;

        v.clear();
        DFS(x, x);
        for(i = 1, o = v[0]; i < (signed)v.size(); i ++)
            if(max(g[o], f[x] - f[o]) > max(g[v[i]], f[x] - f[v[i]]))
                o = v[i];

        return o;
    }
}

int a[N];
vector<pair<int, int> > e[N];
bool u[N];
double v[N];

void Son(int x, int p, int w, double &s, double &t)
{
    int i;

    s += a[x] * pow(w, 1.5);
    t += a[x] * 1.5 * sqrt(w);
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i].first != p)
            Son(e[x][i].first, x, w + e[x][i].second, s, t);

    return;
}

pair<double, int> DFS(int x)
{
    int i;
    double s;
    pair<double, int> o;

    x = G::G(x);
    u[x] = true;

    for(i = o.first = s = 0; i < (signed)e[x].size(); i ++)
    {
        v[e[x][i].first] = 0;
        Son(e[x][i].first, x, e[x][i].second, o.first, v[e[x][i].first]);
        s += v[e[x][i].first];
    }
    o.second = x;

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(!u[e[x][i].first] && s - v[e[x][i].first] * 2 < 0)
        {
            o = min(o, DFS(e[x][i].first));
            break;
        }

    return o;
}

int main(void)
{
    int n, u, v, w;
    int i;
    pair<double, int> o;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }

    o = DFS(1);
    printf("%d %.10f\n", o.second, o.first);

    return 0;
}