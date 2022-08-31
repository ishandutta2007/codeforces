#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		std::vector<std::pair<int, int>> ops; ops.reserve(N*N);
		std::vector<int> segs; segs.reserve(N);
		auto solve = [&]() -> bool {
			for (int i = N-1; i >= 0; i -= 2) {
				int j;
				for (j = i-1; true; j--) {
					if (j < 0) return false;
					if (A[j] == A[i]) break;
				}
				assert(j >= 0 && A[j] == A[i]);
				for (int k = i-1; k > j; k--) {
					ops.push_back({j + (i-1-k), A[k]});
				}
				segs.push_back(2*(i-j));
				std::reverse(A.begin()+j, A.begin()+i);
			}
			std::reverse(segs.begin(), segs.end());
			return true;
		};
		if (solve()) {
			cout << ops.size() << '\n';
			for (auto [p, c] : ops) {
				cout << p << ' ' << c << '\n';
			}
			cout << segs.size() << '\n';
			for (int z = 0; z < int(segs.size()); z++) {
				cout << segs[z] << " \n"[z+1==int(segs.size())];
			}
		} else {
			cout << -1 << '\n';
		}
	}

	return 0;
}