#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	string S; cin >> S;
	int N = int(S.size());
	int X; cin >> X;

	int factor_mask = 0;
	for (int v = 1; v < X; v++) {
		if (X % v == 0) {
			factor_mask |= 1 << (v-1);
		}
	}

	vector<int> dp(1 << (X-1), -N-1);
	dp[0] = 0;

	vector<int> ndp(1 << (X-1));

	for (char c : S) {
		// skip the character
		for (int m = 0; m < (1 << (X-1)); m++) {
			ndp[m] = dp[m];
		}

		for (int m = 0; m < (1 << (X-1)); m++) {
			if (dp[m] < 0) continue;
			int nm = (m*2+1) << (c - '1');
			int a = nm & factor_mask;
			if (a) {
				nm &= (a-1) & ~factor_mask;
			} else if (nm & (1 << (X-1))) {
				continue;
			}
			nm &= (1 << (X-1)) - 1;
			ndp[nm] = max(ndp[nm], dp[m]+1);
		}

		swap(dp, ndp);
	}

	cout << N-*max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}