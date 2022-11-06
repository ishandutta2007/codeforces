#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
namespace min_cost_flow{
    #define N 110
    #define M 210
    #define inf 1000000000
    #define winf 1000000000
    struct road{
        int nxt,to,f,w;
    }r[M<<1];
    int head[N],cnt=1;
    void add(int u,int v,int f,int w)
    {
        r[++cnt]=(road){head[u],v,f,w};head[u]=cnt;
        r[++cnt]=(road){head[v],u,0,-w};head[v]=cnt;
    }
    int cur[N],all;
    bool vis[N];
    struct node{
        int u,v;
        node(int U=0,int V=0):u(U),v(V){}
        bool operator <(const node a)const{return v>a.v;}
    };
    priority_queue<node>q;
    int dis[N],tag[N];
    bool dij(int s,int t)
    {
        for(int i=1;i<=all;i++) dis[i]=winf,cur[i]=head[i];
        dis[t]=0;q.push(node(t,0));
        while(!q.empty())
        {
            int u=q.top().u;q.pop();
            if(vis[u]) continue;
            vis[u]=true;
            for(int i=head[u];i;i=r[i].nxt)
            {
                int v=r[i].to,w=tag[u]+r[i^1].w-tag[v];
                if(r[i^1].f && dis[u]+w<dis[v]) dis[v]=dis[u]+w,q.push(node(v,dis[v]));
            }
        }
        for(int i=1;i<=all;i++) tag[i]=min(tag[i]+dis[i],winf);
        if(!vis[s]) return false;
        for(int i=1;i<=all;i++) vis[i]=false;
        return true;
    }
    int dfs(int u,int t,int fl)
    {
        if(u==t || !fl) return fl;
        int res=0;
        vis[u]=true;
        for(int &i=cur[u];i;i=r[i].nxt)
        if(r[i].f)
        {
            int v=r[i].to,f;
            if(!vis[v] && tag[v]+r[i].w==tag[u] && (f=dfs(v,t,min(fl,r[i].f))))
            {
                r[i].f-=f,r[i^1].f+=f;
                res+=f,fl-=f;
                if(!fl) break;
            }
        }
        vis[u]=false;
        return res;
    }
    int maxf,minw;
    void work(int s,int t){while(dij(s,t)){int w=dfs(s,t,inf);maxf+=w,minw+=w*tag[s];}}
}
inline int add(int u,int v,int f,int w){min_cost_flow::add(u,v,f,w);}
int init(int n,int s,int t){min_cost_flow::all=n;min_cost_flow::work(s,t);return min_cost_flow::minw;}
int deg[N];
int main()
{
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,c,f;
        scanf("%d%d%d%d",&u,&v,&c,&f);
        if(c>=f) add(v,u,f,1),add(u,v,c-f,1),add(u,v,inf,2);
        else ans+=f-c,add(v,u,f-c,0),add(v,u,c,1),add(u,v,inf,2);
        deg[u]+=f,deg[v]-=f;
    }
    int s=n+1,t=n+2;
    for(int i=1;i<=n;i++)
    if(deg[i]>=0) add(i,t,deg[i],0);
    else add(s,i,-deg[i],0);
    add(n,1,inf,0);
    printf("%d\n",ans+init(t,s,t));
    return 0;
}