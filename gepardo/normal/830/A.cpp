// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|  Codeforces Round #424 (Div. 1)  |
+----------------------------------+
|             Problem A            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(42);

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

signed main() {
	ios_base::sync_with_stdio(false);
	int n, k; int64_t p; cin >> n >> k >> p;
	vector<int64_t> a(n), b(k);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	static int64_t dp[3000][3000] = {};
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = LLONG_MAX;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[i][j] == LLONG_MAX) {
				continue;
			}
			dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
			dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[i] - b[j]) + abs(b[j] - p)));
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}