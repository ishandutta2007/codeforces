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
    int f;
    int l;
    int s[S];

    Node(void) : f(-1), l(0)
    {
        memset(s, 0, sizeof(s));

        return;
    }
};

char a[N];
Node f[N];
int c, d;
int g[N], t[N], v[N];

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

void InsertSAM(int k)
{
    int b, p, q;

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
    int t;
    int i;
    long long o;

    scanf("%d", &t);
    while(t --)
    {
        for(i = 0; i < N; i ++)
        {
            f[i] = Node();
            g[i] = ::t[i] = 0;
        }
        scanf("%s", a);
        InitSAM();

        for(i = 0; a[i]; i ++)
            InsertSAM(ID(a[i]));
        for(i = 0; i < c; i ++)
            ::t[f[i].l] ++;
        for(i = 1; a[i - 1]; i ++)
            ::t[i] += ::t[i - 1];
        // for(i=0;i<=2;i++)cout<<::t[i]<<' ';cout<<endl;
        for(i = c - 1; i > -1; i --)
            v[-- ::t[f[i].l]] = i;
        for(i = c - 1; i > 0; i --)
            g[f[v[i]].f] += g[v[i]];

        // for(i=0;i<c;i++)cout<<v[i]<<' ';cout<<endl;
        // for(i=0;i<c;i++)cout<<g[i]<<' ';cout<<endl;

        for(i = 1, o = 0; i < c; i ++)
            o += (long long)g[i] * g[i] * (f[i].l - f[f[i].f].l);
        printf("%lld\n", o);
    }

    return 0;
}