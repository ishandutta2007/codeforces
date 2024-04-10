#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,k;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
set<pair<int,int> > G[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].emplace(v,w);
		G[v].emplace(u,w);
	}
	for(int i=1;i<=n;++i){
		if(G[i].size()==1)q.emplace((G[i].begin()->second),i);	
	}
	int ans=0;
	while(q.size()>2||k<n){
		auto [dis,u]=q.top();
		q.pop();
		--n;
		auto [v,w]=*G[u].begin();
		ans=max(ans,dis);
		G[v].erase(G[v].lower_bound(make_pair(u,w)));
		if(G[v].size()==1){
			q.emplace(dis+(G[v].begin()->second),v);	
		}
	}
	cout<<ans<<'\n';
	return 0;
}