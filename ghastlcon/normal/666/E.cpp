#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#define N 1000020
#define M 17
#define S 26
using namespace std;

class Segment
{
private:
    class Node
    {
    public:
        Node *s[2];
        int v;
        int p;

        int Value(int k)
        {
            return s[k] ? s[k] -> v : 0;
        }

        Node(int _v = 0, int _p = -1) : v(_v), p(_p)
        {
            s[0] = s[1] = NULL;

            return;
        }
    };

public:
    Node *r;

    Segment(void)
    {
        return;
    }

    void AddSegment(Node *&x, int l, int r, int p)
    {
        int m;

        if(l == r)
        {
            if(!x)
                x = new Node(1, p);
            else
                x -> v ++;

            return;
        }

        if(!x)
            x = new Node();
        m = (l + r) >> 1;
        if(p <= m)
            AddSegment(x -> s[0], l    , m, p);
        else
            AddSegment(x -> s[1], m + 1, r, p);
        x -> v = max(x -> Value(0), x -> Value(1));
        x -> p = x -> Value(0) >= x -> Value(1) ? x -> s[0] -> p : x -> s[1] -> p;

        return;
    }

    pair<int, int> MaxSegment(Node *x, int l, int r, int s, int t)
    {
        int m;
        pair<int, int> p, q;

        if(l > t || r < s || !x)
            return make_pair(0, -1);
        if(l >= s && r <= t)
            return make_pair(x -> v, x -> p);

        m = (l + r) >> 1;
        p = MaxSegment(x -> s[0], l    , m, s, t);
        q = MaxSegment(x -> s[1], m + 1, r, s, t);
        if(p.first == q.first)
            return make_pair(p.first, min(p.second, q.second));
        else if(p.first > q.first)
            return p;

        return q;
    }

    Node *MergeSegment(Node *x, Node *y, int l, int r)
    {
        int m;
        Node *t;

        if(!x)
            return y;
        if(!y)
            return x;
        if(l == r)
        {
            t = new Node();
            if(x)
                t -> v += x -> v;
            if(y)
                t -> v += y -> v;
            t -> p = l;

            return t;
        }

        m = (l + r) >> 1;
        t = new Node();
        t -> s[0] = MergeSegment(x -> s[0], y -> s[0], l    , m);
        t -> s[1] = MergeSegment(x -> s[1], y -> s[1], m + 1, r);
        t -> v = max(t -> Value(0), t -> Value(1));
        if(t -> v)
            t -> p = t -> Value(0) >= t -> Value(1) ? t -> s[0] -> p : t -> s[1] -> p;

        return t;
    }
};

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

int m;
char a[N], b[N];
Node f[N];
Segment g[N];
int c, d;
int h[N], p[M][N];
int r[N], l[N];

bool Compare(int a, int b)
{
    return f[a].l > f[b].l;
}

void InitSAM(void)
{
    c = 1;
    d = 0;

    return;
}

void InsertSAM(int k, int v)
{
    int p, q, b;

    p = d;
    if(f[p].s[k])
    {
        if(f[f[p].s[k]].l == f[p].l + 1)
            d = f[p].s[k];
        else
        {
            q = f[p].s[k];
            f[d = c ++] = f[q];
            f[d].l = f[p].l + 1;
            f[q].f = d;

            for(; p != -1 && f[p].s[k] == q; p = f[p].f)
                f[p].s[k] = d;
        }
        g[d].AddSegment(g[d].r, 0, m - 1, v);

        return;
    }

    f[d = c ++].l = f[p].l + 1;
    g[d].AddSegment(g[d].r, 0, m - 1, v);
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

void Solve(int l, int r, int x, int y)
{
    int i, p;
    pair<int, int> o;

    if(y - x + 1 > ::l[y])
        printf("%d 0\n", l + 1);
    else
    {
        p = ::r[y];
        for(i = M - 1; i > -1; i --)
            if(f[::p[i][p]].l >= y - x + 1)
                p = ::p[i][p];
        // printf("reach %d\n", p);
        o = g[p].MaxSegment(g[p].r, 0, m - 1, l, r);
        printf("%d %d\n", !o.first ? l + 1 : o.second + 1, o.first);
    }

    return;
}

int main(void)
{
    int n, q, l, r, x, y;
    int i, j;

    scanf("%s %d", a, &m);
    n = strlen(a);
    InitSAM();
    for(i = 0; i < m; i ++)
    {
        scanf("%s", b);
        for(j = d = 0; b[j]; j ++)
            InsertSAM(b[j] - 97, i);
    }
    for(i = 0; i < c; i ++)
        h[i] = i;
    sort(h, h + c, Compare);
    for(i = 0; i < c - 1; i ++)
        g[f[h[i]].f].r = g[f[h[i]].f].MergeSegment(g[f[h[i]].f].r, g[h[i]].r, 0, m - 1);
    for(i = c - 2; i > -1; i --)
        for(j = 1, p[0][h[i]] = f[h[i]].f; j < M; j ++)
            p[j][h[i]] = p[j - 1][p[j - 1][h[i]]];
    // cout<<c<<endl;
    // for(i=0;i<c;i++){pair<int,int>t=g[i].MaxSegment(g[i].r,0,m-1,0,m-1);printf("[%d, %d]\n",t.first,t.second);}

    for(i = x = y = 0; i < n; i ++)
    {
        if(f[x].s[a[i] - 97])
        {
            y = min(y + 1, f[x].l + 1);
            x = f[x].s[a[i] - 97];
            ::r[i] = x;
            ::l[i] = y;
        }
        else
        {
            while(f[x].f != -1 && !f[x].s[a[i] - 97])
                x = f[x].f;
            if(!f[x].s[a[i] - 97])
            {
                y = 0;
                ::r[i] = x;
                ::l[i] = y;
            }
            else
            {
                y = min(y + 1, f[x].l + 1);
                x = f[x].s[a[i] - 97];
                ::r[i] = x;
                ::l[i] = y;
            }
        }
        // printf("prefix %d, vertex %d, length %d\n", i, x, y);
    }

    scanf("%d", &q);
    while(q --)
    {
        scanf("%d %d %d %d", &l, &r, &x, &y);
        Solve(l - 1, r - 1, x - 1, y - 1);
    }

    return 0;
}