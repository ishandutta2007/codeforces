#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll mi,mx;
int sz[300001];
vector<pair<int,int> >adj[300001];
int n;
void dfs(int id,int p,ll w){
	sz[id]=1;
	for(auto cur:adj[id]){
		if(cur.se==p) continue;
		dfs(cur.se,id,cur.fi);
		sz[id]+=sz[cur.se];
	}
	if(sz[id]%2==1) mi+=w;
	mx+=w*min(sz[id],n-sz[id]);
}
void solve(){
	cin >> n;n*=2;
	for(int i=1; i<=n ;i++) adj[i].clear();
	mi=0,mx=0;
	for(int i=1; i<n ;i++){
		int u,v,w;cin >> u >> v >> w;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
	dfs(1,0,0);
	cout << mi << ' ' << mx << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}