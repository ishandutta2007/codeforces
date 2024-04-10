#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
int n,m;
ll a[1001];
vector<int>adj[1001];
bool vis[1001];
int st;
int ord[1001];
void dfs(int id){
	if(vis[id]) return;
	vis[id]=true;
	for(auto c:adj[id]){
		dfs(c);
	}
	ord[++st]=id;
}
ll dp[1001];
void solve(){
	cin >> n >> m;st=0;
	for(int i=1; i<=n ;i++){
		adj[i].clear();vis[i]=0;
		cin >> a[i];
	}
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
	}
	for(int i=1; i<=n ;i++){
		dfs(i);
	}
	ll ans=0;
	for(int i=n; i>=2 ;i--){
		int x=ord[i];
		//cout << "doing " << x << endl;
		if(a[x]==0) continue;
		ans+=1;
		ans%=mod;
		for(int j=1; j<=n ;j++){
			int y=ord[j];
			if(!a[y]) continue;
			for(auto c:adj[y]){
				a[c]++;
				if(a[c]>=2*mod) a[c]=a[c]%mod+mod;
			}
			a[y]--;
		}/*
		for(int j=1; j<=n ;j++){
			cout << a[j] << ' ';
		}
		cout << endl;*/
		for(auto c:adj[x]){
			a[c]+=a[x];
			if(a[c]>=2*mod) a[c]=a[c]%mod+mod;
		}
		a[x]=0;
	}
	ans=(ans+a[ord[1]])%mod;
	cout << ans << '\n';
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}