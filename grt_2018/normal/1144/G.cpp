#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+10;
const int INF = 1000*1000*1000;
int n;
int a[MAXN];
int dp[MAXN][2];
int prevv[MAXN][2];
bool co[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>a[i];
		dp[i][0] = -INF;
		dp[i][1] = INF;
	}
	dp[0][0] = INF;
	dp[0][1] = -INF;
	for(int i=1; i<n;i++) {
		if(a[i]>a[i-1]&&dp[i][0]<dp[i-1][0]) {
			dp[i][0] = max(dp[i][0],dp[i-1][0]);
			prevv[i][0] = 0;
		}
		if(a[i]<a[i-1]&&dp[i][1]>dp[i-1][1]) {
			dp[i][1] = min(dp[i][1],dp[i-1][1]);
			prevv[i][1] = 1;
		}
		if(a[i]<dp[i-1][0]&&dp[i][1]>a[i-1]) {
			dp[i][1] = min(dp[i][1],a[i-1]);
			prevv[i][1] = 0;
		}
		if(a[i]>dp[i-1][1]&&dp[i][0]<a[i-1]) {
			dp[i][0] = max(dp[i][0],a[i-1]);
			prevv[i][0] = 1;
		}
	}
	if(dp[n-1][0]==-INF&&dp[n-1][1]==INF) {
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	int x = 0;
	if(dp[n-1][1]!=INF) x = 1;
	for(int i=n-1; i>=0;i--) {
		if(x==1) co[i]=1;
		x = prevv[i][x];
	}
	for(int i=0; i<n;i++) {
		cout<<co[i]<<" ";
	}
	return 0;
}