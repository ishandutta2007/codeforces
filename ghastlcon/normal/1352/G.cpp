#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void)
{
    int t, n;
    int i;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        if(n <= 3)
            printf("-1\n");
        else if(n == 4)
            printf("3 1 4 2\n");
        else if(n & 1)
        {
            for(i = 1; i <= n; i += 2)
                printf("%d ", i);
            printf("%d %d ", n - 3, n - 1);
            for(i = n - 5; i >= 1; i -= 2)
                printf("%d ", i);
            printf("\n");
        }
        else
        {
            for(i = 1; i <= n; i += 2)
                printf("%d ", i);
            printf("%d %d %d ", n - 4, n, n - 2);
            for(i = n - 6; i >= 1; i -= 2)
                printf("%d ", i);
            printf("\n");
        }
    }

    return 0;
}