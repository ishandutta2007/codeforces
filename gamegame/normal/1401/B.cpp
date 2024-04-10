#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
ll a[N],b[N];
void solve(){
	ll x,y,z;cin >> x >> y >> z;
	ll p,q,r;cin >> p >> q >> r;
	ll t=min(z,q);
	z-=t;
	q-=t;
	ll ans=t*2;
	ll duh=x+y+z;
	ll w=max(0LL,y+r-duh);
	ans-=w*2;
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}