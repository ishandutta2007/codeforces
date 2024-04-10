#include<bits/stdc++.h>
using namespace std;
#define N 300100
typedef long long ll;
typedef pair<int,int> pii;
int n,m,ban[N];
vector<int> G[N];
vector<pii> E;
int cnt[N],ans;
void topo(){
	static int d[N];
	queue<int> q;
	for(int i=1;i<=n;++i){
		d[i]=0;
	}
	for(int u=1;u<=n;++u){
		for(auto v:G[u])++d[v];
	}
	int myh=0;
	for(int i=1;i<=n;++i){
		if(!d[i])q.push(i),++myh;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(q.size()<=1)cnt[u]+=n-myh;
		if(q.size()==1){
			int t=q.front();
			for(auto v:G[t]){
				if(d[v]==1){
					ban[u]=1;
					break;
				}
			}
		}
		for(auto v:G[u]){
			if(!--d[v])q.push(v),++myh;	
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	E.resize(m);
	for(int i=0;i<m;++i){
		cin>>E[i].first>>E[i].second;
	}
	for(auto [u,v]:E){
		G[u].push_back(v);
	}
	topo();
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(auto [v,u]:E){
		G[u].push_back(v);	
	}
	topo();
	for(int i=1;i<=n;++i){
		ans+=cnt[i]>=n-2&&!ban[i];
	}
	cout<<ans<<'\n';
	return 0;
}