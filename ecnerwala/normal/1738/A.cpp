#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		std::vector<int> B(N);
		for (auto& a : B) cin >> a;

		std::array<std::vector<int>, 2> vals;
		vals[0].reserve(N);
		vals[1].reserve(N);
		for (int i = 0; i < N; i++) {
			vals[A[i]].push_back(B[i]);
		}
		if (vals[0].size() == vals[1].size()) {
			cout << std::accumulate(B.begin(), B.end(), int64_t(0)) * 2 - *std::min_element(B.begin(), B.end()) << '\n';
		} else {
			if (vals[0].size() > vals[1].size()) std::swap(vals[0], vals[1]);
			assert(vals[0].size() < vals[1].size());
			std::nth_element(vals[1].begin(), vals[1].end() - vals[0].size(), vals[1].end());
			cout << std::accumulate(B.begin(), B.end(), int64_t(0)) * 2 - std::accumulate(vals[1].begin(), vals[1].end() - vals[0].size(), int64_t(0)) << '\n';
		}
	}

	return 0;
}