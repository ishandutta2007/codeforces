#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int ans[N],n,m,a[N],vis[N];
struct Edge{
	int to,id,h;
};
vector<Edge> G[N];
void dfs(int u){
	vis[u]=1;
	for(auto [v,id,t]:G[u]){
		if(vis[v])continue;
		dfs(v);
		ans[id]=t*a[v];
		a[u]+=a[v];
		a[v]=0;
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back({v,i,1});
		G[v].push_back({u,i,-1});
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			dfs(i);
			if(a[i]){
				cout<<"Impossible\n";
				return 0;
			}	
		}
	}
	cout<<"Possible\n";
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}