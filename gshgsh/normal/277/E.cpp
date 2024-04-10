#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=now[u];i;i=nxt[i])
#define INF 0x3fffffff
#define MAXN 1001
#define MAXM 1000001
int N,x[MAXN],y[MAXN],s,t,fst[MAXN],now[MAXN],cnt=1,to[MAXM],nxt[MAXM],flow[MAXM],ans;double len[MAXM],dis[MAXN],cost;bool in[MAXN],vis[MAXN];string a;
void add(int u,int v,double l,int f){to[++cnt]=v,len[cnt]=l,flow[cnt]=f,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,len[cnt]=-l,flow[cnt]=0,nxt[cnt]=fst[v],fst[v]=cnt;}
double dist(int a,int b){return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));}
bool spfa()
{
	For(i,s,t)dis[i]=1e18;memset(in,0,sizeof(in));memset(vis,0,sizeof(vis));queue<int>q;dis[s]=0;q.push(s);in[s]=1;
	while(!q.empty()){int u=q.front();q.pop();in[u]=0;now[u]=fst[u];FOR(i,u)if(flow[i]&&dis[to[i]]>dis[u]+len[i]){dis[to[i]]=dis[u]+len[i];if(!in[to[i]])q.push(to[i]),in[to[i]]=1;}}return abs(dis[t]-1e18)>1e-6;
}
int dfs(int u,int in)
{
	if(u==t||!in)return in;int tmp,ans=0;vis[u]=1;
	FOR(i,u)if(!vis[to[i]]&&flow[i]&&abs(dis[to[i]]-dis[u]-len[i])<=1e-6){now[u]=i;tmp=dfs(to[i],min(in,flow[i]));if(!tmp)vis[to[i]]=1;else in-=tmp,ans+=tmp,flow[i]-=tmp,flow[i^1]+=tmp,cost+=tmp*len[i];if(!in)break;}vis[u]=0;return ans;
}
int main(){cin>>N,s=0,t=2*N+1;For(i,1,N)cin>>x[i]>>y[i],add(s,i,0,2),add(i+N,t,0,1);For(i,1,N)For(j,1,N)if(y[i]>y[j])add(i,j+N,dist(i,j),1);while(spfa())ans+=dfs(s,INF);if(ans!=N-1){cout<<-1<<endl;return 0;}printf("%.12lf\n",cost);return 0;}