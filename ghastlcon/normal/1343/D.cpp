#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define N 400020
#define B 8000000
using namespace std;

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

class Mempool
{
private:
    Node b[B];
    int c;

public:
    Mempool(void) : c(0)
    {
        return;
    }

    Node *New(void)
    {
        b[c] = Node();

        return &b[c ++];
    }

    void Clear(void)
    {
        c = 0;

        return;
    }
};

int n, a[N];
pair<int, int> c[N];
Node *f[N];
Mempool b;
int s[N];

void AddSegment(Node *&x, int l, int r, int p)
{
    Node *t;
    int m;

    if(l > p || r < p)
        return;
    t = x;
    x = b.New();
    if(t)
        *x = *t;
    if(l == r)
    {
        x -> v ++;

        return;
    }

    m = (l + r) >> 1;
    AddSegment(x -> s[0], l    , m, p);
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

inline int Sum(int n, int x, int y, int p, int q)
{
    int i, o;

    // o = 0;
    // for(i = 1; i <= ::n / 2; i ++)
    //     if(c[i].first >= x && c[i].first <= y && c[i].second >= p && c[i].second <= q)
    //         o ++;

    // return o;

    x = max(x, 1);
    p = max(p, 1);
    y = min(y, n);
    q = min(q, n);

    // printf("x %d-%d, y %d-%d : %d\n", x, y, p, q, x > y || p > q ? 0 : SumSegment(f[y], 1, n, p, q) - SumSegment(f[x - 1], 1, n, p, q));

    if(x > y || p > q)
        return 0;

    return SumSegment(f[y], 1, n, p, q) - SumSegment(f[x - 1], 1, n, p, q);
}

int main(void)
{
    int t, k;
    int i, j, v, o;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &k);
        for(i = 1; i <= k * 2; i ++)
            s[i] = 0;
        for(i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        for(i = 1; i <= n / 2; i ++)
        {
            s[a[i] + a[n - i + 1]] ++;
            c[i] = make_pair(a[i], a[n - i + 1]);
        }
        sort(c + 1, c + n / 2 + 1);

        // printf("wtf? %d\n", n / 2);
        // for(j=1;j<=n/2;j++)printf("[%d,%d] ",c[j].first,c[j].second);puts("");
        b.Clear();
        for(i = j = 1; i <= k; i ++)
        {
            f[i] = f[i - 1];
            for(; j <= n / 2 && c[j].first == i; j ++)
            {
                // printf("at %d insert %d\n", i, c[j].second);
                AddSegment(f[i], 1, k, c[j].second);
            }
        }

        for(i = 2, o = n; i <= k * 2; i ++)
        {
            // v = Sum(k, i - k, i - 1, 1, k)
            //   + Sum(k, 1, k, i - k, i - 1)
            //   + Sum(k, i + 1, i + k, 1, k)
            //   + Sum(k, 1, k, i + 1, i + k)
            //   - Sum(k, i - k, i - 1, i - k, i - 1)
            //   - Sum(k, i - k, i - 1, i + 1, i + k)
            //   - Sum(k, i + 1, i + k, i - k, i - 1)
            //   - Sum(k, i + 1, i + k, i + 1, i + k)
            //   ;
            v = Sum(k, i - k, i - 1, 1, k)
              + Sum(k, 1, k, i - k, i - 1)
              - Sum(k, i - k, i - 1, i - k, i - 1)
              ;
            // printf("at %d select %d (%d-%d) (%d-%d), has %d, ans %d\n", i, v, i - k, i - 1, i + 1, i + k, s[i], v - s[i] + (n / 2 - v) * 2);
            o = min(o, v - s[i] + (n / 2 - v) * 2);
        }
        printf("%d\n", o);
    }

    return 0;
}