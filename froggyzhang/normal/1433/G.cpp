#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define N 1005
const int inf=0x3f3f3f3f;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,k,a[N],b[N],dis[N][N],ans,x[N],y[N];
vector<pair<int,int> > G[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void Dijkstra(int S,int *dis){
	static bool vis[N];
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(x));
	dis[S]=0;
	q.push(make_pair(0,S));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:G[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
		x[i]=u,y[i]=v;
	}
	for(int i=1;i<=k;++i){
		a[i]=read(),b[i]=read();
	} 
	for(int i=1;i<=n;++i){
		Dijkstra(i,dis[i]);
	} 
	ans=inf;
	for(int i=1;i<=m;++i){
		int tmp=0;
		for(int j=1;j<=k;++j){
			tmp+=min(dis[a[j]][b[j]],min(dis[a[j]][x[i]]+dis[b[j]][y[i]],dis[a[j]][y[i]]+dis[b[j]][x[i]]));
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}