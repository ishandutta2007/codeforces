#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long n,x,y,i,j,m,u[100005],v[100005],p[100005],l[100005],pp[100005][20],val[100005]={0};
vl a[100005];
mll w;
void dfs1(long node,long par)
{
    long i;
    p[node]=par;
    l[node]=(par==-1)?1:l[par]+1;
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    dfs1(a[node][i],node);
}
long lca(long u,long v)
{
    long i;
    if(l[u]<l[v]) return lca(v,u);
    for(i=19;i>=0;i--)
    if(l[u]-(1<<i)>=l[v])
    u=pp[u][i];
    if(u==v) return v;
    for(i=19;i>=0;i--)
    if(pp[u][i]!=pp[v][i] && pp[u][i]!=-1) u=pp[u][i],v=pp[v][i];
    return p[u];
}
long dfs2(long node,long par)
{
    long s=0,i;
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    s+=dfs2(a[node][i],node);
    s+=val[node];
    w[{node,par}]=s;
    w[{par,node}]=s;
    return s;
}
int main()
{
    io
    cin>>n;
    for(i=0;i<n-1;++i)
    {
        cin>>u[i]>>v[i];
        x=u[i],y=v[i];
        a[x].pb(y);
        a[y].pb(x);
    }
    cin>>m;
    dfs1(1,-1);
    memset(pp,-1,sizeof(pp));
    for(i=1;i<=n;++i)
    pp[i][0]=p[i];
    for(i=1;i<20;++i)
    for(j=1;j<=n;++j)
    if(pp[j][i-1]!=-1)
    pp[j][i]=pp[pp[j][i-1]][i-1];
    for(i=0;i<m;++i)
    {
        cin>>x>>y;
        val[x]++;val[y]++;
        val[lca(x,y)]-=2;
    }
    dfs2(1,-1);
    for(i=0;i<n-1;++i)
    cout<<w[{u[i],v[i]}]<<" ";
    return 0;
}