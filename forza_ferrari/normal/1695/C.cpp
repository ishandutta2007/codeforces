#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,dp[1001][1001][2],a[1001][1001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<=n;++i)
            for(int j=0;j<=m;++j)
            {
                dp[i][j][0]=1e9,dp[i][j][1]=-1e9;
                if(i&&j)
                    cin>>a[i][j];
            }
        if((n+m)&1^1)
        {
            cout<<"NO\n";
            continue;
        }
        dp[0][1][0]=dp[0][1][1]=dp[1][0][0]=dp[1][0][1]=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                dp[i][j][0]=min(dp[i-1][j][0],dp[i][j-1][0])+a[i][j];
                dp[i][j][1]=max(dp[i-1][j][1],dp[i][j-1][1])+a[i][j];
            }
        if(dp[n][m][0]<=0&&dp[n][m][1]>=0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}