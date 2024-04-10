#include<bits/stdc++.h>
using namespace std;
#define N 800080
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
int n,m;
ll dis[N];
vector<pair<int,int> > G[N];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void Dijkstra(int S){
	static int vis[N];
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0;
	q.push(make_pair(0LL,S));
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
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		for(int j=0;j<4;++j){
			G[j*n+u].emplace_back(j*n+v,w);
			G[j*n+v].emplace_back(j*n+u,w);
		}
		G[u].emplace_back(3*n+v,w);
		G[v].emplace_back(3*n+u,w);
		for(int j=0;j<2;++j){
			G[j*n+u].emplace_back((j+2)*n+v,w<<1);
			G[j*n+v].emplace_back((j+2)*n+u,w<<1);
		}
		for(int j=0;j<4;j+=2){
			G[j*n+u].emplace_back((j+1)*n+v,0);
			G[j*n+v].emplace_back((j+1)*n+u,0);
		}
	}
	Dijkstra(1);
	for(int i=2;i<=n;++i){
		printf("%lld ",dis[3*n+i]);
	}
	return 0;
}