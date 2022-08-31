#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<string> G(N); for (auto& s : G) cin >> s;
		[&]() {
			for (int z = 0; z < 2; z++) {
				bool is_good = true;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						char cur = "RW"[(i^j^z)&1];
						if (G[i][j] == '.' || G[i][j] == cur) {
						} else {
							is_good = false;
						}
					}
				}
				if (is_good) {
					cout << "YES" << '\n';
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < M; j++) {
							char cur = "RW"[(i^j^z)&1];
							cout << cur;
						}
						cout << '\n';
					}
					return;
				}
			}
			cout << "NO" << '\n';
		}();
	}

	return 0;
}