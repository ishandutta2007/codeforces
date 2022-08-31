#include <bits/stdc++.h>

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		const int INF = 1e9;
		array<int, 4> dp{0,0,0,0};
		for (int i = 0; i < int(S.size()); i++) {
			array<int, 4> ndp{INF, INF, INF, INF};
			for (int m = 0; m < 4; m++) {
				setmin(ndp[(m << 1) & 3], dp[m] + 1);
				if ((m & 1) && (i >= 1) && S[i-1] == S[i]) {
					continue;
				}
				if ((m & 2) && (i >= 2) && S[i-2] == S[i]) {
					continue;
				}
				setmin(ndp[((m<<1) | 1) & 3], dp[m]);
			}
			dp = ndp;
		}
		cout << *min_element(dp.begin(), dp.end()) << '\n';
	}

	return 0;
}