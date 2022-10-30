#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1020
using namespace std;

int a[N];

int main(void)
{
    int t, n;
    int i, l, r;
    int x, y, p, q;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i ++)
            scanf("%d", &a[i]);

        x = y = p = q = 0;
        for(i = l = 0, r = n - 1; l <= r; i ++)
        {
            if(i & 1)
            {
                for(q = 0; r >= l && q <= p; r --)
                    q += a[r];
                y += q;
            }
            else
            {
                for(p = 0; l <= r && p <= q; l ++)
                    p += a[l];
                x += p;
            }
        }
        printf("%d %d %d\n", i, x, y);
    }

    return 0;
}