#include<bits/stdc++.h>

#define ll long long

using namespace std;
int main() {
	string ref="RGB";
	ll t; cin>>t; for(ll l=1; l<=t; l++) {
		ll n, k; string s; cin>>n>>k>>s; ll ans=k;
		for (ll i=0; i<=n-k; i++) {
			for (int j=0; j<3; j++) {
				ll cnt=0;
				for (ll r=0; r<k; r++)
					if (s[i+r]!=ref[(j+r)%3]) cnt++;
				ans=min(ans, cnt);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}