#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
ll a[N],b[N];
vector<int>adj[N];
ll dp1[N],dp2[N];
void dfs(int id,int p){
	for(auto c:adj[id]){
		if(c==p) continue;
		dfs(c,id);
		dp1[id]=max(dp1[id],dp1[c]);
		dp2[id]=max(dp2[id],dp2[c]);
	}
	a[id]+=dp1[id]-dp2[id];
	if(a[id]>0) dp2[id]+=a[id];
	else dp1[id]-=a[id];
//	cout << id << ' ' << dp1[id] << ' ' << dp2[id] << endl;
//	cout << dp1[id] << ' ' << dp2[id] << endl;
}
void solve(){
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n ;i++) cin >> a[i];
	dfs(1,0);
	cout << dp1[1]+dp2[1] << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	solve();
}