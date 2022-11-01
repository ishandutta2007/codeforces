#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

const ll INF = 1e9;

int main() {
	ll n, h, l, r;
	cin >> n >> h >> l >> r;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <vector <ll>> dp(n + 1, vector <ll>(h, -INF));
	dp[0][0] = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < h; j++) {
			ll t1 = (j + a[i] - 1 + h) % h;
			if (t1 >= l && t1 <= r) dp[i + 1][t1] = max(dp[i + 1][t1], dp[i][j] + 1);
			else dp[i + 1][t1] = max(dp[i + 1][t1], dp[i][j]);
			ll t2 = (j + a[i]) % h;
			if (t2 >= l && t2 <= r) dp[i + 1][t2] = max(dp[i + 1][t2], dp[i][j] + 1);
			else dp[i + 1][t2] = max(dp[i + 1][t2], dp[i][j]);
		}
	}
	ll ans = 0;
	for (ll i = 0; i < h; i++)
		ans = max(ans, dp[n][i]);
	cout << ans;
	return 0;
}