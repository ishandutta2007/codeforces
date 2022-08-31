#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
ll a[100001];
pair<ll,int>b[500001];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		a[i]=0;
		for(int j=1; j<=m ;j++){
			ll x;cin >> x;
			a[i]+=j*x;
		}
		b[i]={a[i],i};
	}
	sort(b+1,b+n+1);
	cout << b[n].se << ' ' << b[n].fi-b[1].fi << '\n';
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}