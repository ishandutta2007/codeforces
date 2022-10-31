#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 100020
using namespace std;

class Node
{
public:
    int v[26];

    Node(void)
    {
        memset(v, 0, sizeof(v));

        return;
    }

    Node operator+(Node that)
    {
        int i;
        Node o;

        for(i = 0; i < 26; i ++)
            o.v[i] = this -> v[i] + that.v[i];

        return o;
    }

    int Value(void)
    {
        int i, o;

        for(i = o = 0; i < 26; i ++)
            o += !!v[i];

        return o;
    }
};

char a[N];
Node f[N << 2];

void InitSegment(int x, int l, int r)
{
    int m;

    if(l == r)
    {
        f[x].v[a[l] - 97] = 1;

        return;
    }

    m = (l + r) >> 1;
    InitSegment(x << 1, l, m);
    InitSegment(x << 1 | 1, m + 1, r);
    f[x] = f[x << 1] + f[x << 1 | 1];

    return;
}

void SetSegment(int x, int l, int r, int p, int v)
{
    int m;

    // printf("set %d-%d : %d(%d)\n", l, r, p, v);
    if(l > p || r < p)
        return;
    if(l == r)
    {
        memset(f[x].v, 0, sizeof(f[x].v));
        f[x].v[v] = 1;

        return;
    }

    m = (l + r) >> 1;
    SetSegment(x << 1, l, m, p, v);
    SetSegment(x << 1 | 1, m + 1, r, p, v);
    f[x] = f[x << 1] + f[x << 1 | 1];

    return;
}

Node SumSegment(int x, int l, int r, int s, int t)
{
    int m;

    if(l > t || r < s)
        return Node();
    if(l >= s && r <= t)
        return f[x];

    m = (l + r) >> 1;

    return SumSegment(x << 1, l, m, s, t) + SumSegment(x << 1 | 1, m + 1, r, s, t);
}

int main(void)
{
    int n, q, p, x, y;

    scanf("%s %d", a, &q);
    n = strlen(a);
    InitSegment(1, 0, n - 1);
    while(q --)
    {
        scanf("%d %d", &p, &x);
        if(p == 1)
        {
            scanf("%s", a);
            SetSegment(1, 0, n - 1, x - 1, a[0] - 97);
        }
        else
        {
            scanf("%d", &y);
            printf("%d\n", SumSegment(1, 0, n - 1, x - 1, y - 1).Value());
        }
    }

    return 0;
}