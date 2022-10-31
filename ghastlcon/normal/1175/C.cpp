#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
#pragma GCC optimize("O3")
using namespace std;

int n, k, a[N];

int Check(int l)
{
    int i, j, o;

    for(i = j = o = 0; i < n; i ++)
    {
        while(j + 1 < n && a[j + 1] - a[i] <= l * 2)
            j ++;
        o = max(o, j - i + 1);
    }

    return o;
}

int Find(int l, int v)
{
    int i, j, o;

    for(i = j = o = 0; i < n; i ++)
    {
        while(j + 1 < n && a[j + 1] - a[i] <= l * 2)
            j ++;
        if(j - i + 1 == v)
            return a[i] + l;
    }

    throw;
}

int BSFind(void)
{
    int l, m, r;

    for(l = -1, r = 1000000000; l + 1 < r; )
        if(Check(m = (l + r) >> 1) >= k + 1)
            r = m;
        else
            l = m;

    return Find(r, Check(r));
}

int main(void)
{
    int t;
    int i;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        printf("%d\n", BSFind());
    }

    return 0;
}