#include<cstdio>
#include<algorithm>
#include<cstring>
double dp[2005][2005];

int main()
{
    int n, t;
    double p, ans = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    scanf("%d %lf %d", &n, &p, &t);
    for(int i = 1; i <= t; i++)
    {
        for(int j = n; j >= 0; j--)
        {
            if(j == n)
                dp[i][j] = dp[i - 1][j - 1] * p + dp[i - 1][j];
            else if(j != 0)
                dp[i][j] = dp[i - 1][j - 1] * p + dp[i - 1][j] * (1 - p);
            else
                dp[i][j] = dp[i - 1][j] * (1 - p);
        }
    }
    for(int i = 1; i <= t; i++)
        ans += (dp[t][i] * i);
    printf("%.7f\n", ans);
}