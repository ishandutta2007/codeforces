#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 8020
using namespace std;

int a[N];
bool u[N];

int main(void)
{
    int t, n;
    int i, j, s, o;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            u[i] = false;
        }

        for(i = 1; i <= n; i ++)
            for(j = i + 1, s = a[i] + a[j]; j <= n && s <= n; j ++)
            {
                u[s] = true;
                if(j < n)
                    s += a[j + 1];
            }

        for(i = 1, o = 0; i <= n; i ++)
            o += u[a[i]];
        printf("%d\n", o);
    }

    return 0;
}