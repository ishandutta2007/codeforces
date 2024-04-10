#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, P, K; cin >> N >> P >> K; P--;
		string s; cin >> s;
		vector<int64_t> A(N);

		int64_t X, Y; cin >> X >> Y;
		int64_t ans = N * X;
		for (int i = N-1; i >= P; i--) {
			A[i] = (s[i] == '1' ? 0 : X);
			if (i+K < N) {
				A[i] += A[i+K];
			}
			ans = min(ans, A[i] + Y * (i - P));
		}
		cout << ans << '\n';
	}

	return 0;
}