#include<iostream>
#include<cstdio>
using namespace std;
int t,n,dp[200001][2][2],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        dp[0][0][0]=dp[0][0][1]=dp[0][1][0]=1e9;
        dp[0][1][1]=0;
        for(int i=1;i<=n;++i)
        {
            int x=0;
            cin>>x;
            dp[i][0][0]=min(dp[i-1][1][0],dp[i-1][1][1])+x;
            dp[i][0][1]=dp[i-1][0][0]+x;
            dp[i][1][0]=min(dp[i-1][0][0],dp[i-1][0][1]);
            dp[i][1][1]=dp[i-1][1][0];
        }
        cout<<min(min(dp[n][0][0],dp[n][0][1]),min(dp[n][1][0],dp[n][1][1]))<<'\n';
    }
    return 0;
}