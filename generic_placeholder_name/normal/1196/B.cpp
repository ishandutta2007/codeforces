#include<bits/stdc++.h>

#define ll long long

using namespace std;
int main() {
	ll t; cin>>t; for(ll l=1; l<=t; l++) {
		ll n, k, cnt=0, tmp; cin>>n>>k; ll a[n]; for(ll i=0; i<n; i++) {
			cin>>tmp; if(tmp%2!=0) {
				a[cnt]=i; cnt++;
			} 
		}
		if(cnt>=k&&cnt%2==k%2) {
			cout<<"YES\n"; for(ll i=0; i<k-1; i++) cout<<a[i]+1<<" "; cout<<n<<"\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}