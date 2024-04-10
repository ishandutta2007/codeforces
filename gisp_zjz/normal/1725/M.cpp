#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
struct edge{int to,cost;};
vector<edge> G[MAXN];
int n,m;
ll d[MAXN];
void add_edge(int u,int v,int w)
{
    G[u].push_back((edge){v,w});
}
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+2*n+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) add_edge(i,n+i,0);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w); add_edge(n+v,n+u,w);
    }
    dijkstra(1);
    for(int i=2;i<=n;i++)
    {
        ll ans=min(d[i],d[n+i]);
        printf("%lld%c",ans==INF?-1:ans,i==n?'\n':' ');
    }
    return 0;
}