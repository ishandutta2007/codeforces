#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#define N 500020
using namespace std;

int n;
int a[N], b[N];
long long c[N];

int Check(int x)
{
    int i, p;
    long long s;

    for(i = 0; i < n; i ++)
        b[i] = a[i];
    b[n] = x;
    sort(b, b + n + 1, greater<int>());

    // for(i=0;i<=n;i++)cout<<b[i]<<' ';cout<<endl;

    for(i = n; i >= 0; i --)
        c[i] = c[i + 1] + b[i];
    for(i = s = 0; i <= n; i ++)
    {
        s += b[i];
        p = max((int)(upper_bound(b, b + n + 1, i + 1, greater<int>()) - b), i + 1);
        // printf("first < %d : %d\n", i + 1, p);
        if(s > (long long)i * (i + 1) + (long long)(i + 1) * (p - i - 1) + c[p])
            return x >= b[i] ? 1 : -1;
    }

    return 0;
}

int SolveLA(void)
{
    int l, m, r, t;

    for(l = -1, r = n >> 1; l + 1 < r; )
    {
        m = (l + r) >> 1;
        t = Check(m << 1 | 1);
        if(t >= 0)
            r = m;
        else
            l = m;
    }

    return r << 1 | 1;
}

int SolveRA(void)
{
    int l, m, r, t;

    for(l = 0, r = (n >> 1) + 1; l + 1 < r; )
    {
        m = (l + r) >> 1;
        t = Check(m << 1 | 1);
        if(t <= 0)
            l = m;
        else
            r = m;
    }

    return l << 1 | 1;
}

int SolveLB(void)
{
    int l, m, r, t;

    for(l = -1, r = n >> 1; l + 1 < r; )
    {
        m = (l + r) >> 1;
        t = Check(m << 1);
        if(t >= 0)
            r = m;
        else
            l = m;
    }

    return r << 1;
}

int SolveRB(void)
{
    int l, m, r, t;

    for(l = 0, r = (n >> 1) + 1; l + 1 < r; )
    {
        m = (l + r) >> 1;
        t = Check(m << 1);
        if(t <= 0)
            l = m;
        else
            r = m;
    }

    return l << 1;
}

int Scan(void)
{
    int c, s;

    for(s = 0; (c = getchar()) < '0' || c > '9'; )
        ;
    do
        s = s * 10 + (c & 15);
    while((c = getchar()) >= '0' && c <= '9');

    return s;
}

void Print(int x)
{
    static int b[20], c;

    if(!x)
        putchar('0');
    else
    {
        for(c = 0; x; x /= 10)
            b[c ++] = x % 10;
        while(c --)
            putchar(b[c] + 48);
    }
    putchar(' ');

    return;
}

int main(void)
{
    int l, r;
    int i, s;

    n = Scan();
    for(i = s = 0; i < n; i ++)
    {
        a[i] = Scan();
        s ^= a[i];
    }

    // for(i = 1; i <= 3; i += 2) cout << Check(i) << ' '; cout << endl; return 0;

    if(s & 1)
    {
        l = SolveLA();
        r = SolveRA();
    }
    else
    {
        l = SolveLB();
        r = SolveRB();
    }

    for(i = l; i <= r; i += 2)
        Print(i);
    if(l > r)
        printf("-1");
    putchar('\n');

    return 0;
}