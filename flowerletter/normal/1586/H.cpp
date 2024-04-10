#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
const int maxn = 2e5;
const int maxlg = 17;
int n, m, a[maxn + 5], val[maxn + 5], top[maxn + 5], vmx[maxn + 5], dep[maxn + 5], lg[maxn + 5];
int fa[maxn + 5][maxlg + 1], mx[maxn + 5][maxlg + 1];
vector<A<2>> g[maxn + 5];
A<4> e[maxn + 5];
A<3> q[maxn + 5]; 
A<2> ans[maxn + 5];
set<int> s;
namespace dsu {
	int fa[maxn + 5];
	vector<int> g[maxn + 5];
	void clear() {rep(i, 1, n) fa[i] = i;}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
}
using dsu::find;
void dfs(int u, int par) {
	rep(i, 1, maxlg) fa[u][i] = fa[fa[u][i - 1]][i - 1], mx[u][i] = max(mx[u][i - 1], mx[fa[u][i - 1]][i - 1]);
	for(auto v : g[u]) if(v[0] != par) {
		dep[v[0]] = dep[u] + 1;
		fa[v[0]][0] = u;
		mx[v[0]][0] = v[1];
		dfs(v[0], u);
	}
}
int qrymx(int u, int v) {
	int d = dep[u] - dep[v], res = 0;
	for(; d; d ^= lb(d)) chkmx(res, mx[u][lg[lb(d)]]), u = fa[u][lg[lb(d)]];
	return res;
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int d = dep[u] - dep[v];
	for(; d; d ^= lb(d)) u = fa[u][lg[lb(d)]];
	if(u == v) return u;
	per(i, maxlg, 0) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
A<2> ask(int u) {
	int x = top[find(u)], y = lca(u, x);
	return {vmx[find(u)], max({qrymx(x, y), qrymx(u, y), val[find(u)]})};
}
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n - 1) cin >> e[i][0] >> e[i][1] >> e[i][2] >> e[i][3], g[e[i][0]].push_back({e[i][1], e[i][3]}), g[e[i][1]].push_back({e[i][0], e[i][3]});
	rep(i, 1, m) cin >> q[i][0] >> q[i][1], q[i][2] = i; 
	dsu::clear();
	sort(e + 1, e + n, [&] (A<4> x, A<4> y){return x[2] > y[2];});
	sort(q + 1, q + m + 1, [&] (A<3> x, A<3> y) {return x[0] > y[0];});
	int p = 1;
	dfs(1, 1);
	rep(i, 1, n) top[i] = i, vmx[i] = a[i];
	rep(i, 0, maxlg) lg[1 << i] = i;
	rep(i, 1, n - 1) {
		while(p <= m && q[p][0] > e[i][2]) ans[q[p][2]] = ask(q[p][1]), p ++;
		if(dep[e[i][0]] > dep[e[i][1]]) swap(e[i][0], e[i][1]);
		int fx = find(e[i][0]), fy = find(e[i][1]);
		dsu::fa[fy] = fx;
		if(vmx[fx] < vmx[fy]) {
			val[fx] = val[fy];
			top[fx] = top[fy];
			vmx[fx] = vmx[fy];
		}
		else if(vmx[fx] > vmx[fy]) {
			;
		}
		else {
			int x = lca(top[fx], top[fy]);
			chkmx(val[fx], max({val[fy], qrymx(top[fx], x), qrymx(top[fy], x)}));
			if(x != top[fx]) top[fx] = x;
		}
	}
	while(p <= m) ans[q[p][2]] = ask(q[p][1]), p ++;
	rep(i, 1, m) cout << ans[i][0] << ' ' << ans[i][1] << '\n';
	return 0;
}