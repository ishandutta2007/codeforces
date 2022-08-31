#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<pair<int, int>> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i].first; A[i].second = i;
		}
		sort(A.begin(), A.end());

		int best = 1;
		int cur = 1;
		for (int i = 1; i < N; i++) {
			if (A[i].second > A[i-1].second) {
				cur++;
			} else {
				cur = 1;
			}
			best = max(best, cur);
		}
		cout << N - best << '\n';
	}

	return 0;
}