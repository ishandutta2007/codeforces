#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		cout << ([&]() -> bool {
			std::sort(A.begin(), A.end());
			A.resize(std::unique(A.begin(), A.end()) - A.begin());
			bool has_1 = false;
			for (auto a : A) {
				if (a == 1) has_1 = true;
			}
			if (!has_1) {
				return true;
			}
			for (int i = 0; i+1 < int(A.size()); i++) {
				if (A[i+1] - A[i] == 1) {
					return false;
				}
			}
			return true;
		}() ? "YES" : "NO") << '\n';
	}

	return 0;
}