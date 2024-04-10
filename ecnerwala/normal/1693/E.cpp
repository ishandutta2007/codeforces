#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<std::vector<int>> idxs(N+1);
	for (int i = 0; i < N; i++) {
		int a; cin >> a; idxs[a].push_back(i);
	}

	std::vector<int> bit(N);

	int64_t ans = 0;
	int lo = 0, hi = N;
	for (int v = N; v > 0; v--) {
		if (idxs[v].empty()) continue;

		std::tie(lo, hi) = std::make_pair(
			std::min(idxs[v].front(), hi),
			std::max(idxs[v].back()+1, lo)
		);

		for (int a : idxs[v]) {
			for (; a < N; a |= a+1) bit[a]++;
		}

		for (int a = lo; a; a &= a-1) ans -= bit[a-1];
		for (int a = hi; a; a &= a-1) ans += bit[a-1];
	}
	cout << ans << '\n';

	return 0;
}