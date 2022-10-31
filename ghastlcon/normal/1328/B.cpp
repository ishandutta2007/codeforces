#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
 
int main(void)
{
    int t, n, k;
    int i, j;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &k);
        for(i = 1; i <= n; i ++)
            if(k <= i)
            {
                for(j = 0; j < n - i - 1; j ++)
                    putchar('a');
                putchar('b');
                for(j = 0; j < i - k; j ++)
                    putchar('a');
                putchar('b');
                for(j = 0; j < k - 1; j ++)
                    putchar('a');
                break;
            }
            else
                k -= i;
        putchar('\n');
    }

    return 0;
}