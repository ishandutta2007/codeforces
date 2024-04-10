#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 5020
#define V 10020
#define M 100020
using namespace std;

inline int Lowbit(int);

class Fenwick1
{
private:
    int f[V];

public:
    Fenwick1(void)
    {
        return;
    }

    void ClearFenwick(void)
    {
        memset(f, 0, sizeof(f));

        return;
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
};

class Fenwick2
{
private:
    int f[V][N];

public:
    Fenwick2(void)
    {
        return;
    }

    void ClearFenwick(void)
    {
        memset(f, 0, sizeof(f));

        return;
    }

    void AddFenwick(int x, int y, int v, int n, int m)
    {
        int i;

        for(; x <= n; x += Lowbit(x))
            for(i = y; i <= m; i += Lowbit(i))
                f[x][i] += v;

        return;
    }

    int SumFenwick(int x, int y)
    {
        int i, o;

        for(o = 0; x; x -= Lowbit(x))
            for(i = y; i; i -= Lowbit(i))
                o += f[x][i];

        return o;
    }
};

class Query
{
public:
    int p;
    int d;
    int x;
    int y;
    int l;

    Query(void)
    {
        return;
    }
};

Query a[M];
int o[M];

inline int Lowbit(int x)
{
    return x & -x;
}

void Solve(int n, int m, int p, int q)
{
    static Fenwick1 f;
    static Fenwick2 g, h;
    int i, x, y;

    f.ClearFenwick();
    g.ClearFenwick();
    h.ClearFenwick();
    for(i = 1; i <= m; i ++)
    {
        x = p + a[i].x;
        y = q + a[i].y;
        if(a[i].p == 2)
            o[i] += f.SumFenwick(x + y) + g.SumFenwick(x + y, x) + h.SumFenwick(x + y, y);
        else if(a[i].p == 1 && a[i].d == 1)
        {
            f.AddFenwick(x + y, 1, n + n);
            f.AddFenwick(x + y + a[i].l + 1, -1, n + n);

            g.AddFenwick(x + y, 1, -1, n + n, n);
            g.AddFenwick(x + y + a[i].l + 1, 1, 1, n + n, n);
            g.AddFenwick(x + y, x, 1, n + n, n);
            g.AddFenwick(x + y + a[i].l + 1, x, -1, n + n, n);

            h.AddFenwick(x + y, 1, -1, n + n, n);
            h.AddFenwick(x + y + a[i].l + 1, 1, 1, n + n, n);
            h.AddFenwick(x + y, y, 1, n + n, n);
            h.AddFenwick(x + y + a[i].l + 1, y, -1, n + n, n);
        }
    }

    return;
}

void Transform(int m)
{
    int i;

    for(i = 1; i <= m; i ++)
    {
        swap(a[i].x, a[i].y);
        a[i].y = -a[i].y;
        if(a[i].p == 1)
            a[i].d = a[i].d % 4 + 1;
    }

    return;
}

int main(void)
{
    int n, m;
    int i;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i ++)
    {
        scanf("%d", &a[i].p);
        if(a[i].p == 1)
        {
            scanf("%d %d %d %d", &a[i].d, &a[i].x, &a[i].y, &a[i].l);
            if(a[i].d >= 3)
                a[i].d = 7 - a[i].d;
        }
        else
            scanf("%d %d", &a[i].x, &a[i].y);
    }

    Solve(n, m, 0, 0);
    Transform(m);
    Solve(n, m, 0, n + 1);
    Transform(m);
    Solve(n, m, n + 1, n + 1);
    Transform(m);
    Solve(n, m, n + 1, 0);

    for(i = 1; i <= m; i ++)
        if(a[i].p == 2)
            printf("%d\n", o[i]);

    return 0;
}