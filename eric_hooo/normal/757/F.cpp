#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, int> pli;

int n, m;
vector <int> seq;

// namespace Graph {
// 	vector <int> G[200010];
// 	int bel[200010];
// 	void AddEdge(int x, int y) {
// 		// cerr << "   " << x << " " << y << endl;
// 		G[y].push_back(x);
// 	}
// 	int Solve(int S) {
// 		static int cnt[200010];
// 		for (auto x : seq) {
// 			bel[x] = -1;
// 			for (auto v : G[x]) {
// 				if (bel[x] == -1) bel[x] = bel[v];
// 				else bel[x] = bel[x] == bel[v] ? bel[x] : S;
// 			}
// 			if (bel[x] == -1) bel[x] = S;
// 			if (bel[x] == S) bel[x] = x;
// 			else bel[x] = bel[bel[x]];
// 			cnt[bel[x]]++;
// 		}
// 		int ans = 0; for (int i = 1; i <= n; i++) if (i != S) ans = max(ans, cnt[i]);
// 		return ans;
// 	}
// }

namespace Graph {
	int rt;
	vector <int> G[200010], H[200010];
	int dfn[200010], sdom[200010], idom[200010], tdom[200010], DFN;
	int seq[200010], fa[200010];
	int MIN(int x, int y) {return dfn[x] < dfn[y] ? x : y;}
	int MAX(int x, int y) {return dfn[x] > dfn[y] ? x : y;}
	void AddEdge(int x, int y) {
		G[x].push_back(y);
		H[y].push_back(x);
	}
	void GetDfn(int x) {
		dfn[x] = ++DFN, seq[DFN] = x;
		for (auto v : G[x]) {
			if (!dfn[v]) fa[v] = x, GetDfn(v);
		}
	}
	namespace DSU {
		int fa[200010], val[200010];
		void Init() {
			for (int i = 1; i <= n; i++) {
				fa[i] = i, val[i] = n + 1;
			}
		}
		void Flush(int x) {
			if (x == fa[x]) return ;
			Flush(fa[x]);
			if (dfn[sdom[val[x]]] > dfn[sdom[val[fa[x]]]]) val[x] = val[fa[x]];
			fa[x] = fa[fa[x]];
		}
		int Query(int x) {
			Flush(x);
			return val[x];
		}
		void Merge(int x, int y) {
			fa[x] = y, val[x] = x;
		}
	}
	void Build(int _rt) {
		rt = _rt;
		fa[rt] = -1, GetDfn(rt);
		dfn[0] = -0x3f3f3f3f, dfn[n + 1] = 0x3f3f3f3f;
		sdom[0] = 0, sdom[n + 1] = n + 1;
		DSU :: Init();
		static vector <int> qry[200010];
		for (int i = DFN; i >= 1; i--) {
			; for (auto x : qry[i]) tdom[x] = DSU :: Query(x);
			if (i == 1) break;
			int x = seq[i];
			sdom[x] = n + 1;
			for (auto v : H[x]) {
				if (dfn[v] < dfn[x]) sdom[x] = MIN(sdom[x], v);
				else sdom[x] = MIN(sdom[x], sdom[DSU :: Query(v)]);
			}
			qry[dfn[sdom[x]]].push_back(x);
			DSU :: Merge(x, fa[x]);
		}
		for (int i = 2; i <= DFN; i++) {
			int x = seq[i];
			idom[x] = sdom[x] == sdom[tdom[x]] ? sdom[x] : idom[tdom[x]];
		}
	}
	int Solve() {
		static int sz[200010];
		int ans = 0;
		for (int i = DFN; i >= 1; i--) {
			int x = seq[i];
			sz[x]++;
			if (x != rt) sz[idom[x]] += sz[x], ans = max(ans, sz[x]);
		}
		return ans;
	}
}

namespace DIJ {
	vector <pii> G[200010];
	long long dist[200010];
	priority_queue <pli, vector <pli>, greater <pli> > q;
	void AddEdge(int x, int y, int w) {
		G[x].push_back(mp(y, w));
		G[y].push_back(mp(x, w));
	}
	int Solve(int S) {
		memset(dist, 0x3f, sizeof(dist)), dist[S] = 0, q.push(mp(dist[S], S));
		while (!q.empty()) {
			pli tmp = q.top(); q.pop();
			int x = tmp.se;
			if (tmp.fi != dist[x]) continue;
			seq.push_back(x);
			for (auto it : G[x]) {
				int v = it.fi, w = it.se;
				if (dist[v] > dist[x] + w) {
					dist[v] = dist[x] + w;
					q.push(mp(dist[v], v));
				}
			}
		}
		int tot = 0;
		for (int i = 1; i <= n; i++) {
			tot += dist[i] != 0x3f3f3f3f3f3f3f3f;
			for (auto it : G[i]) {
				int j = it.fi, w = it.se;
				if (dist[j] == dist[i] + w) {
					Graph :: AddEdge(i, j);
				}
			}
		}
		return tot;
	}
}

int main() {
	int S; scanf("%d%d%d", &n, &m, &S);
	for (int i = 0; i < m; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		DIJ :: AddEdge(x, y, w);
	}
	int tot = DIJ :: Solve(S);
	Graph :: Build(S);
	printf("%d\n", Graph :: Solve());
	return 0;
}