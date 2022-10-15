#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int g, d, f; cin >> g >> d >> f;
	set<int> all;
	vector<int> pg(102002), pd(102002), pf(102002);
	for (int i = 0; i < g; i++) {
		int a; cin >> a;
		all.insert(a);
		pg[a]++;
	}
	for (int i = 0; i < d; i++) {
		int a; cin >> a;
		all.insert(a);
		pd[a]++;
	}
	for (int i = 0; i < f; i++) {
		int a; cin >> a;
		all.insert(a);
		pf[a]++;
	}
	for (int i = 1; i < 102002; i++) {
		pg[i] += pg[i-1];
		pd[i] += pd[i-1];
		pf[i] += pf[i-1];
	}
	
	static int64_t dp[2000][2000] = {};
	static int64_t pp[2000][2000] = {};
	vector<int> kompr(all.begin(), all.end());
	int ks = kompr.size();
	
	int64_t res = 0;
	for (int l = 0; l < ks; l++) {
		for (int i = 0, j = l; j < ks; i++, j++) {
			pp[i][j] = 0;
			if (i != j) {
				pp[i][j] += pp[i+1][j] + pp[i][j-1];
			}
			if (i+1 <= j-1) {
				pp[i][j] -= pp[i+1][j-1];
			}
			if (kompr[i] * 2 < kompr[j]) {
				dp[i][j] = 0;
			} else {
				int ki = kompr[i], kj = kompr[j];
				int64_t part1 = pg[kj] - pg[ki-1];
				int64_t part2 = pd[kj] - pd[ki-1];
				int64_t part3 = pf[kj] - pf[ki-1];
				part2 = part2 * (part2-1) / 2;
				part3 = part3 * (part3-1) * (part3-2) / 6;
				dp[i][j] = part1 * part2 * part3;
				dp[i][j] -= pp[i][j];
				pp[i][j] += dp[i][j];
			}
			res += dp[i][j];
		}
	}
	
	cout << res << endl;
	return 0;
}