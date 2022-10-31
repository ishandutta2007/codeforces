#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 1000020
#define M 20
using namespace std;

char a[N];
bool f[1 << M | 1];
int g[1 << M | 1];

int main(void)
{
    int n;
    int i, j, k;

    scanf("%s", a);
    n = strlen(a);
    for(i = 0; i < n; i ++)
        for(j = i, k = 0; j < n; j ++)
        {
            if(k & (1 << (a[j] - 97)))
                break;
            k |= 1 << (a[j] - 97);
            f[k] = true;
        }

    for(i = 0; i < (1 << M); i ++)
        if(f[i])
            g[i] = __builtin_popcount(i);
    for(k = 0; k < M; k ++)
        for(i = 0; i < (1 << M); i += 2 << k)
            for(j = 0; j < (1 << k); j ++)
                g[i + j + (1 << k)] = max(g[i + j + (1 << k)], g[i + j]);

    for(i = k = 0; i < (1 << M); i ++)
        if(f[i])
            k = max(k, __builtin_popcount(i) + g[((1 << M) - 1) ^ i]);
    printf("%d\n", k);

    return 0;
}