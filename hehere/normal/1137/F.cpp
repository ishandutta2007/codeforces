#include <bits/stdc++.h>
using namespace std;

const int maxN = 200000 + 233;
int n, q;
class FenwickTree {
	int n;
	int C[maxN * 2];
public:
	void assign(int n) {
		this->n = n;
		memset(C, 0, sizeof(C));
	}
	void add(int p, int x) {
		for(; p <= n; p += p & -p) C[p] += x;
	}
	int sum(int p) {
		int r = 0;
		for(; p > 0; p -= p & -p) r += C[p];
		return r;
	}
} fwt;
class SegmentTree {
#define lson (o << 1)
#define rson (lson | 1)
	int col[maxN * 4], tag[maxN * 4];
	int ql, qr, qv;
	void pushdown(int o) {
		if(tag[o]) {
			col[lson] = col[rson] = tag[lson] = tag[rson] = tag[o];
			tag[o] = 0;
		}
	}
	void maintain(int o) {
		col[o] = col[lson] == col[rson] ? col[lson] : 0;
	}
	void _cover(int o, int L, int R) {
		if(ql <= L && R <= qr) {
			if(col[o] > 0 || L == R) {
				if(col[o]) fwt.add(col[o], - (R - L + 1));
				col[o] = tag[o] = qv;
				fwt.add(col[o], R - L + 1);
			} else {
				int M = (L + R) >> 1;
				_cover(lson, L, M);
				_cover(rson, M + 1, R);
				maintain(o);
			}
		} else {
			int M = (L + R) >> 1;
			pushdown(o);
			if(ql <= M) _cover(lson, L, M);
			if(qr > M) _cover(rson, M + 1, R);
			maintain(o);
		}
	}
	int _query(int o, int L, int R, int p) {
		RE:
		if(tag[o]) return tag[o];
		if(col[o]) return col[o];
		int M = (L + R) >> 1;
		if(p <= M) o = lson, R = M;
		else o = rson, L = M + 1;
		goto RE;
	}
public:
	void cover(int l, int r, int v) {
//		printf("%d %d %d\n", l, r, v);
		ql = l; qr = r; qv = v;
		assert(1 <= l && l <= r && r <= n);
		_cover(1, 1, n);
	}
	int query(int p) {
		return _query(1, 1, n, p);
	}
#undef lson
#undef rson
} st;
vector<int> G[maxN];
int pre[maxN], post[maxN], euler[maxN], dfs_clock;
int top[maxN], pa[maxN], dep[maxN], sz[maxN];
void DFS(int u, int fa) {
	for(auto p = G[u].begin(); p != G[u].end(); ++p)
		if(*p == fa) { G[u].erase(p); break; }
	sz[u] = 1;
	
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int &v = G[u][i];
		dep[v] = dep[u] + 1;
		pa[v] = u;
		DFS(v, u);
		sz[u] += sz[v];
		if(sz[v] > sz[G[u][0]]) swap(v, G[u][0]);
	}
}

void DFS2(int u, int t) {
	euler[pre[u] = ++dfs_clock] = u;
	top[u] = t;
	for(int v : G[u]) DFS2(v, v == G[u][0] ? t : v);
	post[u] = dfs_clock;
}

int dist(int u, int v) {
	int ans = 0;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		ans += dep[u] - dep[top[u]] + 1;
		u = pa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	ans += dep[u] - dep[v];
	return ans;
}

void chain_cover(int u, int v, int col) {
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		st.cover(pre[top[u]], pre[u], col);
		u = pa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	st.cover(pre[v], pre[u], col);
}

vector<int> h;

void initialize() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 1; i < n; ++i) {
		int x, y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	priority_queue<int, vector<int>, greater<int> > pq;
	vector<int> deg(n + 1, 0);
	for(int u = 1; u <= n; ++u) deg[u] = G[u].size();
	for(int u = 1; u <= n; ++u) if(deg[u] == 1) pq.push(u);
	
	h.push_back(-1);
	while(pq.size()) {
		int u = pq.top(); pq.pop();
		h.push_back(u);
		for(int v : G[u]) if(--deg[v] == 1) pq.push(v);
	}
	
	dep[1] = 0; pa[1] = 0;
	DFS(1, -1);
	dfs_clock = 0;
	DFS2(1, 1);
	
	assert(n + 1 == (int)h.size());
	for(int i = 1; i <= n; ++i) {
		int u = h[i];
		st.cover(pre[u], pre[u], i);
	}
	fwt.assign(n + q);
	for(int i = 1; i <= n; ++i) fwt.add(i, 1);
}

void up(int u) {
	int col = h.size();
	h.push_back(u);
	chain_cover(u, h[col - 1], col);
}

int query(int u) {
	int col = st.query(pre[u]);
	int ans = fwt.sum(col - 1) + 1;
	if(col > n) ans += dist(u, h[col - 1]);
	return ans;
}

void solve() {
	string op; cin >> op;
	if(op == "up") {
		int u; cin >> u;
		up(u);
	} else if(op == "when") {
		int u; cin >> u;
		cout << query(u) << '\n';
	} else if(op == "compare") {
		int u, v; cin >> u >> v;
		cout << ((query(u) < query(v)) ? u : v) << '\n';
	} else {
		assert(false);
	}
}

int main() {
	initialize();
	while(q--) solve();
	return 0;
}