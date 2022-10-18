#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
struct edge
{
    int nxt,to;
}e[2001<<1];
const long long mod=1000000007;
long long n,tot,h[2001],dep[2001],fac[2001],inv[2001],s[2001],fa[2001][11],dp[2001][2001],sum;
map<long long,long long> mp;
inline long long read()
{
    long long x=0;
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
long long pw(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline long long c(int x,int y)
{
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void dfs(int k,int f,int deep)
{
    dep[k]=deep;
    s[k]=1;
    fa[k][0]=f;
    for(register int i=1;i<=8;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k,deep+1);
        s[k]+=s[e[i].to];
    }
}
inline int lca(int x,int y)
{
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(register int d=dep[x]-dep[y],i=0;1<<i<=d;++i)
        if(d&(1<<i))
            x=fa[x][i];
    if(x==y)
        return x;
    for(register int i=8;~i;--i)
        if(fa[x][i]^fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
int main()
{
    n=read();
    for(register int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    fac[0]=inv[0]=1;
    for(register int i=1;i<=n;++i)
        fac[i]=fac[i-1]*i%mod;
    inv[n]=pw(fac[n],mod-2);
    for(register int i=n-1;i;--i)
        inv[i]=inv[i+1]*(i+1)%mod;
    for(register int i=1;i<=n;++i)
        dp[0][i]=1;
    dfs(1,0,1);
    int node=1;
    for(register int i=1;i<=n;++i)
        if(dep[i]>dep[node])
            node=i;
    dfs(node,0,1);
    for(register int i=1;i<=n;++i)
        if(dep[i]>dep[node])
            node=i;
    for(register int i=1;i<=dep[node];++i)
        for(register int j=1;j<=dep[node];++j)
            for(register int k=0;k<j;++k)
            {
                if(!mp[mod-1-i-k])
                    mp[mod-1-i-k]=pw(2,mod-1-i-k);
                dp[i][j]=(dp[i][j]+mp[mod-1-i-k]*c(i+k-1,k)%mod)%mod;
            }
    for(register int i=1;i<=n;++i)
    {
        dfs(i,0,1);
        sum=(sum+(i-1)*pw(n,mod-2)%mod)%mod;
        for(register int j=1;j<n;++j)
            if(i!=j)
                for(register int k=j+1;k<=n;++k)
                    if(i!=k)
                    {
                        int p=lca(j,k);
                        if(p==k)
                        {
                            sum=(sum+pw(n,mod-2))%mod;
                            continue;
                        }
                        if(p==j)
                            continue;
                        sum=(sum+dp[dep[k]-dep[p]][dep[j]-dep[p]]*pw(n,mod-2)%mod)%mod;
                    }
    }
    printf("%lld\n",sum);
    return 0;
}