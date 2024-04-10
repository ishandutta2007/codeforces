#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <functional>
#define N 500020
using namespace std;

class Node
{
public:
    Node *s[2];
    Node *p;
    Node *q;
    int v;
    Node *w;
    int x;
    int k;
    int z;
    bool f;
    bool e;

    Node(int _v = 0) : v(_v), x(0), k(0), z(1), f(false), e(false)
    {
        s[0] = s[1] = p = q = NULL;
        w = this;

        return;
    }

    bool Relation(void)
    {
        return this == p -> s[1];
    }

    void Maintain(void)
    {
        w = this;
        k = x;
        z = e;
        if(s[0])
        {
            k += s[0] -> k;
            z += s[0] -> z;
            s[0] -> f ^= f;
            if(w -> v < s[0] -> w -> v)
                w = s[0] -> w;
        }
        if(s[1])
        {
            k += s[1] -> k;
            z += s[1] -> z;
            s[1] -> f ^= f;
            if(w -> v < s[1] -> w -> v)
                w = s[1] -> w;
        }

        if(f)
        {
            swap(s[0], s[1]);
            f = false;
        }

        return;
    }
};

int u[N], v[N], w[N];
Node *a[N], b[N];
int c;

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

void PushdownLCT(Node *x)
{
    if(x -> p)
        PushdownLCT(x -> p);
    x -> Maintain();

    return;
}

void SplayLCT(Node *x)
{
    PushdownLCT(x);
    while(x -> p)
        if(x -> p -> p)
        {
            if(x -> Relation() == x -> p -> Relation())
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
        x -> x += x -> s[1] -> z + x -> s[1] -> k;
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
    x -> p -> x -= x -> z + x -> k;
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
    SplayLCT(x);
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
    EvertLCT(y);
    AccessLCT(x);
    SplayLCT(x);
    if((y -> z + y -> k) & 1 && (x -> z + x -> k) & 1)
        c -= 2;
    y -> q = x;
    x -> x += y -> z + y -> k;

    return;
}

void CutLCT(Node *x, Node *y)
{
    EvertLCT(x);
    AccessLCT(y);
    SplayLCT(x);
    x -> s[1] = y -> p = NULL;

    c -= (x -> z + x -> k) & 1;
    c += (y -> z + y -> k) & 1;
    x -> Maintain();
    c += (x -> z + x -> k) & 1;

    return;
}

Node *MaxLCT(Node *x, Node *y)
{
    EvertLCT(x);
    AccessLCT(y);
    SplayLCT(x);

    // printf("%p %p during max size %d\n", x, y, x -> z);

    return x -> w;
}

inline int Scan(void)
{
    int s;

    scanf("%d", &s);

    return s;
}

int main(void)
{
    int n, m;
    int i, j;
    Node *t;
    set<pair<int, int>, greater<pair<int, int> > > q;

    n = Scan();
    m = Scan();
    for(i = 0; i < n; i ++)
    {
        a[i] = &b[i];
        b[i].e = true;
    }

    for(i = 0, c = n; i < m; i ++)
    {
        u[i] = Scan() - 1;
        v[i] = Scan() - 1;
        a[i + n] = &b[i + n];
        a[i + n] -> v = w[i] = Scan();

        if(FindLCT(a[u[i]]) == FindLCT(a[v[i]]))
        {
            t = MaxLCT(a[u[i]], a[v[i]]);
            j = (int)(t -> w - b - n);
            // printf("try link %d-%d, found %d-%d(%d, max %d)\n", u[i], v[i], u[j], v[j], j, t -> v);
            if(w[i] < w[j])
            {
                q.erase (make_pair(w[j], j));
                q.insert(make_pair(w[i], i));
                CutLCT (a[u[j]], a[j + n]);
                CutLCT (a[v[j]], a[j + n]);
                LinkLCT(a[u[i]], a[i + n]);
                LinkLCT(a[v[i]], a[i + n]);
            }
        }
        else
        {
            // printf("linked %d-%d\n", u[i], v[i]);
            q.insert(make_pair(w[i], i));
            LinkLCT(a[u[i]], a[i + n]);
            LinkLCT(a[v[i]], a[i + n]);
        }

        if(c)
            printf("-1\n");
        else
        {
            for(j = -1; !q.empty(); q.erase(*q.begin()))
            {
                j = q.begin() -> second;
                CutLCT(a[u[j]], a[j + n]);
                CutLCT(a[v[j]], a[j + n]);
                if(c)
                {
                    LinkLCT(a[u[j]], a[j + n]);
                    LinkLCT(a[v[j]], a[j + n]);
                    break;
                }
            }
            printf("%d\n", w[j]);
        }
    }

    return 0;
}