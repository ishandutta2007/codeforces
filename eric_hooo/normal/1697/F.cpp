#include <bits/stdc++.h>
using namespace std;

namespace Graph {
	vector <int> G[400010];
	int dfn[400010], low[400010], DFN, ins[400010], scc[400010], ALL;
	vector <int> S;
	int N;
	void Init(int _N) {
		N = _N;
		for (int i = 0; i < N; i++) {
			G[i].clear(), dfn[i] = 0;
		}
		DFN = ALL = 0;
	}
	void AddEdge(int x, int y) {
		// cerr << "    Edge:" << x << " " << y << endl;
		assert(x >= 0 && x < N && y >= 0 && y < N);
		G[x].push_back(y);
	}
	void Tarjan(int x) {
		dfn[x] = low[x] = ++DFN, ins[x] = 1;
		S.push_back(x);
		for (auto v : G[x]) {
			if (!dfn[v]) Tarjan(v), low[x] = min(low[x], low[v]);
			else if (ins[v]) low[x] = min(low[x], dfn[v]);
		}
		if (low[x] < dfn[x]) return ;
		while (1) {
			int v = S.back(); S.pop_back(), ins[v] = 0;
			scc[v] = ALL;
			if (x == v) break;
		}
		ALL++;
	}
	void Solve() {
		for (int i = 0; i < N; i++) {
			if (!dfn[i]) Tarjan(i);
		}
	}
}

void Add(int x, int y) {Graph :: AddEdge(x, y);}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		goto BEG;
		END:;
		continue;
		BEG:;
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		Graph :: Init(n * (k - 1) * 2);
		#define ID(i, j) (((i) - 1) * (k - 1) + (j) - 1)
		#define Leq(i, j) (ID(i, j) << 1)
		#define Geq(i, j) (ID(i, (j) - 1) << 1 | 1)
		; for (int i = 1; i <= n; i++) for (int j = 1; j + 1 < k; j++) Add(Leq(i, j), Leq(i, j + 1));
		; for (int i = 1; i <= n; i++) for (int j = k; j - 1 > 1; j--) Add(Geq(i, j), Geq(i, j - 1));
		for (int i = 1; i + 1 <= n; i++) {
			; for (int j = 1; j < k; j++) Add(Leq(i + 1, j), Leq(i, j));
			; for (int j = k; j > 1; j--) Add(Geq(i, j), Geq(i + 1, j));
		}
		for (int _ = 0; _ < m; _++) {
			int op; scanf("%d", &op);
			if (op == 1) {
				int i, x; scanf("%d%d", &i, &x);
				if (x == 1) Add(Leq(i, 1), Geq(i, 2));
				else if (x == k) Add(Geq(i, k), Leq(i, k - 1));
				else {
					Add(Leq(i, x), Leq(i, x - 1));
					Add(Geq(i, x), Geq(i, x + 1));
				}
			} else if (op == 2) {
				int i, j, x; scanf("%d%d%d", &i, &j, &x);
				for (int t = k; t > 1; t--) {
					if (x - t < 1) {
						Add(Geq(i, t), Leq(i, t - 1));
						Add(Geq(j, t), Leq(j, t - 1));
					} else if (x - t < k) {
						Add(Geq(i, t), Leq(j, x - t));
						Add(Geq(j, t), Leq(i, x - t));
					}
				}
			} else if (op == 3) {
				int i, j, x; scanf("%d%d%d", &i, &j, &x);
				for (int t = 1; t < k; t++) {
					if (x - t > k) {
						Add(Leq(i, t), Geq(i, t + 1));
						Add(Leq(j, t), Geq(j, t + 1));
					} else if (x - t > 1) {
						Add(Leq(i, t), Geq(j, x - t));
						Add(Leq(j, t), Geq(i, x - t));
					}
				}
			} else assert(0);
		}
		Graph :: Solve();
		for (int i = 1; i <= n; i++) for (int j = 1; j < k; j++) if (Graph :: scc[Leq(i, j)] == Graph :: scc[Geq(i, j + 1)]) {
			printf("-1\n");
			goto END;
		}
		for (int i = 1; i <= n; i++) {
			int val = -1;
			for (int j = 1; j < k; j++) {
				if (Graph :: scc[Leq(i, j)] < Graph :: scc[Geq(i, j + 1)]) {
					val = j;
					break;
				}
			}
			if (val == -1) val = k;
			printf("%d ", val);
		}
		printf("\n");
		#undef Geq
		#undef Leq
		#undef ID
	}
	return 0;
}