#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int MAXK = MAXN * MAXN / 2;

vector<int> simple[MAXN];
vector<int> dp[MAXN][MAXK];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	for (int n = 4; n <= 100; n++) {
		// 1 3 5 0 2 4
		// 1 3 5 0 6 2 4
		for (int i = 1; i < n; i += 2) {
			simple[n].push_back(i);
		}
		simple[n].push_back(0);
		if (n % 2 == 1) {
			simple[n].push_back(n-1);
		}
		for (int i = 2; i < n-1; i += 2) {
			simple[n].push_back(i);
		}
	}

	dp[1][1] = vector<int>({0});

	for (int n = 2; n <= 100; n++) {
		for (int k = n+1; k <= n * (n+1) / 2; k++) {
			for (int s = 4; s <= n; s++) {
				if (!dp[n-(s-1)][k-s].empty()) {
					for (int v : dp[n-(s-1)][k-s]) {
						dp[n][k].push_back(v + simple[s][0]);
					}
					for (int z = 1; z < s; z++) {
						int val = simple[s][z];
						if (val > simple[s][0]) {
							val += n-s;
						}
						dp[n][k].push_back(val);
					}
					goto found;
				}
			}

			for (int l = 2; l <= n && l * (l+1) / 2 <= k; l++) {
				if (!dp[n - (l-1)][k - l * (l+1) / 2 + 1].empty()) {
					dp[n][k] = dp[n-(l-1)][k-l*(l+1)/2 + 1];
					reverse(dp[n][k].begin(), dp[n][k].end());
					while (int(dp[n][k].size()) < n) {
						dp[n][k].push_back(int(dp[n][k].size()));
					}
					goto found;
				}
			}
found:
			;
		}
	}

	int Q; cin >> Q;
	while (Q--) {
		int n, k; cin >> n >> k;
		if (dp[n][k].empty()) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				cout << dp[n][k][i]+1 << " \n"[i+1==n];
			}
		}
	}

	return 0;
}