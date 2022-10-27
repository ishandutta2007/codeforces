#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int maxn = 300005;

ll a[maxn], dp[maxn][3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, x;
	cin>>n>>x;

	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	ll ans = 0;
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for(int i = 1; i <= n; i++){
		dp[i][0] = max(dp[i-1][0], 0LL) + a[i];
		dp[i][1] = max(max(dp[i-1][0], dp[i-1][1]), 0LL) + a[i]*x;
		dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + a[i];
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
		ans = max(ans, dp[i][2]);
	}
	cout<<ans<<endl;

	return 0;
}