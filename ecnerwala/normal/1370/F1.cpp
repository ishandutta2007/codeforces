#include<bits/stdc++.h>

void solve() {
	using namespace std;
	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto query = [&](const vector<int>& v) -> pair<int, int> {
		assert(!v.empty());
		cout << '?' << ' ' << v.size();
		for (int i : v) cout << ' ' << i+1;
		cout << '\n' << flush;
		int x, d; cin >> x >> d;
		if (x == -1 && d == -1) {
			exit(0);
		}
		x--;
		return {x, d};
	};
	vector<int> all(N); iota(all.begin(), all.end(), 0);
	auto [ROOT, D] = query(all);
	assert(D >= 1);
	assert((D+1) / 2 >= 1);

	vector<int> depth(N, -1);
	vector<int> par(N, -1);
	depth[ROOT] = 0;
	vector<int> q; q.reserve(N);
	q.push_back(ROOT);
	for (int z = 0; z < N; z++) {
		int cur = q[z];
		for (int nxt : adj[cur]) {
			if (depth[nxt] == -1) {
				depth[nxt] = depth[cur]+1;
				par[nxt] = cur;
				q.push_back(nxt);
			}
		}
	}

	vector<int> depth_d2;
	for (int i = 0; i < N; i++) {
		if (depth[i] == (D+1)/2) {
			depth_d2.push_back(i);
		}
	}
	auto [f_d2, D_f_d2] = query(depth_d2);
	assert(D_f_d2 == D);
	int f_sub = f_d2;
	while (par[f_sub] != ROOT) f_sub = par[f_sub];

	vector<bool> is_f(N);
	for (int cur : q) {
		if (cur == ROOT) continue;
		else if (cur == f_sub) is_f[cur] = true;
		else is_f[cur] = is_f[par[cur]];
	}

	int mi = 0;
	int ma = D/2 + 1;
	int s = ROOT;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		vector<int> vec; vec.reserve(N);
		for (int i = 0; i < N; i++) {
			if (!is_f[i] && depth[i] == md) {
				vec.push_back(i);
			}
		}
		if (vec.empty()) {
			ma = md; continue;
		}
		auto [x, d] = query(vec);
		if (d == D) {
			mi = md;
			s = x;
		} else {
			ma = md;
		}
	}
	vector<int> vec; vec.reserve(N);
	for (int i = 0; i < N; i++) {
		if (is_f[i] && depth[i] == D - depth[s]) {
			vec.push_back(i);
		}
	}
	auto [f, d_f] = query(vec);
	cout << '!' << ' ' << s+1 << ' ' << f+1 << '\n' << flush;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		solve();
		string good; cin >> good;
		if (good == "Correct") {
			continue;
		} else if (good == "Incorrect") {
			exit(0);
		} else assert(false);
	}

	return 0;
}