#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
//min cost feasible flow
namespace MCFF{
    typedef long long typ;
    #define N 3010
    #define M 10010
    #define inf 1000000000
    #define winf 10000000000000ll
    struct road{
        int nxt,to,f;
        typ w;
    }r[N<<1];
    int head[N],cnt=1;
    int deg[N];
    int cur[N],all;
    int add(int u,int v,int f,int w)
    {
        all=max(all,max(u,v));
        r[++cnt]=(road){head[u],v,f,w};head[u]=cnt;
        r[++cnt]=(road){head[v],u,0,-w};head[v]=cnt;
        return cnt;
    }
    void add(int u,int v,int l,int r,int w)//u->v (f,w) F\in[l,r]
    {
        deg[u]-=l;deg[v]+=l;
        add(u,v,r-l,w);
    }
    bool vis[N];
    struct node{
        int u;typ v;
        node(int U=0,typ V=0):u(U),v(V){}
        bool operator <(const node a)const{return v>a.v;}
    };
    priority_queue<node>q;
    typ dis[N],tag[N];
    bool dij(int s,int t)
    {
        for(int i=1;i<=all;i++) dis[i]=winf,cur[i]=head[i];
        dis[t]=0;
        q.push(node(t,0));
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
                fl-=f;res+=f;
                r[i].f-=f;r[i^1].f+=f;
                if(!fl) break;
            }
        }
        vis[u]=false;
        return res;
    }
    int maxf,exflow;typ minw;
    void work(int s,int t){while(dij(s,t)){int w=dfs(s,t,inf);maxf+=w;minw+=1ll*w*tag[s];}}
    int S,T;
    void init()
    {
        S=all+1,T=all+2;all+=2;
        for(int i=1;i<=all-2;i++)
        if(deg[i]>0) exflow+=deg[i],add(S,i,deg[i],0);
        else if(deg[i]<0) add(i,T,-deg[i],0);
    }
    bool solve()
    {
        work(S,T);
        if(maxf!=exflow) return false;
        return true;
    }
}
char s1[N],s2[N];
int id[M][2];
int main()
{
    int n1,n2,m,r,b;
    scanf("%d%d%d%d%d",&n1,&n2,&m,&r,&b);
    scanf("%s%s",s1+1,s2+1);
    int s=n1+n2+1,t=s+1;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        id[i][0]=MCFF::add(u,v+n1,1,r);
        id[i][1]=MCFF::add(v+n1,u,1,b);
    }
    for(int i=1;i<=n1;i++)
    {
        if(s1[i]!='B') MCFF::add(s,i,1,inf,0);
        if(s1[i]!='R') MCFF::add(i,t,1,inf,0);
    }
    for(int i=1;i<=n2;i++)
    {
        if(s2[i]!='R') MCFF::add(s,i+n1,1,inf,0);
        if(s2[i]!='B') MCFF::add(i+n1,t,1,inf,0);
    }
    MCFF::add(t,s,0,inf,0);
    MCFF::init();
    if(!MCFF::solve()) puts("-1");
    else
    {
        printf("%lld\n",MCFF::minw);
        for(int i=1;i<=m;i++)
        if(MCFF::r[id[i][0]].f) putchar('R');
        else if(MCFF::r[id[i][1]].f) putchar('B');
        else putchar('U');
    }
    return 0;
}