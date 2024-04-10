#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 2000020
#define M 21
using namespace std;

int a[N];
int f[N];

void InsertAnd(int x, int l)
{
    if(f[x] == 2)
        return;
    if(l == -1)
    {
        f[x] ++;

        return;
    }

    InsertAnd(x, l - 1);
    if(x & (1 << l))
        InsertAnd(x ^ (1 << l), l - 1);

    return;
}

int MaxOr(int x)
{
    int i, o;

    for(i = M - 1, o = 0; i > -1; i --)
    {
        // printf("val %d, o = %d\n", x, o);
        if(~x & (1 << i) && f[o | (1 << i)] == 2)
            o |= 1 << i;
    }

    return x | o;
}

int main(void)
{
    int n;
    int i, o;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    for(i = n - 1, o = 0; i > -1; i --)
    {
        if(i < n - 2)
            o = max(o, MaxOr(a[i]));
        InsertAnd(a[i], M - 1);
    }
    printf("%d\n", o);

    return 0;
}