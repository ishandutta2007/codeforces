#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int n; long long k;
string s;
long long dp[110][110];
int vis[26];

void chmin(long long &x, long long y) {
	x = min(x, y);
}

int main() {
	cin >> n >> k;
	cin >> s;
	for (int i = n; i >= 0; i--) {
		memset(vis, 0, sizeof(vis));
		for (int j = i; j < n; j++) {
			if (vis[s[j] - 'a']) continue;
			vis[s[j] - 'a'] = 1;
			for (int k = 0; k <= n; k++) {
				chmin(dp[i][k + 1] += dp[j + 1][k], INF);
			}
		}
		dp[i][0]++;
	}
	long long ans = 0;
	for (int i = n; i >= 0; i--) {
		long long tmp = min(dp[0][i], k);
		k -= tmp, ans += tmp * (n - i);
	}
	if (k) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}