#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int K; cin >> K;
		if (K == 0) {
			for (int i = 0; i < N/2; i++) {
				cout << i << ' ' << N-1-i << '\n';
			}
		} else if (K == N-1) {
			if (N == 4) {
				cout << -1 << '\n';
			} else {
				for (int i = 3; i < N/2; i++) {
					if (i == K || i == N-1-K) continue;
					cout << i << ' ' << N-1-i << '\n';
				}
				cout << 0 << ' ' << 2 << '\n';
				cout << 1 << ' ' << N-3 << '\n';
				cout << N-2 << ' ' << N-1 << '\n';
			}
		} else {
			for (int i = 1; i < N/2; i++) {
				if (i == K || i == N-1-K) continue;
				cout << i << ' ' << N-1-i << '\n';
			}
			cout << 0 << ' ' << N-1-K << '\n';
			cout << K << ' ' << N-1 << '\n';
		}
	}

	return 0;
}