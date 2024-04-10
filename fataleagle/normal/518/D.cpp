#include <bits/stdc++.h>

using namespace std;

int N, T;
double P;
double dp[2002][2002];

int main()
{
    scanf("%d%lf%d", &N, &P, &T);
    dp[0][0]=1.0;
    for(int i=0; i<=N; i++)
        for(int j=0; j<=T; j++)
        {
            if(i==N)
                dp[i][j+1]+=dp[i][j];
            else
            {
                dp[i+1][j+1]+=dp[i][j]*P;
                dp[i][j+1]+=dp[i][j]*(1.0-P);
            }
        }
    double ans=0.0;
    for(int i=0; i<=N; i++)
        ans+=i*dp[i][T];
    printf("%.9f\n", ans);
    return 0;
}