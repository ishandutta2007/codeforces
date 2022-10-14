#include <bits/stdc++.h>

#define ll long long

using namespace std;
int main() {
	string ref="RGB";
	ll t; scanf("%lld", &t); for(ll l=1; l<=t; l++) {
		ll n, k; string s; char p[200000]; scanf("%lld %lld %s", &n, &k, p); s=p; ll ans=k;
		for (ll j=0; j<3; j++) {
			vector<int> res(n);
			ll cnt=0;
			for (ll i=0; i<n; i++) {
				res[i]=(s[i]!=ref[(i+j)%3]);
				cnt+=res[i];
				if (i>=k) cnt-=res[i-k];
				if (i>=k-1) ans=min(ans, cnt);
			}
		}
		printf("%lld \n", ans);
	}
	return 0;
}