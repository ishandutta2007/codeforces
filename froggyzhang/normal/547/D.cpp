#include<bits/stdc++.h>
using namespace std;
#define N 600020
const int n=200000;
typedef long long ll;
int m,ans[N],vis[N];
vector<pair<int,int> > G[N];
vector<int> cir;
void dfs(int u){
	while(!G[u].empty()){
		auto [v,id]=G[u].back();
		G[u].pop_back();
		if(vis[id])continue;
		vis[id]=1;
		dfs(v);
		cir.push_back(id);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].emplace_back(v+n,i);
		G[v+n].emplace_back(u,i);
	}
	for(int i=1;i<=(n<<1);++i){
		if(G[i].size()&1){
			G[0].emplace_back(i,m+i);
			G[i].emplace_back(0,m+i);
		}
	}
	for(int i=0;i<=(n<<1);++i){
		if(!G[i].empty())dfs(i);	
	}
	for(int i=0;i<(int)cir.size();++i)ans[cir[i]]=i&1;
	for(int i=1;i<=m;++i){
		putchar(ans[i]?'b':'r');
	}
	return 0;
}