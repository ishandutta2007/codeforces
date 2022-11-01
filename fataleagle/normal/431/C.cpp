#include <bits/stdc++.h>

using namespace std;

int dp[101][2];

int main()
{
    int n, K, d;
    cin>>n>>K>>d;
    dp[0][0]=1;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=1; j++)
            for(int k=1; k<=K; k++)
                if(i-k>=0)
                    dp[i][j|(k>=d)]=(dp[i][j|(k>=d)]+dp[i-k][j])%1000000007;
    printf("%d\n", dp[n][1]);
    return 0;
}