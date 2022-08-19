#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<string> G(N);
		for (auto& r : G) cin >> r;

		array<int, 3> cnt{0,0,0};
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (G[i][j] == 'X') {
					cnt[(i+j)%3]++;
				}
			}
		}
		int v = int(min_element(cnt.begin(), cnt.end()) - cnt.begin());
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (G[i][j] == 'X') {
					if ((i+j)%3 == v) G[i][j] = 'O';
				}
			}
		}
		for (int i = 0; i < N; i++) {
			cout << G[i] << '\n';
		}
	}

	return 0;
}