#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, f[10];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++)
    {
        int t;
        scanf("%d", &t);
        f[5 - t] ++;
    }
    int ans = 0, p = 5;
    while (p >= k)
    {
        ans += f[p] / 3;
        f[p - 1] += f[p] % 3;
        p --;
    }
    printf("%d\n", ans);
    return 0;
}