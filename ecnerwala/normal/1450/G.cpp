#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int L, A, B; cin >> L >> A >> B;
	string S; cin >> S;
	struct cat_t {
		int mi = int(1e9), ma = -1, cnt = 0;
		char v;
	};
	map<char, cat_t> cat_map;
	for (int i = 0; i < L; i++) {
		cat_t& c = cat_map[S[i]];
		c.mi = min(c.mi, i);
		c.ma = max(c.ma, i);
		c.cnt++;
		c.v = S[i];
	}

	vector<cat_t> cats; cats.reserve(cat_map.size());
	for (auto it : cat_map) cats.push_back(it.second);
	sort(cats.begin(), cats.end(), [&](const auto& a, const auto& b) { return a.mi < b.mi; });

	int N = int(cats.size());

	vector<bool> can_any(1 << N);
	vector<bool> can_same(1 << N);
	can_any[0] = true;

	for (int m = 1; m < (1 << N) - 1; m++) {
		// check if we can make everything
		for (int v = m; v; v &= v-1) {
			int i = __builtin_ctz(v);
			if (can_any[m ^ (1 << i)]) {
				can_same[m] = true;
				break;
			}
		}
		if (can_same[m]) {
			cat_t cur_range;
			for (int v = m; v; v &= v-1) {
				int i = __builtin_ctz(v);
				cur_range.mi = min(cur_range.mi, cats[i].mi);
				cur_range.ma = max(cur_range.ma, cats[i].ma);
				cur_range.cnt += cats[i].cnt;
			}
			if (cur_range.cnt * B >= (cur_range.ma - cur_range.mi + 1) * A) {
				can_any[m] = true;
			}
		}

		if (!can_any[m]) {
			for (int v = m & (m-1); v; v &= v-1) {
				int mhi = v;
				int mlo = m ^ v;

				if (can_any[mlo] && can_any[mhi]) {
					can_any[m] = true;
					break;
				}
			}
		}
	}

	vector<char> ans;
	for (int i = 0; i < N; i++) {
		if (can_any[(1 << N) - 1 - (1 << i)]) {
			ans.push_back(cats[i].v);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size();
	for (char c : ans) cout << ' ' << c;
	cout << '\n';

	return 0;
}