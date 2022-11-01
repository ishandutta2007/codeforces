#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	vector <ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <vector <ll>> dp(n + 1, vector <ll>(4));
	// 0: _, 1: h, 2: ha, 3: har;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (c[i - 1] == 'h') dp[i][0] = dp[i - 1][0] + a[i - 1];
		if (c[i - 1] == 'a') dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + a[i - 1]);
		if (c[i - 1] == 'r') dp[i][2] = min(dp[i - 1][1], dp[i - 1][2] + a[i - 1]);
		if (c[i - 1] == 'd') dp[i][3] = min(dp[i - 1][2], dp[i - 1][3] + a[i - 1]);
	}
	cout << dp[n][3];
	return 0;
}