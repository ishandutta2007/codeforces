#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 600020
#define S 26
using namespace std;

class Node
{
public:
    int f;
    int l;
    int s[S];

    Node(void) : f(-1), l(0)
    {
        return;
    }
};

char a[N], b[N];
Node f[N];
int c, d;
int g[N], t[N], v[N];
int o[N];

inline int ID(char c)
{
    return c - 97;
}

void InitSAM(void)
{
    c = 1;
    d = 0;

    return;
}

void InsertSAM(int k, int i)
{
    int b, p, q;

    p = d;
    f[d = c ++].l = f[p].l + 1;
    g[d] = 49 - ::b[i];

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
            f[q].f = f[d].f = b;
            f[b].l = f[p].l + 1;

            for(; p != -1 && f[p].s[k] == q; p = f[p].f)
                f[p].s[k] = b;
        }
    }

    return;
}

int main(void)
{
    int n;
    int i;
    long long o;

    scanf("%d %s %s", &n, a, b);
    InitSAM();
    for(i = 0; i < n; i ++)
        InsertSAM(ID(a[i]), i);
    for(i = 0; i < c; i ++)
        ::t[f[i].l] ++;
    for(i = 1; a[i - 1]; i ++)
        ::t[i] += ::t[i - 1];
    for(i = c - 1; i > -1; i --)
        v[-- ::t[f[i].l]] = i;
    for(i = c - 1; i > 0; i --)
        g[f[v[i]].f] += g[v[i]];

    for(i = o = 0; i < c; i ++)
        o = max(o, (long long)g[i] * f[i].l);
    printf("%lld\n", o);

    return 0;
}