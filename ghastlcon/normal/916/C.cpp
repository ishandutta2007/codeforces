#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define B 19260817LL
#define int long long
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    int n, m;
    int i, j, c;

    printf("%I64d %I64d\n", B, B);
    scanf("%I64d %I64d", &n, &m);
    for(i = 1;i < n - 1;i ++)
        printf("%I64d %I64d 1\n", i, i + 1);
    printf("%I64d %I64d %I64d\n", n - 1, n, B - (n - 2));

    c = m - (n - 1);
    for(i = 1;i <= n && c;i ++)
        for(j = i + 2;j <= n && c;j ++)
        {
            c --;
            printf("%I64d %I64d %I64d\n", i, j, B);
        }

    return 0;
}