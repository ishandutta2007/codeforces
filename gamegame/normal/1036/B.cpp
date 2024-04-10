#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll n,s;
ll w[100001];
ll l,r;
ll ql,qr;
ll pf[100001];
int solve(){
	ll n,m,k;
	cin >> n >> m >> k;
	if(n<m) swap(n,m);
	if(n>k) return cout << "-1\n",0;
	if((n+m)%2!=0) cout << k-1 << '\n';
	else if(n%2!=k%2) cout << k-2 << '\n';
	else cout << k << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
	//solve();
}