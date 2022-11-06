#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define int long long
using namespace std;
struct node{
    int x,y,v,id;
    bool operator <(const node a)const{return v<a.v;}
}p[N];
int nxt[N<<1],to[N<<1],head[N],cnt;
int deg[N],w[N];
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    deg[u]++;
    head[u]=cnt;
}
int tot;
void dfs(int u,int f)
{
    if(f && deg[u]==1){++tot;p[u]=(node){tot,tot+1,w[u],u};return;}
    int l=tot+1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==f) continue;
        dfs(v,u);
    }
    p[u]=(node){l,tot+1,w[u],u};
}
int fa[N];
int find(int x){return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}
signed main()
{
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]),fa[i]=i;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        add(u,v),add(v,u);
    }
    dfs(1,0);
    sort(p+1,p+n+1);
    memset(w,0,sizeof(w));
    int ans=0,tot=0;
    for(int i=1;i<=n;)
    {
        int j=i;
        for(;j<=n && p[j].v==p[i].v;j++);
        for(int k=i;k<j;k++)
        if(find(p[k].x)!=find(p[k].y)) w[p[k].id]=true,++tot;
        for(int k=i;k<j;k++)
        if(find(p[k].x)!=find(p[k].y))
        {
            fa[find(p[k].x)]=find(p[k].y);
            ans+=p[k].v;
        }
        i=j;
    }
    printf("%lld %lld\n",ans,tot);
    for(int i=1;i<=n;i++)
    if(w[i]) printf("%lld ",i);
    return 0; 
}