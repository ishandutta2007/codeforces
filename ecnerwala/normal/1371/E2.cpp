#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, P; cin >> N >> P;
	vector<int> A(N); for (auto& a : A) cin >> a;
	sort(A.begin(), A.end());
	int V = *max_element(A.begin(), A.end());

	// # of things <= i
	vector<int> pref(2 * N + 1);
	for (auto a : A) {
		pref[max(a - V + N, 0)]++;
	}
	for (int i = 0; i+1 < int(pref.size()); i++) {
		pref[i+1] += pref[i];
	}

	vector<int> good(N); // x ranges from [0, N)
	for (int v = 0; v <= 2*N; v++) {
		// applies to (v-N, v-0]
		int hi = v - pref[v] % P;
		if (hi <= 0) continue;
		int lo = hi - (hi - max(0, v-N+1)) / P * P;
		assert(lo > v-N && lo >= 0);
		assert(!(lo-P > v-N && lo-P >= 0));
		if (lo < N) good[lo] ++;
		if (hi + P < N) good[hi+P] --;
	}
	for (int i = 0; i+P < N; i++) {
		good[i+P] += good[i];
	}

	vector<int> ans; ans.reserve(N);
	for (int i = 1; i < N; i++) {
		if (good[i] == 0) ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < int(ans.size()); i++) {
		if (i) cout << ' ';
		cout << ans[i] + V - N;
	}
	cout << '\n';

	return 0;
}