#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;

int n,m,x,y;
ll a[N],sz[N];
vector<int>adj[N];
void dfs(int id,int p){
	sz[id]=1;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs(cur,id);
		sz[id]+=sz[cur];
	}
}
void solve(){
	cin >> n >> x >> y;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(x,0);
	ll cur=sz[y];
	dfs(y,0);
	cur=cur*sz[x];
	cout << 1LL*n*(n-1)-cur << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	solve();
}