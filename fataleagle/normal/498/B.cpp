#include <bits/stdc++.h>

using namespace std;

int N, T;
double dp[5001][5001];
double p[5001];
int t[5001];
double pw[5001];

int main()
{
    scanf("%d%d", &N, &T);
    for(int i=1; i<=N; i++)
        scanf("%lf%d", p+i, t+i), p[i]/=100.0;
    dp[0][0]=1.0;
    pw[0]=1.0;
    double ans=0.0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=T; j++)
        {
            pw[j]=pw[j-1]*(1.0-p[i]);
            if(pw[j]<1e-18)
                pw[j]=0.0;
        }
        double tmp=0.0;
        for(int j=0; j<t[i]; j++)
        {
            dp[i][j]+=tmp;
            tmp=tmp*pw[1]+dp[i-1][j]*p[i];
            ans+=dp[i][j];
            if(dp[i][j]<1e-18)
                dp[i][j]=0.0;
            if(tmp<1e-18)
                tmp=0.0;
        }
        for(int j=t[i]; j<=T; j++)
        {
            dp[i][j]+=dp[i-1][j-t[i]]*pw[t[i]-1];
            tmp-=dp[i-1][j-t[i]]*p[i]*pw[t[i]-1];
            dp[i][j]+=tmp;
            tmp=tmp*pw[1]+dp[i-1][j]*p[i];
            ans+=dp[i][j];
            if(dp[i][j]<1e-18)
                dp[i][j]=0.0;
            if(tmp<1e-18)
                tmp=0.0;
        }
    }
    printf("%.9lf\n", ans);
    return 0;
}