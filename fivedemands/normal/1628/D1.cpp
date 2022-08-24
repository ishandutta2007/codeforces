#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e5+1;
const int iu=2000;
ll n,m,k;
const ll mod=1e9+7;;
ll dp[2001][2001];
void solve(){
	cin >> n >> m >> k;
	ll ans=dp[n][m]*k%mod;
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	for(int i=1; i<=iu ;i++){
		dp[i][0]=0;
		dp[i][i]=i;
		for(int j=1; j<i ;j++){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*(mod+1)/2%mod;
		}
	}
	int t;cin >> t;
	while(t--) solve();
}