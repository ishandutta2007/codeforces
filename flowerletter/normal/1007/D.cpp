#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
const int maxn = 2e6;
const int maxm = 1e4;
int n, m, id[maxn + 5];
int dfn[maxn + 5], siz[maxn + 5], son[maxn + 5], rev[maxn + 5], dep[maxn + 5], fa[maxn + 5], top[maxn + 5];
vector<int> e[maxn + 5], g[maxn + 5], G[maxn + 5];
int stk[maxn + 5], col[maxn + 5], in[maxn + 5], dfstime[maxn + 5], low[maxn + 5], tp, num;
int ncnt;
struct Path {
	int u, v;
	void input() {
		cin >> u >> v;
	}
}a[maxn + 5], b[maxn + 5];
void dfs1(int u, int par) {
	siz[u] = 1, dep[u] = dep[fa[u] = par] + 1;
	for(auto v : G[u]) if(v != par) {
		dfs1(v, u);
		if(siz[son[u]] < siz[v]) son[u] = v;
		siz[u] += siz[v];
	}
}
void dfs2(int u, int tpar) {
	static int ts = 0;
	top[u] = tpar, rev[dfn[u] = ++ ts] = u;
	if(son[u]) dfs2(son[u], tpar);
	for(auto v : G[u]) if(v != fa[u] && v != son[u]) {
		dfs2(v, v);
	} 
}
#define ls u << 1
#define rs u << 1 | 1
#define mid (l + r >> 1)
void add(int u, int v) {
	g[u].pb(v), g[v ^ 1].pb(u ^ 1);
}
void link(int u, int l, int r, int ql, int qr, int c) {
	if(l >= ql && r <= qr) return e[u].pb(c), void();
	if(qr <= mid) link(ls, l, mid, ql, qr, c);
	else if(ql > mid) link(rs, mid + 1, r, ql, qr, c);
	else link(ls, l, mid, ql, qr, c), link(rs, mid + 1, r, ql, qr, c);
}
void build(int u, int l, int r) {
	id[u] = ncnt + 2, ncnt += 2;
	rep(i, 0, sz(e[u]) - 1) {
		ncnt += 2;
		add(e[u][i], ncnt - 1);
		add(ncnt - 1, ncnt - 3);
		if(i) add(ncnt - 1, e[u][i - 1] ^ 1);
	}
	if(u > 1) {
		add(id[u >> 1] - 1, ncnt - 1);
		if(!e[u].empty()) add(id[u >> 1] - 1, e[u].back() ^ 1);
	}
	if(l == r) return ;
	build(ls, l, mid), build(rs, mid + 1, r);
}
#undef ls
#undef rs 
#undef mid
void upd(int u, int v, int c) {
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		link(1, 1, n, dfn[top[u]], dfn[u], c);
		u = fa[top[u]];
	}
	if(dep[u] > dep[v]) swap(u, v);
	if(u != v) link(1, 1, n, dfn[u] + 1, dfn[v], c);
}
void tarjan(int u) {
	static int ts = 0;
	stk[++ tp] = u, in[u] = 1;
	low[u]= dfstime[u] = ++ ts;
	for(auto v : g[u]) {
		if(!dfstime[v]) tarjan(v), chkmn(low[u], low[v]);
		else if(in[v]) chkmn(low[u], dfstime[v]);
	}
	if(low[u] == dfstime[u]) {
		col[u] = ++ num, in[u] = 0;
		while(stk[tp] != u) {
			in[stk[tp]] = 0;
			col[stk[tp]] = num;
			tp --;
		}
		tp --;
	}
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 2, n) {
		int u, v;
		cin >> u >> v;
		G[u].pb(v), G[v].pb(u);
	}
	dfs1(1, 1), dfs2(1, 1);
	cin >> m;
	rep(i, 1, m) {
		a[i].input(), b[i].input();
	}
	ncnt = 2 * m + 1;
	rep(i, 1, m) {
		upd(a[i].u, a[i].v, i * 2);
		upd(b[i].u, b[i].v, i * 2 + 1);
	}
	build(1, 1, n);
	rep(i, 1, ncnt) if(!dfstime[i]) tarjan(i);
	rep(i, 1, m) if(col[2 * i] == col[2 * i + 1]) return cout << "NO\n", 0;
	cout << "YES\n";
	rep(i, 1, m) cout << 1 + (col[2 * i] > col[2 * i + 1]) << '\n';
	return 0;
}