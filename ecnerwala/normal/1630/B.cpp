#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		std::vector<int> V = A;
		std::sort(V.begin(), V.end());
		std::array<int, 2> best{V[0], V[N-1]};
		// cnt - (N - cnt) >= K
		// cnt >= ceil((N+K) / 2)
		for (int i = 0, j = std::max(0, (N+K+1) / 2 - 1); j < N; i++, j++) {
			if (V[j] - V[i] < best[1] - best[0]) {
				best = {V[i], V[j]};
			}
		}
		cout << best[0] << ' ' << best[1] << '\n';
		for (int z = 0, i = 0, j = 0; z < K; z++, i = j) {
			if (z == K-1) j = N;
			else {
				j = i;
				int cnt = 0;
				while (cnt <= 0) {
					if (best[0] <= A[j] && A[j] <= best[1]) {
						cnt++;
					} else {
						cnt--;
					}
					j++;
				}
			}
			cout << i+1 << ' ' << j << '\n';
		}
	}

	return 0;
}