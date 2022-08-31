#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll mod=1e9+7;
ll n,m,k;
vector<int>adj[N];
ll sz[N];
void dfs(int id,int p){
	sz[id]=1;
	for(auto c:adj[id]){
		if(c==p) continue;
		dfs(c,id);
		sz[id]+=sz[c];
	}
}
ll pr[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) adj[i].clear();
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1; i<=n ;i++){
		sz[i]=sz[i]*(n-sz[i]);
	}
	sort(sz+1,sz+n+1);
	cin >> m;
	for(int i=1; i<=m ;i++) cin >> pr[i];pr[++m]=1;
	
	while(m<n){
		pr[++m]=1;
	}
	sort(pr+1,pr+m+1);
	while(m>n){
	    pr[m-1]=pr[m-1]*pr[m]%mod;
	    m--;
	}
	ll ans=0;
	for(int i=2; i<=n ;i++){
		ans+=sz[i]%mod*pr[i];
		ans%=mod;
	}
	cout << ans%mod << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}