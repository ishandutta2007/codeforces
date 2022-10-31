#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#define N 2000020
#define S 26
#define K 197
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
int c, d;
int s[N], t[N], g[N];
set<unsigned long long> u;

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
    s[d] = 1;

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
    int n, m;
    int i, v, l;
    unsigned long long k, p, o;

    scanf("%s", a);
    InitSAM();
    n = strlen(a);
    for(i = 0; i < n; i ++)
        InsertSAM(ID(a[i]));

    for(i = 0; i < c; i ++)
        t[f[i].l] ++;
    for(i = 1; i <= n; i ++)
        t[i] += t[i - 1];
    for(i = c - 1; i > -1; i --)
        g[-- t[f[i].l]] = i;
    for(i = c - 1; i > 0; i --)
        s[f[g[i]].f] += s[g[i]];
    // for(i=0;i<c;i++)cout<<s[i]<<' ';

    scanf("%d", &m);
    while(m --)
    {
        scanf("%s", a);
        n = strlen(a);
        u.clear();

        for(i = k = v = o = l = 0, p = 1; i < n; i ++)
        {
            if(i)
                p *= K;
            k = k * K + a[i];

            while(v != -1 && !f[v].s[ID(a[i])])
            {
                l --;
                if(l < 0)
                    break;

                if(l == f[f[v].f].l)
                    v = f[v].f;
            }
            if(l == -1)
                v = l = 0;
            else
            {
                l ++;
                v = f[v].s[ID(a[i])];
            }
            // cout<<i<<' '<<v<<endl;
        }
        u.insert(k);
        // cout<<k<<' '<<p<<endl;
        // cout<<v<<' '<<f[v].l<<' '<<l<<endl;
        if(l >= n)
        {
            // puts("ON");
            o += s[v];
        }

        for(i = 0; i < n; i ++)
        {
            k = (k - p * a[i]) * K + a[i];
            // cout<<i<<' '<<k<<endl;
            if(u.count(k))
                break;
            u.insert(k);

            if(l == n)
            {
                l --;
                if(l == f[f[v].f].l)
                    v = f[v].f;
            }
            while(v != -1 && !f[v].s[ID(a[i])])
            {
                l --;
                if(l < 0)
                    break;

                if(l == f[f[v].f].l)
                    v = f[v].f;
            }

            if(l == -1)
                l = v = 0;
            else
            {
                l ++;
                v = f[v].s[ID(a[i])];
                if(l == n)
                {
                    // cout<<i<<' '<<s[v]<<endl;
                    o += s[v];
                }
            }
        }
        printf("%llu\n", o);
    }

    return 0;
}