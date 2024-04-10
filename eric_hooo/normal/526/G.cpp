#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n;
vector <pii> G[100010];

struct Solver {
	int dst[100010];
	pii maxj[100010];
	vector <pii> wei;
	vector <int> sum;
	int col[100010], fa[100010][17];
	void CalcDst(int x, int last) {
		fa[x][0] = last;
		maxj[x] = mp(dst[x], x);
		for (auto it : G[x]) {
			int v = it.fi, w = it.se;
			if (v == last) continue;
			dst[v] = dst[x] + w, CalcDst(v, x), maxj[x] = max(maxj[x], maxj[v]);
		}
	}
	void CalcWei(int x, int last) {
		int y = maxj[x].se;
		wei.push_back(mp(dst[y] - dst[last], y));
		while (y != x) {
			int p = fa[y][0];
			for (auto it : G[p]) {
				int v = it.fi, w = it.se;
				if (v == y || v == fa[p][0]) continue;
				CalcWei(v, p);
			}
			y = p;
		}
	}
	void Paint(int x, int c) {
		while (col[x] == -1) col[x] = c, x = fa[x][0];
	}
	void init(int rt) {
		CalcDst(rt, rt);
		for (int j = 1; j < 17; j++) {
			for (int i = 1; i <= n; i++) {
				fa[i][j] = fa[fa[i][j - 1]][j - 1];
			}
		}
		wei.clear();
		for (auto it : G[rt]) {
			CalcWei(it.fi, rt);
		}
		sort(wei.rbegin(), wei.rend());
		memset(col, -1, sizeof(col));
		sum = {0};
		for (int i = 0; i < wei.size(); i++) {
			sum.push_back(sum.back() + wei[i].fi);
			Paint(wei[i].se, i);
		}
	}
	int Solve(int x, int k) {
		k = k * 2 - 1, k = min(k, (int)wei.size());
		if (col[x] < k) return sum[k];
		int p = x;
		for (int i = 16; i >= 0; i--) {
			if (col[fa[p][i]] >= k) p = fa[p][i];
		}
		p = fa[p][0];
		int len = maxj[x].fi - dst[p];
		return max(sum[k - 1], sum[k] - dst[wei[col[p]].se] + dst[p]) + len;
	}
}sol[2];

namespace MaxChain {
	int dist[100010];
	pii dfs(int x, int last) {
		pii ans = mp(dist[x], x);
		for (auto it : G[x]) {
			int v = it.fi, w = it.se;
			if (v == last) continue;
			dist[v] = dist[x] + w, ans = max(ans, dfs(v, x));
		}
		return ans;
	}
	pii Solve() {
		dist[1] = 0;
		pii tmp = dfs(1, 1);
		dist[tmp.se] = 0;
		return mp(tmp.se, dfs(tmp.se, tmp.se).se);
	}
}

int main() {
	int q; scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		G[x].push_back(mp(y, w));
		G[y].push_back(mp(x, w));
	}
	pii point = MaxChain :: Solve();
	sol[0].init(point.fi), sol[1].init(point.se);
	int LastAns = 0;
	while (q--) {
		int x, k; scanf("%d%d", &x, &k);
		x = (x + LastAns - 1) % n + 1, k = (k + LastAns - 1) % n + 1;
		printf("%d\n", LastAns = max(sol[0].Solve(x, k), sol[1].Solve(x, k)));
	}
	return 0;
}