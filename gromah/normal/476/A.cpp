#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 10000 + 5
#define M 10 + 5

int n, m, Dp[N][M];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < m; i ++)
        Dp[0][i] = 10000000;
    Dp[1][0] = 10000000;
    Dp[1][1] = 1;
    for (int i = 2; i < m; i ++)
        Dp[1][i] = 10000000;
    for (int i = 2; i <= n; i ++)
        for (int j = 0; j < m; j ++)
        {
            int t = (j + m - 1) % m;
            Dp[i][j] = min(Dp[i - 2][t], Dp[i - 1][t]) + 1;
        }
    printf("%d\n", Dp[n][0] > n ? -1 : Dp[n][0]);;
    return 0;
}