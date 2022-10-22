#include <bits/stdc++.h>
#define N 1000005
using namespace std;
typedef long long ll;
struct edge
{int u,v;ll c;};
int n,k,m,l,par[N],nxt[N],h[N],use[N],pe[N];
int p[N][25];
edge a[N];
ll dp[N],ans;
vector<int> g[N];
int fi(int x)
{
    if(par[x]==x) return x;
    return par[x]=fi(par[x]);
}
void un(int x,int y)
{
    x=fi(x),y=fi(y);
    if(x==y) return;
    par[y]=x;
}
void dfs(int v,int pp)
{
    for(auto &it : g[v]){
        if(it==pp) continue;
        p[it][0]=v;
        h[it]=h[v]+1;
        dfs(it,v);
    }
}
int color(int s,int e,ll x)
{
    if(h[s]<=h[e]) return s;
    if(!dp[s]) dp[s]=x;
    return nxt[s]=color(nxt[s],e,x);
}
int getlca(int u,int v)
{
    if(h[u]>=h[v])
        swap(u,v);
    int d=h[v]-h[u];
    for(int bit=0;bit<=20;bit++)
        if(d&(1<<bit))
            v=p[v][bit];
    if(u==v) return u;
    for(int bit=20;bit>=0;bit--)
        if(p[u][bit]&&p[v][bit]&&p[u][bit]!=p[v][bit])
            u=p[u][bit],v=p[v][bit];
    if(u==v) return u;
    return p[u][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1,u,v;i<=k;i++){
        cin>>u>>v;
        a[l++]={u,v,0};
    }
    for(int i=1,u,v,c;i<=m;i++){
        cin>>u>>v>>c;
        a[l++]={u,v,c};
    }
    for(int i=0;i<l;i++){
        int u=a[i].u,v=a[i].v;
        if(fi(u)!=fi(v)){
            g[u].push_back(v);
            g[v].push_back(u);
            use[i]=true;
            //cout<<u<<" "<<v<<" "<<i<<" use"<<endl;
            un(u,v);
        }
    }
    h[1]=1;
    dfs(1,0);
    for(int bit=1;bit<=20;bit++)
        for(int i=1;i<=n;i++)
            p[i][bit]=p[p[i][bit-1]][bit-1];
    for(int i=1;i<=n;i++)
        nxt[i]=p[i][0];
    for(int i=0;i<l;i++){
        if(use[i]) continue;
        int u=a[i].u,v=a[i].v,pu=getlca(u,v);
        //if(h[u]<h[v]) swap(u,v);
        //cout<<u<<" "<<p<<" "<<a[i].c<<" coloring start"<<endl;
        color(u,pu,(ll)a[i].c);
        //cout<<v<<" "<<p<<" "<<a[i].c<<" coloring start"<<endl;
        color(v,pu,(ll)a[i].c);
    }
    for(int i=0;i<l;i++){
        if(a[i].c) continue;
        int u=a[i].u,v=a[i].v;
        if(h[u]>=h[v]) swap(u,v);
        if(!dp[v]){
            cout<<-1;
            return 0;
        }
        ans+=dp[v];
    }
    cout<<ans;
    return 0;
}