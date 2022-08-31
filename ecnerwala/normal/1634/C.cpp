#include <bits/stdc++.h>

// Every pair of adjacent elements must have the same parity.

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		if (K == 1) {
			cout << "YES" << '\n';
			for (int i = 1; i <= N; i++) {
				cout << i << '\n';
			}
			continue;
		}
		if ((N & 1)) {
			assert(K >= 2);
			// we break by parity, since there's one more odd shelf than even
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		for (int i = 0; i < N*K/2; i++) {
			cout << 2*i+1 << " \n"[(i+1)%K==0];
		}
		for (int i = 0; i < N*K/2; i++) {
			cout << 2*i+2 << " \n"[(i+1)%K==0];
		}
	}

	return 0;
}