#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) { cin >> a; a = abs(a); }
		vector<int> sums(1<<N);
		for (int i = 0; i < N; i++) {
			for (int m = 0; m < (1 << i); m++) {
				sums[m+(1<<i)] = sums[m] + A[i];
			}
		}
		sort(sums.begin(), sums.end());
		if (unique(sums.begin(), sums.end()) != sums.end()) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}