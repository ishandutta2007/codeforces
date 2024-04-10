#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
		}
		vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
		for (int i = 1; i <= n; i += 1) {
			cnt[i] = cnt[i - 1];
			cnt[i][p[i]]++;
		}
		for (int i = 0; i <= n; i += 1) {
			for (int j = 1; j <= n; j += 1) {
				cnt[i][j] += cnt[i][j - 1];
			}
		}
		ll ans = 0;
		for (int b = 1; b <= n; b += 1) {
			for (int c = b + 1; c <= n; c += 1) {
				ll x = cnt[b - 1][p[c] - 1];
				ll y = cnt[n][p[b] - 1] - cnt[c][p[b] - 1];
				ans += x * y;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}