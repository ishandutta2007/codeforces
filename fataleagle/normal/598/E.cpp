#include <bits/stdc++.h>

using namespace std;

int dp[31][31][51];

int main()
{
    memset(dp, 0x3f, sizeof dp);
    for(int i=1; i<=30; i++)
        for(int j=1; j<=30; j++)
            for(int k=0; k<=min(i*j, 50); k++)
            {
                if(k==0 || k==i*j)
                    dp[i][j][k]=0;
                else
                {
                    for(int l=0; l<=k; l++)
                    {
                        for(int m=1; m<i; m++)
                            dp[i][j][k]=min(dp[i][j][k], dp[m][j][l]+dp[i-m][j][k-l]+j*j);
                        for(int m=1; m<j; m++)
                            dp[i][j][k]=min(dp[i][j][k], dp[i][m][l]+dp[i][j-m][k-l]+i*i);
                    }
                }
            }
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int N, M, K;
        scanf("%d%d%d", &N, &M, &K);
        printf("%d\n", dp[N][M][K]);
    }
    return 0;
}