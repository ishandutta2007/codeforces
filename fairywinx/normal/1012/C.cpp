#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 5e3 + 228;
const int INF = 1e9 + 228;

int dp[N][N / 2][3]; //     i - 1  i  - 0,    i - 1  - 1,    i  - 2

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < N / 2; ++j)
				dp[i][j][0] = INF, dp[i][j][1] = INF, dp[i][j][2] = INF;
	}
	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	dp[1][0][0] = 0;
	dp[1][1][1] = max(a[1] - a[0] + 1, 0);
	dp[1][1][2] = max(a[0] - a[1] + 1, 0);

	for (int i = 2; i < n; ++i) {
		dp[i][0][0] = 0;
		for (int k = 1; k <= (i + 2) / 2; ++k) {
			dp[i][k][0] = min(dp[i - 1][k][0], dp[i - 1][k][1]);
			dp[i][k][1] = dp[i - 1][k][2] + max(a[i] - a[i - 1] + 1, 0);
			dp[i][k][2] = min(dp[i - 1][k - 1][0] + max(a[i - 1] - a[i] + 1, 0), dp[i - 1][k - 1][1] + max(min(a[i - 2], a[i - 1] + 1) - a[i], 0));
		}
	}
	int c = (n + 1) / 2;
	vector<int> ans(c);
	for (int i = 1; i <= c; ++i) {
		ans[i - 1] = min(dp[n - 1][i][0], min(dp[n - 1][i][1], dp[n - 1][i][2]));
	}
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
}