#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; int64_t R1, R1All, R2, D; cin >> N >> R1 >> R1All >> R2 >> D;
	vector<int64_t> A(N); for (auto& a : A) cin >> a;

	R1 = min(R1, R2);
	assert(R1 <= R2);

	vector<int64_t> cost1(N);
	vector<int64_t> cost2(N);
	for (int i = 0; i < N; i++) {
		cost1[i] = R1 * A[i] + R2;
		cost2[i] = min(R1All, R1 * (A[i]+1)) + min(R1, R1All);
		cost2[i] = min(cost2[i], cost1[i]);
		cost1[i] = min(cost1[i], cost2[i] + 2 * D);
	}

	// cost to clear everything in the first i levels and end at level i
	vector<int64_t> pref_cost(N+1, int64_t(1e18));
	pref_cost[0] = -D;
	for (int i = 0; i < N; i++) {
		if (i+1 < N) {
			pref_cost[i+2] = min(pref_cost[i+2], pref_cost[i] + 4 * D + cost2[i] + cost2[i+1]);
		}
		if (i+2 == N) {
			// special case
			pref_cost[i+2] = min(pref_cost[i+2], pref_cost[i] + 3 * D + cost2[i] + cost1[i+1]);
		}

		pref_cost[i+1] = min(pref_cost[i+1], pref_cost[i] + D + cost1[i]);
	}

	cout << pref_cost[N] << '\n';

	return 0;
}