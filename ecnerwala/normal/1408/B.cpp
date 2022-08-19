#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		int last;
		cin >> last;
		int num_diff = 0;
		for (int i = 1; i < N; i++) {
			int a; cin >> a;
			assert(a >= last);
			num_diff += (a > last);
			last = a;
		}
		cerr << K << ' ' << num_diff << '\n';
		if (K == 1) {
			if (num_diff > 0) {
				cout << -1 << '\n';
			} else {
				cout << 1 << '\n';
			}
		} else {
			cout << max((num_diff + K-2) / (K-1), 1) << '\n';
		}
	}

	return 0;
}