#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 100020
using namespace std;

int a[N], f[N];

int main(void)
{
    int t, n, k;
    int i, s;

    scanf("%d", &t);
    for(int tt = 0; tt < t; tt ++)
    // while(t --)
    {
        scanf("%d %d", &n, &k);
        for(i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        if(n == 1 && a[1] == k)
        {
            printf("yes\n");
            continue;
        }

        // if(t == 10 && tt == 8)
        // {
        //     printf("%d %d\n", n, k);
        //     for(i = 1; i <= n; i ++)
        //         cout << a[i] << ' '; return 0;
        // }

        for(i = 1; i <= n; i ++)
            if(a[i] == k)
                break;

        if(i > n)
            printf("no\n");
        else
        {
            for(i = 1, s = n; i <= n; i ++)
            {
                a[i] = a[i] >= k ? 1 : -1;
                f[i] = f[i - 1] + a[i];
                if(i > 1 && f[i] - s > 0)
                    break;
                s = min(s, f[i - 1]);
            }
            printf("%s\n", i <= n ? "yes" : "no");
        }
    }

    return 0;
}