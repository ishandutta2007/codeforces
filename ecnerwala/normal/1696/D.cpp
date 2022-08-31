#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N); for (auto& a : A) cin >> a;
		if (N == 1) {
			cout << 0 << '\n';
			continue;
		}
		int ans = -1;
		for (int z = 0; z < 2; z++, std::reverse(A.begin(), A.end())) {
			int mi = A[0], ma = A[0];
			int prv = -1;
			for (int i = 1; i < N; i++) {
				if (A[i] > ma) {
					ma = A[i];
					if (prv != 0) {
						ans++;
						prv = 0;
					}
				} else if (A[i] < mi) {
					mi = A[i];
					if (prv != 1) {
						ans++;
						prv = 1;
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}