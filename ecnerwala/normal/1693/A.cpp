#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N); for (auto& a : A) cin >> a;
		cout << ([&]() -> bool {
			int64_t tot = 0;
			bool was_zero = false;
			for (int i = 0; i < N; i++) {
				tot += A[i];
				if (tot < 0) return false;
				if (tot > 0 && was_zero) return false;
				if (tot == 0) was_zero = true;
			}
			return tot == 0;
		}() ? "Yes" : "No") << '\n';
	}

	return 0;
}