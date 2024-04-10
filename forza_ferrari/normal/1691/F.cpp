#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
struct edge
{
    int nxt,to;
}e[200001<<1];
int n,m,tot,dp[200001],s[200001],h[200001],sum,ans,fac[200001],inv[200001];
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
    if(x<y||x<0||y<0)
        return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs1(int k,int f)
{
    s[k]=1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k);
        s[k]+=s[e[i].to];
    }
    dp[k]=c(s[k],m);
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dp[k]=(dp[k]-c(s[e[i].to],m)+mod)%mod;
    }
    sum=(sum+1ll*dp[k]*s[k]%mod)%mod;
}
inline void dfs2(int k,int f)
{
    sum=(sum-1ll*dp[k]*s[k]%mod+mod)%mod;
    int res=c(n,m);
    for(int i=h[k];i;i=e[i].nxt)
        if(e[i].to==f)
            res=(res-c(n-s[k],m)+mod)%mod;
        else
            res=(res-c(s[e[i].to],m)+mod)%mod;
    sum=(sum+1ll*res*n%mod)%mod;
    ans=(ans+sum)%mod;
    sum=(sum-1ll*res*n%mod+mod)%mod;
    res=(res-c(n,m)+mod)%mod;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        res=(res+c(n-s[e[i].to],m))%mod;
        res=(res+c(s[e[i].to],m))%mod;
        sum=(sum+1ll*res*(n-s[e[i].to])%mod)%mod;
        dfs2(e[i].to,k);
        sum=(sum-1ll*res*(n-s[e[i].to])%mod+mod)%mod;
        res=(res-c(n-s[e[i].to],m)+mod)%mod;
        res=(res-c(s[e[i].to],m)+mod)%mod;
    }
    sum=(sum+1ll*dp[k]*s[k]%mod)%mod;
}
int main()
{
    n=read(),m=read();
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=pw(fac[n],mod-2);
    for(int i=n-1;i>=1;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs1(1,0);
    dfs2(1,0);
    cout<<ans<<'\n';
    return 0;
}