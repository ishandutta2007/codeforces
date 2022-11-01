#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <vector <ll>> w(n, vector <ll>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	vector <int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	reverse(x.begin(), x.end());
	vector <bool> used(n);
	vector <ll> ans(n);
	vector <vector <ll>> old_dp(n, vector <ll>(n, INF));
	vector <vector <ll>> new_dp(n, vector <ll>(n, INF));
	for (int i = 0; i < n; i++) old_dp[i][i] = 0;
	for (int it = 0; it < n; it++) {
		int k = x[it];
		k--;
		used[k] = true;
		for (int i = 0; i < n; i++) old_dp[i][k] = min(old_dp[i][k], w[i][k]);
		for (int i = 0; i < n; i++) old_dp[k][i] = min(old_dp[k][i], w[k][i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				new_dp[i][j] = min(old_dp[i][j], old_dp[i][k] + old_dp[k][j]);
				if (!used[i] || !used[j]) continue;
				ans[it] += new_dp[i][j];
			}
		swap(new_dp, old_dp);
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}