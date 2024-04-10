#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,a[101],b[101],ans,dp[101][20001],sum,minn,maxn,res;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=minn=maxn=res=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            res+=a[i]*a[i];
        }
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
            res+=b[i]*b[i];
        }
        for(int i=0;i<=n;++i)
            for(int j=0;j<=200*n;++j)
                dp[i][j]=1e18;
        dp[0][0]=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=minn;j<=maxn;++j)
            {
                if(dp[i-1][j]==1e18)
                    continue;
                dp[i][j+a[i]]=min(dp[i][j+a[i]],dp[i-1][j]+a[i]*j+b[i]*(sum-j));
                dp[i][j+b[i]]=min(dp[i][j+b[i]],dp[i-1][j]+b[i]*j+a[i]*(sum-j));
                
            }
            sum+=a[i]+b[i];
            minn+=min(a[i],b[i]);
            maxn+=max(a[i],b[i]);
        }
        ans=1e18;
        for(int i=minn;i<=maxn;++i)
            ans=min(ans,dp[n][i]);
        cout<<2*ans+res*(n-1)<<'\n';
    }
    return 0;
}