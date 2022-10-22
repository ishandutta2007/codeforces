#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const ll INF = 1e18;
pl2 arr[120]; ll prf[120];
ll dp[120][20020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i].fr; }
		for (int i = 1; i <= n; i++){ cin >> arr[i].sc; }
		for (int i = 1; i <= n; i++){ prf[i] = prf[i-1] + arr[i].fr + arr[i].sc; }
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= 200*n; j++){ dp[i][j] = INF; }
		}
		dp[0][0] = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j <= 200*i; j++){
				if (dp[i][j] == INF){ continue; }
				//cout << "DP " << i << ' ' << j << " = " << dp[i][j] << endl;
				ll sum1 = j; ll sum2 = prf[i] - sum1;
				if (sum1 < 0 || sum2 < 0){ continue; }
				ll a1 = min(arr[i+1].fr, arr[i+1].sc), a2 = max(arr[i+1].fr, arr[i+1].sc);
				ll res = 2*a1*sum1 + 2*a2*sum2;
				dp[i+1][sum1 + a1] = min(dp[i+1][sum1+a1], dp[i][sum1] + res);
				res = 2*a2*sum1 + 2*a1*sum2;
				dp[i+1][sum1 + a2] = min(dp[i+1][sum1+a2], dp[i][sum1] + res);
			}
		}
		ll ans = INF;
		for (int j = 0; j <= 200*n; j++){
			if (dp[n][j] == -1){ continue; }
			ans = min(ans, dp[n][j]);
		}
		for (int i = 1; i <= n; i++){
			ans += (n-1) * (arr[i].fr*arr[i].fr);
			ans += (n-1) * (arr[i].sc*arr[i].sc);
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}