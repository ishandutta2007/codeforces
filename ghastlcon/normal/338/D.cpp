#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 10020
using namespace std;

long long a[N];

long long Power(long long x, long long y, long long p)
{
    long long o;

    x = (x % p + p) % p;
    y = (y % p + p) % p;
    for(o = 0; y; y >>= 1)
    {
        if(y & 1)
            o = (o + x) % p;
        x = (x + x) % p;
    }

    return o;
}

void ExGCD(long long a, long long b, long long &d, long long &x, long long &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        ExGCD(b, a % b, d, y, x);
        y -= x * (a / b);
    }

    return;
}

int main(void)
{
    long long n, m;
    int k;
    int i;
    long long s, v, d, x, y;

    scanf("%lld %lld %d", &n, &m, &k);
    for(i = s = 0; i < k; i ++)
    {
        scanf("%lld", &a[i]);
        if(!i)
        {
            s = a[i];
            v = 0;
        }
        else
        {
            ExGCD(s, a[i], d, x, y);
            if((-i - v) % d)
            {
                printf("NO2\n");

                return 0;
            }

            y *= -(-i - v) / d;
            // printf("(%d) got %lld %lld : %lld\n", i, x, s, x * s);
            // v = (v + Power(x, s, s / d * a[i])) % (s / d * a[i]);
            s *= a[i] / d;
            v = ((Power(a[i], y, s) - i) % s + s) % s;
        }

        if(s > n)
        {
            printf("NO\n");

            return 0;
        }
    }

    v = (v % s + s) % s;
    if(!v)
        v = s;

    for(i = 0; i < k; i ++)
        if(v + i > m || __gcd(v + i, s) != a[i])
        {
            printf("NO\n");

            return 0;
        }
    printf("YES\n");

    return 0;
}