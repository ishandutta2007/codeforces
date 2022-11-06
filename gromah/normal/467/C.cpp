#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 5000 + 5

int n, m, k, A[N];
LL Sum[N], Dp[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", A + i);
        Sum[i] = Sum[i - 1] + A[i];
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i / m; j ++)
            Dp[i][j] = max(Dp[i - m][j - 1] + Sum[i] - Sum[i - m], Dp[i - 1][j]);
    cout << Dp[n][k] << endl;
    return 0;
}