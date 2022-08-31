#include <bits/stdc++.h>
#include <random>

static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
std::mt19937 mt(FIXED_RANDOM);

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M, P; cin >> N >> M >> P;
	vector<int64_t> msk(N);
	for (auto& a : msk) {
		string s; cin >> s;
		for (int i = 0; i < M; i++) {
			a += (int64_t(s[i] - '0')) << i;
		}
	}

	int ans = 0;
	int64_t best_msk = 0;

	vector<int> cnt(1 << P);
	for (int z = 0; z < 100; z++) {
		const int64_t cur_msk = msk[std::uniform_int_distribution(0, N-1)(mt)];
		const int cur_p = __builtin_popcountll(cur_msk);
		std::fill(cnt.begin(), cnt.begin() + (1 << cur_p), 0);
		for (auto m : msk) {
			int compressed = 0;
			int64_t v = cur_msk;
			for (int i = 0; i < cur_p; i++) {
				compressed |= bool(m & (v & -v)) << i;
				v -= (v & -v);
			}
			cnt[compressed]++;
		}

		for (int b = 0; b < cur_p; b++) {
			for (int m = 0; m < (1 << cur_p); m++) {
				if (m & (1 << b)) {
					m += (1 << b) - 1;
					continue;
				}
				cnt[m] += cnt[m + (1 << b)];
			}
		}
		for (int m = (1 << cur_p) - 1; m >= 0; m--) {
			if (cnt[m] * 2 >= N) {
				int c = __builtin_popcount(m);
				if (c > ans) {
					ans = c;
					best_msk = 0;
					int64_t v = cur_msk;
					for (int i = 0; i < cur_p; i++) {
						if (m & (1 << i)) {
							best_msk |= (v & -v);
						}
						v -= (v & -v);
					}
				}
			}
		}
	}

	for (int b = 0; b < M; b++) {
		cout << ((best_msk >> b) & 1);
	}
	cout << '\n';

	return 0;
}