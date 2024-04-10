#include <bits/extc++.h>

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		[]() {
			int N, M, K; cin >> N >> M >> K;
			vector<hash_set<int>> adj(N);
			for (int e = 0; e < M; e++) {
				int u, v; cin >> u >> v; u--, v--;
				adj[u].insert(v);
				adj[v].insert(u);
			}
			vector<int> deg(N);
			for (int i = 0; i < N; i++) deg[i] = int(adj[i].size());

			vector<bool> alive(N, true);
			vector<int> q; q.reserve(N);
			for (int i = 0; i < N; i++) {
				if (deg[i] < K - 1) q.push_back(i);
			}
			for (int z = 0; z < int(q.size()); z++) {
				int cur = q[z];
				alive[cur] = false;
				for (int nxt : adj[cur]) {
					if (deg[nxt] == K-1) q.push_back(nxt);
					--deg[nxt];
				}
			}

			q.clear();

			for (int i = 0; i < N; i++) {
				if (!alive[i]) continue;
				if (deg[i] == K-1) q.push_back(i);
			}

			vector<int> cur_verts; cur_verts.reserve(K);
			for (int z = 0; z < int(q.size()); z++) {
				int cur = q[z];
				assert(deg[cur] <= K-1);
				alive[cur] = false;
				for (int nxt : adj[cur]) {
					if (deg[nxt] == K) q.push_back(nxt);
					--deg[nxt];
				}

				if (deg[cur] < K-1) continue;
				assert(deg[cur] == K-1);

				cur_verts.clear();
				cur_verts.push_back(cur);
				for (int nxt : adj[cur]) {
					if (alive[nxt]) {
						if (deg[nxt] < K-2) goto bad;
						cur_verts.push_back(nxt);
					}
				}
				assert(int(cur_verts.size()) == K);
				for (int i = 1; i < K; i++) {
					int a = cur_verts[i];
					const auto& mp = adj[a];
					for (int j = i+1; j < K; j++) {
						if (mp.find(cur_verts[j]) == mp.end()) {
							goto bad;
						}
					}
				}
				{
					cout << 2 << '\n';
					for (int i = 0; i < K; i++) {
						cout << cur_verts[i]+1 << " \n"[i+1==K];
					}
					return;
				}
bad:
				continue;
			}

			vector<int> still_alive; still_alive.reserve(N);
			for (int i = 0; i < N; i++) {
				if (alive[i]) still_alive.push_back(i);
			}
			if (!still_alive.empty()) {
				cout << 1 << ' ' << still_alive.size() << '\n';
				for (int z = 0; z < int(still_alive.size()); z++) {
					cout << still_alive[z]+1 << " \n"[z+1==int(still_alive.size())];
				}
				return;
			}
			cout << -1 << '\n';
		}();
	}

	return 0;
}