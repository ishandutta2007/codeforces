#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;

const int N = 1111;
ll dp[N][2 * N][4];

void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n, k; cin >> n >> k;
	dp[1][1][0] = 1;
	dp[1][1][3] = 1;
	dp[1][2][1] = 1;
	dp[1][2][2] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int ncomp = 0; ncomp <= 2 * n; ++ncomp) {
			add(dp[i][ncomp][0], dp[i - 1][ncomp][0]);
			add(dp[i][ncomp][0], dp[i - 1][ncomp][1]);
			add(dp[i][ncomp][0], dp[i - 1][ncomp][2]);
			add(dp[i][ncomp + 1][0], dp[i - 1][ncomp][3]);
			add(dp[i][ncomp + 1][1], dp[i - 1][ncomp][0]);
			add(dp[i][ncomp][1], dp[i - 1][ncomp][1]);
			add(dp[i][ncomp + 2][1], dp[i - 1][ncomp][2]);
			add(dp[i][ncomp + 1][1], dp[i - 1][ncomp][3]);
			add(dp[i][ncomp + 1][2], dp[i - 1][ncomp][0]);
			add(dp[i][ncomp][2], dp[i - 1][ncomp][2]);
			add(dp[i][ncomp + 2][2], dp[i - 1][ncomp][1]);
			add(dp[i][ncomp + 1][2], dp[i - 1][ncomp][3]);
			add(dp[i][ncomp + 1][3], dp[i - 1][ncomp][0]);
			add(dp[i][ncomp][3], dp[i - 1][ncomp][1]);
			add(dp[i][ncomp][3], dp[i - 1][ncomp][2]);
			add(dp[i][ncomp][3], dp[i - 1][ncomp][3]);
		}
	}
	ll ans = dp[n][k][0];
	add(ans, dp[n][k][1]);
	add(ans, dp[n][k][2]);
	add(ans, dp[n][k][3]);
	cout << ans << "\n";
	return 0;
}