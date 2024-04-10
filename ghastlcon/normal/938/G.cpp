#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <tuple>
#define N 200020
#define M 30
using namespace std;

class Linear
{
public:
    int f[M];

    Linear(void)
    {
        memset(f, 0, sizeof(f));

        return;
    }

    void InsertLinear(int x)
    {
        int i, j;

        for(i = M - 1; i > -1; i --)
            if(x & (1 << i))
            {
                if(f[i])
                {
                    x ^= f[i];
                    continue;
                }

                for(j = 0; j < i; j ++)
                    if(x & (1 << j))
                        x ^= f[j];
                for(j = i + 1; j < M; j ++)
                    if(f[j] & (1 << i))
                        f[j] ^= x;
                f[i] = x;
                break;
            }

        return;
    }
};

class Node
{
public:
    Node *s[2];
    Node *p;
    Node *q;
    int v;
    int x;
    bool f;

    Node(int _v = 0) : v(_v), x(_v), f(false)
    {
        s[0] = s[1] = p = q = NULL;

        return;
    }

    bool Relation(void)
    {
        return this == p -> s[1];
    }

    void Maintain(void)
    {
        x = v;
        if(s[0])
        {
            x ^= s[0] -> x;
            s[0] -> f ^= f;
        }
        if(s[1])
        {
            x ^= s[1] -> x;
            s[1] -> f ^= f;
        }
        if(f)
        {
            swap(s[0], s[1]);
            f = false;
        }

        return;
    }

    void Pushdown(void)
    {
        if(p)
            p -> Pushdown();
        Maintain();

        return;
    }
};

Node f[N];
vector<tuple<int, int, int> > g[N << 2];
pair<int, int> q[N << 2];
int o[N];

void RotateLCT(Node *x)
{
    Node *p;
    int k;

    p = x -> p;
    k = x -> Relation();

    x -> q = p -> q;
    p -> q = NULL;

    x -> p = p -> p;
    if(x -> p)
        x -> p -> s[p -> Relation()] = x;

    p -> s[k] = x -> s[!k];
    if(p -> s[k])
        p -> s[k] -> p = p;

    x -> s[!k] = p;
    p -> p = x;

    p -> Maintain();
    x -> Maintain();

    return;
}

void SplayLCT(Node *x)
{
    x -> Pushdown();
    while(x -> p)
        if(x -> p -> p)
        {
            if(x -> p -> Relation() == x -> Relation())
                RotateLCT(x -> p);
            else
                RotateLCT(x);
            RotateLCT(x);
        }
        else
            RotateLCT(x);

    return;
}

void ExposeLCT(Node *x)
{
    SplayLCT(x);
    if(x -> s[1])
    {
        x -> s[1] -> q = x;
        x -> s[1] -> p = NULL;
        x -> s[1] = NULL;
    }

    return;
}

bool SpliceLCT(Node *x)
{
    SplayLCT(x);
    if(!x -> q)
        return false;

    ExposeLCT(x -> q);
    x -> q -> s[1] = x;
    x -> p = x -> q;
    x -> q = NULL;

    return true;
}

void AccessLCT(Node *x)
{
    for(ExposeLCT(x); SpliceLCT(x); )
        ;

    return;
}

void EvertLCT(Node *x)
{
    AccessLCT(x);
    x -> f ^= 1;

    return;
}

Node *FindLCT(Node *x)
{
    AccessLCT(x);
    SplayLCT(x);
    for(; x -> s[0]; x = x -> s[0])
        ;
    SplayLCT(x);

    return x;
}

void LinkLCT(Node *x, Node *y)
{
    EvertLCT(x);
    x -> q = y;

    return;
}

void CutLCT(Node *x, Node *y)
{
    EvertLCT(x);
    AccessLCT(y);
    SplayLCT(x);
    if(x -> s[1] != y || x -> s[1] -> s[0])
    {
        // puts("while cutting");
        throw;
    }
    x -> s[1] -> p = NULL;
    x -> s[1] = NULL;

    return;
}

