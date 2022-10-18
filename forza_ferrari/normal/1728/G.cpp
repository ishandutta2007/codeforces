#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod=998244353;
int d,n,m,q,sum[21][21],p1[200001],p2[21],dp[21];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
int main()
{
    d=read(),n=read(),m=read();
    for(int i=1;i<=n;++i)
        p1[i]=read();
    sort(p1+1,p1+n+1);
    for(int i=1;i<=m;++i)
        p2[i]=read();
    sort(p2+1,p2+m+1);
    p2[0]=-1e9;
    p2[m+1]=1e9;
    for(int i=0;i<=m;++i)
        for(int j=i+1;j<=m+1;++j)
        {
            sum[i][j]=1;
            for(int k=1;k<=n;++k)
                if(p1[k]>=p2[i]&&p1[k]<=p2[j])
                    sum[i][j]=1ll*sum[i][j]*min(d+1,min(p1[k]-p2[i],p2[j]-p1[k]))%mod;
        }
    q=read();
    while(q--)
    {
        int x=read(),ans=0;
        dp[0]=dp[m+1]=1;
        for(int i=1;i<=m;++i)
            dp[i]=0;
        for(int i=1;i<=m&&p2[i]<x;++i)
            for(int j=0;j<i;++j)
                dp[i]=(dp[i]-1ll*dp[j]*sum[j][i]%mod+mod)%mod;
        for(int i=m;i>=1&&p2[i]>x;--i)
            for(int j=m+1;j>i;--j)
                dp[i]=(dp[i]-1ll*dp[j]*sum[i][j]%mod+mod)%mod;
        for(int i=0;i<=m&&p2[i]<x;++i)
            for(int j=m+1;j>=1&&p2[j]>x;--j)
                ans=(ans+1ll*dp[i]*dp[j]%mod*sum[i][j]%mod*min(d+1,min(x-p2[i],p2[j]-x))%mod)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}