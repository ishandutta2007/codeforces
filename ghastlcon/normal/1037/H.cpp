#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 200020
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

        Node(int _v = 0) : v(_v)
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
                x = new Node(1);
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
        x -> v = (x -> s[0] ? x -> s[0] -> v : 0) + (x -> s[1] ? x -> s[1] -> v : 0);

        return;
    }

    int SumSegment(Node *x, int l, int r, int s, int t)
    {
        int m;

        if(l > t || r < s || !x)
            return 0;
        if(l >= s && r <= t)
            return x -> v;

        m = (l + r) >> 1;

        return SumSegment(x -> s[0], l, m, s, t) + SumSegment(x -> s[1], m + 1, r, s, t);
    }

    Node *MergeSegment(Node *x, Node *y, int l, int r)
    {
        int m;
        Node *t;

        if(!x)
            return y;
        if(!y)
            return x;

        m = (l + r) >> 1;
        t = new Node();
        t -> s[0] = MergeSegment(x -> s[0], y -> s[0], l    , m);
        t -> s[1] = MergeSegment(x -> s[1], y -> s[1], m + 1, r);
        t -> v = (t -> s[0] ? t -> s[0] -> v : 0) + (t -> s[1] ? t -> s[1] -> v : 0);

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

int n;
char s[N];
Node f[N];
int d, c;
Segment g[N];
int h[N];

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

void InsertSAM(int k, int i)
{
    int p, q, b;

    p = d;
    f[d = c ++].l = f[p].l + 1;
    g[d].AddSegment(g[d].r, 0, n - 1, i);

    for(; p != -1 && !f[p].s[k]; p = f[p].f)
        f[p].s[k] = d;

    if(p == -1)
        f[d].f = 0;
    else
    {
        q = f[p].s[k];
        if(f[p].l + 1 == f[q].l)
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

void Solve(int l, int r)
{
    int m;
    int i, j, t, p, v, o;

    m = strlen(s);
    o = -1;

    // printf("org[%d, %d], s : %s, length %d\n", l, r, s, m);
    for(i = p = 0; i <= m; i ++)
        if(i == m)
            for(j = 0; j < S; j ++)
            {
                // printf("try to ")
                t = f[p].s[j];
                if(t && g[t].SumSegment(g[t].r, 0, n - 1, l + i, r))
                {
                    // printf("fetch, t = %d, p = %d\n", t, p);
                    v = i;
                    o = j;
                    break;
                }
            }
        else
        {
            for(j = s[i] - 97 + 1; j < S; j ++)
            {
                t = f[p].s[j];
                if(t && g[t].SumSegment(g[t].r, 0, n - 1, l + i, r))
                {
                    v = i;
                    o = j;
                    break;
                }
            }

            t = f[p].s[s[i] - 97];
            if(!t || !g[t].SumSegment(g[t].r, 0, n - 1, l + i, r))
            {
                // printf("break at %d\n", i);
                break;
            }
            p = t;
        }

    if(o == -1)
        printf("-1\n");
    else
    {
        for(i = 0; i < v; i ++)
            putchar(s[i]);
        putchar(o + 97);
        putchar('\n');
    }

    return;
}

int main(void)
{
    int q, l, r;
    int i;

    scanf("%s %d", s, &q);
    n = strlen(s);
    InitSAM();
    for(i = 0; i < n; i ++)
        InsertSAM(s[i] - 97, i);

    for(i = 0; i < c; i ++)
        h[i] = i;
    sort(h, h + c, Compare);
    for(i = 0; i < c - 1; i ++)
    {
        // printf("merge %d -> %d\n", h[i], f[h[i]].f);
        g[f[h[i]].f].r = g[f[h[i]].f].MergeSegment(g[f[h[i]].f].r, g[h[i]].r, 0, n - 1);
    }
    // cout << c << endl;
    // for(i=0;i<c;i++) cout << g[i].SumSegment(g[i].r, 0, n, 0, n) << ' ';

    while(q --)
    {
        scanf("%d %d %s", &l, &r, s);
        Solve(l - 1, r - 1);
    }

    return 0;
}