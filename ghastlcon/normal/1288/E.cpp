#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 300020
using namespace std;

class Node
{
public:
    Node *s[2];
    int v;

    Node(int _v = 0) : v(_v)
    {
        s[0] = s[1] = NULL;

        return;
    }
};

int a[N], c[N];
vector<int> b[N];
int f[N];
Node *g[N];
int x[N], y[N];

inline int Lowbit(int x)
{
    return x & -x;
}

void AddFenwick(int p, int n)
{
    for(; p <= n; p += Lowbit(p))
        f[p] ++;

    return;
}

int SumFenwick(int p)
{
    int o;

    for(o = 0; p; p -= Lowbit(p))
        o += f[p];

    return o;
}

void AddChairman(Node *&x, int l, int r, int p)
{
    Node *t;
    int m;

    t = x;
    x = new Node();
    if(t)
        *x = *t;

    if(l == r)
    {
        x -> v ++;

        return;
    }

    m = (l + r) >> 1;
    if(p <= m)
        AddChairman(x -> s[0], l, m, p);
    else
        AddChairman(x -> s[1], m + 1, r, p);
    x -> v = (x -> s[0] ? x -> s[0] -> v : 0) + (x -> s[1] ? x -> s[1] -> v : 0);

    return;
}

int SumChairman(Node *x, int l, int r, int s, int t)
{
    int m;

    if(!x || l > t || r < s)
        return 0;
    if(l >= s && r <= t)
        return x -> v;

    m = (l + r) >> 1;

    return SumChairman(x -> s[0], l, m, s, t) + SumChairman(x -> s[1], m + 1, r, s, t);
}

int main(void)
{
    int n, m;
    int i, j;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
        x[i] = y[i] = i;
    for(i = 1; i <= m; i ++)
    {
        scanf("%d", &a[i]);
        x[a[i]] = 1;
        if(b[a[i]].empty())
        {
            y[a[i]] += SumFenwick(n) - SumFenwick(a[i]);
            AddFenwick(a[i], n);
        }
        b[a[i]].push_back(i);

        g[i] = g[i - 1];
        // printf("%d ", c[a[i]]);
        AddChairman(g[i], 0, m - 1, c[a[i]]);
        c[a[i]] = i;
    }
    // puts("");

    for(i = 1; i <= n; i ++)
    {
        if(b[i].empty())
            y[i] += SumFenwick(n) - SumFenwick(i);
        b[i].push_back(m + 1);
    }
    for(i = 1; i <= n; i ++)
        for(j = 0; j < (signed)b[i].size() - 1; j ++)
        {
            // printf("color %d : %d-%d : %d,%d\n", i, b[i][j], b[i][j + 1], SumChairman(g[b[i][j + 1] - 1], 0, m - 1, 0, b[i][j] - 1), SumChairman(g[b[i][j]], 0, m - 1, 0, b[i][j] - 1));
            y[i] = max(y[i], 1 + SumChairman(g[b[i][j + 1] - 1], 0, m - 1, 0, b[i][j] - 1) - SumChairman(g[b[i][j]], 0, m - 1, 0, b[i][j] - 1));
        }

    for(i = 1; i <= n; i ++)
        printf("%d %d\n", x[i], y[i]);

    return 0;
}