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
	dp[0][0]=dp[0][1]=0;
	ll ans=0;
	int fun=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		dp[i][1]=min(dp[i-1][0],dp[i-1][1]+a[i]);
		if(dp[i-1][0]<dp[i-1][1]+a[i]){
			dp[i][1]=dp[i-1][0];
			f[i][1]=i;
		}
		else{
			dp[i][1]=dp[i-1][1]+a[i];
			f[i][1]=f[i-1][1];
		}
		dp[i][0]=dp[i-1][0]+a[i];
		if(dp[i][0]<=m) ans=max(ans,(ll)i);
		if(dp[i][1]<=m){
			if(ans<i-1){
				ans=i-1;
				fun=f[i][1];
			}
			ans=max(ans,(ll)i-1);
		}
	}
	cout << fun << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--) solve();
}