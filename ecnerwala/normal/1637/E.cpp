#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;

		std::map<int, int> cnts;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			cnts[a]++;
		}

		std::vector<std::array<int, 2>> bad(M);
		for (auto& [x, y] : bad) {
			cin >> x >> y;
		}
		std::sort(bad.begin(), bad.end());

		std::vector<std::pair<int, int>> vals; vals.reserve(cnts.size());
		for (auto [a, c] : cnts) {
			vals.push_back({c, a});
		}
		std::sort(vals.begin(), vals.end());

		std::vector<int> starts; starts.reserve(vals.size()+1);
		for (int i = 0; i < int(vals.size()); i++) {
			if (i == 0 || vals[i].first != vals[i - 1].first) {
				starts.push_back(i);
			}
		}
		starts.push_back(int(vals.size()));

		int64_t ans = 0;

		for (int i = 0; i+1 < int(starts.size()); i++) {
			for (int j = i; j+1 < int(starts.size()); j++) {
				int si = starts[i], ei = starts[i+1];
				int sj = starts[j], ej = starts[j+1];

				int tot_cnt = vals[si].first + vals[sj].first;;
				// check si..ei against sj..ej
				std::priority_queue<std::pair<int, std::array<int, 2>>> pq;
				pq.push({vals[ei-1].second + vals[ej-1].second, {ei-1, ej-1}});
				while (!pq.empty()) {
					auto [a, b] = pq.top().second; pq.pop();
					int x = vals[a].second, y = vals[b].second;
					if (x > y) std::swap(x, y);
					if (x != y && !std::binary_search(bad.begin(), bad.end(), std::array<int, 2>{x, y})) {
						ans = std::max(ans, int64_t(tot_cnt) * int64_t(x + y));
						break;
					}
					if (b == ej-1 && a > si) {
						pq.push({vals[a-1].second + vals[b].second, {a-1, b}});
					}
					if (b > sj) {
						pq.push({vals[a].second + vals[b-1].second, {a, b-1}});
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}