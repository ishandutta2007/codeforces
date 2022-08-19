#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N+2);
		A[0] = A[N+1] = 0;
		for (int i = 1; i <= N; i++) cin >> A[i];
		int64_t ans = 0;
		for (int i = 1; i <= N; i++) ans += A[i];
		for (int i = 1; i <= N; i++) {
			A[i] = min(A[i], max(A[i-1], A[i+1]));
		}
		for (int i = 1; i <= N; i++) ans -= A[i];
		for (int i = 0; i <= N; i++) {
			ans += abs(A[i+1] - A[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}