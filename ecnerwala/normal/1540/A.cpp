#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N);
		for (auto& a : A) cin >> a;
		sort(A.begin(), A.end());
		int64_t ans = A.back();
		for (int i = 0; i < N; i++) {
			ans += int64_t(N - 1 - i - i) * int64_t(A[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}