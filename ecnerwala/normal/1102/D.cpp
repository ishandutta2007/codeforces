#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	string S; cin >> S;
	auto cost = [&](std::array<int, 3> cur, std::array<int, 3> nxt) -> int {
		return (abs(cur[0] - nxt[0]) + abs(cur[1] - nxt[1]) + abs(cur[2] - nxt[2])) / 2;
	};
	std::array<int, 3> cur_cnt{0, 0, 0};
	for (char c : S) {
		cur_cnt[c - '0']++;
	}
	std::array<int, 3> tgt_cnt{N/3, N/3, N/3};
	string res; res.reserve(N);
	for (int i = 0; i < N; i++) {
		for (int v = 0; ; v++) {
			assert(v < 3);
			auto nxt_cur_cnt = cur_cnt;
			auto nxt_tgt_cnt = tgt_cnt;
			nxt_cur_cnt[S[i] - '0']--;
			if (nxt_tgt_cnt[v] == 0) continue;
			nxt_tgt_cnt[v]--;
			if (cost(nxt_cur_cnt, nxt_tgt_cnt) + (S[i] - '0' != v) != cost(cur_cnt, tgt_cnt)) {
				continue;
			}
			res += char(v + '0');
			cur_cnt = nxt_cur_cnt;
			tgt_cnt = nxt_tgt_cnt;
			break;
		}
	}
	cout << res << '\n';

	return 0;
}