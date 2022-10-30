#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 520
using namespace std;

bool f[N][N];

int main(void)
{
    int n, k, a, b;
    int i, j, t;
    long long x, y;

    scanf("%d %d", &n, &k);
    x = y = 0;
    f[0][0] = true;
    for(i = 1; i <= n; i ++)
    {
        scanf("%d %d", &a, &b);
        x += a;
        y += b;
        for(j = 0; j < k; j ++)
            for(t = 0; t < k && t <= a; t ++)
                if((k - t) % k <= b)
                    f[i][j] |= f[i - 1][(j - t + k) % k];
    }

    if(x / k + y / k == (x + y) / k)
        printf("%lld\n", (x + y) / k);
    else
    {
        for(i = 1; i < k; i ++)
            if(f[n][i] && (x - i) / k + (y - (k - i)) / k + 1 == (x + y) / k)
                break;
        printf("%lld\n", (x + y) / k - (i == k));
    }

    return 0;
}