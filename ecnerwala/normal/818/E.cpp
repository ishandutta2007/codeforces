#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	int64_t K; cin >> K;
	vector<int64_t> A(N);
	for (auto& a : A) cin >> a;

	if (K == 1) {
		cout << int64_t(N) * int64_t(N+1) / 2 << '\n';
		exit(0);
	}

	vector<pair<int64_t, int>> pfac;
	for (int64_t p = 2; K > 1; p++) {
		if (int64_t(p) * int64_t(p) > K) p = K;
		if (K % p == 0) {
			int e = 0;
			while (K % p == 0) K /= p, e++;
			pfac.emplace_back(p, e);
		}
	}
	int P = int(pfac.size());

	int64_t ans = 0;

	vector<int> cnt(P, 0);
	int num_good = 0;

	for (int i = 0, j = 0; i < N; i++) {
		while (j < N && num_good < P) {
			for (int k = 0; k < P; k++) {
				int64_t p = pfac[k].first;
				num_good -= cnt[k] >= pfac[k].second;
				int64_t v = A[j];
				while (v % p == 0) cnt[k]++, v /= p;
				num_good += cnt[k] >= pfac[k].second;
			}
			j++;
		}
		if (num_good < P) {
			break;
		}
		ans += N - j + 1;

		if (i < j) {
			// delete the ith guy
			for (int k = 0; k < P; k++) {
				int64_t p = pfac[k].first;
				num_good -= cnt[k] >= pfac[k].second;
				int64_t v = A[i];
				while (v % p == 0) cnt[k]--, v /= p;
				num_good += cnt[k] >= pfac[k].second;
			}
		} else {
			j++;
		}
	}
	cout << ans << '\n';

	return 0;
}