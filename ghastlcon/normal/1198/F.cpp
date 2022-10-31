#define __SSE__ 1
#define __SSE2__ 1
#define __SSE2_MATH__ 1
#define __SSE3__ 1
#define __SSSE3__ 1
#define __SSE4_1__ 1
#define __SSE4_2__ 1
#define __SSE_MATH__ 1
#define __AVX__ 1
#define __AVX2__ 1
#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <random>
#include <chrono>
#include <utility>
#define N 100020
#define M 100
using namespace std;

pair<int, int> a[N];
int o[N];

int main(void)
{
    int n;
    int i, j, x, y;
    mt19937 r(chrono::steady_clock::now().time_since_epoch().count());

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    for(i = 0; i < M; i ++)
    {
        shuffle(a, a + n, r);
        for(j = x = y = 0; j < n; j ++)
            if(x != 1 && x != __gcd(x, a[j].first))
            {
                x = __gcd(x, a[j].first);
                o[a[j].second] = 1;
            }
            else
            {
                y = __gcd(y, a[j].first);
                o[a[j].second] = 2;
            }
        if(x == 1 && y == 1)
        {
            printf("YES\n");
            for(j = 0; j < n; j ++)
                printf("%d ", o[j]);
            printf("\n");
            break;
        }
    }
    if(i == M)
        printf("NO\n");

    return 0;
}