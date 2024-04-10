#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int>adj[100001];
int g[100001];
vector<int>ans;
void dfs(int id,int p,int o,int e,int d){
	if(d%2==0){
		if(o!=g[id]){
			o^=1;
			ans.push_back(id);
		}
	}
	else{
		if(e!=g[id]){
			e^=1;
			ans.push_back(id);
		}
	}
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs(cur,id,o,e,d+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=2; i<=n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n ;i++){
		cin >> g[i];
	}
	for(int i=1; i<=n ;i++){
		int x;cin >> x;g[i]^=x;
	}
	dfs(1,0,0,0,0);
	cout << ans.size() << '\n';
	for(auto cur:ans){
		cout << cur << '\n';
	}
}