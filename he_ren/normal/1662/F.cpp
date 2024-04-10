#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define tab "\t"
#define endl "\n"

#define ferr std::cerr

#ifdef DEBUG
std::ifstream fin("in");
std::ofstream fout("out");
#else
#define fin std::cin
#define fout std::cout
#endif

const int mxn = 1 << 18;

int dis[mxn];
int que[mxn], ql, qr;

struct segment_tree {
	int sz;
	std::vector <std::pair <int, int> > g[mxn << 1];
	int pl[mxn << 1], pr[mxn << 1];
	inline void init(int n, int a[]) {
		for (sz = 1; sz < n; sz <<= 1);
		for (int i = 1; i < sz << 1; ++ i) g[i].clear();
		rep(i, n) g[i + sz].push_back({a[i], i});
		for (int i = sz - 1; i; -- i) {
			g[i].resize(g[i << 1].size() + g[i << 1 | 1].size());
			std::merge(
					g[i << 1].begin(), g[i << 1].end(),
					g[i << 1 | 1].begin(), g[i << 1 | 1].end(),
					g[i].begin());
		}
		for (int i = 1; i < sz << 1; ++ i) pl[i] = 0, pr[i] = (int) g[i].size() - 1;
	}
	inline void dodo(int i, int l, int r, int d) {
		while (pl[i] <= pr[i] && g[i][pl[i]].first >= l && g[i][pl[i]].first <= r) {
			int x = g[i][pl[i]].second;
			if (!~dis[x]) dis[x] = d, que[qr ++] = x;
			++ pl[i];
		}
		while (pl[i] <= pr[i] && g[i][pr[i]].first >= l && g[i][pr[i]].first <= r) {
			int x = g[i][pr[i]].second;
			if (!~dis[x]) dis[x] = d, que[qr ++] = x;
			-- pr[i];
		}
	}
	inline void update(int l, int r, int L, int R, int d) {
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) dodo(l ++, L, R, d);
			if (r & 1) dodo(-- r, L, R, d);
		}
	}
} segl, segr;

int n, l[mxn], r[mxn];

inline void Main() {
	int S, T;
	fin >> n >> S >> T;
	-- S, -- T;
	rep(i, n) {
		int p;
		fin >> p;
		l[i] = std::max(0, i - p);
		r[i] = std::min(n - 1, i + p);
	}
	segl.init(n, l);
	segr.init(n, r);
	rep(i, n) dis[i] = -1;
	ql = qr = 0;
	que[qr ++] = S;
	dis[S] = 0;
	while (ql < qr) {
		int u = que[ql ++];
		segl.update(u, r[u] + 1, 0, u, dis[u] + 1);
		segr.update(l[u], u + 1, u, n - 1, dis[u] + 1);
	}
	fout << dis[T] << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	fin >> T;
	while (T --) Main();
	return 0;
}