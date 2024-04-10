#include <bits/stdc++.h>
#define il inline
#define ri register int
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 100005
#define MAXM 1000005
#define MOD
#define INF (1<<25)
#define eps (1e-6)
#define rep(i, x, y) for(ri i = x; i <= y; ++i)
#define dwn(i, x, y) for(ri i = x; i >= y; --i)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <int, int> pii;
typedef pair <LL, int> pli;
typedef pair <int, LL> pil;
typedef pair <LL, LL> pll;
template <typename T> inline bool chkmin(T &x, T y) {return x > y ? x = y, 1 : 0;}
template <typename T> inline bool chkmax(T &x, T y) {return x < y ? x = y, 1 : 0;}
il void read(int &x) {
	char ch = getchar(); int f = 1; x = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = getchar();
	x *= f;
}
int n, m, lim[MAXN<<2], pos[MAXN], f[MAXN][20], g[MAXN][20], id[MAXN], size[MAXN], son[MAXN], top[MAXN], fa[MAXN];
int vis[MAXM], idcnt, fv[MAXN], res[MAXN], dep[MAXN], ans[MAXM];
struct node {
	int u, v, w, id;
	bool operator < (const node &x) const {
		return w < x.w;
	}
} E[MAXM];
vector <pair <int, pair <int, int> > > adj[MAXN];
int get(int u) {
	return u == fa[u] ? u : fa[u] = get(fa[u]);
} 
il bool merge(int u, int v) {
	u = get(u), v = get(v);
	if(u != v) return fa[u] = v;
	return 0;
}
void dfs1(int u) {
	size[u] = 1;
	rep(i, 1, 19) f[u][i] = f[f[u][i-1]][i-1], g[u][i] = max(g[u][i-1], g[f[u][i-1]][i-1]);
	for(auto pa: adj[u]) {
		int v = pa.fir, w = pa.sec.fir, c = pa.sec.sec;
		if(v != f[u][0]) {
			f[v][0] = u, g[v][0] = w, fv[v] = c, dep[v] = dep[u] + 1, dfs1(v), size[u] += size[v];
			if(size[v] > size[son[u]]) son[u] = v;
		}
	}
}
void dfs2(int u, int t) {
	pos[id[u] = ++idcnt] = u, top[u] = t;
	if(!son[u]) return ;
	dfs2(son[u], t);
	for(auto pa: adj[u])
		if(!id[pa.fir]) dfs2(pa.fir, pa.fir);
}
int query(int u, int v) {
	int ret = 0;
	if(dep[u] < dep[v]) swap(u, v);
	rep(i, 0, 19) if((dep[u]-dep[v]) & (1<<i)) chkmax(ret, g[u][i]), u = f[u][i];
	dwn(i, 19, 0) if(f[u][i] != f[v][i]) chkmax(ret, max(g[u][i], g[v][i])), u = f[u][i], v = f[v][i];
	if(u != v) chkmax(ret, max(g[u][0], g[v][0]));
	return ret;
}
void build(int u, int l, int r) {
	lim[u] = 1e9;
	if(l == r) return ;
	build(u<<1, l, mid), build(u<<1|1, mid+1, r);
}
void modify(int u, int l, int r, int tl, int tr, int w) {
	if(tl <= l && r <= tr) return (void)(chkmin(lim[u], w));
	if(tl <= mid) modify(u<<1, l, mid, tl, tr, w);
	if(mid < tr) modify(u<<1|1, mid+1, r, tl, tr, w);
}
void calc(int u, int l, int r, int minn) {
	chkmin(minn, lim[u]);
	if(l == r) return (void)(res[pos[l]] = minn);
	calc(u<<1, l, mid, minn), calc(u<<1|1, mid+1, r, minn);
}
void change(int u, int v, int w) {
//	cout<<"modify "<<u<<' '<<v<<' '<<w<<endl;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
//		cout<<"change "<<top[u]<<' '<<u<<' '<<id[top[u]]<<' '<<id[u]<<endl;
		modify(1, 1, n, id[top[u]], id[u], w);
		u = f[top[u]][0];
	}
	if(id[u] > id[v]) swap(u, v);
	if(u != v) 
		modify(1, 1, n, id[u]+1, id[v], w);
}
int main() {
	int u, v, w;
	read(n), read(m);
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m)
		read(E[i].u), read(E[i].v), read(E[i].w), E[i].id = i;
	sort(E+1, E+m+1);
	rep(i, 1, m) {
		u = E[i].u, v = E[i].v, w = E[i].w;
		if(merge(u, v)) vis[i] = 1, adj[u].pb(mp(v, mp(w, i))), adj[v].pb(mp(u, mp(w, i)));
	}
	dfs1(1), dfs2(1, 1), build(1, 1, n);
	rep(i, 1, m) {
		if(!vis[i]) {
			ans[E[i].id] = query(E[i].u, E[i].v);
			change(E[i].u, E[i].v, E[i].w);
		}
	}
	calc(1, 1, n, 1e9);
	rep(i, 2, n) ans[E[fv[i]].id] = res[i];
	rep(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}