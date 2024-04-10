#include<bits/stdc++.h>
using namespace std;

int H[10][10];
double dp[10][10];
double dp2[10][10];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> H[i][j];
		}
	}
	vector<pair<int, int>> pts;
	for (int i = 9; i >= 0; i--) {
		if (i & 1) {
			for (int j = 0; j < 10; j++) {
				pts.emplace_back(i,j);
			}
		} else {
			for (int j = 9; j >= 0; j--) {
				pts.emplace_back(i,j);
			}
		}
	}
	assert(pts.size() == 100);
	dp[0][0] = dp2[0][0] = 0;
	for (int z = 98; z >= 0; z--) {
		int i = pts[z].first, j = pts[z].second;
		int numGood = min(6, 99-z);
		dp[i][j] = 6. / numGood;
		for (int k = 1; k <= numGood; k++) {
			dp[i][j] += dp2[pts[z+k].first][pts[z+k].second] / numGood;
		}
		dp2[i][j] = min(dp[i][j], dp[i-H[i][j]][j]);
	}
	cout << fixed << setprecision(20) << dp[9][0] << '\n';

	return 0;
}