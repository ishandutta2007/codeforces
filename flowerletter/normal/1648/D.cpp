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
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 5e5;
const ll inf = 1e18;
int n, m;
ll a[4][maxn + 5];
ll f[maxn + 5], g[maxn + 5], sum[maxn + 5], dp[maxn + 5], mn[maxn + 5];
struct Node {
	int l, r; ll s;
	friend bool operator < (Node x, Node y) {
		return x.l == y.l ? x.r < y.r : x.l < y.l;
	}
};
set<Node> s;
auto split(int p) {
	auto it = s.lower_bound({p, 0, 0});
	if(it -> l == p) return it;
	else {
		it --;
		Node tmp = *it;
		s.erase(it);
		s.insert({tmp.l, p - 1, tmp.s});
		return s.insert({p, tmp.r, tmp.s}).fi;
	}
}
Node stk[maxn + 5], tp;
struct Upd {
	int l, r; ll k;
};
vector<Upd> upd[maxn + 5], ins[maxn + 5];
struct Segment {
	#define ls u << 1
	#define rs u << 1 | 1
	ll mx[maxn + 5 << 2], tag[maxn + 5 << 2];
	void pushup(int u) {mx[u] = max(mx[ls], mx[rs]);}
	void seta(int u, ll k) {mx[u] += k, tag[u] += k;}
	void pushdown(int u) {
		if(tag[u]) {
			seta(ls, tag[u]);
			seta(rs, tag[u]);
			tag[u] = 0;
		}
	}
	void update(int u, int l, int r, int ql, int qr, ll k) {
		if(l >= ql && r <= qr) return seta(u, k);
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) update(ls, l, mid, ql, qr, k);
		else if(ql > mid) update(rs, mid + 1, r, ql, qr, k);
		else update(ls, l, mid, ql, qr, k), update(rs, mid + 1, r, ql, qr, k);
		pushup(u);
	}
	ll query(int u, int l, int r, int ql, int qr) {
		if(l >= ql && r <= qr) return mx[u];
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
		else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
	}
}ds;
struct Sgement2 {
	ll tag[maxn + 5 << 2];
	void seta(int u, ll k) {chkmn(tag[u], k);}
	void pushdown(int u) {
		seta(ls, tag[u]);
		seta(rs, tag[u]);
	}
	void update(int u, int l, int r, int ql, int qr, ll k) {
		if(l >= ql && r <= qr) return seta(u, k);
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) update(ls, l, mid, ql, qr, k);
		else if(ql > mid) update(rs, mid + 1, r, ql, qr, k);
		else update(ls, l, mid, ql, qr, k), update(rs, mid + 1, r, ql, qr, k);
	} 
	void dfs(int u, int l, int r) {
		if(l == r) {
			mn[l] = tag[u];
			return ;
		}
		int mid = l + r >> 1; pushdown(u);
		dfs(ls, l, mid), dfs(rs, mid + 1, r);
	}
	void build(int u, int l, int r) {
		tag[u] = inf;
		if(l == r) return ;
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
	}
}dsmn;
int main() {
//   	freopen("in.txt", "r", stdin);
	n = read(), m = read();
	rep(i, 1, 3) {
		rep(j, 1, n) a[i][j] = read();
	}
	rep(i, 1, n) f[i] = f[i - 1] + a[1][i];
	per(i, n, 1) g[i] = g[i + 1] + a[3][i];
	rep(i, 1, n) sum[i] = sum[i - 1] + a[2][i];
	dsmn.build(1, 1, n);
	rep(i, 1, m) {
		int l = read(), r = read(), k = read();
		ins[l].pb({l, r, k});
		dsmn.update(1, 1, n, l, r, k);
	}
	dsmn.dfs(1, 1, n);
	s.insert({1, n + 1, inf});
	rep(i, 1, n) {
//		cout << "qwq\n";
		auto it = s.begin();
		Node tmp = *it;
		upd[i - 1].pb({i, i, tmp.s});
		s.erase(it);
		if(tmp.l != tmp.r) s.insert({tmp.l +1, tmp.r, tmp.s}); 
//		cout << "qwq\n";
		for(auto x : ins[i]) {
			int p = x.r + 1, pos = -1;
//			cout << "qwq\n";
			auto it = split(p);
//			cout << "qwq\n";
//			cout << it-> l << '\n';
			if(it == s.begin()) continue;
			it --;
			while(it -> s >= x.k) {
				upd[i - 1].pb({it -> l, it -> r, it -> s - x.k});
				pos = it -> l; 
				it = s.erase(it); it --;
				if(it == s.begin()) break;
			}
			if(pos != -1) s.insert({pos, p - 1, x.k});
		}
	}
//	for(auto x : s) {
//		upd[n].pb({x.l, x.r, x.s});
//	}
//	cout << "qwq\n";
	ll ans = -inf;
	ll x = -inf, y = -inf;
	per(i, n, 1) {
//		cout << i << "---\n";
		for(auto x : upd[i]) ds.update(1, 1, n, x.l, x.r, -x.k);//, cout << x.l << ' ' << x.r << ' ' << -x.k << '\n';
		y = max(a[2][i] + g[i], x + a[2][i]);
		x = max(i == n ? -inf : ds.query(1, 1, n, i + 1, n) - sum[i - 1], y - mn[i]);
		dp[i] = max(x, y);
		ds.update(1, 1, n, i, i, dp[i] + sum[i - 1]);
//		cout << i << ":" << dp[i] << ' ' << x << ' ' << y << '\n';
		chkmx(ans, f[i] + x);
		chkmx(ans, f[i] + y - mn[i]);
	}
	cout << ans << '\n';
	return 0;
}