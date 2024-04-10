#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
 
int main(void)
{
    int t, n, x, s;
    int i;
 
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = s = 0; i < n; i ++)
        {
            scanf("%d", &x);
            s += x;
        }
        for(i = 1; i <= 1000000000; i ++)
            if((long long)i * n >= s)
                break;
        printf("%d\n", i);
    }
 
    return 0;
}