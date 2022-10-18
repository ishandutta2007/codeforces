#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=1000000007;
struct edge
{
    int nxt,to;
}e[200001<<1];
int n,h[200001],cnt,w[200001],ans,tot,dep[200001],sum;
int vis[200001];
inline int pw(int a,int b)
{
    int res=1;
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
void dfs(int k,int f,int deep)
{
    if(vis[k]==1)
    {
        w[++cnt]=dep[f]-dep[k]+1;
        return;
    }
    dep[k]=deep;
    vis[k]=1;
    for(register int i=h[k];i;i=e[i].nxt)
        if(vis[e[i].to]!=-1)
            dfs(e[i].to,k,deep+1);
    vis[k]=-1;
}
signed main()
{
    ans=1;
    scanf("%lld",&n);
    for(register int i=1;i<=n;++i)
    {
        int x;
        scanf("%lld",&x);
        add(i,x);
    }
    for(register int i=1;i<=n;++i)
        if(!vis[i])
            dfs(i,0,1);
    for(register int i=1;i<=cnt;++i)
    {
        ans=ans*((pw(2,w[i])-2+mod)%mod)%mod;
        sum+=w[i];
    }
    ans=ans*pw(2,n-sum)%mod;
    printf("%lld\n",ans);
    return 0;
}