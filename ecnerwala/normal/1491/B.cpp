#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int64_t U, V; cin >> U >> V;
		vector<int> A(N); for (auto& a : A) cin >> a;
		int max_gap = 0;
		for (int i = 0; i+1 < N; i++) {
			max_gap = max(max_gap, abs(A[i] - A[i+1]));
		}
		if (max_gap >= 2) {
			cout << 0 << '\n';
		} else if (max_gap == 1) {
			cout << min(U, V) << '\n';
		} else {
			cout << V + min(U, V) << '\n';
		}
	}

	return 0;
}