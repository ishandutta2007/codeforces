#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 100020
using namespace std;

class Node
{
public:
    Node *s[2];
    Node *p;
    int k;
    int x;
    int v;
    int z;

    Node(int _k = 0, int _x = 0) : k(_k), x(_x), v(_x)
    {
        s[0] = s[1] = p = NULL;
        z = 1;

        return;
    }

    bool Relation(void)
    {
        return this == p -> s[1];
    }

    void Maintain(void)
    {
        v = x;
        z = 1;
        if(s[0])
        {
            v = max(v, s[0] -> v);
            z += s[0] -> z;
        }
        if(s[1])
        {
            v = max(v, s[1] -> v);
            z += s[1] -> z;
        }

        return;
    }
};

Node *r, *f[N];

void RotateSplay(Node *&x)
{
    Node *p;
    int k;

    p = x -> p;
    k = x -> Relation();

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

void SplaySplay(Node *&x)
{
    while(x -> p)
        if(x -> p -> p)
        {
            if(x -> Relation() == x -> p -> Relation())
                RotateSplay(x -> p);
            else
                RotateSplay(x);
            RotateSplay(x);
        }
        else
            RotateSplay(x);
    r = x;

    return;
}

void OutputSplay(Node *x, int n)
{
    if(!x)
        return;

    OutputSplay(x -> s[1], n);
    if(x -> k && x -> k <= n)
        printf("%d ", x -> k);
    OutputSplay(x -> s[0], n);

    return;
}

void debug(Node *x)
{
    if(!x)
        return;

    debug(x->s[0]);
    printf("tree node %p[L %p, R %p, P %p], %d th, num %d, max %d, size %d\n",x,x->s[0],x->s[1],x->p,x->k,x->x,x->v,x->z);
    debug(x->s[1]);

    return;
}

void Insert(int x, int a, int c)
{
    Node *t, *p;

    c ++;
    f[x] = new Node(x, a);
    for(p = r; true; )
        if(p -> s[0] && (p -> s[0] -> v > a || p -> s[0] -> z > c))
            p = p -> s[0];
        else if(p -> x > a || (p -> s[0] ? p -> s[0] -> z : 0) == c)
            break;
        else
        {
            c -= (p -> s[0] ? p -> s[0] -> z : 0) + 1;
            p = p -> s[1];
        }
    // printf("%p %d\n", p, p -> k);

    SplaySplay(p);
    if(!p -> s[0])
    {
        p -> s[0] = f[x];
        f[x] -> p = p;
    }
    else
    {
        for(t = p -> s[0]; t -> s[1]; t = t -> s[1])
            ;
        t -> s[1] = f[x];
        f[x] -> p = t;
    }

    for(t = f[x] -> p; t -> p; t = t -> p)
        t -> Maintain();
    t -> Maintain();

    // debug(r);puts("");
    // printf("%d : %p, P %p\b", x, f[x], f[x] -> p);
    SplaySplay(f[x]);
    // debug(r);

    return;
}

int main(void)
{
    int n, a, c;
    int i;

    scanf("%d", &n);
    f[0] = new Node(0);
    f[n + 1] = new Node(n + 1, n + 1);
    f[0] -> s[1] = f[n + 1];
    f[n + 1] -> p = f[0];
    f[0] -> Maintain();
    r = f[0];
    for(i = 1; i <= n; i ++)
    {
        scanf("%d %d", &a, &c);
        Insert(i, a, c);
    }

    OutputSplay(r, n);
    printf("\n");

    return 0;
}