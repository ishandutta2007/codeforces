#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#define N 100020
#define M 27
#define K 47
#define L 17
using namespace std;

extern int n;

class Data
{
public:
    int t;
    int v;
    int c;
};

class Fenwick
{
private:
    int f[N];

    inline int Lowbit(int x)
    {
        return x & -x;
    }

public:
    void Add(int p, int v)
    {
        for(; p <= n; p += Lowbit(p))
            f[p] += v;

        return;
    }

    int Sum(int p)
    {
        int o;

        for(o = 0; p; p -= Lowbit(p))
            o += f[p];

        return o;
    }
};

class Node
{
public:
    int s[M];
    int l;
    int r;
    unsigned long long v;
};

int n;
Data a[N];
Node l[N];
Fenwick x, y;
int c, p[N], d[N], g[L][N];
map<unsigned long long, int> f;
unsigned long long w[N], h[N];

inline int ID(char c)
{
    return c - 96;
}

void Init(int x, int d)
{
    int i;
    static int k;

    l[x].l = ++ k;
    f[l[x].v] = x;
    for(i = 1; i < M; i ++)
        if(l[x].s[i])
        {
            l[l[x].s[i]].v = l[x].v + i * w[d];
            Init(l[x].s[i], d + 1);
        }
    l[x].r = k;

    return;
}

int main(void) //2642.cpp
{
    int i, j, v, k;
    long long o;

    for(i = w[0] = 1; i < N; i ++)
        w[i] = w[i - 1] * K;

    scanf("%d", &n);
    c = 1;
    p[1] = 1;
    for(i = 0, k = 1; i < n; i ++)
    {
        scanf("%d %d", &a[i].t, &a[i].v);
        while((a[i].c = getchar()) < 'a' || a[i].c > 'z')
            ;
        a[i].c = ID(a[i].c);

        if(a[i].t == 1)
        {
            a[i].v = p[a[i].v];
            k ++;
            if(l[a[i].v].s[a[i].c])
                p[k] = l[a[i].v].s[a[i].c];
            else
            {
                p[k] = ++ c;
                l[a[i].v].s[a[i].c] = c;
            }
        }
    }

    Init(1, 0);
    c = 1;
    for(i = 0; i < L; i ++)
        g[i][1] = 1;
    y.Add(1, 1);

    for(i = 0, o = 1; i < n; i ++)
    {
        if(a[i].t == 1)
        {
            v = l[a[i].v].s[a[i].c];
            o += x.Sum(l[v].r) - x.Sum(l[v].l - 1);
            y.Add(l[v].l, 1);
            y.Add(l[v].r + 1, -1);
        }
        else
        {
            d[++ c] = d[a[i].v] + 1;
            h[c] = h[a[i].v] * K + a[i].c;
            for(j = 1, g[0][c] = a[i].v; j < L; j ++)
                g[j][c] = g[j - 1][g[j - 1][c]];

            v = c;
            for(j = L - 1; j > -1; j --)
                if(f.count(g[j][v] == 1 ? h[c] : h[c] - h[g[j][v]] * w[d[c] - d[g[j][v]]]))
                    v = g[j][v];

            v = f[v == 1 ? h[c] : h[c] - h[v] * w[d[c] - d[v]]];
            o += y.Sum(l[v].l);
            x.Add(l[v].l, 1);
        }
        printf("%I64d\n", o);
    }

    return 0;
}