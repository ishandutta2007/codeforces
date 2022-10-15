#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

inline void umax(int &a, int b) {
	a = max(a, b);
}

int main() {
	int n, l, r; cin >> n >> l >> r;
	vector< pair<int, int> > v(n);
	int soom = 0, imp = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].second;
		soom += v[i].second;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		imp += v[i].first;
		v[i].first ^= 1;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		v[i].first ^= 1;
	}
	r = soom - r;
	int tSoom = soom;
	vector< vector<int> > dp(2, vector<int>(tSoom+1, INT_MIN));
	auto pat = dp;
	dp[0][0] = imp;
	soom = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto pdp = move(dp);
		dp = pat;
		int curImp = v[i].first, curVal = v[i].second;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k <= tSoom; k++) {
				if (pdp[j][k] == INT_MIN) {
					continue;
				}
				if (k >= l && soom - k >= r) {
					ans = max(ans, j + pdp[j][k]);
				}
				umax(dp[j | curImp][k], pdp[j][k] - curImp);
				umax(dp[j][k + curVal], pdp[j][k] - curImp);
			}
		}
		soom += curVal;
	}
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k <= tSoom; k++) {
			if (dp[j][k] == INT_MIN) {
				continue;
			}
			if (k >= l && soom - k >= r) {
				ans = max(ans, j + dp[j][k]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}