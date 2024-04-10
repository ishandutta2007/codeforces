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
const int maxn = 7.5e5;
int n, m; 
A<2> e[maxn + 5];
ll ans;
struct lct {
	#define ls son[u][0]
	#define rs son[u][1]
	int son[maxn + 5][2], mx[maxn + 5], val[maxn + 5], fa[maxn + 5], cov[maxn + 5], rev[maxn + 5], cnt[maxn + 5];
	inline bool type(int u) {return son[fa[u]][1] == u;}
	inline bool nrt(int u) {return son[fa[u]][0] == u || son[fa[u]][1] == u;}
	inline void pushup(int u) {
		mx[u] = max({mx[ls], mx[rs], (u > n) * val[u]});
		cnt[u] = cnt[ls] + cnt[rs] + (u > n);
	}
	inline void seta(int u, int k1, int k2) {
		if(k1) rev[u] ^= 1, swap(ls, rs);
		if(k2 != -1) cov[u] = val[u] = k2, mx[u] = (cnt[u] > 0) * k2;
	}
	inline void pushdown(int u) {
		if(rev[u]) seta(ls, 1, -1), seta(rs, 1, -1), rev[u] = 0;
		if(cov[u] != -1) seta(ls, 0, cov[u]), seta(rs, 0, cov[u]), cov[u] = -1;
	}
	void pushall(int u) {
		if(nrt(u)) pushall(fa[u]);
		pushdown(u);
	}
	void rot(int u) {
		int f = fa[u], g = fa[f], k = type(u), s = son[u][!k];
		if(nrt(f)) son[g][type(f)] = u;
		if(s) fa[s] = f;
		son[u][!k] = f, son[f][k] = s;
		fa[u] = g, fa[f] = u;
		pushup(f), pushup(u);
	}
	void splay(int u) {
		pushall(u);
		while(nrt(u)) {
			int f = fa[u];
			if(nrt(f)) rot(type(u) == type(f) ? f : u);
			rot(u);
		}
	}
	void access(int u) {
		for(int x = 0; u; x = u, u = fa[u]) splay(u), rs = x, pushup(u);
	}
	void mkrt(int u) {
		access(u), splay(u), seta(u, 1, -1);
	}
	void split(int u, int v) {
		mkrt(u), access(v), splay(v);
	}
}t;
bool add(int u, int v, int p) {
	t.mkrt(u), t.mkrt(v);
	if(t.nrt(u) || t.nrt(v)) {
		t.access(u), t.splay(u);
		if(t.mx[u]) return 0;
		t.seta(u, 0, p);
		return 1;
	}
	t.fa[u] = t.fa[v] = p;
	return 1;
}
void del(int u, int v, int p) {
	t.split(u, v);
	t.splay(p);
	int c = t.val[p];
	if(c) {
		t.split(e[c - n][0], e[c - n][1]);
		t.seta(e[c - n][1], 0, 0);
		t.split(u, v), t.splay(p);
	}
	t.fa[v] = 0, t.son[p][0] = 0;
	t.fa[u] = 0, t.son[p][1] = 0;
	if(c) {
		t.mkrt(e[c - n][0]);
		t.mkrt(e[c - n][1]);
		t.fa[e[c - n][0]] = t.fa[e[c - n][1]] = c;
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int p = 1;
	rep(i, 1, n + m) t.cov[i] = -1, t.cnt[i] = (i > n);
	rep(i, 1, m) {
		cin >> e[i][0] >> e[i][1];
		while(!add(e[i][0], e[i][1], i + n)) del(e[p][0], e[p][1], p + n), p ++;
		ans += i - p + 1; 
	}
	cout << ans << '\n';
	return 0;
}