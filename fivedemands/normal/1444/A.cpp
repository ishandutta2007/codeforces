#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
ll a[N],b[N];
void solve(){
	ll x,y;cin >> x >> y;
	if(x%y!=0){
		cout << x << '\n';
		return;
	}
	ll ans=0;
	for(ll i=2; i*i<=y ;i++){
		if(y%i==0){
			ll z=x;
			while(z%y==0) z/=i;
			ans=max(ans,z);
			while(y%i==0) y/=i;
		}
	}
	if(y!=1){
		ll i=y;
		ll z=x;
		while(z%y==0) z/=i;
		ans=max(ans,z);
		while(y%i==0) y/=i;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}