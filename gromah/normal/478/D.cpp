#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 400000 + 5
#define Mod 1000000007

int n, m, h, ans, sum, Dp[N];

int main()
{
    scanf("%d%d", &n, &m);
    if (n > m) swap(n, m);
    h = (int) sqrt(n + m << 1);
    if (h * (h + 1) / 2 > n + m)
        h --;
    sum = h * (h + 1) / 2;
    Dp[0] = 1;
    for (int i = 1; i <= h; i ++)
        for (int j = n; j >= i; j --)
            Dp[j] = (Dp[j] + Dp[j - i]) % Mod;
    for (int i = 0; i <= min(sum, m); i ++)
        ans = (ans + Dp[sum - i]) % Mod;
    printf("%d\n", ans);
    return 0;
}