#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;

		int n0 = 0;
		int lo = 0;
		while (lo < N-1) {
			if (A[lo] == 0) {
				lo++;
				n0++;
				continue;
			}

			for (int i = N-1; i > lo; i--) A[i] -= A[i-1];
			if (n0 > 0) {
				n0--;
			} else {
				lo++;
			}
			std::sort(A.begin() + lo, A.end());
		}
		cout << A[N-1] << '\n';
	}

	return 0;
}