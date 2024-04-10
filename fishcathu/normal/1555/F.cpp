#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3E5+10,M=5E5+10;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
vector<pair<int,bool>>to[N];
vector<pii>_to[N];
int u[M],v[M],lca[M];
int fd[N],fa[N],dfn[N],low[N],q[N],cnt=1;
bool w[M],xr[N],ans[M];
int find(int x){return fd[x]^x?fd[x]=find(fd[x]):x;}
void dfs(int x)
{
    dfn[x]=cnt++;
    for(auto [t,val]:to[x])
    {
        if(!dfn[t])
        {
            fa[t]=x;
            xr[t]=xr[x]^val;
            dfs(t);
            fd[t]=x;
        }
    }
    low[x]=cnt;
    for(auto [t,i]:_to[x])
    {
        if(fd[t]^t)
        {
            lca[i]=find(t);
        }
    }
}
int sum(int x)
{
    int res=0;
    for(int i=dfn[x];i;i-=i&-i)res+=q[i];
    return res;
}
void ins(int u,int v)
{
    while(u^v)
    {
        for(int i=dfn[u];i<N;i+=i&-i)++q[i];
        for(int i=low[u];i<N;i+=i&-i)--q[i];
        u=fa[u];
    }
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)fd[i]=i;
    for(int i=1;i<=m;++i)
    {
        u[i]=read();
        v[i]=read();
        w[i]=read();
        int l=find(u[i]),r=find(v[i]);
        if(l^r)
        {
            to[u[i]].pb({v[i],w[i]});
            to[v[i]].pb({u[i],w[i]});
            fd[r]=l;
            ans[i]=1;
        }
        else
        {
            _to[u[i]].pb({v[i],i});
            _to[v[i]].pb({u[i],i});
        }
    }
    for(int i=1;i<=n;++i)fd[i]=i;
    for(int i=1;i<=n;++i)
    {
        if(!dfn[i])
        {
            dfs(i);
        }
    }
    for(int i=1;i<=m;++i)
    {
        if(ans[i]||xr[u[i]]^xr[v[i]]^w[i]^1)continue;
        if(sum(u[i])+sum(v[i])-sum(lca[i])*2)continue;
        ins(u[i],lca[i]);
        ins(v[i],lca[i]);
        ans[i]=1;
    }
    for(int i=1;i<=m;++i)puts(ans[i]?"YES":"NO");
}