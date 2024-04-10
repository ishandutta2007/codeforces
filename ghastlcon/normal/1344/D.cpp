#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <utility>
#define N 100020
using namespace std;

int a[N];
int o[N];
pair<long long, int> b[N];

long long Eval(long long a, long long x)
{
    return a - 3 * x * x + 3 * x - 1;
}

__int128 Quad(__int128 a, __int128 b, __int128 c)
{
    __int128 d;

    d = b * b - 4 * a * c;

    return max((__int128)round((-b + sqrt((long double)d)) / a / 2), (__int128)round((-b - sqrt((long double)d)) / a / 2));
}

long long BSFind(long long a, long long x)
{
    long long l, m, r;

    for(l = 0, r = a + 1; l + 1 < r; )
    {
        m = (l + r) / 2;
        if(Eval(a, m) >= x)
            l = m;
        else
            r = m;
    }

    return l;
}

long long Solve(int n, long long m)
{
    int i;
    long long s, t;

    for(i = s = 0; i < n; i ++)
    {
        t = Quad(-3, 3, a[i] - m - 1);
        o[i] = t - (Eval(a[i], t) < m);
        // o[i] = BSFind(a[i], m);
        o[i] = min(o[i], a[i]);
        s += o[i];
    }

    return s;
}

int main(void)
{
    int n;
    long long k;
    int i;
    long long l, m, r;

    scanf("%d %I64d", &n, &k);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    for(l = -4000000000000000000LL, r = 2000000000LL; l + 1 < r; )
    {
        m = (l + r) / 2;
        if(Solve(n, m) >= k)
            l = m;
        else
            r = m;
    }

    Solve(n, l);
    for(i = 0; i < n; i ++)
    {
        k -= o[i];
        b[i] = make_pair(Eval(a[i], o[i] - 1), i);
    }
    sort(b, b + n);
    for(i = 0; i < -k; i ++)
        o[b[i].second] --;
    for(i = 0; i < n; i ++)
        printf("%d%c", o[i], " \n"[i == n - 1]);

    return 0;
}