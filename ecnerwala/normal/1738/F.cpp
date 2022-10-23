#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<std::pair<int, int>> degs(N);
		for (int i = 0; i < N; i++) {
			cin >> degs[i].first;
			degs[i].second = i;
		}
		std::sort(degs.begin(), degs.end(), std::greater<>());

		std::vector<int> par(N, -1);

		std::vector<bool> used(N);
		for (auto [d, v] : degs) {
			if (used[v]) continue;
			used[v] = true;
			for (int z = 0; z < d-1; z++) {
				cout << '?' << ' ' << v+1 << '\n' << flush;
				int u; cin >> u;
				assert(u != -1);
				u--;
				if (used[u]) {
					par[v] = u;
					break;
				} else {
					used[u] = true;
					par[u] = v;
				}
			}
		}
		auto get_par = [&](int a) -> int {
			while (par[a] >= 0) {
				if (par[par[a]] >= 0) par[a] = par[par[a]];
				a = par[a];
			}
			return a;
		};
		cout << '!';
		for (int i = 0; i < N; i++) cout << ' ' << get_par(i)+1;
		cout << '\n' << flush;
	}

	return 0;
}