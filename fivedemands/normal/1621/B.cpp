#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
void solve(){
	cin >> n;
	ll mn=1e18,mx=-1e18;
	ll b1=1e18,b2=1e18,b3=1e18;
	for(int i=1; i<=n ;i++){
		ll l,r,c;cin >> l >> r >> c;
		if(l<mn) b1=1e18;
		if(r>mx) b2=1e18;
		if(l<mn || r>mx) b3=1e18;
		mn=min(mn,l);mx=max(mx,r);
		if(l==mn) b1=min(b1,c);
		if(r==mx) b2=min(b2,c);
		if(l==mn && r==mx) b3=min(b3,c);
		cout << min(b1+b2,b3) << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}