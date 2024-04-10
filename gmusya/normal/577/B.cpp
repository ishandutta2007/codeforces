#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	if (n > m) {
		cout << "YES";
		return 0;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		a[i] %= m;
	vector <vector <int>> dp(n, vector <int>(m));
	dp[0][0] = 1;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++) {
			dp[i + 1][(j + a[i]) % m] |= dp[i][j];
			dp[i + 1][j] |= dp[i][j];
		}
	for (int i = 0; i < n; i++)
		if (a[i] == 0 || dp[i][m - a[i]]) {
			cout << "YES";
			return 0;
		}
	cout << "NO";
	return 0;
}