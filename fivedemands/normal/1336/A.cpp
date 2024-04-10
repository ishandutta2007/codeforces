#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
ll a[1000001],b[1000001];
int d[1000001],sz[1000001];
vector<int>adj[1000001];
void dfs(int id,int p){
	sz[id]=1;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		d[cur]=d[id]+1;
		dfs(cur,id);
		sz[id]+=sz[cur];
	}
	a[id]=d[id]-sz[id]+1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	cin >> n >> m;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ll ans=0;
	for(int i=1; i<=m ;i++){
		ans+=a[i];
	}
	cout << ans << endl;
}