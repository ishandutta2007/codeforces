#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int ans = N-1;
		// ans is N - largest nontrivial factor
		for (int g = 1; g * g <= N; g++) {
			if (N % g == 0) {
				ans = min(ans, N-g);
				if (g > 1) ans = min(ans, N-N/g);
			}
		}
		cout << N - ans << ' ' << ans << '\n';
	}

	return 0;
}