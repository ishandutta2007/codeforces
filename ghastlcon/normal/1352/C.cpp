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
    long long l, m, r;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &k);
        for(l = 0, r = 1000000000000LL; l + 1 < r; )
        {
            m = (l + r) / 2;
            if(m - m / n >= k)
                r = m;
            else
                l = m;
        }
        printf("%I64d\n", r);
    }

    return 0;
}