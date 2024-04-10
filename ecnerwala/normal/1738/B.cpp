#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		std::vector<int64_t> S(K); for (auto& s : S) cin >> s;
		cout << ([&]() -> bool {
			for (int i = 0; i+2 < K; i++) {
				if (S[i+1] - S[i] > S[i+2] - S[i+1]) return false;
			}
			if (K > 1) {
				if (S[0] - (N-K+1) * (S[1] - S[0]) > 0) {
					return false;
				}
			}
			return true;
		}() ? "Yes" : "No") << '\n';
	}

	return 0;
}