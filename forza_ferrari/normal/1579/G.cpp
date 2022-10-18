#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,a[10001],dp[2][2005],now,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        memset(dp,0x3f,sizeof dp);
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        now=0;
        dp[0][a[1]]=a[1];
        for(int i=2;i<=n;++i)
        {
            now^=1;
            for(int j=0;j<=2000;++j)
                dp[now][j]=0x3f3f3f3f;
            for(int j=0;j<=2000;++j)
                if(dp[now^1][j]!=0x3f3f3f3f)
                {
                    if(j+a[i]<=2000)
                        dp[now][j+a[i]]=min(dp[now][j+a[i]],max(dp[now^1][j],a[i]+j));
                    dp[now][max(j-a[i],0)]=min(dp[now][max(j-a[i],0)],dp[now^1][j]+max(a[i]-j,0));
                }
        }
        ans=1e9;
        for(int i=0;i<=2000;++i)
            ans=min(ans,dp[now][i]);
        cout<<ans<<endl;
    }
    return 0;
}