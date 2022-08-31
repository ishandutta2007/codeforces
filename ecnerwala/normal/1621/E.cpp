#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int NT, M; cin >> NT >> M;
		std::vector<int> teachers(NT);

		for (auto& a : teachers) cin >> a;
		std::sort(teachers.begin(), teachers.end());
		teachers.erase(teachers.begin(), teachers.begin() + (NT-M));

		std::vector<std::pair<int, std::vector<std::pair<int, int>>>> groups(M);
		int S = 0;
		for (int i = 0; i < M; i++) {
			int K; cin >> K;
			groups[i].second.resize(K);
			int64_t sum = 0;
			for (auto& [a, v] : groups[i].second) {
				cin >> a;
				sum += a;
				v = (S++);
			}
			groups[i].first = int((sum + K - 1) / K);
		}
		std::sort(groups.begin(), groups.end(), [&](const auto& a, const auto& b) { return a.first < b.first; });

		std::vector<int> pref_bad(M+1);
		for (int i = 0; i < M; i++) {
			pref_bad[i+1] = pref_bad[i] + (groups[i].first > teachers[i]);
		}
		std::vector<int> pref_l_shift_bad(M);
		for (int i = 0; i+1 < M; i++) {
			pref_l_shift_bad[i+1] = pref_l_shift_bad[i] + (groups[i].first > teachers[i+1]);
		}
		std::vector<int> pref_r_shift_bad(M);
		for (int i = 0; i+1 < M; i++) {
			pref_r_shift_bad[i+1] = pref_r_shift_bad[i] + (groups[i+1].first > teachers[i]);
		}

		std::string res(S, '?');
		for (int i = 0; i < M; i++) {
			int K = int(groups[i].second.size());
			int64_t sum = 0;
			for (auto& [a, _] : groups[i].second) {
				sum += a;
			}
			assert(groups[i].first == (sum + K - 1) / K);
			for (auto [a, idx] : groups[i].second) {
				int nv = int((sum - a + (K-1) - 1) / (K-1));
				int lo = -1, hi = M;
				while (hi - lo > 1) {
					int md = lo + (hi - lo) / 2;
					if (nv < groups[md].first) hi = md;
					else lo = md;
				}
				int cnt_bad = 0;
				if (hi <= i) {
					cnt_bad += pref_bad[hi] - pref_bad[0];
					cnt_bad += pref_bad[M] - pref_bad[i+1];
					cnt_bad += pref_l_shift_bad[i] - pref_l_shift_bad[hi];
					cnt_bad += (nv > teachers[hi]);
				} else if (lo >= i) {
					cnt_bad += pref_bad[i] - pref_bad[0];
					cnt_bad += pref_bad[M] - pref_bad[lo+1];
					cnt_bad += pref_r_shift_bad[lo] - pref_r_shift_bad[i];
					cnt_bad += (nv > teachers[lo]);
				} else assert(false);
				res[idx] = '0' + !cnt_bad;
			}
		}
		cout << res << '\n';
	}

	return 0;
}