#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
using namespace std;

int a[N], o[N];

int main(void)
{
    int t, n;
    int i;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i ++)
            scanf("%d", &a[i]);

        o[0] = 1;
        for(i = 1; i < n; i ++)
        {
            o[i] = o[i - 1];
            if(a[i] != a[i - 1])
            {
                o[i] = o[i - 1] == 1 ? 2 : 1;
                if(i == n - 1 && a[i] != a[0])
                {
                    if(o[i - 1] != o[0])
                        o[i] = 3;
                    else
                        o[i] = o[i - 1] == 1 ? 2 : 1;
                }
            }
            else if(i == n - 1 && a[i] != a[0])
                o[i] = o[0] == 1 ? 2 : 1;
        }

        if(o[n - 1] == 3)
        {
            for(i = 1; i < n; i ++)
                if(o[i] == o[i - 1])
                {
                    for(; i < n - 1; i ++)
                        o[i] = o[i] == 1 ? 2 : 1;
                    break;
                }
            if(i < n)
                o[i] = o[0] == 1 ? 2 : 1;
        }

        printf("%d\n", *max_element(o, o + n));
        for(i = 0; i < n; i ++)
            printf("%d%c", o[i], " \n"[i == n - 1]);
    }

    return 0;
}