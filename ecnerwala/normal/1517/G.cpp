#include <bits/stdc++.h>

namespace kactl {
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
template <typename T> int sz(const T& x) { return (int)(x).size(); }
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// https://github.com/kth-competitive-programming/kactl/blob/5db8a69390d0e11d23cefdd7c0c52004c25ddeec/content/graph/Dinic.h
struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
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
} // namespace kactl

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<array<int, 2>> P(N);
	vector<int64_t> W(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i][0] >> P[i][1] >> W[i];
	}

	kactl::Dinic flower(2*N+2);
	int S = 2*N, T = 2*N+1;
	for (int i = 0; i < N; i++) {
		flower.addEdge(2*i, 2*i+1, W[i]);
	}

	const int INF = int(1e9) + 100;
	// S -> odd/odd -> even/odd -> even/even -> even/odd -> T
	auto get_step = [&](int i) -> int {
		int x = P[i][0] & 1;
		int y = P[i][1] & 1;
		return (!y) * 2 + (x ^ y);
	};
	for (int i = 0; i < N; i++) {
		if (get_step(i) == 0) flower.addEdge(S, 2*i, INF);
		else if (get_step(i) == 3) flower.addEdge(2*i+1, T, INF);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (abs(P[i][0] - P[j][0]) + abs(P[i][1] - P[j][1]) == 1 && get_step(j) - get_step(i) == 1) {
				flower.addEdge(2*i+1, 2*j, INF);
			}
		}
	}

	cout << std::accumulate(W.begin(), W.end(), int64_t(0)) - flower.calc(S, T) << '\n';

	return 0;
}