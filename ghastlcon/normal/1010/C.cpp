#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 100020
using namespace std;

int a[N];
bool f[N];

int main(void)
{
    int n, k;
    int i, j, t, s;

    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        a[i] = __gcd(a[i], k);
        // printf("%d\n",a[i]);
    }

    sort(a, a + n);
    n = (int)(unique(a, a + n) - a);
    f[0] = 1;
    for(i = 0; i < n; i ++)
        for(j = 0; j < a[i]; j ++)
            for(t = j; t < k; t += a[i])
                if(f[t])
                {
                    for(t = j; t < k; t += a[i])
                        f[t] = true;
                    break;
                }
    for(i = s = 0; i < k; i ++)
        s += f[i];
    printf("%d\n", s);
    for(i = 0; i < k; i ++)
        if(f[i])
            printf("%d ", i);

    return 0;
}