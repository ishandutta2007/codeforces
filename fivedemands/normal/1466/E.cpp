#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
const int N=2e6+1;
const int iu=60;
ll n,m;
ll a[N];
ll b[60];
void solve(){
	cin >> n;
	for(int i=0; i<60 ;i++) b[i]=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		for(int j=0; j<60 ;j++){
			if((a[i]>>j)&1) b[j]++;
		}
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ll ji=0,jk=0;
		for(int j=59; j>=0 ;j--){
			ji=ji*2%mod;
			jk=jk*2%mod;
			if((a[i]>>j)&1){
				ji=(ji+b[j])%mod;
				jk=(jk+n)%mod;
			}
			else jk=(jk+b[j])%mod;
		}
		ans=(ans+ji*jk)%mod;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}