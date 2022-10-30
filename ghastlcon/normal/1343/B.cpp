#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void)
{
    int t, n;
    int i;
    long long s;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        if(n / 2 % 2)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for(i = s = 0; i < n / 2; i ++)
            {
                s += (i + 1) * 2;
                printf("%d ", (i + 1) * 2);
            }
            for(i = 0; i < n / 2 - 1; i ++)
            {
                s -= i * 2 + 1;
                printf("%d ", i * 2 + 1);
            }
            printf("%I64d\n", s);
        }
    }

    return 0;
}