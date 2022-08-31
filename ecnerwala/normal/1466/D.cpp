#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> W(N);
		for (int i = 0; i < N; i++) {
			cin >> W[i];
		}
		vector<int> deg(N);
		vector<int> cnds; cnds.reserve(N-2);
		for (int e = 0; e < N-1; e++) {
			int u, v; cin >> u >> v; u--, v--;
			deg[u]++;
			if (deg[u] > 1) cnds.push_back(W[u]);
			deg[v]++;
			if (deg[v] > 1) cnds.push_back(W[v]);
		}
		assert(int(cnds.size()) == N-2);
		int64_t ans = 0;
		for (int w : W) ans += w;
		cout << ans;
		sort(cnds.begin(), cnds.end(), std::greater<>());
		for (int v : cnds) {
			ans += v;
			cout << ' ' << ans;
		}
		cout << '\n';
	}

	return 0;
}