#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define N 300010
#define ll long long
using namespace std;
int nxt[N<<2],to[N<<2],w[N<<2],head[N],cnt;
ll dis[N];
void add(int u,int v,int w1)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    w[cnt]=w1;
    head[u]=cnt;
}
int n;
struct node{
    int u;
    ll v;
    bool operator <(const node a)const{return v>a.v;}
};
priority_queue<node>q;
bool vis[N];
int k;
void dij()
{
    for(int i=1;i<=n;i++) dis[i]=1e16;
    for(int i=1;i<=k;i++) dis[i]=0,q.push((node){i,0});
    while(!q.empty())
    {
        int u=q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i;i=nxt[i])
        {
            int v=to[i];
            if(!vis[v] && dis[v]>dis[u]+w[i])
            {
                dis[v]=dis[u]+w[i];
                q.push((node){v,dis[v]});
            }
        }
    }
}
struct road{
    int x,y;
    ll v;
    bool operator <(const road a)const{return v<a.v;}
}r[N];
ll ans[N];
int f[N];
int find(int x){return x==f[x]?f[x]:(f[x]=find(f[x]));}
struct ques{
    int x,id;
};
vector<ques>qs[N];
int main()
{
    int m,q;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    dij();
    int tm=0;
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=nxt[j])
        if(i<to[j])r[++tm]=(road){i,to[j],dis[i]+w[j]+dis[to[j]]};
    sort(r+1,r+tm+1);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        qs[x].push_back((ques){y,i});
        qs[y].push_back((ques){x,i});
    }
    for(int i=1;i<=tm;i++)
    {
        int x=find(r[i].x),y=find(r[i].y);
        if(x==y) continue;
        if(qs[y].size()>qs[x].size()) swap(x,y);
        for(ques a:qs[y])
        if(find(a.x)==x) ans[a.id]=r[i].v;
        else qs[x].push_back(a);
        qs[y].clear();
        f[y]=x;
    }
    for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    return 0;
}