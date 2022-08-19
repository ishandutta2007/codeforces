#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const int MAXV = int(1e6) + 10;
	std::vector<int> pfac(MAXV+1);
	std::vector<int> primes; primes.reserve(MAXV);
	for (int i = 2; i <= MAXV; i++) {
		if (pfac[i] == 0) {
			primes.push_back(i);
			pfac[i] = i;
		}
		for (int p : primes) {
			if (p > MAXV / i) break;
			pfac[i*p] = p;
			if (p == pfac[i]) break;
		}
	}

	int T; cin >> T;
	while (T--) {
		int N, E; cin >> N >> E;
		std::vector<int> A(N);
		for (auto& a : A) { cin >> a; }
		int64_t ans = 0;
		for (int i = 0; i < E && i < N; i++) {
			int num_0 = 1;
			int num_1 = 0;
			for (int j = i; j < N; j += E) {
				if (A[j] == 1) {
					num_0++;
				} else if (pfac[A[j]] == A[j]) {
					num_1 = num_0;
					num_0 = 1;
				} else {
					num_1 = 0;
					num_0 = 1;
				}
				ans += num_1;
			}
		}
		for (int i = 0; i < N; i++) ans -= (pfac[A[i]] == A[i]);
		cout << ans << '\n';
	}

	return 0;
}