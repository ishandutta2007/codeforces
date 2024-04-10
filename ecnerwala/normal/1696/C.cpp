#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		int K; cin >> K;
		std::vector<int> B(K);
		for (auto& b : B) cin >> b;

		auto canonicalize = [&](const std::vector<int>& a) {
			std::vector<std::pair<int, int64_t>> r;
			r.reserve(a.size());
			for (int v : a) {
				int64_t cnt = 1;
				while (v % M == 0) { v /= M, cnt *= M; }
				if (!r.empty() && r.back().first == v) r.back().second += cnt;
				else r.push_back({v, cnt});
			}
			return r;
		};

		cout << (canonicalize(A) == canonicalize(B) ? "Yes" : "No") << '\n';
	}

	return 0;
}