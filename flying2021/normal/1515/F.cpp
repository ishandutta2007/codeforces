#include<iostream>
#include<cstdio>
#include<cstring>
#define N 300010
#define ll long long
using namespace std;
int nxt[N<<1],to[N<<1],id[N<<1],head[N],cnt;
void add(int u,int v,int w)
{
    nxt[++cnt]=head[u];id[cnt]=w;
    to[cnt]=v;head[u]=cnt;
}
int f[N];
int find(int x){return f[x]==x?f[x]:(f[x]=find(f[x]));}
ll s[N],c[N],x;
int ans[N],la=1,ra=N;
void dfs(int u,int p)
{
    s[u]=c[u];
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        dfs(v,u);
        if(s[v]+s[u]>=x) ans[la++]=id[i],s[u]+=s[v]-x;
        else ans[ra--]=id[i];
    }
}
int main()
{
    int n,m;
    scanf("%d%d%lld",&n,&m,&x);
    ll s=0;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]),f[i]=i,s+=c[i];
    if(s<x*(n-1)){puts("NO");return 0;}
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(find(u)==find(v)) continue;
        f[find(u)]=find(v);
        add(u,v,i),add(v,u,i);
    }
    ra=n-1;
    dfs(1,0);
    puts("YES");
    for(int i=1;i<n;i++) printf("%d\n",ans[i]);
    return 0;
}