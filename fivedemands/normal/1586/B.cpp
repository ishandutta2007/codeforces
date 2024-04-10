#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++) a[i]=false;
	for(int i=1; i<=m ;i++){
		int u,v,w;cin >> u >> v >> w;
		a[v]=true;
	}
	for(int i=1; i<=n ;i++){
		if(!a[i]){
			for(int j=1; j<=n ;j++){
				if(j!=i) cout << i << ' ' << j << '\n';
			}
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}