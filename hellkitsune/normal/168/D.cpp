#include <iostream>
#include <stdio.h>

using namespace std;

int n, l, k, a[201];
double p[201], dp[201][201][401] = {{{0}}}, ans;

int main(void)
{
    int i, j;
    cin >> n >> l >> k;
    for (i = 1; i <= n; ++i)
    {
        cin >> p[i];
        p[i] /= 100;
    }
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    if (k > n)
        dp[0][0][2 * n] = 1;
    else
        dp[0][0][n + k] = 1;
    for (i = 0; i < n; ++i)
        for (j = 0; j <= l; ++j)
            for (k = 0; k <= 2 * n; ++k)
            {
                dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i + 1]);
                int t = k + a[i + 1];
                if (t > 2 * n)
                    t = 2 * n;
                if (t < 0)
                    t = 0;
                int t2 = j + 1;
                if (t2 > l)
                    t2 = l;
                dp[i + 1][t2][t] += dp[i][j][k] * p[i + 1];
            }
    ans = 0;
    for (i = n; i <= 2 * n; ++i)
        ans += dp[n][l][i];
    printf("%.10lf", ans);
    return 0;
}