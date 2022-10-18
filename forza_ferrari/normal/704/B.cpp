#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,s,t,cnt,x[5001],a[5001],b[5001],c[5001],d[5001],dp[5001][5001];
signed main()
{
    cin>>n>>s>>t;
    for(int i=1;i<=n;++i)
        cin>>x[i];
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        cin>>b[i];
    for(int i=1;i<=n;++i)
        cin>>c[i];
    for(int i=1;i<=n;++i)
        cin>>d[i];
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            dp[i][j]=1e18;
    dp[0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(j==1&&cnt==2)
                dp[i][j]=1e18;
            if(dp[i][j]<1e18)
            {
                if(s==i+1)
                {
                    if(j<n)
                        dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]-x[i+1]+d[i+1]);
                    if(j)
                        dp[i+1][j]=min(dp[i+1][j],dp[i][j]+x[i+1]+c[i+1]);
                }
                else if(t==i+1)
                {
                    if(j<n)
                        dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]-x[i+1]+b[i+1]);
                    if(j)
                        dp[i+1][j]=min(dp[i+1][j],dp[i][j]+x[i+1]+a[i+1]);
                }
                else
                {
                    if(j<n)
                        dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]-x[i+1]+b[i+1]-x[i+1]+d[i+1]);
                    if(j>1)
                        dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+x[i+1]+a[i+1]+x[i+1]+c[i+1]);
                    if(j)
                    {
                        if(t>i+1||j>1)
                            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+d[i+1]+a[i+1]);
                        if(s>i+1||j>1)
                            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+c[i+1]+b[i+1]);
                    }
                }
            }
        }
        cnt+=s==i+1||t==i+1;
    }
    cout<<dp[n][1]<<'\n';
    return 0;
}