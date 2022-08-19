#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t A, B, X, Y, N; cin >> A >> B >> X >> Y >> N;

		N = min(N, A-X + B-Y);

		int64_t da = min(A-X, N);
		int64_t ans = (A - da) * (B - (N - da));

		int64_t db = min(B-Y, N);
		ans = min(ans, (A - (N - db)) * (B - db));

		cout << ans << '\n';
	}

	return 0;
}