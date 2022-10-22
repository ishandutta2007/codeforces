#include <bits/stdc++.h>
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

typedef long long ll;
typedef pair<int,int> P;
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int inf = 1e9;
const int maxn = 2e5;
const int lg = 30;
int n, m, q;
int v[maxn + 5], ans[maxn + 5];
int fa[maxn + 5], sz[maxn + 5], w[maxn + 5];
P ask[maxn + 5];
struct Edge {
	int u, v, w;
};
struct Node {
	int *f;
	int val;
};
map<P, P> mp; 
stack<Node> s;
vector<Edge> add[maxn * 4];
int find(int x) {return fa[x] == x ? x : find(fa[x]);}
int getval(int x) {return fa[x] == x ? 0 : getval(fa[x]) ^ w[x];}
void equal(int *a, int b) {s.push({a, *a}), *a = b;}  
void insert(int x) {
	per(i, lg, 0) if(x >> i & 1) {
		if(v[i]) x ^= v[i];
		else {
			equal(&v[i], x);
			break;
		}
	}
} 
int query(int x) {
	per(i, lg, 0) if((x ^ v[i]) < x) x ^= v[i];
	return x;
}
#define ls u << 1 
#define rs u << 1 | 1
void ins(int u, int l, int r, int ql, int qr, Edge v) {
	if(l >= ql && r <= qr) return add[u].pb(v), void();
	int mid = l + r >> 1;
	if(qr <= mid) ins(ls, l, mid, ql, qr, v); 
	else if(ql > mid) ins(rs, mid + 1, r, ql, qr, v);
	else ins(ls, l, mid, ql, qr, v), ins(rs, mid + 1, r, ql, qr, v);
}
void solve(int u, int l, int r) {
	int tp = sz(s);
	for(auto e : add[u]) {
		int fx = find(e.u), fy = find(e.v);
		if(fx == fy) {
			insert(e.w ^ getval(e.u) ^ getval(e.v));
		}
		else {
			if(sz[fx] > sz[fy]) swap(fx, fy), swap(e.u, e.v);
			equal(&w[fx], e.w ^ getval(e.u) ^ getval(e.v));
			equal(&fa[fx], fy);
			equal(&sz[fy], sz[fx] + sz[fy]);
		}
	}
	if(l == r) {
		if(ask[l] != P{0, 0}) {
			ans[l] = query(getval(ask[l].fi) ^ getval(ask[l].se));
		}
		while(sz(s) > tp) {
			*s.top().f = s.top().val;
			s.pop();
		}
		return ;
	}
	int mid = l + r >> 1;
	solve(ls, l, mid);
	solve(rs, mid + 1, r);
	while(sz(s) > tp) {
		*s.top().f = s.top().val;
		s.pop();
	}
}
#undef ls
#undef rs 
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), m = read();
	rep(i, 1, n) fa[i] = i, sz[i] = 1;
	rep(i, 1, m) {
		int u = read(), v = read(), w = read();
		if(u > v) swap(u, v);
		mp[{u, v}] = {0, w};
	}
	q = read();
	rep(i, 1, q) {
		int opt = read();
		if(opt == 1) {
			int u = read(), v = read(), w = read();
			if(u > v) swap(u, v);
			mp[{u, v}] = {i, w};
		}
		else if(opt == 2) {
			int u = read(), v = read();
			if(u > v) swap(u, v); 
			ins(1, 0, q, mp[{u, v}].fi, i - 1, {u, v, mp[{u, v}].se});
			mp.erase({u, v});
		}
		else {
			int u = read(), v = read();
			ask[i] = {u, v};
		}
	}
	for(auto x : mp) ins(1, 0, q, x.se.fi, q, {x.fi.fi, x.fi.se, x.se.se});
	solve(1, 0, q);
	rep(i, 1, q) if(ask[i] != P{0, 0}) cout << ans[i] << '\n';  
	return 0;
}