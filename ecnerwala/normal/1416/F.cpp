#include <bits/stdc++.h>

namespace kactl {
//https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/Dinic.h
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() const { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};
#undef rep
#undef all
#undef sz
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int NCASES; cin >> NCASES;
	while (NCASES--) {
		int N, M; cin >> N >> M;
		vector<int> G(N*M);
		for (auto& v : G) cin >> v;

		const int V = N*M+4;
		int S = N*M;
		int T = N*M+1;
		int S2 = N*M+2;
		int T2 = N*M+3;
		kactl::Dinic flower(V);
		vector<int> cost(N*M);
		vector<char> dir(N*M, '\0');
		// First, gather all possible decreasing edges
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i-1 >= 0 && G[i*M+j] > G[(i-1)*M+j]) {
					cost[i*M+j] = G[i*M+j] - G[(i-1)*M+j];
					dir[i*M+j] = 'U';
				} else if (i+1 < N && G[i*M+j] > G[(i+1)*M+j]) {
					cost[i*M+j] = G[i*M+j] - G[(i+1)*M+j];
					dir[i*M+j] = 'D';
				} else if (j-1 >= 0 && G[i*M+j] > G[i*M+(j-1)]) {
					cost[i*M+j] = G[i*M+j] - G[i*M+(j-1)];
					dir[i*M+j] = 'L';
				} else if (j+1 < M && G[i*M+j] > G[i*M+(j+1)]) {
					cost[i*M+j] = G[i*M+j] - G[i*M+(j+1)];
					dir[i*M+j] = 'R';
				}
				if (dir[i*M+j]) {
					if ((i^j)&1) {
						flower.addEdge(S, i*M+j, 1);
					} else {
						flower.addEdge(i*M+j, T, 1);
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i+1 < N && G[i*M+j] == G[(i+1)*M+j]) {
					int a = i*M+j;
					int b = (i+1)*M+j;
					if ((i^j)&1) std::swap(a, b);
					flower.addEdge(a, b, 1);
				}
				if (j+1 < M && G[i*M+j] == G[i*M+(j+1)]) {
					int a = i*M+j;
					int b = i*M+(j+1);
					if ((i^j)&1) std::swap(a, b);
					flower.addEdge(a, b, 1);
				}
			}
		}

		int num_even = 0;
		int num_odd = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if ((i^j) & 1) {
					num_odd++;
					flower.addEdge(i*M+j, T2, 1);
				} else {
					num_even++;
					flower.addEdge(S2, i*M+j, 1);
				}
			}
		}
		flower.addEdge(S2, T, num_odd);
		flower.addEdge(S, T2, num_even);
		flower.addEdge(T, S, N*M);

		int tot_flow = int(flower.calc(S2, T2));
		if (tot_flow != N * M) {
			cout << "NO" << '\n';
			continue;
		} else {
			cout << "YES" << '\n';
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if ((i^j) & 1) continue;
					for (const auto& e : flower.adj[i*M+j]) {
						if (0 <= e.to && e.to < N*M && e.flow()) {
							// This guy is paired
							int i2 = e.to / M;
							int j2 = e.to % M;
							assert(abs(i - i2) + abs(j - j2) == 1);
							assert(G[i*M+j] == G[i2*M+j2]);
							cost[i*M+j] = G[i*M+j] / 2;
							cost[i2*M+j2] = (G[i*M+j]+1) / 2;
							if (i2 - i == 1) {
								dir[i*M+j] = 'D';
								dir[i2*M+j2] = 'U';
							} else if (i2 - i == -1) {
								dir[i*M+j] = 'U';
								dir[i2*M+j2] = 'D';
							} else if (j2 - j == 1) {
								dir[i*M+j] = 'R';
								dir[i2*M+j2] = 'L';
							} else if (j2 - j == -1) {
								dir[i*M+j] = 'L';
								dir[i2*M+j2] = 'R';
							} else assert(false);
						}
					}
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cout << cost[i*M+j] << " \n"[j+1==M];
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					assert(dir[i*M+j]);
					cout << dir[i*M+j] << " \n"[j+1==M];
				}
			}
		}

		// Basic setup:
		// We have S || Evens || Odds || T
		// We have edges:
		//   S -> all Evens (must be filled)
		//   all Odds -> T (must be filled)
		//   Evens -> Odds when adjacent
		//   Events -> T and S -> Odds when can skip
		//
		//   S -> T' with # Evens
		//   S' -> all Evens
		//   S' -> T with # Odds
		//   all Odds -> T'
		//
		//   S' ->  T -infty-> S -> T'
		//          ^          |
		//          |          v
		//      -> Evens -> Odds ->
	}

	return 0;
}