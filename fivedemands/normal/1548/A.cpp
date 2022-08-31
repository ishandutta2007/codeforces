#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
set<int>adj[N];
int ans=0;
void upd(int i,int v){
	if(!adj[i].empty() && *adj[i].rbegin()>i) ans+=v;
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		cin >> a[i] >> b[i];
		adj[a[i]].insert(b[i]);
		adj[b[i]].insert(a[i]);
	}
	ans=0;
	for(int i=1; i<=n ;i++){
		upd(i,1);
	}
	int q;cin >> q;
	for(int i=1; i<=q ;i++){
		int t;cin >> t;
		if(t==1){
			int x,y;cin >> x >> y;
			upd(x,-1);upd(y,-1);
			adj[x].insert(y);
			adj[y].insert(x);
			upd(x,1);upd(y,1);
		}
		if(t==2){
			int x,y;cin >> x >> y;
			upd(x,-1);upd(y,-1);
			adj[x].erase(y);
			adj[y].erase(x);
			upd(x,1);upd(y,1);
		}
		if(t==3){
			cout << n-ans << '\n';
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t; while(t--) solve();
	solve();
}