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
        for(i = 2; (1 << i) - 1 <= n; i ++)
            if(!(n % ((1 << i) - 1)))
            {
                printf("%d\n", n / ((1 << i) - 1));
                break;
            }
    }

    return 0;
}