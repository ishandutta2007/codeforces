#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 200020
using namespace std;

int a[N];
vector<int> e[N];
int p[N], d[N], l[N], r[N];
int f[N];

inline int Lowbit(int x)
{
    return x & -x;
}

void AddFenwick(int p, int v, int n)
{
    for(; p <= n; p += Lowbit(p))
        f[p] += v;

    return;
}

int SumFenwick(int p)
{
    int o;

    for(o = 0; p; p -= Lowbit(p))
        o += f[p];

    return o;
}

void DFS(int x, int p)
{
    static int k;
    int i;

    l[x] = ++ k;
    ::p[x] = p;
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i] != p)
        {
            d[e[x][i]] = d[x] + 1;
            DFS(e[x][i], x);
        }
    r[x] = k;

    return;
}

int main(void)
{
    int n, m, k, u, v;
    int i, c;

    scanf("%d %d", &n, &m);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    DFS(1, 1);

    // for(i=0;i<n;i++)cout<<p[i]<<' ';cout<<endl;

    while(m --)
    {
        scanf("%d", &k);
        for(i = 0, c = -1; i < k; i ++)
        {
            scanf("%d", &a[i]);
            AddFenwick(l[p[a[i]]], 1, n);
            AddFenwick(r[p[a[i]]], -1, n);
            // printf("dep %d\n",d[p[a[i]]]);
            if(c == -1 || d[c] < d[p[a[i]]])
                c = p[a[i]];
        }
        // printf("got %d\n",c);
        printf("%s\n", SumFenwick(l[c]) == k ? "YES" : "NO");
        for(i = 0; i < k; i ++)
        {
            AddFenwick(l[p[a[i]]], -1, n);
            AddFenwick(r[p[a[i]]], 1, n);
        }
    }

    return 0;
}