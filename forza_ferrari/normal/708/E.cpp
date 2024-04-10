#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
int n,m,val,cnt,ans,w[100001][2],f[1501][1501],g[1501],fac[100001],inv[100001],sum[1501],p[1501],q[1501];
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
inline int c(int x,int y)
{
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    int a,b;
    cin>>n>>m>>a>>b>>cnt;
    val=1ll*a*pw(b,mod-2)%mod;
    fac[0]=inv[0]=w[0][0]=w[0][1]=1;
    for(int i=1;i<=cnt;++i)
    {
        fac[i]=1ll*fac[i-1]*i%mod;
        w[i][0]=1ll*val*w[i-1][0]%mod;
        w[i][1]=1ll*(1-val+mod)%mod*w[i-1][1]%mod;
    }
    inv[cnt]=pw(fac[cnt],mod-2);
    for(int i=cnt-1;i>=1;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    for(int i=0;i<=m;++i)
        g[i]=1ll*c(cnt,i)*w[i][0]%mod*w[cnt-i][1]%mod;
    p[0]=g[0];
    for(int i=1;i<=m;++i)
        p[i]=(p[i-1]+g[i])%mod;
    f[0][m]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
            sum[j]=q[j]=0;
        for(int j=1;j<=m;++j)
        {
            sum[j]=(sum[j-1]+f[i-1][j])%mod;
            q[j]=(q[j-1]+1ll*g[j]*sum[j]%mod)%mod;
        }
        for(int j=1;j<=m;++j)
            f[i][j]=1ll*(1ll*(sum[m]-sum[m-j]+mod)%mod*p[j-1]%mod-q[j-1]+mod)%mod*g[m-j]%mod;
    }
    for(int i=1;i<=m;++i)
        ans=(ans+f[n][i])%mod;
    cout<<ans<<'\n';
    return 0;
}