#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;

		std::vector<int64_t> pref(N+1);
		for (int i = 0; i < N; i++) {
			pref[i+1] = pref[i] + ((i & 1) ? -A[i] : A[i]);
		}
		std::deque<std::pair<int64_t, int>> mins, maxs;

		std::vector<std::pair<int64_t, int>> vals(N+1);
		for (int i = 0; i <= N; i++) vals[i] = {pref[i], i};
		std::sort(vals.begin(), vals.end());

		int64_t ans = 0;
		for (int i = 0, j = 0; i <= N; i++) {
			// push i
			if (i & 1) {
				// pref[i] is a max
				while (!maxs.empty() && pref[i] <= maxs.back().first) maxs.pop_back();
				maxs.push_back({pref[i], i});
			} else {
				while (!mins.empty() && pref[i] >= mins.back().first) mins.pop_back();
				mins.push_back({pref[i], i});
			}
			while (j < i && maxs.front().first < mins.front().first) {
				assert(((i & 1) ? maxs : mins).size() == 1);
				if (maxs.front().second == j) {
					maxs.pop_front();
				}
				if (mins.front().second == j) {
					mins.pop_front();
				}
				j++;
			}
			assert(i == j || maxs.front().first >= mins.front().first);
			int lo = j;
			if (i & 1) {
				assert(maxs.back().second == i);
				if (maxs.size() > 1) {
					maxs.pop_back();
					lo = maxs.back().second + 1;
					maxs.push_back({pref[i], i});
				}
			} else {
				assert(mins.back().second == i);
				if (mins.size() > 1) {
					mins.pop_back();
					lo = mins.back().second + 1;
					mins.push_back({pref[i], i});
				}
			}
			auto it = std::lower_bound(vals.begin(), vals.end(), std::pair<int64_t, int>{pref[i], lo});
			auto jt = std::lower_bound(vals.begin(), vals.end(), std::pair<int64_t, int>{pref[i], i});
			ans += int(jt - it);
		}
		cout << ans << '\n';
	}

	return 0;
}