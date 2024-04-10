#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-5;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Task {
	int power, proc;
	bool operator < (const Task& v) const {
		return power > v.power;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	Task tasks[n];

	for (int i=0; i<n; i++) {
		cin >> tasks[i].power;
	}
	for (int i=0; i<n; i++) {
		cin >> tasks[i].proc;
	}
	sort(tasks, tasks+n);

	auto valid = [&] (ld threshold) {
		//cerr << "SOLVE " << threshold << nl;
		ld dp[n+1][n+1][n+1];
		fill(dp[0][0], dp[0][0] + (n+1)*(n+1)*(n+1), -INF);

		dp[0][0][0] = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				for (int k=0; k<n-j; k++) {
					if (i+1 < n && tasks[i].power == tasks[i+1].power) {
						// take ith as first
						dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + threshold*tasks[i].proc - tasks[i].power);
						// take ith as second
						if (j > 0) {
							dp[i+1][j-1][k] = max(dp[i+1][j-1][k], dp[i][j][k]);
						}
					}
					else {
						// take ith as first
						dp[i+1][j+k+1][0] = max(dp[i+1][j+k+1][0], dp[i][j][k] + threshold*tasks[i].proc - tasks[i].power);
						// take ith as second
						if (j > 0) {
							dp[i+1][j+k-1][0] = max(dp[i+1][j+k-1][0], dp[i][j][k]);
						}
					}
				}
			}
		}

		//cerr << "DP TABLE" << nl; for (int i=0; i<=n; i++) { for (int j=0; j<=n; j++) { for (int k=0; k<=n; k++) {
			//cerr << i << ',' << j << ',' << k << " : " << dp[i][j][k] << nl; } } }
		//cerr << nl;

		ld ans = -INF;
		for (int j=0; j<=n; j++) {
			for (int k=0; k<=n; k++) {
				ans = max(ans, dp[n][j][k]);
			}
		}
		return ans >= 0;
	};

	ld left, right, mid;
	left = 0;
	right = INF;
	while (right-left > EPS) {
		mid = (left+right)/2;
		(valid(mid) ? right : left) = mid;
	}
	cout << llround(ceil(1000*(mid-EPS))) << nl;

	return 0;
}