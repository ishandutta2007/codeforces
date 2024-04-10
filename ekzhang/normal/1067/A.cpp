#include <fenv.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define MOD 998244353
const int maxv = 200;
int N;
int dp[MAXN][maxv + 1][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	dp[0][0][0] = 1;
	for (int i = 1; i <= N; i++) {
		int cur; cin >> cur;

		int val = 0;
		for (int v = 1; v <= 200; v++) {
			val = ((val + dp[i - 1][v - 1][0]) % MOD + dp[i - 1][v - 1][1]) % MOD;
			dp[i][v][1] = val;
		}
		val = 0;
		for (int v = 200; v >= 1; v--) {
			val = (val + dp[i - 1][v][0]) % MOD;
			dp[i][v][0] = (val + dp[i - 1][v][1]) % MOD;
		}

		if (cur != -1) {
			for (int v = 1; v <= 200; v++) {
				if (v != cur) {
					dp[i][v][0] = dp[i][v][1] = 0;
				}
			}
		}
	}

	int ans = 0;
	for (int v = 1; v <= 200; v++) {
		ans = (ans + dp[N][v][0]) % MOD;
	}

	cout << ans << endl;
	return 0;
}