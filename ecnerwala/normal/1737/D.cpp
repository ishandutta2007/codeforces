#include <bits/stdc++.h>
template <typename T> using max_pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		struct edge_t {
			std::array<int, 2> v;
			int w;
		};
		std::vector<edge_t> edges(M);
		std::vector<std::vector<int>> adj(N);
		for (auto& e : edges) {
			cin >> e.v[0] >> e.v[1] >> e.w;
			e.v[0]--;
			e.v[1]--;
			adj[e.v[0]].push_back(e.v[1]);
			adj[e.v[1]].push_back(e.v[0]);
		}
		auto bfs = [&](int st) -> std::vector<int> {
			std::vector<int> dist(N, -1);
			std::vector<int> q; q.reserve(N);
			dist[st] = 0;
			q.push_back(st);
			for (int z = 0; z < int(q.size()); z++) {
				int cur = q[z];
				for (int nxt : adj[cur]) {
					if (dist[nxt] == -1) {
						dist[nxt] = dist[cur] + 1;
						q.push_back(nxt);
					}
				}
			}
			assert(int(q.size()) == N);
			return dist;
		};
		auto d0 = bfs(0);
		auto d1 = bfs(N-1);
		auto bfs2 = [&]() -> std::vector<int> {

			max_pq<std::pair<int, int>> pq;
			std::vector<int> dist(N, -1);
			for (int i = 0; i < N; i++) {
				dist[i] = d0[i] + d1[i];
				pq.push({dist[i], i});
			}
			while (!pq.empty()) {
				auto [d, cur] = pq.top(); pq.pop();
				if (d != dist[cur]) continue;
				for (int nxt : adj[cur]) {
					int nd = d + 1;
					if (nd < dist[nxt]) {
						dist[nxt] = nd;
						pq.push({nd, nxt});
					}
				}
			}
			return dist;
		};
		auto dmid = bfs2();
		int64_t ans = -1;
		for (auto e : edges) {
			for (int z = 0; z < 2; z++) {
				{
					int a = d0[e.v[z]], b = d1[e.v[!z]];
					assert(a != -1 && b != -1);
					int64_t cnd = (a + b + 1) * int64_t(e.w);
					if (ans == -1 || cnd < ans) ans = cnd;
				}
				{
					int a = dmid[e.v[z]];
					int64_t cnd = (a + 1 + 1) * int64_t(e.w);
					if (ans == -1 || cnd < ans) ans = cnd;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}