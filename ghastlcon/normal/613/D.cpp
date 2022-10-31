#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 100020
#define M 17
using namespace std;

int a[N];
vector<int> e[N];
int f[M][N], d[N], l[N];
vector<int> k, g[N];
bool b[N];
int o[2][N];

bool Compare(int a, int b)
{
    return l[a] < l[b];
}

void DFS(int x, int p)
{
    static int k;
    int i;

    l[x] = k ++;
    for(i = 1, f[0][x] = p; i < M; i ++)
        f[i][x] = f[i - 1][f[i - 1][x]];

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
        {
            d[e[x].at(i)] = d[x] + 1;
            DFS(e[x].at(i), x);
        }

    return;
}

int GetLCA(int u, int v)
{
    int i, t;

    if(d[u] < d[v])
        swap(u, v);
    t = d[u] - d[v];

    for(i = 0; i < M; i ++)
        if(t & (1 << i))
            u = f[i][u];
    if(u == v)
        return u;

    for(i = M - 1; i > -1; i --)
        if(f[i][u] != f[i][v])
        {
            u = f[i][u];
            v = f[i][v];
        }

    return f[0][u];
}

void Depth(int x)
{
    int i;

    if(b[x])
    {
        o[0][x] = 1;
        for(i = o[1][x] = 0; i < (signed)g[x].size(); i ++)
        {
            Depth(g[x].at(i));
            o[1][x] += o[0][g[x].at(i)] + o[1][g[x].at(i)];
        }
    }
    else
    {
        for(i = o[0][x] = o[1][x] = 0; i < (signed)g[x].size(); i ++)
        {
            Depth(g[x].at(i));
            o[0][x] += o[0][g[x].at(i)];
            o[1][x] += o[1][g[x].at(i)];
        }

        if(o[0][x] >= 2)
        {
            o[0][x] = 0;
            o[1][x] ++;
        }
    }

    return;
}

int main(void)
{
    int n, m, q, u, v;
    int i;

    scanf("%d", &n);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[-- u].push_back(-- v);
        e[   v].push_back(   u);
    }
    DFS(0, 0);

    scanf("%d", &q);
    while(q --)
    {
        scanf("%d", &m);
        for(i = 0; i < m; i ++)
        {
            scanf("%d", &a[i]);
            k.push_back(-- a[i]);
            b[a[i]] = true;
        }
        for(i = 0; i < m; i ++)
            if(a[i] && b[a[i]] && b[f[0][a[i]]])
                break;

        if(i == m)
        {
            sort(k.begin(), k.end(), Compare);
            k.push_back(0);
            for(i = 1; i < m; i ++)
                k.push_back(GetLCA(k.at(i - 1), k.at(i)));
            sort(k.begin(), k.end(), Compare);
            k.erase(unique(k.begin(), k.end()), k.end());
            // for(i=0;i<k.size();i++)cout<<k[i]+1<<' ';cout<<endl;

            for(i = 1; i < (signed)k.size(); i ++)
                g[GetLCA(k.at(i - 1), k.at(i))].push_back(k.at(i));
            Depth(0);
            printf("%d\n", o[1][0]);
        }
        else
            printf("-1\n");

        for(i = 0; i < (signed)k.size(); i ++)
            g[k.at(i)].clear();
        k.clear();
        for(i = 0; i < m; i ++)
            b[a[i]] = false;
    }

    return 0;
}