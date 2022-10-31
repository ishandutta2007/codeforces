#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
#define M 18
#define B 30
#pragma GCC optimize("O3")
using namespace std;

int n;
int a[N];
int f[N][B], g[N][M], h[N];

void InitOr(void)
{
    int i, j, t;

    for(i = 1;i <= n;i ++)
    {
        for(j = 0;j < B;j ++)
            f[i][j] = f[i - 1][j];
        for(t = a[i], j = 0;t;t >>= 1, j ++)
            f[i][j] += t & 1;
    }

    return;
}

void InitMax(void)
{
    int i, j;
    
    for(i = 1;i <= n;i ++)
        g[i][0] = a[i];

    for(j = 1;j < M;j ++)
        for(i = 1;i <= n;i ++)
            if(i + (1 << j) - 1 <= n)
                g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);

    for(i = 1;i <= n;i ++)
        h[i] = h[i - 1] + ((1 << (h[i - 1] + 1)) < i);
    
    return;
}

int Or(int l, int r)
{
    int i, o;

    for(i = o = 0;i < B;i ++)
        o += (f[r][i] - f[l - 1][i]) ? (1 << i) : 0;

    return o;
}

int Max(int l, int r)
{
    return max(g[l][h[r - l + 1]], g[r - (1 << h[r - l + 1]) + 1][h[r - l + 1]]);
}

int FindMaxLeft(int x)
{
    int l, m, r;

    for(l = 0, r = x;l + 1 < r;)
        if(Max(m = (l + r) / 2, x) <= a[x])
            r = m;
        else
            l = m;

    return r;
}

int FindMaxRight(int x)
{
    int l, m, r;

    if(x == n || a[x + 1] >= a[x])
        return x;

    for(l = x + 1, r = n + 1;l + 1 < r;)
        if(Max(x + 1, m = (l + r) / 2) < a[x])
            l = m;
        else
            r = m;

    return l;
}

int FindOrLeft(int x, int y)
{
    int l, m, r;

    if(!(Or(y, x) & (~a[x])))
        return y - 1;

    for(l = y, r = x;l + 1 < r;)
        if(Or(m = (l + r) / 2, x) & (~a[x]))
            l = m;
        else
            r = m;

    return l;
}

int FindOrRight(int x, int y)
{
    int l, m, r;

    if(!(Or(x, y) & (~a[x])))
        return y + 1;

    //printf("%d %d\n",x,y);
    for(l = x, r = y;l + 1 < r;)
    {
        //printf("[%d, %d] = %d\n",x,(l+r)/2,Or(x, m = (l + r) / 2));
        if(Or(x, m = (l + r) / 2) & (~a[x]))
            r = m;
        else
            l = m;
    }

    return r;
}

long long Count(int x)
{
    int l, r, p, q;

    l = FindMaxLeft (x);
    r = FindMaxRight(x);
    p = FindOrLeft(x, l);
    q = FindOrRight(x, r);

    //printf("%d %d %d %d\n", l, r, p, q);

    return (long long)(p - l + 1) * (r - x + 1) + (long long)(r - q + 1) * (x - l + 1) - (long long)(p - l + 1) * (r - q + 1);
}

int main() //2334.cpp
{
    int i;
    long long o;

    /*freopen("2334.in" , "r", stdin );
    freopen("2334.out", "w", stdout);*/

    scanf("%d", &n);
    for(i = 1;i <= n;i ++)
        scanf("%d", &a[i]);

    InitOr ();
    InitMax();
    /*while(1)
    {
        int l,r;
        cin>>l>>r;
        cout<<Max(l,r)<<endl;
    }*/

    for(i = 1, o = 0;i <= n;i ++)
        o += Count(i);
    printf("%I64d\n", o);

    return 0;
}