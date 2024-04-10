#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=5001;
int n,m;
char s[N],t[N];
int dp[N][N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	cin >> n >> m;
	for(int i=1; i<=n ;i++) cin >> s[i];
	for(int i=1; i<=m ;i++) cin >> t[i];
	int ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
			dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
			if(s[i]==t[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
			ans=max(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
}