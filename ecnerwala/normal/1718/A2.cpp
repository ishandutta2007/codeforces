#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N); for (auto& a : A) cin >> a;
		int pref = 0;
		int last_val = 0;
		std::map<int, int> dp;
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			pref ^= A[i];
			int val = last_val + 1;
			auto it = dp.find(pref);
			if (it != dp.end()) {
				val = std::min(val, i + it->second - 1);
				it->second = std::min(it->second, val - i);
			} else {
				dp[pref] = val - i;
			}
			last_val = val;
		}
		cout << last_val << '\n';
	}

	return 0;
}