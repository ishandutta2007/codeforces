#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(void)
{
    int t, n, k;
    int i;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &k);
        if(n < k)
            printf("NO\n");
        else
        {
            if((n - (k - 1)) % 2)
            {
                printf("YES\n");
                for(i = 0; i < k - 1; i ++)
                    printf("1 ");
                printf("%d\n", n - (k - 1));
            }
            else if(n > (k - 1) * 2 && (n - (k - 1) * 2) % 2 == 0)
            {
                printf("YES\n");
                for(i = 0; i < k - 1; i ++)
                    printf("2 ");
                printf("%d\n", n - (k - 1) * 2);
            }
            else
                printf("NO\n");
        }
    }

    return 0;
}