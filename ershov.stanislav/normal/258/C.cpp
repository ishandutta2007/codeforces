#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
#define inf 1000000000
#define mod 1000000007
ll n, t, m, ans;
vector<ll> v;
ll degree(ll a, ll b) {
	ll x=1, y=b, z=a;
	while (y) {
		if (y&1L) x*=z; x%=mod;
		y>>=1;
		z*=z; z%=mod;
	}
	return x;
}
int main(){
	cin >> n;
	for (ll i=0; i<n; i++) {
		cin >> t;
		v.push_back(t);
		if (t>m) m=t;
	}
	sort(v.begin(), v.end());
	for (ll i=1; i<=m; i++) {
		set<ll> d;
		for (ll j=1; j<=sqrt(i); j++) if (i%j==0) d.insert(j), d.insert(i/j);
		ll a=0, cnt=0, ans2=1;
		for (set<ll>::iterator j=d.begin(); j!=d.end(); j++) {
			ll d2=*j;
			ll b=lower_bound(v.begin(), v.end(), d2)-v.begin();
			ans2*=degree(cnt, b-a);
			ans2%=mod;
			cnt++; a=b;
		}
		ans2=ans2*degree(cnt, n-a)-ans2*degree(cnt-1, n-a);
		ans2%=mod;
		while (ans2<0) ans2+=mod;
		ans=(ans+ans2)%mod;
	}
	cout << ans;
	return 0;
}