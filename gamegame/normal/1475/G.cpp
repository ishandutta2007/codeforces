#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
const int N=2e6+1;
const int iu=2e5;
ll n,m,k;
ll f[N];
ll dp[N];
void solve(){
	cin >> n;
	for(int i=1; i<=iu ;i++) f[i]=dp[i]=0;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;f[x]++;
	}
	ll ans=0;
	for(int i=1; i<=iu ;i++){
		dp[i]+=f[i];
		for(int j=i*2; j<=iu ;j+=i){
			dp[j]=max(dp[j],dp[i]);
		}
		ans=max(ans,dp[i]);
	}
	cout << n-ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	;
	int t;cin >> t;while(t--) solve();
}