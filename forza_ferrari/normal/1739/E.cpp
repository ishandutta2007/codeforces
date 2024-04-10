#include<iostream>
#include<cstdio>
using namespace std;
int n,dp[200005][2][2],a[200005][2];
int main()
{
    cin>>n;
    for(int i=0;i<2;++i)
    {
        string s;
        cin>>s;
        s=" "+s;
        for(int j=1;j<=n;++j)
            a[j][i]=s[j]-'0';
    }
    for(int i=n;i>=1;--i)
    {
        dp[i][0][0]=dp[i][0][1]=dp[i+1][0][0]+a[i][0];
        dp[i][1][0]=dp[i][1][1]=dp[i+1][1][0]+a[i][1];
        if(a[i][1])
            dp[i][0][0]=max(dp[i][0][0],dp[i+1][1][1]+1+a[i][0]);
        if(a[i][0])
            dp[i][1][0]=max(dp[i][1][0],dp[i+1][0][1]+1+a[i][1]);
    }
    cout<<max(dp[1][0][0],dp[1][0][1])<<'\n';
    return 0;
}