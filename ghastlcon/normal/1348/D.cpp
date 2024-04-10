#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 50
using namespace std;

int a[N];

int main(void)
{
    int t, n, m;
    int i;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        m = 31 - __builtin_clz(n);

        a[0] = 1;
        for(i = 1; i < m; i ++)
            a[i] = a[i - 1] * 2;

        a[m] = n;
        for(i = 0; i < m; i ++)
            a[m] -= a[i];
        for(i = m - 1; i > -1; i --)
            if(a[i + 1] < a[i])
                swap(a[i], a[i + 1]);

        printf("%d\n", m);
        for(i = 1; i <= m; i ++)
            printf("%d%c", a[i] - a[i - 1], " \n"[i == m]);
    }

    return 0;
}