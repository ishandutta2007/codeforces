#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
vector<int>adj[N];
bool ok;
void dfs(int id,int p){
	ll s=-a[id];
	for(auto x:adj[id]){
		if(x==p) continue;
		dfs(x,id);
		a[id]+=a[x];
		s+=b[x];
	}
	//cout << id << ' ' << s << ' ' << b[id] << endl;
	if((s+b[id])%2!=0) ok=false;
	if(s>b[id]) ok=false;
	if(b[id]>a[id]) ok=false;
}
void solve(){
	cin >> n >> m;ok=true;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++) cin >> b[i];
	for(int i=1; i<=n ;i++) adj[i].clear();
	for(int i=1; i<n ;i++){
		int x,y;cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}