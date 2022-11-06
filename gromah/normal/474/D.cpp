#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define Mod 1000000007

int n, k, Max, Ask[N][2], Dp[N], Sum[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d%d", Ask[i], Ask[i] + 1);
        Max = max(Max, Ask[i][1]);
    }
    Dp[0] = 1;
    for (int i = 1; i <= Max; i ++)
    {
        Dp[i] = Dp[i - 1];
        if (i >= k)
            Dp[i] += Dp[i - k];
        Dp[i] %= Mod;
        Sum[i] = (Sum[i - 1] + Dp[i]) % Mod;
    }
    for (int i = 1; i <= n; i ++)
        printf("%d\n", (Sum[Ask[i][1]] - Sum[Ask[i][0] - 1] + Mod) % Mod, i == n ? '\n' : ' ');
    return 0;
}