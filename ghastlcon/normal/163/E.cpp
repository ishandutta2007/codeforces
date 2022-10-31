#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 1000020
#define S 26
using namespace std;

class Node
{
public:
    int s[S];
    int f;
    int v;

    Node(void) : f(-1), v(0)
    {
        return;
    }
};

char a[N];
Node f[N];
int p[N], q[N], c;
vector<int> e[N];
int v[N], g[N], l[N], r[N];

inline int ID(char c)
{
    return c - 97;
}

inline int Lowbit(int x)
{
    return x & -x;
}

void AddFenwick(int p, int v)
{
    for(; p <= c; p += Lowbit(p))
        g[p] += v;

    return;
}

int SumFenwick(int p)
{
    int o;

    for(o = 0; p; p -= Lowbit(p))
        o += g[p];

    return o;
}

void InitACAM(void)
{
    c = 1;

    return;
}

void BuildACAM(void)
{
    int l, r;
    int i, s;

    for(i = l = r = 0; i < S; i ++)
        if(f[0].s[i])
        {
            q[r ++] = f[0].s[i];
            f[f[0].s[i]].f = 0;
        }

    for(; l < r; l ++)
    {
        s = q[l];
        for(i = 0; i < S; i ++)
            if(f[s].s[i])
            {
                f[f[s].s[i]].f = f[s].f;
                while(f[f[s].s[i]].f && !f[f[f[s].s[i]].f].s[i])
                    f[f[s].s[i]].f = f[f[f[s].s[i]].f].f;
                f[f[s].s[i]].f = f[f[f[s].s[i]].f].s[i];
                q[r ++] = f[s].s[i];
            }
            else
            {
                // printf("vertex %d(%d) char %d link to %d\n", s, f[s].f, i, f[f[s].f].s[i]);
                f[s].s[i] = f[f[s].f].s[i];
            }
    }

    for(i = 1; i < c; i ++)
        e[f[i].f].push_back(i);

    return;
}

void InsertTrie(int k, char *s)
{
    int i, p;

    for(i = p = 0; s[i]; i ++)
    {
        if(!f[p].s[ID(s[i])])
            f[p].s[ID(s[i])] = c ++;
        p = f[p].s[ID(s[i])];
    }
    f[p].v ++;
    ::p[k] = p;

    return;
}

void DFS(int x)
{
    static int k;
    int i;

    l[x] = ++ k;
    for(i = 0; i < (signed)e[x].size(); i ++)
    {
        v[e[x].at(i)] = v[x] + f[e[x].at(i)].v;
        DFS(e[x].at(i));
    }
    r[x] = k;

    return;
}

int main(void)
{
    int n, m, x;
    int i;
    long long o;

    scanf("%d %d", &m, &n);
    InitACAM();
    for(i = 0; i < n; i ++)
    {
        scanf("%s", a);
        InsertTrie(i, a);
    }
    BuildACAM();

    DFS(0);
    for(i = 0; i < c; i ++)
    {
        AddFenwick(l[i], v[i]);
        AddFenwick(l[i] + 1, -v[i]);
    }

    // for(i=0;i<c;i++)cout<<v[i]<<' ';cout<<endl;
    // for(i=0;i<c;i++)cout<<SumFenwick(l[i])<<' ';cout<<endl;

    for(i = 0; i < n; i ++)
        q[i] = 1;

    // cout<<c<<endl;
    // for(i=0;i<c;i++){cout<<f[i].f<<' '<<f[i].v<<"   ";for(int j=0;j<S;j++)cout<<f[i].s[j]<<' ';cout<<endl;}

    while(m --)
    {
        while((x = getchar()) != '?' && x != '+' && x != '-')
            ;
        if(x == '?')
        {
            scanf("%s", a);
            for(i = x = o = 0; a[i]; i ++)
            {
                x = f[x].s[ID(a[i])];
                // printf("get vertex %d(%d)\n",x,l[x]);
                o += SumFenwick(l[x]);
            }
            printf("%lld\n", o);
        }
        else if(x == '+')
        {
            scanf("%d", &x);
            if(!q[-- x])
            {
                q[x] = 1;
                AddFenwick(l[p[x]], 1);
                AddFenwick(r[p[x]] + 1, -1);
            }
        }
        else
        {
            scanf("%d", &x);
            if(q[-- x])
            {
                q[x] = 0;
                AddFenwick(l[p[x]], -1);
                AddFenwick(r[p[x]] + 1, 1);
                // for(i=0;i<c;i++)cout<<SumFenwick(l[i])<<' ';cout<<endl;
            }
        }
    }

    return 0;
}