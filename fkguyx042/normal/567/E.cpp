#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <algorithm>
using namespace std ;
#pragma comment(linker, "/STACK:102400000,102400000")
#define LL __int64
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
const int MAXN=100000+10;
int head[MAXN], cnt, source, sink, vis[MAXN], ok[MAXN];
LL d[2][MAXN];
struct N
{
        int u, v;
        LL w;
}fei[MAXN];
struct node
{
        int u, v, next;
        LL w;
}edge[MAXN];
void add(int u, int v, LL w)
{
        edge[cnt].v=v;
        edge[cnt].w=w;
        edge[cnt].next=head[u];
        head[u]=cnt++;
}
void init(int n, int x)
{
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=1;i<=n;i++){
                d[x][i]=(LL)1e15;
        }
}
struct Heap
{
        LL w;
        int id;
        Heap () {}
        Heap(LL w, int id): w(w),id(id) {}
        bool operator < (const Heap &a) const{
                return w>a.w;
        }
};
priority_queue<Heap>q;
void dijk(int x, int st)
{
        memset(vis,0,sizeof(vis));
        while(!q.empty()) q.pop();
        q.push(Heap(0,st));
        d[x][st]=0;
        while(!q.empty()){
                int u=q.top().id;
                q.pop();
                if(vis[u]) continue ;
                vis[u]=1;
                for(int i=head[u];i!=-1;i=edge[i].next){
                        int v=edge[i].v;
                        if(d[x][v]>d[x][u]+edge[i].w){
                                d[x][v]=d[x][u]+edge[i].w;
                                q.push(Heap(d[x][v],v));
                        }
                }
        }
}
int dfn[MAXN], low[MAXN], indx;
vector<pair<int,int> >G[MAXN];
void init1(int n)
{
        memset(dfn,0,sizeof(dfn));
        indx=0;
        memset(ok,0,sizeof(ok));
        for(int i=1;i<=n;i++){
                G[i].clear();
        }
}
void tarjan(int u, int fa)
{
        dfn[u]=low[u]=++indx;
        int flag=0;
        for(int i=0;i<G[u].size();i++){
                int v=G[u][i].first;
                if(v==fa&&!flag){
                        flag=1;
                        continue ;
                }
                if(!dfn[v]){
                        tarjan(v,u);
                        low[u]=min(low[u],low[v]);
                        if(dfn[u]<low[v]){
                                ok[G[u][i].second]=1;
                        }
                }
                else low[u]=min(low[u],dfn[v]);
        }
}
int main()
{
        int n, m, i, u, v, j;
        LL w;
        while(scanf("%d%d%d%d",&n,&m,&source,&sink)!=EOF){
                init(n,0);
                for(i=0;i<m;i++){
                        scanf("%d%d%I64d",&fei[i].u,&fei[i].v,&fei[i].w);
                        add(fei[i].u,fei[i].v,fei[i].w);
                }
                dijk(0,source);
                init(n,1);
                for(i=0;i<m;i++){
                        add(fei[i].v,fei[i].u,fei[i].w);
                }
                dijk(1,sink);
                init1(n);
                for(i=0;i<m;i++){
                        u=fei[i].u;
                        v=fei[i].v;
                        if(d[0][u]+d[1][v]+fei[i].w==d[0][sink]){
                                G[u].push_back(make_pair(v,i));
                                G[v].push_back(make_pair(u,i));
                        }
                }
                tarjan(source,-1);
                for(i=0;i<m;i++){
                        if(ok[i]){
                                puts("YES");
                                continue ;
                        }
                        u=fei[i].u;v=fei[i].v;
                        w=d[0][sink]-d[0][u]-d[1][v];
                        w--;
                        if(w<=0) puts("NO");
                        else printf("CAN %I64d\n",fei[i].w-w);
                }
        }
        return 0;
}