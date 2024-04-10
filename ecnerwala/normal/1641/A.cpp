#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, X; cin >> N >> X;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		std::sort(A.begin(), A.end());
		int64_t ans = 0;
		for (int i = 0, j = 0; i < N; i++) {
			if (A[i] == 0) continue;
			while (j < N && (A[j] == 0 || A[j] < int64_t(A[i]) * X)) j++;
			if (j < N && A[j] == int64_t(A[i]) * X) {
				A[j] = 0;
			} else {
				ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}