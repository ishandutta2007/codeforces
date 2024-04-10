#include <iostream>

using namespace std;

const int64_t llInf = 123456789012345678;

int main() {
	static int64_t dp[31][31][51] = {};
	// 
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			dp[i][j][0] = 0;
		}
	}
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			for (int k = 1; k <= 50; k++) {
				dp[i][j][k] = llInf / 2;
			}
		}
	}
	//  n = 1  m = 1
	dp[1][1][1] = 0;
	for (int i = 2; i <= 30; i++) {
		for (int k = 1; k <= 50; k++) {
			if (k > i) {
				continue;
			}
			if (k == i) {
				dp[i][1][k] = dp[1][i][k] = 0;
				continue;
			}
			for (int ni = 1; ni < i; ni++) {
				for (int nk = 0; nk <= k; nk++) {
					dp[i][1][k] = min(dp[i][1][k], dp[ni][1][nk] + dp[i - ni][1][k - nk] + 1);
				}
			}
			dp[1][i][k] = dp[i][1][k];
		}
	}
	//  
	for (int i = 2; i <= 30; i++) {
		for (int j = 2; j <= 30; j++) {
			for (int k = 1; k <= 50; k++) {
				if (k > i*j) {
					continue;
				}
				if (k == i*j) {
					dp[i][j][k] = 0;
					continue;
				}
				//   n ()
				for (int ni = 1; ni < i; ni++) {
					for (int nk = 0; nk <= k; nk++) {
						dp[i][j][k] = min(
							dp[i][j][k], 
							dp[ni][j][nk] + dp[i-ni][j][k-nk] + j*j
						);
					}
				}
				//   m ()
				for (int nj = 1; nj < j; nj++) {
					for (int nk = 0; nk <= k; nk++) {
						dp[i][j][k] = min(
							dp[i][j][k],
							dp[i][nj][nk] + dp[i][j-nj][k-nk] + i*i
						);
					}
				}
			}
		}
	}
	//  
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m, k; cin >> n >> m >> k;
		cout << dp[n][m][k] << "\n";
	}
	return 0;
}