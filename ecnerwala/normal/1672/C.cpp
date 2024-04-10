#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		int first = -1;
		int last = -1;
		for (int i = 0; i+1 < N; i++) {
			if (A[i] == A[i+1]) {
				if (first == -1) first = i;
				last = i;
			}
		}
		if (first == last) {
			cout << 0 << '\n';
		} else {
			cout << std::max(1, last-first-1) << '\n';
		}
	}

	return 0;
}