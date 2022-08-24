#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2001;
ll n,m,l,r;
int f[N],g[N];
int dp[2][N][N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> l >> r;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			char c;cin >> c;
			if(c=='#') f[j]++;
			else g[j]++;
		}
	}
	for(int j=0; j<=m ;j++){
		dp[0][1][j]=1e9;
		dp[1][1][j]=1e9;
	}
	dp[0][1][1]=f[1];
	dp[1][1][1]=g[1];
	for(int i=2; i<=m ;i++){
		for(int j=1; j<=m ;j++){
			dp[0][i][j]=dp[1][i][j]=1e9;
		}
		for(int j=1; j<=i ;j++){
			dp[0][i][j+1]=min(dp[0][i][j+1],dp[0][i-1][j]+f[i]);
			if(l<=j && j<=r) dp[1][i][1]=min(dp[1][i][1],dp[0][i-1][j]+g[i]);
			dp[1][i][j+1]=min(dp[1][i][j+1],dp[1][i-1][j]+g[i]);
			if(l<=j && j<=r) dp[0][i][1]=min(dp[0][i][1],dp[1][i-1][j]+f[i]);
		}
	}
	int ans=1e9;
	for(int j=1; j<=m ;j++){
		if(j<l || j>r) continue;
		ans=min(ans,dp[0][m][j]);
		ans=min(ans,dp[1][m][j]);
	}
	cout << ans << '\n';
}