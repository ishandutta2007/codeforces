#include <bits/stdc++.h>

struct counter {
	int64_t x = 0, y = 0, z = 0;
	int64_t xy = 0, yz = 0, xyz = 0;
	void add_z() {
		z++;
		yz += y;
		xyz += xy;
	}
	void add_y() {
		y++;
		xy += x;
	}
	void add_x() {
		x++;
	}
	void add_v(int v) {
		if (v == 0) add_x();
		else if (v == 1) add_y();
		else if (v == 2) add_z();
		else assert(false);
	}
};

struct pref_counter {
	int64_t x = 0, xy = 0, xyz = 0;
	void add_counter(counter c) {
		xyz += c.xyz;
		xyz += x * c.yz;
		xyz += xy * c.z;
		xy += c.xy;
		xy += x * c.y;
		x += c.x;
	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	vector<int> A0(N); for (auto& a : A0) { cin >> a; a--; }
	vector<int> PB(N); for (auto& pb : PB) { cin >> pb; pb--; }
	vector<int> PC(N); for (auto& pc : PC) { cin >> pc; pc--; }

	int N_RESP = 0;
	vector<tuple<int, int, int>> queries(Q);
	for (int q = 0; q < Q; q++) {
		int op; cin >> op;
		if (op == 1) {
			int k, x; cin >> k >> x; k--, x--;
			queries[q] = {op, k, x};
		} else if (op == 2) {
			int r; cin >> r;
			queries[q] = {op, r, N_RESP++};
		} else assert(false);
	}

	vector<int64_t> ans(N_RESP, 0);

	vector<vector<int>> value_starts(N);
	vector<vector<pair<int, int>>> value_changes(N);
	vector<vector<pair<int, int>>> value_buckets(N);
	vector<vector<int>> value_ends(N);

	const int Q_BUCKET = 100;
	const int N_BUCKET = 400;

	{
		vector<bool> changed(N);
		vector<array<int64_t, 2>> dp(N);
		vector<int64_t> pref_ans(N+1);
		vector<int> A = A0;
		vector<int> B(N);
		vector<int> C(N);
		for (int i = 0; i < N; i++) {
			B[i] = PB[A[i]], C[i] = PC[A[i]];
		}
		for (int i = 0; i < N; i++) {
			value_starts[B[i]].push_back(3*i+0);
			value_starts[A[i]].push_back(3*i+1);
			value_starts[C[i]].push_back(3*i+2);
		}
		for (int qlo = 0; qlo < Q; qlo += Q_BUCKET) {
			int qhi = min(Q, qlo + Q_BUCKET);
			for (int i = 0; i < N; i++) {
				changed[i] = 0;
			}
			for (int q = qlo; q < qhi; q++) {
				auto [op, p, v] = queries[q];
				if (op == 1) {
					changed[A[p]] = changed[B[p]] = changed[C[p]] = true;
					value_changes[B[p]].push_back({3*p+0, q});
					value_changes[A[p]].push_back({3*p+1, q});
					value_changes[C[p]].push_back({3*p+2, q});
					A[p] = v;
					B[p] = PB[v];
					C[p] = PC[v];
					value_changes[B[p]].push_back({3*p+0, q});
					value_changes[A[p]].push_back({3*p+1, q});
					value_changes[C[p]].push_back({3*p+2, q});
					changed[A[p]] = changed[B[p]] = changed[C[p]] = true;
				}
			}

			for (int v = 0; v < N; v++) {
				if (changed[v]) value_buckets[v].push_back({qlo, qhi});
			}

			for (int v = 0; v < N; v++) dp[v] = {0,0};
			pref_ans[0] = 0;
			int64_t cur_ans = 0;
			for (int i = 0; i < N; i++) {
				if (!changed[C[i]]) {
					cur_ans += dp[C[i]][1];
				}
				if (!changed[A[i]]) {
					dp[A[i]][1] += dp[A[i]][0];
				}
				if (!changed[B[i]]) {
					dp[B[i]][0]++;
				}
				pref_ans[i+1] = cur_ans;
			}

			for (int q = qlo; q < qhi; q++) {
				auto [op, r, o] = queries[q];
				if (op == 2) {
					ans[o] += pref_ans[r];
				}
			}
		}
		for (int i = 0; i < N; i++) {
			value_ends[B[i]].push_back(3*i+0);
			value_ends[A[i]].push_back(3*i+1);
			value_ends[C[i]].push_back(3*i+2);
		}
	}

	{
		vector<array<bool, 3>> on(N, array<bool, 3>{false, false, false});
		vector<counter> counters(N);
		vector<pref_counter> pref_counters((N + N_BUCKET - 1) / N_BUCKET);
		auto update_counter = [&](int loc) {
			int i = loc / 3;
			int v = loc % 3;
			on[i][v] ^= 1;
			// recompute prefixes
			int b = i / N_BUCKET;
			counter cur;
			for (int z = b*N_BUCKET; z < min(N, (b+1)*N_BUCKET); z++) {
				if (on[z][2]) cur.add_z();
				if (on[z][1]) cur.add_y();
				if (on[z][0]) cur.add_x();
				counters[z] = cur;
			}
			for (int z = b; z+1 < int(pref_counters.size()); z++) {
				pref_counters[z+1] = pref_counters[z];
				pref_counters[z+1].add_counter(counters[(z+1)*N_BUCKET-1]);
			}
		};
		for (int v = 0; v < N; v++) {
			for (int loc : value_starts[v]) update_counter(loc);
			auto it = value_changes[v].begin();
			for (auto [qlo, qhi] : value_buckets[v]) {
				for (int q = qlo; q < qhi; q++) {
					for (; it != value_changes[v].end() && it->second == q; ++it) {
						update_counter(it->first);
					}
					auto [op, r, o] = queries[q];
					if (op == 2) {
						pref_counter ctr = pref_counters[(r-1)/N_BUCKET];
						ctr.add_counter(counters[r-1]);
						ans[o] += ctr.xyz;
					}
				}
			}
			for (int loc : value_ends[v]) update_counter(loc);
		}
	}

	for (int64_t v : ans) cout << v << '\n';

	return 0;
}