#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 500020
using namespace std;

int f[N];

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        for(int j = 2; i * j <= n; j ++)
            f[i * j] = max(f[i * j], i);

    sort(f + 2, f + n + 1);
    for(i = 2; i <= n; i ++)
        printf("%d%c", f[i], " \n"[i == n]);

    return 0;
}