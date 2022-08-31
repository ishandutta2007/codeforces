#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> X(N);
		for (int i = 0; i < N; i++) {
			cin >> X[i];
		}
		uint64_t has = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				has |= uint64_t(1) << (X[j] - X[i]);
			}
		}
		cout << __builtin_popcountll(has) << '\n';
	}

	return 0;
}