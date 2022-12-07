#include<bits/stdc++.h>

using ll = long long;
using namespace std;

const int N = 210;

int n, p[N];
ll c[N][N], d[N][N];
pair<ll, int> dp[N][N];

int build(int l, int r) {
	if (l > r) return 0;
	int mid = dp[l][r].second;
	p[build(l, mid - 1)] = mid;
	p[build(mid + 1, r)] = mid;
	return mid;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			d[i][j] = d[i][j - 1];
			for (int x = 1; x <= n; x++) {
				d[i][j] += (i <= x && x <= j ? -1 : 1) * c[j][x];
			}
		}

	for (int len = 1; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			dp[i][j] = {1e18, 0};
			for (int mid = i; mid <= j; mid++)
				dp[i][j] = min(dp[i][j], {dp[i][mid - 1].first + dp[mid + 1][j].first + d[i][mid - 1] + d[mid + 1][j], mid});
		}
	}

	//cout << dp[1][n].first << "\n";

	build(1, n);

	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << "\n";

	return 0;
}