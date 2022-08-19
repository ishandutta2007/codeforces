#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<std::vector<int>> outEdges(N);
		std::vector<int> inDeg(N);

		for (int i = 0; i < N; i++) {
			int K; cin >> K;
			inDeg[i] = K;
			for (int z = 0; z < K; z++) {
				int j; cin >> j; j--;
				outEdges[j].push_back(i);
			}
		}

		std::set<int> alive;
		for (int i = 0; i < N; i++) {
			if (inDeg[i] == 0) alive.insert(i);
		}

		int cnt = 0;
		int cur = N;
		int ans = 0;
		while (cnt < N && !alive.empty()) {
			auto it = alive.lower_bound(cur);
			if (it == alive.end()) {
				ans++;
				it = alive.begin();
			}
			cur = *it;
			alive.erase(it);
			cnt++;
			for (int j : outEdges[cur]) {
				if (--inDeg[j] == 0) {
					alive.insert(j);
				}
			}
		}
		if (cnt < N) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}

	return 0;
}