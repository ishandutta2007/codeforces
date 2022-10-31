#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 400020
#define M 19
#define S 26
using namespace std;

class Node
{
public:
    int s[S];
    int f;
    int l;

    Node(void) : f(-1), l(0)
    {
        return;
    }
};

char a[N];
Node f[N];
int c, p[N];
vector<int> e[N], r[N], h;
int l[N], d[N], b[M][N];
int g[2][N];

inline int ID(char c)
{
    return c - 97;
}

bool Compare(int x, int y)
{
    return l[x] < l[y];
}

void InitSAM(void)
{
    c = 1;

    return;
}

void InsertSAM(int i, int k)
{
    static int d;
    int p, q, b;

    p = d;
    f[d = c ++].l = f[p].l + 1;
    ::p[i] = d;
    for(; p != -1 && !f[p].s[k]; p = f[p].f)
        f[p].s[k] = d;

    if(p == -1)
        f[d].f = 0;
    else
    {
        q = f[p].s[k];
        if(f[q].l == f[p].l + 1)
            f[d].f = q;
        else
        {
            f[b = c ++] = f[q];
            f[b].l = f[p].l + 1;
            f[d].f = f[q].f = b;

            for(; p != -1 && f[p].s[k] == q; p = f[p].f)
                f[p].s[k] = b;
        }
    }

    return;
}

void DFS(int x)
{
    static int k;
    int i;

    l[x] = k ++;
    for(i = 1; i < M; i ++)
        b[i][x] = b[i - 1][b[i - 1][x]];
    for(i = 0; i < (signed)e[x].size(); i ++)
    {
        d[e[x][i]] = d[x] + 1;
        b[0][e[x][i]] = x;
        DFS(e[x][i]);
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
            u = b[i][u];
    if(u == v)
        return u;

    for(i = M - 1; i > -1; i --)
        if(b[i][u] != b[i][v])
        {
            u = b[i][u];
            v = b[i][v];
        }

    return b[0][u];
}

long long Solve(int x)
{
    int i, p, q;
    long long o;

    for(i = o = p = q = 0; i < (signed)r[x].size(); i ++)
    {
        o += Solve(r[x][i]);
        p += g[0][r[x][i]];
        q += g[1][r[x][i]];
    }

    o += (long long)f[x].l * g[0][x] * q;
    o += (long long)f[x].l * g[1][x] * p;
    o += (long long)f[x].l * g[0][x] * g[1][x];
    for(i = 0; i < (signed)r[x].size(); i ++)
    {
        o += (long long)f[x].l * g[0][r[x][i]] * (q - g[1][r[x][i]]);
        // o += (long long)f[x].l * g[1][r[x][i]] * (p - g[0][r[x][i]]);
    }
    g[0][x] += p;
    g[1][x] += q;

    return o;
}

int main(void)
{
    int n, m, t, x, y;
    int i;

    scanf("%d %d %s", &n, &m, a);
    InitSAM();
    for(i = n - 1; i > -1; i --)
        InsertSAM(n - i - 1, ID(a[i]));

    for(i = 1; i < c; i ++)
        e[f[i].f].push_back(i);
    DFS(0);
    // for(i=0;i<c;i++)printf("[%d %d] ",f[i].f,f[i].l);
    // while(1){cin>>x>>y;cout<<f[GetLCA(p[n-x],p[n-y])].l<<endl;}

    while(m --)
    {
        scanf("%d %d", &x, &y);
        h.clear();
        for(i = 0; i < x; i ++)
        {
            scanf("%d", &t);
            h.push_back(p[n - t]);
            g[0][p[n - t]] ++;
        }
        for(i = 0; i < y; i ++)
        {
            scanf("%d", &t);
            h.push_back(p[n - t]);
            g[1][p[n - t]] ++;
        }

        sort(h.begin(), h.end(), Compare);
        for(i = 1; i < x + y; i ++)
            h.push_back(GetLCA(h[i], h[i - 1]));
        sort(h.begin(), h.end(), Compare);
        h.erase(unique(h.begin(), h.end()), h.end());
        for(i = 1; i < (signed)h.size(); i ++)
            r[GetLCA(h[i], h[i - 1])].push_back(h[i]);
        printf("%lld\n", Solve(h[0]));

        for(i = 0; i < (signed)h.size(); i ++)
        {
            r[h[i]].clear();
            g[0][h[i]] = g[1][h[i]] = 0;
        }
    }

    return 0;
}