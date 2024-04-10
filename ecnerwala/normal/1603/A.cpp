#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;

		int max_A = *std::max_element(A.begin(), A.end());

		bool good = true;
		int64_t lo = 2;
		for (int i = 0; i < N && lo <= max_A; i++, lo = std::lcm(lo, i+2)) {
			if (A[i] % lo == 0) {
				good = false;
				break;
			}
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}