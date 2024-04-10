/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 2e5;
int T, n, u, v, x, y;
int dfs_time, top[maxn + 5], size[maxn + 5], dep[maxn + 5], son[maxn + 5], fa[maxn + 5], id[maxn + 5];
int cnt, head[maxn + 5];
ll ans[maxn + 5];
struct Edge {
	int to, next;
}e[maxn * 2 + 5];

inline void add(int u, int v) {
	e[++cnt] = (Edge) {v, head[u]}, head[u] = cnt;
}
void dfs1(int u, int par) {
	dep[u] = dep[fa[u] = par] + 1, size[u] = 1; 
	trv(i, u, v) if(v != par) {
		dfs1(v, u);
		size[u] += size[v];
		if(!son[u] || size[v] > size[son[u]]) son[u] = v; 
	}
} 
void dfs2(int u, int tpar) {
	top[u] = tpar, id[u] = ++dfs_time;
	if(son[u]) dfs2(son[u], tpar);
	trv(i, u, v) if(v != fa[u] && v != son[u]) dfs2(v, v);
}
int lca(int u, int v) {
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}
inline bool in(int u, int v) {return id[u] <= id[v] && id[v] < id[u] + size[u];}
inline int get(int y) {
	int last;
	while(top[y] != 0) {
		last = top[y];
		y = fa[top[y]];
	}
	if(y == 0) return last;
	else return son[0];
}
int getsz(int x, int y) {
	if(!x) return n - size[get(y)];
	else return size[x];
}
void init() {
	x = 0, y = 1, dfs1(0, 0), dfs2(0, 0);
	trv(i, 0, u) ans[0] += 1ll * size[u] * (size[u] - 1) / 2; 
	int res = 1;
	trv(i, 0, u) {
		if(in(u, 1)) ans[1] += 1ll * res * (size[u] - size[1]), res += size[u] - size[1];
		else ans[1] += 1ll * res * size[u], res += size[u];
	}
} 
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 2, n) scanf("%d%d", &u, &v), add(u, v), add(v, u);
		if(n == 2) {puts("0 0 1"); cnt = 0, head[0] = head[1] = 0; continue;}
		init();
		rep(i, 2, n - 1) {
			if(in(y, i)) {
				ans[i] = 1ll * getsz(x, y) * (size[y] - size[i]);
				y = i;
			}
			else if((x == 0 && !in(get(y), i)) || (x != 0 && in(x, i))) {
				ans[i] = 1ll * (getsz(x, y) - size[i]) * size[y];
				x = i;
			}
			else if(in(i, x) || in(i, y)) {
				ans[i] = 0;
			}
			else {
				ans[i] = 1ll * getsz(x, y) * size[y];
				break;
			} 
			if(i == n - 1) ans[n] = 1;
		}
		rep(i, 0, n) printf("%lld ", ans[i]); puts("");
		rep(i, 0, n) head[i] = ans[i] = size[i] = id[i] = son[i] = dep[i] = fa[i] = top[i] = 0;
		dfs_time = cnt = 0;
	}
	return 0;
}