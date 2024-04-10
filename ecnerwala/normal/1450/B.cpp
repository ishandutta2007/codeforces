#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<array<int, 2>> pts(N);
		for (auto& p : pts) cin >> p[0] >> p[1];
		bool good = false;
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				if (abs(pts[i][0] - pts[j][0]) + abs(pts[i][1] - pts[j][1]) <= K) cnt++;
			}
			if (cnt == N) { good = true; break; }
		}
		if (good) cout << 1 << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}