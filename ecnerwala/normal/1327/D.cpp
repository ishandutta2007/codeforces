#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<vector<int>> factors(2.1e5);
	for (int i = 1; i < int(factors.size()); i++) {
		for (int j = i; j < int(factors.size()); j += i) {
			factors[j].push_back(i);
		}
	}

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> P(N);
		for (int i = 0; i < N; i++) {
			cin >> P[i]; P[i] --;
		}
		vector<int> C(N);
		for (int i = 0; i < N; i++) {
			cin >> C[i];
		}

		int ans = N+1;
		for (int i = 0; i < N; i++) {
			if (P[i] == -1) continue;
			vector<int> cycColors;
			for (int j = i; P[j] != -1; ) {
				cycColors.push_back(C[j]);
				int nj = P[j]; P[j] = -1; j = nj;
			}

			for (int k : factors[int(cycColors.size())]) {
				for (int a = 0; a < k; a++) {
					bool isGood = true;
					for (int v = a; v < int(cycColors.size()); v += k) {
						isGood = isGood && cycColors[a] == cycColors[v];
					}
					if (isGood) {
						ans = min(ans, k);
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}