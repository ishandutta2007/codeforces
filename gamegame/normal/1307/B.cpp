#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N];
ll dp[N][2];
int f[N][2];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		if(m==a[i]){
			cout << "1\n";
			return;
		}
	}
	ll ans=1e18;
	for(int i=1; i<=n ;i++){
		ans=min(ans,(m+a[i]-1)/a[i]);
	}
	ans=max(ans,2LL);
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--) solve();
}