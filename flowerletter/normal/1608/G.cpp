#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
typedef long long ll;
typedef unsigned long long u64;
typedef pair<int,int> P;
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
const int inf = 1e9;
const int maxn = 1e5; 
const int maxm = 4e5;
const int B = 400;
const int V = 64;
const int maxl = 2e5 / V; 
int n, m, q, lp[maxn + 5], rp[maxn + 5];
int vis[maxn + 5], bel[maxn + 5], siz[maxn + 5], mx[maxn + 5];
A<2> pos[maxn + 5];
int rt, all, dis[maxn + 5];
int ans[maxn + 5];
string str[maxn + 5];
vector<P> G[maxn + 5]; 
struct Bitset {
	u64 a[maxl + 5];
	void flip(int p) {
		int u = p / V, v = p % V;
		a[u] ^= 1ull << v;
	}
	Bitset operator & (Bitset b) {
		rep(i, 0, maxl) b.a[i] &= a[i];
		return b; 
	}
	Bitset operator >> (int k) {
		Bitset b;
		int s = k / V, r = k % V, v = V - r;
		if(v == V) {
			rep(i, 0, maxl - s) b.a[i] = a[i + s];
		} 
		else {
			int lim = maxl - s - 1;
			rep(i, 0, lim) b.a[i] = a[i + s] >> r | a[i + s + 1] << v;
			b.a[lim + 1] = a[lim + 1 + s] >> r; 
		}
		rep(i, maxl - s + 1, maxl) b.a[i] = 0;
		return b;
	}
	int count() {
		int cnt = 0;
		rep(i, 0, maxl) cnt += __builtin_popcountll(a[i]);
		return cnt;
	}
	Bitset getrange(int l, int r) {
		int u = l / V, v = r / V;
		int ql = l % V, qr = r % V;
		Bitset b;
		memset(b.a, 0, sizeof b.a);
		rep(i, u + 1, v - 1) b.a[i] = a[i];
		if(u == v) {
			b.a[u] = 0;
			rep(i, ql, qr) b.a[u] |= a[u] & (1ull << i);
		}
		else {
			b.a[u] = 0;
			rep(i, ql, V - 1) b.a[u] |= a[u] & (1ull << i);
			b.a[v] = 0;
			rep(i, 0, qr) b.a[v] |= a[v] & (1ull << i);
		}
		return b;
	}
}sl, sr;
struct Sam {
	int ncnt, ts;
	int nxt[maxm + 5][27], len[maxm + 5], link[maxm + 5];
	int lp[maxm + 5], rp[maxm + 5], id[maxn + 5];
	vector<int> G[maxm + 5];
	vector<int> pos[maxm + 5];
	Sam () {ncnt = 1;}
	int insert(int c, int lst) {
		int cur = ++ncnt, p = lst;
		len[cur] = len[p] + 1;
		for(; p && !nxt[p][c]; p = link[p]) nxt[p][c] = cur;
		if(!p) link[cur] = 1;
		else {
			int q = nxt[p][c];
			if(len[p] + 1 == len[q]) link[cur] = q;
			else {
				int clone = ++ncnt;
				len[clone] = len[p] + 1;
				memcpy(nxt[clone], nxt[q], 4 * 27);
				link[clone] = link[q];
				for(; p && nxt[p][c] == q; p = link[p]) nxt[p][c] = clone;
				link[cur] = link[q] = clone;
			}
		}
		return cur;
	}
	void dfs(int u, int par) {
		lp[u] = ts + 1;
		for(auto x : pos[u]) id[++ ts] = x;
		for(auto v : G[u]) if(v != par) dfs(v, u);
		rp[u] = ts;
	}
	void build() {
		rep(i, 2, ncnt) G[link[i]].pb(i);
		dfs(1, 1);
	}
}sam[2];
struct Query {
	int u, v, l, r, id;
};
vector<Query> s[maxn + 5];
struct Ask {
	int l, r, d, ql, qr, k, id;
}a[maxn * 4 + 5];
int tot;
void dfs(int u, int par, A<2> cur, int col) {
	bel[u] = col, pos[u] = cur, dis[u] = dis[par] + 1;
	for(auto v : G[u]) if(v.fi != par && !vis[v.fi]) {
		dfs(v.fi, u, {sam[0].nxt[cur[0]][v.se], sam[1].nxt[cur[1]][v.se]}, col);
	}
}
void findrt(int u, int par) {
	siz[u] = 1, mx[u] = 0;
	for(auto v : G[u]) if(!vis[v.fi] && v.fi != par) {
		findrt(v.fi, u);
		siz[u] += siz[v.fi];
		chkmx(mx[u], siz[v.fi]);
	}
	chkmx(mx[u], all - siz[u]);
	if(mx[u] < mx[rt]) rt = u;
}
void solve(int u, vector<Query> t) {
	vis[u] = 1, bel[u] = u, pos[u] = {1, 1}, dis[u] = 0;
	for(auto v : G[u]) if(!vis[v.fi]) {
		s[v.fi].clear();
		dfs(v.fi, 0, {sam[0].nxt[1][v.se], sam[1].nxt[1][v.se]}, v.fi);
	}
	for(auto x : t) {
		if(bel[x.u] != bel[x.v]) {
			int id0 = pos[x.v][0], id1 = pos[x.u][1], d = dis[x.u] + dis[x.v] - 1, ql = x.l + d - 1, qr = x.r - 1;
			if(!id0 || !id1 || ql > qr) continue;
			a[++tot] = {sam[0].rp[id0], sam[1].rp[id1], d, ql, qr, 1, x.id};  
			if(sam[0].lp[id0] > 1) a[++tot] = {sam[0].lp[id0] - 1, sam[1].rp[id1], d, ql, qr, -1, x.id};
			if(sam[1].lp[id1] > 1) a[++tot] = {sam[0].rp[id0], sam[1].lp[id1] - 1, d, ql, qr, -1, x.id};
			if(sam[0].lp[id0] > 1 && sam[1].lp[id1] > 1) a[++tot] = {sam[0].lp[id0] - 1, sam[1].lp[id1] - 1, d, ql, qr, 1, x.id}; 
		}
		else {
			s[bel[x.u]].pb(x);
		}
	}
	for(auto v : G[u]) if(!vis[v.fi]) {
		rt = 0, all = siz[v.fi], findrt(v.fi, u), solve(rt, s[v.fi]);
	}
}
inline void insl(int p) {sl.flip(p - 1);}
inline void insr(int p) {sr.flip(p - 1);}
inline void dell(int p) {sl.flip(p - 1);}
inline void delr(int p) {sr.flip(p - 1);}
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	cin >> n >> m >> q;
	rep(i, 2, n) {
		int u, v; cin >> u >> v; char c; cin >> c;
		G[u].pb({v, c - 'a'});
		G[v].pb({u, c - 'a'}); 
	}
	rep(i, 1, m) cin >> str[i];
	int id = 0, lst = 1;
	rep(i, 1, m) {
		int len = str[i].size();
		lp[i] = id + 1;
		rep(j, 0, len - 1) sam[0].pos[lst = sam[0].insert(str[i][j] -'a', lst)].pb(++ id);
		rp[i] = id;
		lst = sam[0].insert(26, lst), id ++;
	}
	lst = 1;
	per(i, m, 1) {
		int len = str[i].size(); id --;
		per(j, len - 1, 0) sam[1].pos[lst = sam[1].insert(str[i][j] - 'a', lst)].pb(id --);
		lst = sam[1].insert(26, lst);
	}
	sam[0].build(), sam[1].build();
	rep(i, 1, q) {	
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		l = lp[l], r = rp[r];
		assert(l <= r);
		s[1].pb({u, v, l, r, i});
	} 
	mx[rt = 0] = inf, all = n, findrt(1, 1), solve(rt, s[1]);
	sort(a + 1, a + tot + 1, [&] (Ask x, Ask y) {return x.l / B == y.l / B ? (x.l / B & 1 ? x.r < y.r : x.r > y.r): x.l < y.l;});
	int l = 0, r = 0;
	rep(i, 1, tot) {
		while(l < a[i].l) l ++, insl(sam[0].id[l]);
		while(r < a[i].r) r ++, insr(sam[1].id[r]);
		while(l > a[i].l) dell(sam[0].id[l]), l --;
		while(r > a[i].r) delr(sam[1].id[r]), r --;
		ans[a[i].id] += a[i].k * (sl.getrange(a[i].ql, a[i].qr) >> a[i].d & sr).count();
	}
	rep(i, 1, q) cout << ans[i] << '\n';
	return 0;
}