#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const ll mod=1e9+7;
#define fi first
#define se second
const int N=1e6+1;
ll d,mod;
ll a[N],b[N];
ll f[31];
ll dp[31];
void solve(){
	cin >> d >> mod;
	for(int i=0; i<=30 ;i++){
		ll l=(1LL<<i);
		ll r=(1LL<<(i+1))-1;
		f[i]=min(r,d)-min(l,d+1)+1;
	}
	ll ans=0;
	for(int i=0; i<=30 ;i++){
		dp[i]=f[i];
		for(int j=0; j<i ;j++){
			dp[i]=dp[i]+dp[j]*f[i];
			dp[i]%=mod;
		}
		ans+=dp[i];
		ans%=mod;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}