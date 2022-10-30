#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 200020
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
        memset(s, 0, sizeof(s));

        return;
    }
};

char a[N];
int c, d;
Node f[N];
int g[N], t[N], h[N];

void InitSAM(void)
{
    int i;

    for(i = 0; i < c; i ++)
        f[i] = Node();
    c = 1;
    d = 0;

    return;
}

void InsertSAM(int k)
{
    int p, b, q;

    p = d;
    f[d = c ++].l = f[p].l + 1;
    g[d] = 1;
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

int main(void)
{
    int n;
    int i;
    long long o;

    scanf("%s", a);
    n = (int)strlen(a);
    InitSAM();
    for(i = 0; i < n; i ++)
        InsertSAM(a[i] - 97);

    for(i = 1; i < c; i ++)
        t[f[i].l] ++;
    for(i = 1; i <= n; i ++)
        t[i] += t[i - 1];
    for(i = 1; i < c; i ++)
        h[-- t[f[i].l]] = i;

    for(i = c - 1; i > -1; i --)
        g[f[h[i]].f] += g[h[i]];

    // for(i = 0; i < c; i ++)
    //     cout << g[i] << ' '; cout << endl;

    for(i = 1, o = 0; i < c; i ++)
        o += (long long)g[i] * (g[i] + 1) / 2 * (f[i].l - f[f[i].f].l);
    printf("%I64d\n", o);

    return 0;
}