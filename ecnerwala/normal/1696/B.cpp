#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		if (*std::max_element(A.begin(), A.end()) == 0) {
			cout << 0 << '\n';
		} else {
			int l = 0;
			int r = N;
			while (A[l] == 0) l++;
			while (A[r-1] == 0) r--;
			assert(l < r);
			if (*std::min_element(A.begin() + l, A.begin() + r) > 0) {
				cout << 1 << '\n';
			} else {
				cout << 2 << '\n';
			}
		}
	}

	return 0;
}