int XorLCT(Node *x, Node *y)
{
    EvertLCT(x);
    AccessLCT(y);
    SplayLCT(x);

    return x -> x;
}

void InsertSegment(int x, int l, int r, int s, int t, tuple<int, int, int> v)
{
    int m;

    if(l > t || r < s)
        return;
    if(l >= s && r <= t)
    {
        if(get<2>(v) == -1)
            q[x] = make_pair(get<0>(v), get<1>(v));
        else
            g[x].push_back(v);

        return;
    }

    m = (l + r) >> 1;
    InsertSegment(x << 1    , l    , m, s, t, v);
    InsertSegment(x << 1 | 1, m + 1, r, s, t, v);

    return;
}

void UndoSegment(vector<pair<Node *, bool> > &t, vector<tuple<int, int, int> > &g)
{
    int i;

    for(i = 0; i < (signed)t.size(); i ++)
        if(t[i].second)
        {
            // printf("cut %d-%d\n", get<0>(g[i]), get<1>(g[i]));
            CutLCT(&f[get<0>(g[i])], t[i].first);
            CutLCT(&f[get<1>(g[i])], t[i].first);
        }

    return;
}

void DFSSegment(int x, int l, int r, Linear h)
{
    int u, v, w;
    int i, m;
    vector<pair<Node *, bool> > t;

    for(i = 0; i < (signed)g[x].size(); i ++)
    {
        tie(u, v, w) = g[x][i];
        t.push_back(make_pair(new Node(w), true));
        if(FindLCT(&f[u]) == FindLCT(&f[v]))
        {
            h.InsertLinear(XorLCT(&f[u], &f[v]) ^ w);
            t.back().second = false;
        }
        else
        {
            LinkLCT(&f[u], t.back().first);
            LinkLCT(&f[v], t.back().first);
            // printf("linked %d-%d\n", u, v);
        }
    }

    if(l == r)
    {
        if(q[x].first)
        {
            tie(u, v) = q[x];
            // printf("ask %d-%d\n", u, v);
            if(FindLCT(&f[u]) != FindLCT(&f[v]))
                throw;
            w = XorLCT(&f[u], &f[v]);

            for(i = M - 1; i > -1; i --)
                if(w & (1 << i))
                    w ^= h.f[i];
            o[l] = w;
        }
        UndoSegment(t, g[x]);

        return;
    }

    m = (l + r) >> 1;
    DFSSegment(x << 1    , l    , m, h);
    DFSSegment(x << 1 | 1, m + 1, r, h);
    UndoSegment(t, g[x]);

    return;
}

int main(void)
{
    int n, m, u, v, w;
    int i;
    map<pair<int, int>, pair<int, int> > f;
    map<pair<int, int>, pair<int, int> >::iterator t;

    scanf("%d %d", &n, &m);
    while(m --)
    {
        scanf("%d %d %d", &u, &v, &w);
        if(u > v)
            swap(u, v);
        f[make_pair(u, v)] = make_pair(w, 0);
    }

    scanf("%d", &m);
    for(i = 1; i <= m; i ++)
    {
        scanf("%d %d %d", &w, &u, &v);
        if(u > v)
            swap(u, v);
        if(w == 1)
        {
            scanf("%d", &w);
            f[make_pair(u, v)] = make_pair(w, i);
        }
        else if(w == 2)
        {
            InsertSegment(1, 0, m, f[make_pair(u, v)].second, i - 1, make_tuple(u, v, f[make_pair(u, v)].first));
            f.erase(make_pair(u, v));
        }
        else
            InsertSegment(1, 0, m, i, i, make_tuple(u, v, -1));
    }
    for(t = f.begin(); t != f.end(); ++ t)
        InsertSegment(1, 0, m, t -> second.second, m, make_tuple(t -> first.first, t -> first.second, t -> second.first));

    memset(o, -1, sizeof(o));
    DFSSegment(1, 0, m, Linear());
    for(i = 1; i <= m; i ++)
        if(o[i] != -1)
            printf("%d\n", o[i]);

    return 0;
}