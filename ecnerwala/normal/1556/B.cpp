#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) { cin >> a; a &= 1; }

		std::vector<int> pos; pos.reserve(N);
		for (int i = 0; i < N; i++) {
			if (A[i]) pos.push_back(i);
		}
		int64_t ans = -1;
		for (int z = 0; z < 2; z++) {
			std::vector<int> pos2; pos2.reserve(N);
			for (int i = z; i < N; i += 2) {
				pos2.push_back(i);
			}
			if (pos.size() == pos2.size()) {
				int64_t cnd = 0;
				for (int a = 0; a < int(pos.size()); a++) cnd += abs(pos[a] - pos2[a]);
				if (ans == -1 || cnd < ans) ans = cnd;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}