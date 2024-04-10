#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
ll ans=0;
vector<int>adj[100001];
int n;
ll x[100001];
void dfs(int id,int p,vector<pair<ll,int> >bk){
	for(auto idd:adj[id]){
		if(idd==p) continue;
		vector<pair<ll,int> >newi;
		ll g=x[idd];
		newi.push_back({g,1});
		ans=(ans+g)%mod;
		for(auto cur:bk){
			g=gcd(g,cur.fi);
			if(g==newi.back().fi) newi.back().se+=cur.se;
			else newi.push_back({g,cur.se});
			ans=(ans+g*cur.se)%mod;
		}
		dfs(idd,id,newi);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> x[i];
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ans=(ans+x[1])%mod;
	vector<pair<ll,int> >empty;
	empty.push_back({x[1],1});
	dfs(1,0,empty);
	cout << ans << endl;
}