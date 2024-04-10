#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
ll w[300001];
ll d[300001],d2[300001];
vector<pair<ll,int> >adj[300001];
ll ans=0;
void dfs(int id,int p){
	for(auto cur:adj[id]){
		if(cur.se==p) continue;
		dfs(cur.se,id);
		d2[id]=max(d2[id],w[cur.se]-cur.fi+d[cur.se]);
		if(d[id]<d2[id]) swap(d[id],d2[id]);
	}
	ans=max(ans,d[id]+d2[id]+w[id]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> w[i];
	for(int i=1; i<n ;i++){
		int u,v;
		ll c;
		cin >> u >> v >> c;
		adj[u].push_back({c,v});
		adj[v].push_back({c,u});
	}
	dfs(1,0);
	cout << ans << endl;
}