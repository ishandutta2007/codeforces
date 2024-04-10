#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int64_t> A(N);
	for (auto& a : A) cin >> a;
	std::vector<int> P(N);
	for (auto& p : P) { cin >> p; p--; }

	int Q; cin >> Q;
	using query_t = std::tuple<int, int, int>;
	std::vector<query_t> queries(Q);
	for (int q = 0; q < Q; q++) {
		int op; cin >> op;
		if (op == 1) {
			int l, r; cin >> l >> r; l--;
			queries[q] = {op, l, r};
		} else if (op == 2) {
			int v, x; cin >> v >> x; v--;
			queries[q] = {op, v, x};
		} else if (op == 3) {
			int i, j; cin >> i >> j; i--, j--;
			queries[q] = {op, i, j};
		} else assert(false);
	}

	const int QUERY_BLOCK = 500;

	std::vector<bool> is_swapped(N);
	std::vector<bool> val_is_swapped(N);
	std::vector<bool> is_updated(N);

	std::vector<int> is_cut(N+1);
	std::vector<int> block_id(N+1);

	std::vector<int> cc_root(N);
	std::vector<int> big_id(N);
	std::vector<int> dest(N); // -1 means cycle

	const int MAX_BLOCKS = QUERY_BLOCK * 2 + 10;
	std::vector<std::array<int, MAX_BLOCKS>> bigs;
	std::vector<int64_t> big_weight;

	bigs.reserve(QUERY_BLOCK * 5);
	big_weight.reserve(QUERY_BLOCK * 5);

	std::vector<int64_t> block_sum; block_sum.reserve(N);

	for (int qlo = 0, qhi; qlo < Q; qlo = qhi) {
		qhi = min(Q, qlo + QUERY_BLOCK);

		std::fill(is_swapped.begin(), is_swapped.end(), false);
		std::fill(val_is_swapped.begin(), val_is_swapped.end(), false);
		std::fill(is_updated.begin(), is_updated.end(), false);

		std::fill(is_cut.begin(), is_cut.end(), 0);
		is_cut[0] = is_cut[N] = true;

		for (int q = qlo; q < qhi; q++) {
			auto [op, x, y] = queries[q];
			if (op == 3) {
				is_swapped[x] = is_swapped[y] = true;
				val_is_swapped[P[x]] = val_is_swapped[P[y]] = true;
			} else if (op == 1) {
				is_cut[x] = is_cut[y] = true;
			} else if (op == 2) {
				is_updated[x] = true;
			}
		}

		block_id[0] = 0;
		for (int i = 1; i <= N; i++) {
			block_id[i] = block_id[i-1] + is_cut[i];
		}
		int NUM_BLOCKS = block_id[N];
		assert(NUM_BLOCKS <= MAX_BLOCKS);

		block_sum.assign(NUM_BLOCKS+1, 0);
		for (int i = 0; i < N; i++) {
			block_sum[block_id[i]+1] += A[i];
		}
		for (int i = 0; i < NUM_BLOCKS; i++) {
			block_sum[i+1] += block_sum[i];
		}

		bigs.clear();
		std::fill(cc_root.begin(), cc_root.end(), -1);

		// First, build up the chains
		for (int i = 0; i < N; i++) {
			if (val_is_swapped[i]) {
				assert(cc_root[i] == -1);
				cc_root[i] = i;
				big_id[i] = int(bigs.size());
				bigs.emplace_back();
				bigs.back().fill(0);

				int cur;
				for (cur = i; true; cur = P[cur]) {
					cc_root[cur] = i;
					bigs.back()[block_id[cur]]++;
					if (is_swapped[cur]) break;
				}
				dest[i] = cur;
			}
		}

		// Now we build the cycles
		for (int i = 0; i < N; i++) {
			if (cc_root[i] == -1 && is_updated[i]) {
				// build the cycle starting from i
				cc_root[i] = i;
				dest[i] = -1;

				big_id[i] = int(bigs.size());
				bigs.emplace_back();
				bigs.back().fill(0);

				for (int cur = P[i]; ; cur = P[cur]) {
					cc_root[cur] = i;
					bigs.back()[block_id[cur]]++;
					if (cur == i) break;
				}
			}
		}

		for (auto& b : bigs) {
			int pref = 0;
			for (int i = 0; i <= NUM_BLOCKS; i++) {
				int v = b[i];
				b[i] = pref;
				pref += v;
			}
		}

		big_weight.assign(bigs.size(), 0);

		for (int q = qlo; q < qhi; q++) {
			auto [op, x, y] = queries[q];
			if (op == 1) {
				y = block_id[y];
				x = block_id[x];
				int64_t ans = block_sum[y] - block_sum[x];
				for (int b = 0; b < int(bigs.size()); b++) {
					ans += big_weight[b] * (bigs[b][y] - bigs[b][x]);
				}
				cout << ans << '\n';
			} else if (op == 2) {
				x = cc_root[x];
				for (int cur = x; true; ) {
					assert(cc_root[cur] == cur);

					big_weight[big_id[cur]] += y;

					if (dest[cur] == -1) break;
					cur = P[dest[cur]];
					if (cur == x) break;
				}
			} else if (op == 3) {
				std::swap(P[x], P[y]);
			} else assert(false);
		}

		for (int i = 0; i < N; i++) {
			if (cc_root[i] != -1) {
				A[i] += big_weight[big_id[cc_root[i]]];
			}
		}
	}

	return 0;
}