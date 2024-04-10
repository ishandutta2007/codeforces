#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
#define M 18
#define S 26
using namespace std;

namespace Segment
{
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

    void InsertSegment(Node *&x, int l, int r, int p)
    {
        int m;

        if(l > p || r < p)
            return;
        if(l == r)
        {
            x = new Node(1);

            return;
        }

        m = (l + r) >> 1;
        if(!x)
            x = new Node();
        InsertSegment(x -> s[0], l    , m, p);
        InsertSegment(x -> s[1], m + 1, r, p);
        x -> v = (x -> s[0] ? x -> s[0] -> v : 0) + (x -> s[1] ? x -> s[1] -> v : 0);

        return;
    }

    int SumSegment(Node *x, int l, int r, int s, int t)
    {
        int m;

        if(!x || l > t || r < s)
            return 0;
        if(l >= s && r <= t)
            return x -> v;

        m = (l + r) >> 1;

        return SumSegment(x -> s[0], l, m, s, t) + SumSegment(x -> s[1], m + 1, r, s, t);
    }

    int GetSegment(Node *x, int l, int r)
    {
        int m;

        if(l == r)
            return l;

        m = (l + r) >> 1;
        if(x -> s[0] && x -> s[0] -> v)
            return GetSegment(x -> s[0], l, m);

        return GetSegment(x -> s[1], m + 1, r);
    }

    void MergeSegment(Node *&x, Node *y)
    {
        Node *t;

        if(!x && !y)
            return;
        if(!x)
        {
            x = new Node();
            *x = *y;

            return;
        }
        if(!y)
            return;

        t = new Node();
        *t = *x;
        MergeSegment(t -> s[0], y -> s[0]);
        MergeSegment(t -> s[1], y -> s[1]);
        x = t;
        x -> v = (x -> s[0] ? x -> s[0] -> v : 0) + (x -> s[1] ? x -> s[1] -> v : 0);

        return;
    }
}

class Node
{
public:
    int s[S];
    int f;
    int l;
    Segment::Node *g;

    Node(void) : f(-1), l(0), g(NULL)
    {
        return;
    }
};

int n;
char a[N];
Node f[N << 1];
int g[M][N << 1], o[N << 1];
int c, d;
int t[N << 1], p[N << 1];

inline int ID(char c)
{
    return c - 97;
}

void InsertSAM(int x, int k)
{
    int b, p, q;

    p = d;
    f[d = c ++].l = f[p].l + 1;
    // printf("will insert %d %d\n", d, x);
    Segment::InsertSegment(f[d].g, 0, n - 1, x);
    // printf("after %d\n", f[d].g->v);
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
            f[b].g = NULL;
            f[b].l = f[p].l + 1;
            f[d].f = f[q].f = b;

            for(; p != -1 && f[p].s[k] == q; p = f[p].f)
                f[p].s[k] = b;
        }
    }

    return;
}

int Goup(int x, int k)
{
    int i;

    while(k)
    {
        i = __builtin_ctz(k);
        x = g[i][x];
        k ^= 1 << i;
    }

    return x;
}

int BSFind(int x)
{
    int l, m, r;
    int p, t;

    // printf("want get %d : %d\n", x,f[x].g->v);
    p = Segment::GetSegment(f[x].g, 0, n - 1);
    for(l = 0, r = n; l + 1 < r; )
    {
        m = (l + r) >> 1;
        t = Goup(x, m);
        // printf("%d up %d : %d\n", x, m, t);
        if(Segment::SumSegment(f[t].g, 0, n - 1, p - f[x].l + f[t].l, p) >= 2)
            r = m;
        else
            l = m;
    }

    return Goup(x, r);
}

int main(void)
{
    int i, j;

    scanf("%d %s", &n, a);
    for(i = 0, c = 1; i < n; i ++)
        InsertSAM(i, ID(a[i]));
    // for(i=1;i<c;i++)cout<<(f[i].g)->v<<' ';cout<<endl;    
    // for(i=0;i<c;i++)cout<<f[i].l<<' ';cout<<endl;
    for(i = 0; i < c; i ++)
        t[f[i].l] ++;
    for(i = 1; i <= n; i ++)
        t[i] += t[i - 1];
    for(i = 0; i < c; i ++)
        p[-- t[f[i].l]] = i;
    // for(i=0;i<c;i++)cout<<p[i]<<' ';cout<<endl;
    f[0].f = 0;
    for(i = 0; i < c; i ++)
        for(j = 1, g[0][p[i]] = f[p[i]].f; j < M; j ++)
            g[j][p[i]] = g[j - 1][g[j - 1][p[i]]];
    for(i = c - 1; i > 0; i --)
        Segment::MergeSegment(f[f[p[i]].f].g, f[p[i]].g);
    // for(i=0;i<c;i++)cout<<f[i].g->v<<' ';cout<<endl;

    for(i = 1; i < c; i ++)
        o[p[i]] = o[BSFind(p[i])] + 1;
    printf("%d\n", *max_element(o, o + c));

    return 0;
}