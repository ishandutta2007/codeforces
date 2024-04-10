#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, C, Q; cin >> N >> C >> Q;
		vector<int> P(N); for (auto& a : P) cin >> a;

		const int64_t INF = 2e18;

		vector<vector<array<int, 2>>> cur_flip(C+1);
		vector<vector<int64_t>> weight(C+1);
		cur_flip[0] = vector<array<int, 2>>(1, {N, N});
		weight[0] = vector<int64_t>({0, 1});

		vector<vector<array<int, 2>>> bounds(C+1, vector<array<int, 2>>(N+1, {0,1}));
		vector<vector<int64_t>> node_weight(C+1, vector<int64_t>(N+1, 1));

		for (int c = 1; c <= C; c++) {
			cur_flip[c] = vector<array<int, 2>>(2*N*c+1, {N,N});
			weight[c] = vector<int64_t>(2*N*c+2, 0);

			int lo = N*c;
			int hi = N*c+1;
			weight[c][lo] = 0;
			weight[c][hi] = 1;
			bounds[c][N] = {lo, hi};
			for (int i = N-1; i >= 0; i--) {
				// we could do nothing
				vector<pair<int, int>> opts(min(N-i, c+1));
				for (int v = 0; v < min(N-i, c+1); v++) {
					opts[v] = {P[i+v], v};
				}
				sort(opts.begin(), opts.end());
				int x0 = 0;
				while (opts[x0].second != 0) x0++;
				for (int z = x0-1; z >= 0; z--) {
					int v = opts[z].second;
					assert(v != 0);
					auto w = node_weight[c-v][i+v+1];
					weight[c][lo-1] = weight[c][lo] - w;
					cur_flip[c][lo-1] = {i, i+v};
					lo--;
				}
				for (int z = x0+1; z < int(opts.size()); z++) {
					int v = opts[z].second;
					assert(v != 0);
					auto w = node_weight[c-v][i+v+1];
					weight[c][hi+1] = weight[c][hi] + w;
					cur_flip[c][hi] = {i, i+v};
					hi++;
				}
				node_weight[c][i] = weight[c][hi] - weight[c][lo];
				bounds[c][i] = {lo, hi};
			}
		}

		auto query = [&](int idx, int64_t perm) -> int {
			int cur_c = C;
			int cur_idx = 0;
			if (perm > node_weight[cur_c][cur_idx]) return -1;
			while (true) {
				// look for the current flip
				auto [mi, ma] = bounds[cur_c][cur_idx];
				while (ma - mi > 1) {
					int md = (mi + ma) / 2;
					if (perm <= weight[cur_c][md] - weight[cur_c][mi]) {
						ma = md;
					} else {
						perm -= weight[cur_c][md] - weight[cur_c][mi];
						mi = md;
					}
				}
				assert(1 <= perm && perm <= weight[cur_c][ma] - weight[cur_c][mi]);
				auto [f1, f2] = cur_flip[cur_c][mi];
				if (idx < f1) {
					return P[idx];
				} else if (f1 <= idx && idx <= f2) {
					return P[f1 + f2 - idx];
				} else {
					cur_c -= f2 - f1;
					cur_idx = f2+1;
				}
			}
		};

		for (int q = 0; q < Q; q++) {
			int idx; int64_t perm; cin >> idx >> perm; idx--;
			cout << query(idx, perm) << '\n';
		}
	}

	return 0;
}