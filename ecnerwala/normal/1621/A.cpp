#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		if (K <= (N+1) / 2) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << ".R"[i==j && !(i&1) && i < 2*K];
				}
				cout << '\n';
			}
		} else {
			cout << -1 << '\n';
		}
	}

	return 0;
}