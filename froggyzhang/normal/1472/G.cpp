#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int inf=0x3f3f3f3f;
typedef long long ll;
int n,m,dis[N],c[N],d[N];
vector<int> G[N],H[N];
vector<pair<int,int> > E;
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		G[i].clear(),H[i].clear();
		dis[i]=inf;
		c[i]=inf;
		d[i]=0;
	}
	E.clear();
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		E.emplace_back(u,v);
		G[u].push_back(v);
	}
	queue<int> q;
	q.push(1);
	dis[1]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G[u]){
			if(dis[v]==inf){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	for(int u=1;u<=n;++u){
		c[u]=dis[u];
		for(auto v:G[u]){
			c[u]=min(c[u],dis[v]);		
		}
	}
	for(auto [u,v]:E){
		if(dis[v]>dis[u]){
			H[v].push_back(u);
			++d[u];
		}	
	}
	for(int u=1;u<=n;++u){
		if(!d[u])q.push(u);	
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:H[u]){
			c[v]=min(c[v],c[u]);
			if(!--d[v])q.push(v);
		}
	}
	for(int i=1;i<=n;++i){
		cout<<c[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}