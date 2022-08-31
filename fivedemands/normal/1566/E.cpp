#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n,m;
vector<int>adj[N];
int sz;
int v[N];
int dfs(int id,int p){
	int sum=0;
	for(auto c:adj[id]){
		if(c==p) continue;
		sum+=dfs(c,id);
	}
	if(sum==0){
		return 1;
	}
	else{
		v[++sz]=sum;
		return 0;
	}
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) adj[i].clear();
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sz=0;
	dfs(1,0);
	int ans=1;
	for(int i=1; i<=sz ;i++) ans+=v[i]-1;
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}