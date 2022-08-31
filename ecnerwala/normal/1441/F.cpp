#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;

	while (T--) {
		int N, M; cin >> N >> M;
		using pt_t = complex<int>;
		vector<pt_t> pts(N);
		for (auto& pt : pts) { int x, y; cin >> x >> y; pt = {x,y}; }
		vector<int> dest(2*M);
		vector<vector<pair<int, int>>> adj(N);
		for (int e = 0; e < M; e++) {
			int u, v; cin >> u >> v; u--, v--;
			dest[2*e+0] = v;
			adj[u].push_back({2*e+0, v});
			dest[2*e+1] = u;
			adj[v].push_back({2*e+1, u});
		}

		vector<int> nxt(2*M), prv(2*M);

		// Build the DCEL
		for (int i = 0; i < N; i++) {
			sort(adj[i].begin(), adj[i].end(), [&](auto e1, auto e2) {
				pt_t p1 = pts[e1.second] - pts[i], p2 = pts[e2.second] - pts[i];
				bool d1 = make_pair(p1.imag(), p1.real()) > make_pair(0,0);
				bool d2 = make_pair(p2.imag(), p2.real()) > make_pair(0,0);
				if (d1 != d2) return d1 < d2;
				return int64_t(p1.real()) * int64_t(p2.imag()) - int64_t(p1.imag()) * int64_t(p2.real()) > 0;
			});
			for (int z = 0; z < int(adj[i].size()); z++) {
				int e1 = adj[i][z].first ^ 1;
				int e2 = adj[i][(z+1)%int(adj[i].size())].first;
				nxt[e1] = e2;
				prv[e2] = e1;
			}
		}

		vector<int> ccid(2*M, -1);
		for (int e = 0; e < 2 * M; e++) {
			if (ccid[e] != -1) continue;
			for (int cur = e; ccid[cur] == -1; cur = nxt[cur]) {
				ccid[cur] = e;
			}
		}

		vector<bool> is_bridge(M);
		vector<int> bridge_queue; bridge_queue.reserve(M);
		vector<bool> is_alive(M, true);

		for (int e = 0; e < M; e++) {
			if (ccid[2*e+0] == ccid[2*e+1]) {
				is_bridge[e] = true;
				bridge_queue.push_back(e);
			}
		}

		// Set a -> b
		auto splice = [&](int a, int b) {
			b = prv[b];
			if (ccid[a] == ccid[b]) {
				// it's a cut; no need to change id's
			} else {
				// it's a join, let's fix the id's
				for (int ca = nxt[a], cb = nxt[b]; true; ca = nxt[ca], cb = nxt[cb]) {
					if (cb == b) {
						break;
					} else if (ca == a) {
						swap(a, b);
						break;
					}
				}
				int nid = ccid[a];
				for (int cur = b; ccid[cur] != nid; cur = nxt[cur]) {
					ccid[cur] = nid;
					if (ccid[cur^1] == nid && !is_bridge[cur>>1]) {
						is_bridge[cur>>1] = true;
						bridge_queue.push_back(cur>>1);
					}
				}
			}
			swap(nxt[a], nxt[b]);
			prv[nxt[a]] = a;
			prv[nxt[b]] = b;
		};

		auto delete_edge = [&](int e) {
			assert(is_alive[e]);
			is_alive[e] = false;
			splice(2*e+0, 2*e+1);
			splice(2*e+1, 2*e+0);
		};

		int epoch = 0;
		vector<int> vis(2*M, epoch);
		vector<int> in_set(N, epoch);
		array<vector<int>, 2> q;
		q[0].reserve(2*M);
		q[1].reserve(2*M);

		int num_matched = 0;
		while (!bridge_queue.empty()) {
			int e = bridge_queue.back(); bridge_queue.pop_back();
			if (!is_alive[e]) continue;
			assert(ccid[2*e+0] == ccid[2*e+1]);

			int u = dest[2*e+1], v = dest[2*e+0];
			int ve = nxt[2*e+0];
			int ue = nxt[2*e+1];

			// First, you split the current face and delete this edge
			delete_edge(e);

			// Now, we check the 2 cc's for parity
			bool should_cut = [&]() -> bool {
				if (ve/2 == e || ue/2 == e) {
					return true;
				}
				// otherwise, we have at least one edge in each side
				epoch++;
				q[0].clear(); q[0].push_back(ue);
				vis[ue] = epoch;
				q[1].clear(); q[1].push_back(ve);
				vis[ve] = epoch;
				array<int, 2> cnt{0,0};
				for (int z = 0; true; z++) {
					for (int d = 0; d < 2; d++) {
						if (z == int(q[d].size())) {
							return cnt[d] & 1;
						}
						int cur = q[d][z];
						if (in_set[dest[cur]] != epoch) cnt[d]++, in_set[dest[cur]] = epoch;
						if (vis[nxt[cur]] != epoch) {
							vis[nxt[cur]] = epoch;
							q[d].push_back(nxt[cur]);
						}
						if (vis[cur^1] != epoch) {
							vis[cur^1] = epoch;
							q[d].push_back(cur^1);
						}
					}
				}
			}();
			if (should_cut) {
				num_matched ++;

				// cut everything else at these two vertices
				for (auto [oe, _] : adj[u]) {
					oe /= 2;
					if (is_alive[oe]) delete_edge(oe);
				}
				for (auto [oe, _] : adj[v]) {
					oe /= 2;
					if (is_alive[oe]) delete_edge(oe);
				}
			}
		}

		cout << int(num_matched * 2 == N) << '\n';
	}

	return 0;
}