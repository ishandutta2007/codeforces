#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define mod 998244353
using namespace std;

typedef pair <int, int> pii;

int op[150010], X[150010], Y[150010], id[150010], size[150010], dep[150010];
vector <int> from[150010], g[150010];
int fa[150010][18];
int n, m; long long INV;

int get_lca(int x, int y);

void merge(vector <pii> &p) {
	sort(p.begin(), p.end());
	vector <pii> tmp;
	for (int i = 0; i < p.size(); i++) {
		if (!tmp.size() || tmp.back().fi != p[i].fi) tmp.push_back(p[i]);
		else tmp.back().se = (tmp.back().se + p[i].se) % mod;
	}
	p = tmp;
}

vector <int> get_node(vector <pii> &p, vector <pii> &q) {
	vector <int> node; node.push_back(1);
	for (int i = 0; i < p.size(); i++) {
		node.push_back(p[i].fi);
	}
	for (int i = 0; i < q.size(); i++) {
		node.push_back(q[i].fi);
	}
	sort(node.begin(), node.end()), node.resize(unique(node.begin(), node.end()) - node.begin());
	return node;
}

bool cmp(int x, int y) {
	return id[x] < id[y];
}

int st[150010];

void get_g(vector <int> &node) {
	sort(node.begin(), node.end(), cmp);
	for (int i = 0; i < node.size(); i++) {
		int x = node[i];
		g[x].clear();
	}
	int tp = 0;
	for (int i = 0; i < node.size(); i++) {
		int x = node[i];
		if (!tp) {
			st[tp++] = x;
			continue;
		}
		int lca = get_lca(x, st[tp - 1]);
		int lst = -1;
		while (tp && dep[st[tp - 1]] > dep[lca]) {
			tp--;
			if (~lst) g[st[tp]].push_back(lst), g[lst].push_back(st[tp]);
			lst = st[tp];
		}
		if (dep[st[tp - 1]] != dep[lca]) st[tp++] = lca;
		if (~lst) g[st[tp - 1]].push_back(lst), g[lst].push_back(st[tp - 1]);
		st[tp++] = x;
	}
	while (tp-- > 1) g[st[tp - 1]].push_back(st[tp]), g[st[tp]].push_back(st[tp - 1]);
}

int ans[150010], TOTOT = 2333;
int T[150010], vis[150010];

void modify(int x, long long v) {
	while (x <= n) {
		if (vis[x] != TOTOT) T[x] = 0, vis[x] = TOTOT;
		T[x] += v;
		if (T[x] >= mod) T[x] -= mod;
		x += x & -x;
	}
}

int query(int x) {
	int res = 0;
	while (x) {
		if (vis[x] != TOTOT) T[x] = 0, vis[x] = TOTOT;
		res += T[x];
		if (res >= mod) res -= mod;
		x -= x & -x;
	}
	return res;
}

void add_t(int x, int v, int d) {
	if (dep[x] > dep[v]) {
//		cerr << "                     x:" << x << " " << v << endl;
		v = fa[x][0];
		long long t = 1ll * d * size[x] % mod * INV % mod;
		modify(1, t), modify(id[x], mod - t);
		modify(id[x] + size[x], t);
		return ;
	}
	int tmp = dep[v] - dep[x] - 1, cnt = 0;
	while (tmp) {
		if (tmp & 1) v = fa[v][cnt];
		tmp >>= 1, cnt++;
	}
	long long t = 1ll * d * (n - size[v]) % mod * INV % mod;
	modify(id[v], t), modify(id[v] + size[v], mod - t);
}

void calc(vector <pii> &p, vector <pii> &q) {
	merge(p);
	vector <int> node = get_node(p, q);
	get_g(node);
	TOTOT++;
	for (int i = 0; i < p.size(); i++) {
		int x = p[i].fi, d = p[i].se;
		modify(id[x], d), modify(id[x] + 1, mod - d);
		for (int j = 0; j < g[x].size(); j++) {
			add_t(x, g[x][j], d);
		}
	}
	for (int i = 0; i < q.size(); i++) {
		int x = q[i].fi, ID = q[i].se;
		ans[ID] += query(id[x]);
		if (ans[ID] >= mod) ans[ID] -= mod;
	}
}

void solve(int l, int r) {
	if (l == r) return ;
	int mid = l + r >> 1;
	solve(l, mid), solve(mid + 1, r);
	vector <pii> p, q;
	for (int i = l; i <= mid; i++) {
		if (op[i] == 1) p.push_back(mp(X[i], Y[i]));
	}
	for (int i = mid + 1; i <= r; i++) {
		if (op[i] == 2) q.push_back(mp(X[i], i));
	}
	calc(p, q);
}

int TMP = 0;

void dfs(int x, int last) {
	id[x] = ++TMP, size[x] = 1, fa[x][0] = last;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dep[v] = dep[x] + 1, dfs(v, x), size[x] += size[v];
	}
}

void get_f() {
	for (int j = 1; j < 18; j++) {
		for (int i = 1; i <= n; i++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
}

int get_lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y], cnt = 0;
	while (tmp) {
		if (tmp & 1) x = fa[x][cnt];
		tmp >>= 1, cnt++;
	}
	if (x == y) return x;
	for (int i = 17; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int main () {
	scanf("%d%d", &n, &m);
	INV = power(n, mod - 2);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	dfs(1, 1), get_f();
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &op[i], &X[i]);
		if (op[i] == 1) scanf("%d", &Y[i]);
	}
	solve(0, m - 1);
	for (int i = 0; i < m; i++) {
		if (op[i] == 2) printf("%d\n", ans[i]);
	}
	return 0;
}