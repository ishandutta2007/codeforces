#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
struct edge
{
    int nxt,to;
}e[2001<<1];
int n,m,tot,ans,h[2001],dp[2001],a[2001];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f,int root)
{
    if(a[k]-a[root]>m||a[k]<a[root]||(a[k]==a[root]&&k<root))
        return;
    dp[k]=1;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k,root);
        dp[k]=1ll*dp[k]*(dp[e[i].to]+1)%mod;
    }
}
int main()
{
    cin>>m>>n;
    for(register int i=1;i<=n;++i)
        cin>>a[i];
    for(register int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(register int i=1;i<=n;++i)
    {
        for(register int j=1;j<=n;++j)
            dp[j]=0;
        dfs(i,0,i);
        ans=(ans+dp[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}