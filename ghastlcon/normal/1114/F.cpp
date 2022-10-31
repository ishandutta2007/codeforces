#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 400020
#define D 62
#define MOD 1000000007
using namespace std;

const int d[D] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

extern int Power(int, int);

class SegmentA
{
private:
    int f[N << 2];
    int g[N << 2];

public:
    SegmentA(void)
    {
        return;
    }

    void InitSegment(int x, int l, int r, int *a)
    {
        int m;

        g[x] = 1;
        if(l == r)
        {
            f[x] = a[l];

            return;
        }

        m = (l + r) >> 1;
        InitSegment(x << 1    , l    , m, a);
        InitSegment(x << 1 | 1, m + 1, r, a);
        f[x] = (long long)f[x << 1] * f[x << 1 | 1] % MOD;

        return;
    }

    void MaintainSegment(int x, int l, int r)
    {
        int m;

        m = (l + r) >> 1;
        f[x << 1    ] = (long long)f[x << 1    ] * Power(g[x], m - l + 1) % MOD;
        g[x << 1    ] = (long long)g[x << 1    ] * g[x] % MOD;
        f[x << 1 | 1] = (long long)f[x << 1 | 1] * Power(g[x], r - m    ) % MOD;
        g[x << 1 | 1] = (long long)g[x << 1 | 1] * g[x] % MOD;
        g[x] = 1;

        return;
    }

    void AddSegment(int x, int l, int r, int s, int t, int v)
    {
        int m;

        if(l > t || r < s)
            return;
        if(l >= s && r <= t)
        {
            f[x] = (long long)f[x] * Power(v, r - l + 1) % MOD;
            g[x] = (long long)g[x] * v % MOD;

            return;
        }
        if(g[x] != 1)
            MaintainSegment(x, l, r);

        m = (l + r) >> 1;
        AddSegment(x << 1    , l    , m, s, t, v);
        AddSegment(x << 1 | 1, m + 1, r, s, t, v);
        f[x] = (long long)f[x << 1] * f[x << 1 | 1] % MOD;

        return;
    }

    int SumSegment(int x, int l, int r, int s, int t)
    {
        int m;

        if(l > t || r < s)
            return 1;
        if(l >= s && r <= t)
            return f[x];
        if(g[x] != 1)
            MaintainSegment(x, l, r);

        m = (l + r) >> 1;

        return (long long)SumSegment(x << 1, l, m, s, t) * SumSegment(x << 1 | 1, m + 1, r, s, t) % MOD;
    }
};

class SegmentB
{
private:
    long long f[N << 2];
    long long g[N << 2];

public:
    SegmentB(void)
    {
        return;
    }

    void InitSegment(int x, int l, int r, long long *a)
    {
        int m;

        if(l == r)
        {
            f[x] = a[l];

            return;
        }

        m = (l + r) >> 1;
        InitSegment(x << 1    , l    , m, a);
        InitSegment(x << 1 | 1, m + 1, r, a);
        f[x] = f[x << 1] | f[x << 1 | 1];

        return;
    }

    void MaintainSegment(int x)
    {
        f[x << 1    ] = f[x << 1    ] | g[x];
        g[x << 1    ] = g[x << 1    ] | g[x];
        f[x << 1 | 1] = f[x << 1 | 1] | g[x];
        g[x << 1 | 1] = g[x << 1 | 1] | g[x];
        g[x] = 0;

        return;
    }

    void AddSegment(int x, int l, int r, int s, int t, long long v)
    {
        int m;

        if(l > t || r < s)
            return;
        if(l >= s && r <= t)
        {
            f[x] |= v;
            g[x] |= v;

            return;
        }
        if(g[x])
            MaintainSegment(x);

        m = (l + r) >> 1;
        AddSegment(x << 1    , l    , m, s, t, v);
        AddSegment(x << 1 | 1, m + 1, r, s, t, v);
        f[x] = f[x << 1] | f[x << 1 | 1];

        return;
    }

    long long SumSegment(int x, int l, int r, int s, int t)
    {
        int m;

        if(l > t || r < s)
            return 0;
        if(l >= s && r <= t)
            return f[x];
        if(g[x])
            MaintainSegment(x);

        m = (l + r) >> 1;

        return SumSegment(x << 1, l, m, s, t) | SumSegment(x << 1 | 1, m + 1, r, s, t);
    }
};

int a[N];
long long b[N];
SegmentA f;
SegmentB g;

int Power(int x, int y)
{
    int o;

    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % MOD;
        x = (long long)x * x % MOD;
    }

    return o;
}

int main(void)
{
    int n, q, l, r, x;
    int i, j, o;
    long long k;
    char s[10];

    scanf("%d %d", &n, &q);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        for(j = 0; j < D; j ++)
            if(!(a[i] % d[j]))
                b[i] |= 1LL << j;
    }
    f.InitSegment(1, 0, n - 1, a);
    g.InitSegment(1, 0, n - 1, b);
    // cout<<f.SumSegment(1,0,n-1,0,n-1)<<endl;

    while(q --)
    {
        scanf("%s %d %d", s, &l, &r);
        l --;
        r --;
        if(s[0] == 'M')
        {
            scanf("%d", &x);
            f.AddSegment(1, 0, n - 1, l, r, x);
            for(i = k = 0; i < D; i ++)
                if(!(x % d[i]))
                    k |= 1LL << i;
            g.AddSegment(1, 0, n - 1, l, r, k);
        }
        else
        {
            o = f.SumSegment(1, 0, n - 1, l, r);
            // cout<<o<<endl;
            k = g.SumSegment(1, 0, n - 1, l, r);
            for(i = 0; i < D; i ++)
                if(k & (1LL << i))
                    o = (long long)o * Power(d[i], MOD - 2) % MOD * (d[i] - 1) % MOD;
            printf("%d\n", o);
        }
    }

    return 0;
}