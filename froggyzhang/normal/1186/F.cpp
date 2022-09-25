#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
int n,m,c[N],vis[N];
vector<int> G[N];
set<pair<int,int> > S,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		if(u>v)swap(u,v);
		ans.emplace(u,v);
		G[u].push_back(v);
		G[v].push_back(u);	
	}
	for(int i=1;i<=n;++i){
		c[i]=G[i].size()-(G[i].size()+1)/2;
		S.emplace(c[i],i);
	}
	int res=max(0,m-(n+m+1)/2);
	while(res){
		int u=(--S.end())->second;
		S.erase(--S.end());
		sort(G[u].begin(),G[u].end(),[&](int i,int j){return c[i]<c[j];});
		vis[u]=1;
		while(c[u]&&res){
			while(!G[u].empty()&&(!c[G[u].back()]||vis[G[u].back()]))G[u].pop_back();
			if(G[u].empty())break;
			--c[u],--res;
			int v=G[u].back();
			G[u].pop_back();
			auto t=(u<v?make_pair(u,v):make_pair(v,u));
			ans.erase(t);
			S.erase(make_pair(c[v],v));
			--c[v];
			S.insert(make_pair(c[v],v));
		}
	}
	cout<<min(m,(n+m+1)/2)<<'\n';
	for(auto [u,v]:ans){
		cout<<u<<' '<<v<<'\n';
	}
	return 0;
}