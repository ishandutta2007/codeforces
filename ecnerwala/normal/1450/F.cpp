#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i]; A[i]--;
		}

		vector<int> freq(N);

		for (int i = 0; i < N; i++) {
			if (i == 0 || A[i] == A[i-1]) {
				freq[A[i]]++;
			}
			if (i == N-1 || A[i] == A[i+1]) {
				freq[A[i]]++;
			}
		}
		int num_ranges = std::accumulate(freq.begin(), freq.end(), 0);
		assert(num_ranges % 2 == 0);
		num_ranges /= 2;

		int v = int(max_element(freq.begin(), freq.end()) - freq.begin());
		for (int i = 0; freq[v] > num_ranges + 1 && i + 1 < N; i++) {
			if (A[i] != A[i+1] && A[i] != v && A[i+1] != v) {
				num_ranges++;
			}
		}
		if (freq[v] > num_ranges + 1) {
			cout << -1 << '\n';
		} else {
			cout << num_ranges - 1 << '\n';
		}
	}

	return 0;
}

// Consider this post-split, into k pieces
// The most common one can occur at most k + 1 times
// If k >= 2 and everything is <= k, pick any 2 different and merge them
// If k >= 2 and one of them is k+1, then pick any different guy with it
// Thus, this is necessary and sufficient