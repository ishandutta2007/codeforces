#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define N 200020
const int inf=0x3f3f3f3f;
typedef long long ll;
const int mod=998244353;
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
int n,m,x[N],y[N];
vector<pair<int,int> > G[N*20];
ll dis[N*20],ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
void Dijkstra(int S){
	static int vis[N*20];
	memset(vis,0,sizeof(vis));
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
		int u=read(),v=read();
		G[u].emplace_back(v,1);
		G[v+n].emplace_back(u+n,1);
		G[v].emplace_back(u+n,inf+1);
		G[u+n].emplace_back(v,inf+1);
		x[i]=u,y[i]=v;
	}
	Dijkstra(1);
	dis[n]=min(dis[n],dis[n<<1]);
	if(dis[n]/inf>=18){
		printf("%d\n",(qpow(2,dis[n]/inf)-1+dis[n]%inf)%mod);
		return 0;
	}
	for(int i=1;i<=n<<1;++i){
		G[i].clear();
	}
	for(int i=1;i<=m;++i){
		int u=x[i],v=y[i];
		for(int j=0;j<=18;++j){
			if(j&1){
				G[j*n+v].emplace_back(j*n+u,1);
				if(j<18){
					G[j*n+u].emplace_back((j+1)*n+v,1+(1<<j));
				}
			}
			else{
				G[j*n+u].emplace_back(j*n+v,1);
				if(j<18){
					G[j*n+v].emplace_back((j+1)*n+u,1+(1<<j));
				}
			}
		}
	}
	ans=1LL*inf*inf;
	Dijkstra(1);
	for(int j=0;j<=18;++j){
		ans=min(ans,dis[j*n+n]);
	}
	printf("%lld\n",ans%mod);
	return 0;
}