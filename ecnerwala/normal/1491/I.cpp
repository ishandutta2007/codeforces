#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	struct animal_t {
		int a, b, c;
		int idx;
	};
	vector<animal_t> V(N);
	for (auto& a : V) cin >> a.a >> a.b >> a.c;
	for (int i = 0; i < N; i++) V[i].idx = i;

	assert(V[0].a != V[1].a);
	if (V[0].a > V[1].a) swap(V[0], V[1]);
	assert(V[1].a > V[0].a && V[1].a > V[0].b);

	int64_t tot_time = 1;
	std::rotate(V.begin(), V.begin()+1, V.end());

	vector<bool> big(N);
	vector<animal_t> smalls; smalls.reserve(N);
	vector<animal_t> bigs; bigs.reserve(N);
	vector<pair<int, int>> q(2*N);

	while (true) {
		assert(V[0].a > V[N-1].b);
		big[0] = true;
		for (int i = 1; i < N; i++) {
			big[i] = V[i].a > V[i-1].b;
		}

		int64_t best_win_time = -1;
		int best_win_idx = -1;
		int cur_win_idx = -1;
		int cur_win_bigs = -1;

		int64_t evt_time = -1;
		int cnt_big = 0;
		int lo = 0, hi = 0;

		for (int z = 0; z < 2; z++) {
			for (int i = 0; i < N; i++) {
				if (big[i]) {
					{
						int j = (i+1)%N;
						bool can_win = (V[i].c > V[(!big[j] ? (j == N-1 ? 1 : j+1) : j)].a);
						if (can_win) {
							cur_win_idx = V[i].idx;
							cur_win_bigs = 0;
						} else if (cur_win_idx != -1) {
							cur_win_bigs++;
						}
					}

					{
						cnt_big++;
						while (hi > lo && V[i].b <= q[hi-1].first) --hi;
						q[hi++] = {V[i].b, cnt_big};
					}
				} else {
					if (cur_win_idx != -1) {
						int64_t cur_win_time = int64_t(cur_win_bigs) * (N-1) + i + 1;
						if (best_win_time == -1 || cur_win_time < best_win_time) {
							best_win_time = cur_win_time;
							best_win_idx = cur_win_idx;
						}
					}

					if (hi > lo && V[i].a > q[lo].first) {
						while (hi > lo && V[i].a > q[lo].first) lo++;

						int64_t cnd_time = int64_t(cnt_big - q[lo-1].second) * (N-1) + i;
						if (evt_time == -1 || cnd_time < evt_time) {
							evt_time = cnd_time;
						}
					}
				}
			}
		}

		if (best_win_time == -1 && evt_time == -1) {
			cout << -1 << ' ' << -1 << '\n';
			break;
		}
		if (best_win_time != -1 && (evt_time == -1 || best_win_time <= evt_time)) {
			cout << best_win_idx << ' ' << tot_time + best_win_time << '\n';
			break;
		}

		assert(evt_time != -1);

		tot_time += evt_time;

		// go forwards by evt_time
		int small_idx = int((evt_time - 1) % (N-1)) + 1;
		int num_shifts = int((evt_time - small_idx) / (N-1));

		int big_idx = small_idx;
		while (!big[big_idx]) big_idx = (big_idx ? big_idx : N) - 1;

		for (int i = small_idx; true; ) {
			if (!big[i]) smalls.push_back(V[i]);
			i++, i %= N;
			if (i == small_idx) break;
		}
		for (int i = big_idx; true; ) {
			if (big[i]) bigs.push_back(V[i]);
			i++, i %= N;
			if (i == big_idx) break;
		}

		std::rotate(bigs.begin(), bigs.end() - num_shifts, bigs.end());

		reverse(smalls.begin(), smalls.end());
		reverse(bigs.begin(), bigs.end());

		std::rotate(big.begin()+1, big.begin()+small_idx, big.end());
		for (int i = 0; i < N; i++) {
			if (big[i]) {
				V[i] = bigs.back();
				bigs.pop_back();
			} else {
				V[i] = smalls.back();
				smalls.pop_back();
			}
		}

		assert(V[1].a > V[0].b);

		std::rotate(V.begin(), V.begin()+1, V.end());
	}

	return 0;
}