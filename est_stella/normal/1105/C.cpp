#include<stdio.h>
#define Mod 1000000007

int n, l, r;
long long int dp[200001][3];

int main()
{
    scanf("%d%d%d", &n, &l, &r);

    int num[3];
    num[0] = (r-l+1)/3;
    num[1] = (r-l+1)/3;
    num[2] = (r-l+1)/3;

    for(int i=0; i<(r-l+1)%3; i++)
    {
        num[(l+i)%3]++;
    }

    dp[0][0]=1;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<3; j++)
        {
            dp[i][j] += dp[i-1][j] * num[0];
            dp[i][j] += dp[i-1][(j+2)%3] * num[1];
            dp[i][j] += dp[i-1][(j+1)%3] * num[2];
            dp[i][j] %= Mod;
        }
    }

    printf("%d", dp[n][0]);
}