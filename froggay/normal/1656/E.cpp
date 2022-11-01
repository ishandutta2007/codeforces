#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int ans[N],n,dep[N];
vector<int> G[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
	ans[u]=(dep[u]&1?1:-1)*G[u].size();
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<' ';
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