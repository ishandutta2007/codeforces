#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int A, B, AB, BA; cin >> A >> B >> AB >> BA;
		string S; cin >> S;
		cout << ([&]() -> bool {
			assert(int(S.size()) == A + B + 2 * AB + 2 * BA);
			std::array<int, 2> cnt{0, 0};
			for (char c : S) {
				cnt[c-'A']++;
			}
			if (A + AB + BA != cnt[0] || B + AB + BA != cnt[1]) {
				return false;
			}
			// we just need to split S into ABs and BAs
			int extra_cnt = 0;
			std::array<std::vector<int>, 2> cnts;
			std::array<int, 2> cur_cnts{0, 0};
			for (int i = 0; i < int(S.size()); ) {
				int j = i;
				while (j+1 < int(S.size()) && S[j] != S[j+1]) {
					j++;
				}
				int seq_len = j - i + 1;
				if (seq_len & 1) {
					extra_cnt += seq_len / 2;
				} else {
					cnts[S[i] - 'A'].push_back(seq_len / 2);
					cur_cnts[S[i] - 'A'] += seq_len / 2;
				}

				i = j+1;
			}

			for (int z = 0; z < 2; z++) {
				std::sort(cnts[z].begin(), cnts[z].end());
			}

			std::array<int, 2> targets{AB, BA};

			// if they're both deficits, just use all
			while (true) {
				if (cur_cnts[0] >= targets[0] && cur_cnts[1] >= targets[1]) {
					return true;
				}
				if (cur_cnts[0] <= targets[0] && cur_cnts[1] <= targets[1]) {
					return cur_cnts[0] + cur_cnts[1] + extra_cnt >= targets[0] + targets[1];
				}
				// neither can be equal, and they're different
				if (cur_cnts[0] > targets[0]) {
					assert(!cnts[0].empty());
					int v = cnts[0].back();
					cnts[0].pop_back();
					cur_cnts[0] -= v;
					extra_cnt += v - 1;
				} else if (cur_cnts[1] > targets[1]) {
					assert(!cnts[1].empty());
					int v = cnts[1].back();
					cnts[1].pop_back();
					cur_cnts[1] -= v;
					extra_cnt += v - 1;
				} else assert(false);
			}

			return false;
		}() ? "YES" : "NO") << '\n';
	}

	return 0;
}