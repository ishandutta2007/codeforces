#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		std::vector<int64_t> A(N); for (auto& a : A) cin >> a;
		std::vector<std::pair<int64_t, int>> B(N);
		for (int i = 0; i < N; i++) {
			B[i] = {A[i] + i, i};
		}
		std::nth_element(B.begin(), B.end() - K, B.end());
		std::vector<bool> jump(N, false);
		for (int i = N-K; i < N; i++) {
			jump[B[i].second] = true;
		}

		int64_t ans = 0;
		int64_t bonus = 0;
		for (int i = 0; i < N; i++) {
			if (jump[i]) {
				bonus++;
			} else {
				ans += A[i] + bonus;
			}
		}
		assert(bonus == K);
		cout << ans << '\n';
	}

	return 0;
}

// For each jump, you gain A[i] but lose N - 1 - i - num_remaining_jumps