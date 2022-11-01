#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[11][11];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        dp[i][1]=dp[1][i]=1;
    for(int i=2; i<=N; i++)
        for(int j=2; j<=N; j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    printf("%lld\n", dp[N][N]);
    return 0;
}