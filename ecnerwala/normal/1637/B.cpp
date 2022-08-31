#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int64_t ans = 0;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			ans += (a == 0 ? 2 : 1) * int64_t(i+1) * int64_t(N-i);
		}
		cout << ans << '\n';
	}

	return 0;
}