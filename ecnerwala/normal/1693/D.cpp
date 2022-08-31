#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int> A(N);
	for (auto& a : A) { cin >> a; a--; }

	std::vector<int> nxt_bad(N, N);
	for (int incr = 0; incr < 2; incr++) {

		// First, we generate when each guy is pareto optimal from the back
		std::vector<std::tuple<int, bool, std::pair<int, int>>> evts2; evts2.reserve(2*N);

		// index, val
		std::vector<std::pair<int, int>> pref_mins; pref_mins.reserve(N);
		std::vector<std::pair<int, int>> pref_mins_2; pref_mins_2.reserve(N);
		for (int i = N-1; i >= 0; i--) {
			int z = int(pref_mins.size());
			while (z > 0 && A[i] < pref_mins[z-1].second) {
				z--;
			}
			assert(z >= 0);
			if (z < int(pref_mins.size())) {
				int y = int(pref_mins_2.size());
				while (y > 0 && pref_mins[z].second < pref_mins_2[y-1].second) {
					y--;
					evts2.push_back({i, false, pref_mins_2[y]});
				}
				pref_mins_2.resize(y);
			}

			for (int k = z; k < int(pref_mins.size()); k++) {
				evts2.push_back({i, true, pref_mins[k]});
			}
			pref_mins_2.insert(pref_mins_2.end(), pref_mins.begin() + z, pref_mins.end());

			pref_mins.resize(z);
			pref_mins.push_back({i, A[i]});
		}

		std::vector<std::pair<int, int>> suff_maxs; suff_maxs.reserve(N);

		std::reverse(evts2.begin(), evts2.end());
		/*
		cerr << "events" << '\n';
		for (auto [i, do_push, val] : evts2) {
			cerr << i << ' ' << do_push << ' ' << val.first << ' ' << val.second << '\n';
		}
		*/

		auto evt_it = evts2.begin();
		for (int i = 0; i < N; i++) {
			for (; evt_it != evts2.end() && std::get<0>(*evt_it) == i; evt_it++) {
				auto [_, do_push, val] = *evt_it;
				if (do_push) {
					assert(!pref_mins_2.empty() && pref_mins_2.back() == val);
					pref_mins_2.pop_back();
				} else {
					pref_mins_2.push_back(val);
				}
			}

			while (!suff_maxs.empty() && A[i] > suff_maxs.back().second) {
				int j = suff_maxs.back().first;
				suff_maxs.pop_back();
				int mi = -1;
				int ma = int(pref_mins_2.size());
				while (ma - mi > 1) {
					int md = (mi + ma) / 2;
					if (pref_mins_2[md].second < A[j]) {
						mi = md;
					} else {
						ma = md;
					}
				}
				if (mi != -1) {
					//cerr << "nxt_bad " << j << ' ' << i << ' ' << pref_mins_2[mi].first << '\n';
					nxt_bad[j] = std::min(nxt_bad[j], pref_mins_2[mi].first);
				}
			}
			suff_maxs.push_back({i, A[i]});
		}
		assert(evt_it == evts2.end());

		for (auto& a : A) { a = N-1-a; }
	}

	for (int i = N-1; i > 0; i--) {
		nxt_bad[i-1] = std::min(nxt_bad[i-1], nxt_bad[i]);
	}
	int64_t ans = 0;
	for (int i = 0; i < N; i++) {
		ans += nxt_bad[i] - i;
	}
	cout << ans << '\n';

	return 0;
}

// Bad if there's a 3412 or a 2143