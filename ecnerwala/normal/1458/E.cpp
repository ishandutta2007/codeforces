#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const int INF = int(1e9) + 200;

	int N, M; cin >> N >> M;
	vector<array<int, 2>> shortcuts(N);
	for (auto& p : shortcuts) cin >> p[0] >> p[1];

	set<array<int, 2>> losing_set(shortcuts.begin(), shortcuts.end());

	vector<pair<int, int>> by_first(N);
	vector<pair<int, int>> by_second(N);
	for (int i = 0; i < N; i++) {
		by_first[i] = {shortcuts[i][0], shortcuts[i][1]};
		by_second[i] = {shortcuts[i][1], shortcuts[i][0]};
	}
	sort(by_first.begin(), by_first.end());
	sort(by_second.begin(), by_second.end());

	auto itx = by_first.begin();
	auto ity = by_second.begin();
	int curx = 0, cury = 0;
	// this is a range of x's
	vector<tuple<int, int, int>> ranges; ranges.reserve(2*N+10);
	while (true) {
		if (losing_set.count({curx, cury})) {
			curx++, cury++;
			continue;
		}
		while (itx != by_first.end() && curx > itx->first) {
			itx++;
		}
		if (itx != by_first.end() && curx == itx->first) {
			int y = itx->second;
			assert(cury != y);
			if (cury > y) {
				curx++;
			}
			itx++;
			continue;
		}
		while (ity != by_second.end() && cury > ity->first) {
			ity++;
		}
		if (ity != by_second.end() && cury == ity->first) {
			int x = ity->second;
			assert(curx != x);
			if (curx > x) {
				cury++;
			}
			ity++;
			continue;
		}
		// otherwise, we have a new thing starting here
		int hi = INF;
		if (itx != by_first.end()) hi = min(hi, itx->first - curx);
		if (ity != by_second.end()) hi = min(hi, ity->first - cury);
		assert(hi > 0);
		ranges.push_back({curx + hi, curx, cury});
		if (hi == INF) break;
		curx += hi;
		cury += hi;
	}

	auto solve = [&](std::array<int, 2> p) -> bool {
		if (losing_set.count(p)) {
			return false;
		}
		auto it = upper_bound(ranges.begin(), ranges.end(), tuple<int, int, int>{p[0], p[0]+1, 0});
		if (it == ranges.end()) return true;
		auto [xhi, xlo, ylo] = *it;
		assert(xhi > p[0]);
		if (xlo <= p[0] && p[1] - p[0] == ylo - xlo) {
			return false;
		}
		return true;
	};

	vector<array<int, 2>> queries(M);
	for (auto& p : queries) cin >> p[0] >> p[1];

	for (auto p : queries) {
		cout << (solve(p) ? "WIN" : "LOSE") << '\n';
	}

	return 0;
}