#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
using namespace std;

int a[N], b[N];
int c[N];

int main(void)
{
    int n;
    int i, j, k, o;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &b[i]);
        if(b[i])
            c[b[i]] = i;
    }

    if(!c[1])
    {
        for(i = 2, o = 0; i <= n; i ++)
            if(c[i])
                o = max(o, c[i] - (i - 1));
        printf("%d\n", o + n);
    }
    else
    {
        for(i = c[1] + 1; i <= n; i ++)
            if(b[i] != i - c[1] + 1)
                break;
        if(i > n)
        {
            for(i = b[n] + 1; i <= n && !c[i]; i ++)
                ;
            if(i > n)
                printf("%d\n", c[1] - 1);
            else
            {
                for(o = 0, j = i; j <= n; j ++)
                    if(i - (b[n] + 1) < c[j] - (j - i))
                        break;
                if(j > n)
                    printf("%d\n", c[1] - 1);
                else
                {
                    k = c[1];
                    for(i = 1; i <= n; i ++)
                    {
                        c[i] -= k;
                        c[i] = max(0, c[i]);
                    }

                    for(i = 2, o = 0; i <= n; i ++)
                        if(c[i])
                            o = max(o, c[i] - (i - 1));
                    printf("%d\n", o + n + k);
                }
            }
        }
        else
        {
            k = c[1];
            for(i = 1; i <= n; i ++)
            {
                c[i] -= k;
                c[i] = max(0, c[i]);
            }

            for(i = 2, o = 0; i <= n; i ++)
                if(c[i])
                    o = max(o, c[i] - (i - 1));
            printf("%d\n", o + n + k);
        }
    }

    return 0;
}