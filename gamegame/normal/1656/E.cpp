#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n;
vector<int>adj[N];
int a[N];
bool b[N];
void dfs(int id,int p){
	for(auto c:adj[id]){
		if(c==p) continue;
		if(a[id]>=0) a[c]=-(int)adj[c].size();
		else a[c]=adj[c].size();
		dfs(c,id);
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
	a[1]=adj[1].size();
	dfs(1,0);
	for(int i=1; i<=n ;i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}