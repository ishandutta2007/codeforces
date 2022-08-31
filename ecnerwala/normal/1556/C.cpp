#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int64_t> C(N);
	for (int i = 0; i < N; i++) {
		cin >> C[i];
		if (i & 1) C[i] = -C[i];
	}

	std::vector<int64_t> pref(N+1);
	for (int i = 0; i < N; i++) pref[i+1] = pref[i] + C[i];

	std::vector<int64_t> vals = pref;
	std::sort(vals.begin(), vals.end());
	vals.resize(std::unique(vals.begin(), vals.end()) - vals.begin());

	int64_t ans = 0;
	for (int z = 0; z < int(vals.size()); z++) {
		if (z) {
			int64_t lo = vals[z-1], hi = vals[z];
			bool has_open = false;
			for (int i = 0; i < N; i++) {
				if (pref[i] >= hi && lo >= pref[i+1]) {
					if (has_open) {
						ans += hi - lo - 1;
						has_open = false;
					}
				} else if (pref[i] <= lo && hi <= pref[i+1]) {
					assert(!has_open);
					has_open = true;
				}
			}
		}

		{
			int64_t v = vals[z];
			int num_open = 0;
			for (int i = 0; i <= N; i++) {
				if (!(i&1)) {
					if (pref[i] == v) {
						ans += num_open;
						num_open++;
					} else if (pref[i] < v) {
						ans += num_open;
						num_open = 0;
					}
				} else {
					if (pref[i-1] < v && pref[i] > v) {
						assert(num_open == 0);
						num_open = 1;
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}