#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int N = int(S.size());
		array<int, 26> cnt; cnt.fill(0);
		for (char c : S) {
			cnt[c - 'a']++;
		}
		string res; res.reserve(S.size());
		auto add_char = [&](int v) -> void {
			assert(cnt[v] > 0);
			cnt[v]--;
			res += char('a' + v);
		};
		[&]() -> void {
			// ans == 0 if a character occurs exactly 1 time
			for (int i = 0; i < 26; i++) {
				if (cnt[i] == 1) {
					add_char(i);
					return;
				}
			}
			// Otherwise ans == 1
			vector<pair<int, int>> dcnts; dcnts.reserve(26);
			for (int i = 0; i < 26; i++) {
				if (cnt[i] > 0) {
					dcnts.push_back({i, cnt[i]});
				}
			}
			if (dcnts.size() <= 1) {
				return;
			}
			assert(dcnts.size() >= 2);

			if (dcnts[0].second <= 2) {
				return;
			}
			// can you start aa
			if (dcnts[0].second <= 2 + N - dcnts[0].second) {
				add_char(dcnts[0].first);
				add_char(dcnts[0].first);
				for (int i = dcnts[0].first+1; cnt[dcnts[0].first] > 0; ) {
					assert(i < 26);
					if (!cnt[i]) {
						i++;
						continue;
					}
					add_char(i);
					add_char(dcnts[0].first);
				}
				return;
			}
			// must start ab
			if (dcnts.size() == 2) {
				// abbbbbbbaaaaaa
				add_char(dcnts[0].first);
				while (cnt[dcnts[1].first]) {
					add_char(dcnts[1].first);
				}
				return;
			}
			assert(dcnts.size() >= 3);
			// abaaaaaaaaaacbbbbbb
			add_char(dcnts[0].first);
			add_char(dcnts[1].first);
			while (cnt[dcnts[0].first]) {
				add_char(dcnts[0].first);
			}
			add_char(dcnts[2].first);
		}();
		for (int i = 0; i < 26; i++) {
			for (; cnt[i] > 0; cnt[i]--) {
				res += char('a' + i);
			}
		}
		cout << res << '\n';
	}

	return 0;
}