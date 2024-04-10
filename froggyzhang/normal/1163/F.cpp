#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll dis1[N],dis2[N],jb[N];
int n,m,Q,On[N],p[N],cnt,L[N],R[N];
vector<pair<int,int> > G[N];
pair<int,int> pre[N];
struct Link{
	int x,y,w;
}E[N];
void Dijkstra(int S,ll *dis){
	memset(dis,0x3f,sizeof(ll)*(n+1));
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	static int vis[N];
	memset(vis,0,sizeof(vis));
	q.emplace(0LL,S);
	dis[S]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,id]:G[u]){
			if(dis[v]>dis[u]+E[id].w){
				dis[v]=dis[u]+E[id].w;
				pre[v]=make_pair(u,id);
				q.emplace(dis[v],v);
			}
		}
	}
}
vector<ll> A[N],B[N];
multiset<ll> S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;++i)L[i]=m+2,R[i]=-1;
	for(int i=1;i<=m;++i){
		cin>>E[i].x>>E[i].y>>E[i].w;
		G[E[i].x].emplace_back(E[i].y,i);
		G[E[i].y].emplace_back(E[i].x,i);
	}
	Dijkstra(1,dis1);
	Dijkstra(n,dis2);
	for(int u=1;u^n;u=pre[u].first){
		L[u]=cnt;
		On[pre[u].second]=++cnt;
		R[u]=cnt;
	}
	L[n]=cnt,R[n]=cnt+1;
	for(int i=1;i<=n;++i){
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return dis1[i]<dis1[j];});
	for(int i=1;i<=n;++i){
		int u=p[i];
		for(auto [v,id]:G[u]){
			if(dis1[v]==dis1[u]+E[id].w&&!On[id]){
				L[v]=min(L[v],L[u]);
			}	
		}
	}
	sort(p+1,p+n+1,[&](int i,int j){return dis2[i]<dis2[j];});
	for(int i=1;i<=n;++i){
		int u=p[i];
		for(auto [v,id]:G[u]){
			if(dis2[v]==dis2[u]+E[id].w&&!On[id]){
				R[v]=max(R[v],R[u]);
			}
		}
	}
	for(int i=1;i<=m;++i){
		if(On[i])continue;
		int u=E[i].x,v=E[i].y;
		if(L[u]<R[v]){
			ll len=E[i].w+dis1[u]+dis2[v];
			A[L[u]].push_back(len);
			B[R[v]].push_back(len);
		}
		if(L[v]<R[u]){
			ll len=E[i].w+dis1[v]+dis2[u];
			A[L[v]].push_back(len);
			B[R[u]].push_back(len);	
		}
	}
	for(int i=1;i<=cnt;++i){
		for(auto x:A[i-1])S.insert(x);	
		for(auto x:B[i])S.erase(S.find(x));
		if(!S.empty())jb[i]=*S.begin();
		else jb[i]=inf;
	}
	while(Q--){
		int t,x;
		cin>>t>>x;
		if(!On[t]){
			cout<<min(dis1[n],min(dis1[E[t].x]+dis2[E[t].y]+x,dis1[E[t].y]+dis2[E[t].x]+x))<<'\n';	
		}
		else{
			cout<<min(dis1[n]-E[t].w+x,jb[On[t]])<<'\n';
		}
	}
	return 0;
}