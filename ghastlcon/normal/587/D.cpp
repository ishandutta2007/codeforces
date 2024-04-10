#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#define N 400020
using namespace std;

int u[N], v[N], c[N], w[N];
vector<int> e[N], g[N];
int d[N], l[N], p[N];

void Tarjan(int x, int &k)
{
    static vector<int> v;
    static bool u[N];
    static int b;
    int i;

    d[x] = l[x] = ++ k;
    v.push_back(x);
    u[x] = true;

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(!d[e[x][i]])
        {
            Tarjan(e[x][i], k);
            l[x] = min(l[x], l[e[x][i]]);
        }
        else if(u[e[x][i]])
            l[x] = min(l[x], d[e[x][i]]);

    if(d[x] == l[x])
    {
        do
        {
            i = v.back();
            v.pop_back();
            u[i] = false;
            p[i] = b;
        }
        while(x != i);
        b ++;
    }

    return;
}

bool Solve(int m, int k, bool s)
{
    int i, c;
    vector<int> o;

    for(i = 1; i <= m; i ++)
        if(w[i] > k)
            e[i].push_back(i + m);

    memset(d, 0, sizeof(d));
    for(i = 1, c = 0; i <= m + m; i ++)
        if(!d[i])
            Tarjan(i, c);
    for(i = 1; i <= m; i ++)
        if(p[i] == p[i + m])
        {
            for(i = 1; i <= m; i ++)
                if(w[i] > k)
                    e[i].pop_back();

            return false;
        }
        else if(p[i] < p[i + m])
            o.push_back(i);

    if(s)
    {
        printf("%d %d\n", k, (int)o.size());
        for(i = 0; i < (signed)o.size(); i ++)
            printf("%d%c", o[i], " \n"[i == (signed)o.size() - 1]);
    }

    for(i = 1; i <= m; i ++)
        if(w[i] > k)
            e[i].pop_back();

    return true;
}

int main(void)
{
    int n, m;
    int i, j, k, l, r;
    map<pair<int, int>, int> f;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i ++)
    {
        scanf("%d %d %d %d", &u[i], &v[i], &c[i], &w[i]);
        if(++ f[make_pair(u[i], c[i])] > 2 || ++ f[make_pair(v[i], c[i])] > 2)
        {
            printf("No\n");
            return 0;
        }
        g[u[i]].push_back(i);
        g[v[i]].push_back(i);
    }

    f.clear();
    for(i = 1; i <= m; i ++)
    {
        if(f.count(make_pair(u[i], c[i])))
        {
            e[i + m].push_back(f[make_pair(u[i], c[i])]);
            e[f[make_pair(u[i], c[i])] + m].push_back(i);
        }
        if(f.count(make_pair(v[i], c[i])))
        {
            e[i + m].push_back(f[make_pair(v[i], c[i])]);
            e[f[make_pair(v[i], c[i])] + m].push_back(i);
        }
        f[make_pair(u[i], c[i])] = f[make_pair(v[i], c[i])] = i;
    }
    for(i = 1, k = m + m; i <= n; i ++)
    {
        for(j = 0; j < (signed)g[i].size(); j ++)
        {
            e[++ k].push_back(g[i][j] + m);
            if(j)
            {
                e[g[i][j]].push_back(k - 1);
                e[k].push_back(k - 1);
            }
        }
        for(j = (signed)g[i].size() - 1; j > -1; j --)
        {
            e[++ k].push_back(g[i][j] + m);
            if(j != (signed)g[i].size() - 1)
            {
                e[g[i][j]].push_back(k - 1);
                e[k].push_back(k - 1);
            }
        }
    }

    if(!Solve(m, 1000000000, false))
        printf("No\n");
    else
    {
        for(l = -1, r = 1000000000; l + 1 < r; )
            if(Solve(m, (l + r) >> 1, false))
                r = (l + r) >> 1;
            else
                l = (l + r) >> 1;
        printf("Yes\n");
        Solve(m, r, true);
    }

    return 0;
}