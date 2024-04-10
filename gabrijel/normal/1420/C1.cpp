#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const ll inf = 1e18;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, q;
		cin >> n >> q;
		vector <ll> svi(n);
		REP(i, n) cin >> svi[i];
		vector <pair <ll, ll> > dp(n);
		dp[0].first = svi[0];
		dp[0].second = -inf;
		for(int i = 1; i < n; i++) {
			dp[i] = dp[i - 1];
			dp[i].first = max(dp[i].first, dp[i - 1].second + svi[i]);
			dp[i].first = max(dp[i].first, svi[i]);
			dp[i].second = max(dp[i].second, dp[i - 1].first - svi[i]);
		}
		cout << dp[n - 1].first << "\n";
	}
	return 0;
}