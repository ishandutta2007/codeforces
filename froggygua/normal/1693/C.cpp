#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,d[N],dis[N],vis[N];
vector<int> G[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[v].push_back(u);
		++d[u];
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.emplace(0,n);
	memset(dis,0x3f,sizeof(dis));
	dis[n]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:G[u]){
			--d[v];
			int w=dis[u]+d[v]+1;
			if(w<dis[v]){
				dis[v]=w;
				q.emplace(dis[v],v);
			}
		}
	}
	cout<<dis[1]<<'\n';
	return 0;
}