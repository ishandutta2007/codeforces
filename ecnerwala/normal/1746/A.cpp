#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		cout << ([&]() -> bool {
			int num_delete = (N - 1) % (K - 1);
			int can_delete = -1;
			for (int i = 0; i < N; i++) {
				if (A[i] == 1) {
					if (i == 0 || i == N-1) {
						can_delete = std::max(can_delete, N - 2);
					} else {
						can_delete = std::max(can_delete, N - 3);
					}
				}
			}
			return can_delete >= num_delete;
		}() ? "YES" : "NO") << '\n';
	}

	return 0;
}