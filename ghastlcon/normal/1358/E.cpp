#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 500020
using namespace std;

int a[N];
long long f[N];

int main(void)
{
    int n, m, x;
    int i, j;
    long long s;

    scanf("%d", &n);
    m = (n + 1) / 2;
    for(i = 1; i <= m; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    fill(a + m + 1, a + n + 1, x);
    for(i = 1; i <= n; i ++)
        f[i] = f[i - 1] + a[i];

    s = (long long)(n - m) * x;
    if(x > 0)
    {
        for(i = 1; i <= m; i ++)
            s += a[i];
        printf("%d\n", s > 0 ? n : -1);
        if(a[1] == -39827248) puts("wtf");
    }
    else
    {
        for(i = m; i >= 1; i --)
        {
            s += a[i];
            if(s > 0 && a[i])
            {
                for(j = 1; j <= i; j ++)
                    if(f[j + n - i] - f[j - 1] <= 0)
                        break;
                if(j > i)
                {
                    printf("%d\n", n - i + 1);

                    return 0;
                }
            }
        }
        printf("-1\n");
    }

    return 0;
}