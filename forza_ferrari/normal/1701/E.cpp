#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int mod=19260817,base=233;
int t,n,m,dp[5001][5001],ans,val[5001][2],w[5001],inv[5001];
bool vis[5005][5005][2];
string a,b;
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
int main()
{
    cin>>t;
    w[0]=inv[0]=1;
    w[1]=base;
    inv[1]=pw(base,mod-2);
    for(int i=2;i<=5000;++i)
    {
        w[i]=1ll*w[i-1]*w[1]%mod;
        inv[i]=1ll*inv[i-1]*inv[1]%mod;
    }
    while(t--)
    {
        cin>>n>>m>>a>>b;
        a=" "+a;
        b=" "+b;
        for(int i=1;i<=n;++i)
            val[i][0]=(val[i-1][0]+1ll*(a[i]-'a'+1)*w[i]%mod)%mod;
        for(int i=1;i<=m;++i)
            val[i][1]=(val[i-1][1]+1ll*(b[i]-'a'+1)*w[i]%mod)%mod;
        for(int i=0;i<=n;++i)
            for(int j=0;j<=m;++j)
                vis[i][j][0]=vis[i][j][1]=0,dp[i][j]=1e9;
        dp[0][0]=1;
        vis[0][0][0]=1;
        for(int i=1;i<=n;++i)
        {
            vis[i][0][0]=1;
            for(int j=1;j<=m;++j)
            {
                vis[i][j][0]=vis[i-1][j][0];
                if(a[i]==b[j])
                    vis[i][j][0]|=vis[i-1][j-1][0];
            }
        }
        if(!vis[n][m][0])
        {
            cout<<"-1\n";
            continue;
        }
        vis[n+1][m+1][1]=1;
        for(int i=n;i>=1;--i)
        {
            vis[i][m+1][1]=1;
            for(int j=m;j>=1;--j)
            {
                vis[i][j][1]=vis[i+1][j][1];
                if(a[i]==b[j])
                    vis[i][j][1]|=vis[i+1][j+1][1];
            }
            if(vis[i+1][1][1])
                vis[i][0][1]=1;
        }
        ans=0;
        while(ans<m&&a[ans+1]==b[ans+1])
            ++ans;
        ans=n-ans;
        for(int i=1;i<=n;++i)
            for(int j=0;j<=m;++j)
            {
                dp[i][j]=dp[i-1][j]+2;
                if(j&&a[i]==b[j])
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                if(vis[i][j][0]&&vis[i+1][j+1][1])
                {
                    int l=1,r=min(n-i,m-j),mid,len=0;
                    while(l<=r)
                    {
                        mid=(l+r)>>1;
                        if(1ll*(val[i+mid][0]-val[i][0]+mod)%mod*inv[i]%mod==1ll*(val[j+mid][1]-val[j][1]+mod)%mod*inv[j]%mod)
                        {
                            len=mid;
                            l=mid+1;
                        }
                        else
                            r=mid-1;
                    }
                    ans=min(ans,dp[i][j]+n-i-len);
                }
            }
        cout<<ans<<'\n';
    }
    return 0;
}