#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	auto go = []() -> bool {
		int N, K; cin >> N >> K;
		vector<int> A(N);
		for (int i = 0; i < N; i++) cin >> A[i];

		auto it = find(A.begin(), A.end(), K);
		if (it == A.end()) {
			return false;
		}

		if (N == 1) return true;

		// if k <= other
		// you need
		// 2 * eq >= gt + eq - lt > 0
		// 2 >= gt + eq - lt > 0
		vector<int> pref(N+1);
		for (int i = 0; i < N; i++) pref[i+1] = pref[i] + (A[i] >= K ? 1 : -1);
		vector<int> bestPref(N+1);
		bestPref[0] = pref[0];
		for (int i = 0; i < N; i++) bestPref[i+1] = min(bestPref[i], pref[i+1]);
		vector<int> bestSuff(N+1);
		bestSuff[N] = pref[N];
		for (int i = N-1; i >= 0; i--) bestSuff[i] = max(bestSuff[i+1], pref[i]);

		for (int i = 0; i+1 < N; i++) {
			if (bestSuff[i+2] > bestPref[i]) {
				return true;
			}
		}

		return false;
	};

	int T; cin >> T;
	while (T--) {
		bool ans = go();
		cout << (ans ? "yes" : "no") << '\n';
	}

	return 0;
}