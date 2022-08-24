#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll dp[N][4];
void solve(){
	string s;cin >> s;
	n=s.size();s='?'+s;
	for(int i=1; i<=n ;i++){
		for(int j=0; j<4 ;j++) dp[i][j]=1e9;
		dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
		dp[i][3]=min(dp[i-1][1],dp[i-1][3])+1;
		dp[i][0]=1e9;
		if(i<=1 || s[i]!=s[i-1]){
			dp[i][0]=min(dp[i][0],dp[i-1][2]);
			if(i<=2 || s[i]!=s[i-2]){
				dp[i][0]=min(dp[i][0],dp[i-1][0]);
			}
		}
		dp[i][2]=dp[i-1][3];
		if(i<=2 || s[i]!=s[i-2]){
			dp[i][2]=min(dp[i][2],dp[i-1][1]);
		}
		
	}
	int ans=min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3]));
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}