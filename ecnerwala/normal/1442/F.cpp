#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M, Q; cin >> N >> M >> Q;
	vector<vector<int>> adj(N);
	vector<vector<int>> radj(N);
	vector<int> outDeg(N);
	for (int e = 0; e < M; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		radj[v].push_back(u);
		outDeg[u]++;
	}
	int L = min(N, 20);
	vector<int> los; los.reserve(L);
	for (int i = 0; i < N && int(los.size()) < L; i++) {
		if (!outDeg[i]) {
			los.push_back(i);
		}
	}
	for (int z = 0; int(los.size()) < L; z++) {
		int i = los[z];
		for (int j : radj[i]) {
			if (!--outDeg[j]) {
				los.push_back(j);
				if (int(los.size()) == L) break;
			}
		}
	}
	assert(int(los.size()) == L);
	vector<int> lo_idx(N, -1);
	for (int i = 0; i < L; i++) {
		lo_idx[los[i]] = i;
	}

	vector<tuple<char, int, int>> ops;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < i; j++) {
			ops.push_back({'+', los[i], los[j]});
		}
	}
	vector<int> idx(1 << L, -1);
	for (int i = 0; i < N; i++) {
		if (lo_idx[i] != -1) continue;
		ops.push_back({'+', i, i});

		int cur_msk = 0;
		for (int j : adj[i]) {
			if (lo_idx[j] != -1) {
				cur_msk ^= 1 << lo_idx[j];
			}
		}
		int new_msk = [&]() {
			if (idx[cur_msk] == -1) {
				return cur_msk;
			}
			for (int a = 0; a < L; a++) {
				int cnd = cur_msk ^ (1 << a);
				if (idx[cnd] == -1) {
					return cnd;
				}
			}
			for (int a = 0; a < L; a++) {
				for (int b = a+1; b < L; b++) {
					int cnd = cur_msk ^ (1 << a) ^ (1 << b);
					if (idx[cnd] == -1) {
						return cnd;
					}
				}
			}
			for (int a = 0; a < L; a++) {
				for (int b = a+1; b < L; b++) {
					for (int c = b+1; c < L; c++) {
						int cnd = cur_msk ^ (1 << a) ^ (1 << b) ^ (1 << c);
						if (idx[cnd] == -1) {
							return cnd;
						}
					}
				}
			}
			assert(false);
		}();

		assert(idx[new_msk] == -1);
		idx[new_msk] = i;
		for (int a = 0; a < L; a++) {
			if ((cur_msk ^ new_msk) & (1 << a)) {
				if (cur_msk & (1 << a)) {
					ops.push_back({'-', i, los[a]});
				} else {
					ops.push_back({'+', i, los[a]});
				}
			}
		}
	}

	cout << ops.size() << '\n';
	for (auto [v, a, b] : ops) {
		cout << v << ' ' << a+1 << ' ' << b+1 << '\n';
	}
	cout << flush;

	while (Q--) {
		int solve = [&]() -> int {
			int cur_msk = 0;
			for (int a = 0; a < L; a++) {
				cout << '?' << ' ' << 1 << ' ' << los[a]+1 << '\n' << flush;
				string resp; cin >> resp;
				if (resp == "Slow") {
					// wrong answer
					exit(0);
				} else if (resp == "Lose") {
					return los[a];
				} else if (resp == "Win") {
					cur_msk ^= 1 << a;
				} else if (resp == "Draw") {
					// do nothing
				} else assert(false);
			}
			assert(idx[cur_msk] != -1);
			return idx[cur_msk];
		}();
		cout << '!' << ' ' << solve+1 << '\n' << flush;
		string resp; cin >> resp;
		if (resp == "Correct") {
			// good
		} else if (resp == "Wrong") {
			exit(0);
		} else assert(false);
	}

	return 0;
}