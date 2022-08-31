#include<bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

// https://github.com/kth-competitive-programming/kactl/blob/master/content/graph/Dinic.h
namespace kactl {
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
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, int rcap = 0) {
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
		const int L = 30;
		do { // 'int L=30' maybe faster for random data
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
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M, K, Q; cin >> N >> M >> K >> Q;
	kactl::Dinic flower(N);
	vector<array<int, 2>> special(K);
	for (int e = 0; e < M; e++) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		if (e < K) special[e] = {u, v};
		else flower.addEdge(u, v, w);
	}

	int base_flow = int(flower.calc(0, N-1));
	vector<int> costs(1<<K);
	std::y_combinator([&](auto self, int i, int msk, int cur_val, const kactl::Dinic& d) {
		if (i == K) {
			costs[msk] = cur_val;
			return;
		}
		self(i+1, msk, cur_val, d);
		kactl::Dinic nd(d);
		nd.addEdge(special[i][0], special[i][1], 25);
		self(i+1, msk | (1 << i), cur_val + int(nd.calc(0, N-1)), nd);
	})(0, 0, base_flow, flower);

	vector<int> fast_costs(1 << K);
	{
		int cur_msk = 0;
		fast_costs[0] = costs[cur_msk];
		for (int m = 1; m < (1 << K); m++) {
			int i = __builtin_ctz(m);
			assert(bool(cur_msk & (1 << i)) == bool(m & (1 << (i+1))));
			cur_msk ^= (1 << i);
			fast_costs[m] = costs[cur_msk];
		}
	}

	vector<int> W(K);
	for (int q = 0; q < Q; q++) {
		for (int k = 0; k < K; k++) cin >> W[k];
		int cur = accumulate(W.begin(), W.end(), 0);
		int ans = cur + fast_costs[0];
		for (int m = 1; m < (1 << K); m++) {
			int i = __builtin_ctz(m);
			if (m & (1 << (i+1))) cur += W[i];
			else cur -= W[i];
			ans = min(ans, cur + fast_costs[m]);
		}
		cout << ans << '\n';
	}

	return 0;
}