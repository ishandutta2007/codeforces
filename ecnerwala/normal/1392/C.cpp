#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) cin >> a;
		int64_t ans = 0;
		for (int i = 1; i < N; i++) {
			ans += max(A[i-1] - A[i], 0);
		}
		cout << ans << '\n';
	}

	return 0;
}