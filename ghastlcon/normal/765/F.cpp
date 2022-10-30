#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#define N 100020
#define M 1000000000
using namespace std;

class Node
{
public:
    Node *s[2];
    int v;
    int i;

    Node(int _v = 0, int _i = 0) : v(_v), i(_i)
    {
        s[0] = s[1] = NULL;

        return;
    }
};

extern void InsertSegment(Node *&, int, int, int, int, int);
extern int MaxSegment(Node *, int, int, int, int);

class Solver
{
private:
    Node *f[N], *g[N];

public:
    Solver(void)
    {
        return;
    }

    void InitSolver(int n, int *a)
    {
        int i, j, p;

        for(i = 1; i <= n; i ++)
        {
            f[i] = f[i - 1];
            InsertSegment(f[i], 0, M, a[i], i, i);
        }
        for(i = 1; i <= n; i ++)
        {
            g[i] = g[i - 1];
            for(j = 0, p = i - 1; p >= 1; p --)
            {
                p = MaxSegment(f[p], 0, M, j, a[i]);
                if(p == INT_MIN)
                    break;

                InsertSegment(g[i], 1, n, p, a[p] - a[i], i);
                // printf("%d-%d\n", i, p);

                if(a[i] == a[p])
                    break;
                j = a[i] - (a[i] - a[p] + 1) / 2;
            }
        }

        return;
    }

    int QuerySolver(int n, int l, int r)
    {
        int o;

        o = MaxSegment(g[r], 1, n, l, n);

        return o == INT_MIN ? INT_MAX : -o;
    }
};

int a[N];
Solver f, g;

void InsertSegment(Node *&x, int l, int r, int p, int v, int i)
{
    Node *t;
    int m;

    if(l > p || r < p)
        return;

    t = x;
    if(!x || x -> i != i)
        x = new Node(INT_MIN);
    if(t)
        *x = *t;
    x -> i = i;

    if(l == r)
    {
        x -> v = max(x -> v, v);

        return;
    }

    m = (l + r) >> 1;
    InsertSegment(x -> s[0], l    , m, p, v, i);
    InsertSegment(x -> s[1], m + 1, r, p, v, i);
    x -> v = max(x -> s[0] ? x -> s[0] -> v : INT_MIN, x -> s[1] ? x -> s[1] -> v : INT_MIN);

    return;
}

int MaxSegment(Node *x, int l, int r, int s, int t)
{
    int m;

    if(!x || l > t || r < s)
        return INT_MIN;
    if(l >= s && r <= t)
        return x -> v;

    m = (l + r) >> 1;

    return max(MaxSegment(x -> s[0], l, m, s, t), MaxSegment(x -> s[1], m + 1, r, s, t));
}

int main(void)
{
    int n, m, l, r;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    f.InitSolver(n, a);
    reverse(a + 1, a + n + 1);
    g.InitSolver(n, a);
    
    scanf("%d", &m);
    while(m --)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", min(f.QuerySolver(n, l, r), g.QuerySolver(n, n - r + 1, n - l + 1)));
    }

    return 0;
}