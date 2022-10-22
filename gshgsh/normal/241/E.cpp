#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 1001
#define MAXM 20001
int N,M,u[MAXM],v[MAXM],fst[MAXN],cnt,to[MAXM],len[MAXM],nxt[MAXM],dis[MAXN],tot[MAXN];bool vis[MAXN][2],in[MAXN];
void add(int u,int v,int l){to[++cnt]=v,len[cnt]=l,nxt[cnt]=fst[u],fst[u]=cnt;}
int main()
{
	cin>>N>>M;For(i,1,M)cin>>u[i]>>v[i],add(u[i],v[i],0);queue<int>q;q.push(1);vis[1][0]=1;while(!q.empty()){int u=q.front();q.pop();FOR(i,u)if(!vis[to[i]][0])vis[to[i]][0]=1,q.push(to[i]);}
	memset(fst,0,sizeof(fst));cnt=0;For(i,1,M)add(v[i],u[i],0);q.push(N);vis[N][1]=1;while(!q.empty()){int u=q.front();q.pop();FOR(i,u)if(!vis[to[i]][1])vis[to[i]][1]=1,q.push(to[i]);}
	memset(fst,0,sizeof(fst));cnt=0;For(i,1,N)add(0,i,0);For(i,1,M)if(vis[u[i]][0]&&vis[v[i]][1])add(u[i],v[i],2),add(v[i],u[i],-1);memset(dis,0x3f,sizeof(dis));dis[0]=0;q.push(0);in[0]=1;
	while(!q.empty()){int u=q.front();q.pop();in[u]=0;tot[u]++;if(tot[u]>N){cout<<"No\n";return 0;}FOR(i,u)if(dis[to[i]]>dis[u]+len[i])dis[to[i]]=dis[u]+len[i],!in[to[i]]?q.push(to[i]),0:0;}
	cout<<"Yes\n";For(i,1,M)cout<<(vis[u[i]][0]&&vis[v[i]][1]?dis[v[i]]-dis[u[i]]:1)<<endl;return 0;
}