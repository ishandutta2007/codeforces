#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, Q; cin >> N >> Q;
	vector<int64_t> cnt(N);
	for (auto& c : cnt) cin >> c;

	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			int pos, val; cin >> pos >> val;
			cnt[pos] = val;
		} else if (op == 2) {
			int x; int64_t k; cin >> x >> k;
			cout << [&]() -> int64_t {
				int64_t cnt_need = k;
				int64_t tot_need = k;
				int64_t ans = k;
				for (int i = 0; i < N; i++) {
					int64_t num_take = min(cnt[i], cnt_need >> max(0, i-x));
					cnt_need -= num_take << max(0, i-x);
					ans -= num_take;
					if (tot_need == 0 || num_take > ((tot_need-1) >> i)) tot_need = 0;
					else tot_need -= num_take << i;

					if (cnt[i] > num_take) {
						// we have an extra
						if (tot_need == 0) return ans;
						assert(0 < tot_need && tot_need <= cnt_need);
						if (x == 0) {
							assert(tot_need == cnt_need);
							// we need to take exactly that many
							return ans + i - x - 1 - __builtin_popcountll(cnt_need-1);
						} else {
							return ans + i - x - 1 - (63 - __builtin_clzll(cnt_need));
						}
					}
				}

				if (tot_need == 0) return ans;
				else return -1;
			}() << '\n';
		} else assert(false);
	}

	return 0;
}