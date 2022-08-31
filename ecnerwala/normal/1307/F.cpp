#include<bits/stdc++.h>
using namespace std;

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

const int MAXN = 2.1e5;
int N;
vector<int> adj[MAXN];
pair<int, int> edges[MAXN];

pair<int, int> restDist[MAXN];

int depth[MAXN];
int par[MAXN][20];

int K;

int R;
bool rest[MAXN];

namespace dsu {
int par[MAXN];
void reset() { memset(par, -1, sizeof(par)); }
int getPar(int a) { return par[a] < 0 ? a : (par[a] = getPar(par[a])); }
bool merge(int a, int b) {
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (par[b] < par[a]) swap(a, b);
	par[a] += par[b];
	par[b] = a;
	return true;
}
}

int color[MAXN];

int main() {
	scanf("%d %d %d", &N, &K, &R);
	for (int e = 0; e < N-1; e++) {
		int a, b; scanf("%d %d", &a, &b);
		edges[e] = {a,b};
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int r = 0; r < R; r++) {
		int c; scanf("%d", &c);
		rest[c] = true;
	}

	std::y_combinator([&](auto self, int cur, int prv) -> void {
		depth[cur] = depth[prv] + 1;
		par[cur][0] = prv;
		for (int i = 0; par[cur][i]; i++) {
			par[cur][i+1] = par[par[cur][i]][i];
		}
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			self(nxt, cur);
		}
	})(1, 0);

	auto getAnc = [&](int cur, int d) -> int {
		assert(d >= 0);
		for (int i = 0; d; i++, d /= 2) {
			if (d & 1) {
				cur = par[cur][i];
			}
		}
		return cur;
	};

	auto lca = [&](int a, int b) {
		if (depth[a] > depth[b]) swap(a, b);
		b = getAnc(b, depth[b] - depth[a]);
		assert(depth[a] == depth[b]);
		if (a == b) return a;
		int i = 0;
		while (par[a][i] != par[b][i]) {
			i++;
		}
		while (i) {
			--i;
			if (par[a][i] != par[b][i]) {
				a = par[a][i];
				b = par[b][i];
			}
		}
		assert(par[a][0] == par[b][0]);
		return par[a][0];
	};

	{
		vector<int> q; q.reserve(N);
		for (int i = 1; i <= N; i++) {
			if (rest[i]) {
				restDist[i] = {0, i};
				q.push_back(i);
			} else {
				restDist[i] = {-1, -1};
			}
		}
		for (int z = 0; z < int(q.size()); z++) {
			int cur = q[z];
			for (int nxt : adj[cur]) {
				if (restDist[nxt].first == -1) {
					restDist[nxt] = restDist[cur];
					restDist[nxt].first++;
					q.push_back(nxt);
				}
			}
		}
	}

	dsu::reset();
	for (int e = 0; e < N-1; e++) {
		int u = edges[e].first, v = edges[e].second;
		if (restDist[u].first + restDist[v].first + 1 <= K) {
			dsu::merge(restDist[u].second, restDist[v].second);
		}
	}

	for (int i = 1; i <= N; i++) color[i] = restDist[i].first <= K/2 ? dsu::getPar(restDist[i].second) : 0;

	auto query = [&](int a, int b) -> bool {
		int c = lca(a, b);
		int da = depth[a] - depth[c];
		int db = depth[b] - depth[c];
		int d = da + db;

		if (d <= K) return true;
		int md = (K+1)/2;
		int pa = md <= da ? getAnc(a, md) : getAnc(b, d - md);
		int pb = md <= db ? getAnc(b, md) : getAnc(a, d - md);
		return color[pa] && color[pa] == color[pb];
	};

	int Q; scanf("%d", &Q);
	while (Q--) {
		int a, b; scanf("%d %d", &a, &b);
		bool ans = query(a, b);
		printf(ans ? "YES\n" : "NO\n");
	}

	return 0;
}