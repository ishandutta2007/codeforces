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
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef array<ll, 2> a2;
typedef array<ll, 3> a3;
typedef array<ll, 5> a5;
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e5; 
const int lg = 20;
const ll inf = 1e18;
int n, m, q, u, v, w, lim; 
ll mn, ans[maxn + 5];
int root[maxn + 5];
map<a2, a2> mp;
vector<a5> e;
vector<a3> ins[maxn * 4 + 5];
vector<ll> s;
set<a2> f[maxn + 5], all;
struct Segment {
	int nodecnt = 0, siz[maxn * 4 * lg], ls[maxn * 4 * lg], rs[maxn * 4 * lg];
	void update(int &rt,int &u, int &v, int l, int r, int p, int k) {
		if(!rt) rt = ++nodecnt;
		if(!u) u = ++nodecnt;
		if(!v) v = ++nodecnt;
		siz[rt] += k, siz[u] += k, siz[v] += k;
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) update(ls[rt], ls[u], ls[v], l, mid, p, k);
		else if(p > mid) update(rs[rt], rs[u], rs[v], mid + 1, r, p, k);
	}
	int query(int rt, int u, int v, int l, int r) {
		if(l == r) return l;
		int res = siz[ls[rt]] - siz[ls[u]] - siz[ls[v]], mid = l + r >> 1;
		if(res) return query(ls[rt], ls[u], ls[v], l, mid);
		else return query(rs[rt], rs[u], rs[v], mid + 1, r);
	}
}t;
#define ls rt << 1
#define rs rt << 1 | 1
void push(int rt, int l, int r, a5 p) {
	if(l >= p[1] && r <= p[2]) {
		ins[rt].push_back({p[3], p[4], p[0]});
		return ;
	}
	int mid = l + r >> 1;
	if(p[2] <= mid) push(ls, l, mid, p);
	else if(p[1] > mid) push(rs, mid + 1, r, p);
	else push(ls, l, mid, p), push(rs, mid + 1, r, p);
}
void solve(int rt, int l, int r) {
	ll lst = mn;
	for(auto x : ins[rt]) {
		if(t.siz[root[0]] > t.siz[root[x[0]]] + t.siz[root[x[1]]]) {
			chkmn(mn, s[t.query(root[0], root[x[0]], root[x[1]], 0, lim)] + s[x[2]]);
		}
		t.update(root[x[0]], root[x[1]], root[0], 0, lim, x[2], 1);
	}
	if(l == r) chkmn(ans[l], mn);
	else {
		int mid = l + r >> 1;
		solve(ls, l, mid), solve(rs, mid + 1, r);
	}
	for(auto x : ins[rt]) {
		t.update(root[x[0]], root[x[1]], root[0], 0, lim, x[2], -1);
	}
	mn = lst;
}
#undef ls 
#undef rs
ll get(int u) {
	if(sz(f[u]) < 3) return inf;
	ll res = 0;
	auto it = f[u].begin();
	rep(i, 0, 2) res += (*it)[0], it ++;
	return res;
}
void add(int u, int v, int w) {
	all.erase({get(u), u});
	f[u].insert({w, v});
	all.insert({get(u), u});
}
void del(int u, int v, int w) {
	all.erase({get(u), u});
	f[u].erase({w, v});
	all.insert({get(u), u});
}
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, 1, n) all.insert({inf, i});
	rep(i, 1, m) cin >> u >> v >> w, mp[{min(u, v), max(u, v)}] = {w, 0}, add(u, v, w), add(v, u, w);
	ans[0] = (*all.begin())[0];
	cin >> q;
	rep(i, 1, q) {
		int opt;
		cin >> opt;
		if(opt) {
			cin >> u >> v >> w;
			if(u > v) swap(u, v);
			mp[{u, v}] = {w, i};
			add(u, v, w), add(v, u, w);
		}
		else {
			cin >> u >> v;
			if(u > v) swap(u, v);
			e.push_back({mp[{u, v}][0], mp[{u, v}][1], i - 1, u, v});
			s.push_back(mp[{u, v}][0]);
			del(u, v, mp[{u, v}][0]), del(v, u, mp[{u, v}][0]);
			mp.erase({u, v});
		}
		ans[i] = (*all.begin())[0];
	}
	for(auto x : mp) {
		e.push_back({x.se[0], x.se[1], q, x.fi[0], x.fi[1]});
		s.push_back(x.se[0]);
	}
	sort(all(s)), s.erase(unique(all(s)), s.end()), lim = sz(s);
	for(auto x : e) {
		x[0] = lower_bound(all(s), x[0]) - s.begin();
		push(1, 0, q, x);
	}
	mn = inf, solve(1, 0, q);
	rep(i, 0, q) cout << ans[i] << '\n';
	return 0;
}