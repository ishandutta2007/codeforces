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

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e5;
const int inf = 1e9;
int n, q, pre[maxn + 5], suf[maxn + 5];
char s[maxn + 5];
struct Node {
	int ans, pl, sr;
};
struct Bit {
	int c[maxn + 5];
	void upd(int x, int k) {
		for(; x <= n; x += lb(x)) c[x] += k;
	}
	int ask(int x, int ans = 0) {
		for(; x; x -= lb(x)) ans += c[x];
		return ans;
	}
	int qry(int l, int r) {return ask(r) - ask(l - 1);}
}aa, bb, cc;
struct Segment {
	#define ls u << 1
	#define rs u << 1 | 1
	template <int T> using A = array<int, T>;
	Node a[maxn * 4];
	A<2> tag[maxn * 4];
	void pushup(int u) {
		a[u].ans = min({a[ls].ans, a[rs].ans, a[rs].sr + a[ls].pl - 1});
		a[u].sr = min(a[ls].sr, a[rs].sr);
		a[u].pl = min(a[ls].pl, a[rs].pl);
	}
	void seta(int u, A<2> k) {
		if(k[0]) a[u].ans += k[0], a[u].sr += k[0], tag[u][0] += k[0];
		if(k[1]) a[u].ans += k[1], a[u].pl += k[1], tag[u][1] += k[1];
	}
	void pushdown(int u) {
		if(tag[u][0] || tag[u][1]) seta(ls, tag[u]), seta(rs, tag[u]), tag[u] = {0, 0};
	}
	void build(int u, int l, int r) {
		if(l == r) {
			if(l == 0) {
				a[u].ans = cc.qry(1, n);
				a[u].pl = 1;
				a[u].sr = cc.qry(1, n) - 1;
			}
			else if(l == n + 1) {
				a[u].ans = aa.qry(1, n);
				a[u].pl = aa.qry(1, n) - bb.qry(1, n);
				a[u].sr = bb.qry(1, n);
			}
			else if(s[l] == 'b') {
				a[u].ans = aa.qry(1, l - 1) + cc.qry(l + 1, n);
				a[u].pl = aa.qry(1, l - 1) - bb.qry(1, l - 1);
				a[u].sr = cc.qry(l + 1, n) + bb.qry(1, l - 1);
			}
			else a[u].ans = inf, a[u].pl = inf, a[u].sr = inf;
			return ;
		}
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(u);
	}
	void update(int u, int l, int r, int ql, int qr, A<2> k) {
		if(l >= ql && r <= qr) return seta(u, k), void();
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) update(ls, l, mid, ql, qr, k);
		else if(ql > mid) update(rs, mid + 1, r, ql, qr, k);
		else update(ls, l, mid, ql, qr, k), update(rs, mid + 1, r, ql, qr, k);
		pushup(u);
	//	cout << l << ' ' << r << ' ' << a[u].sr << ' ' << a[u].pl << ' ' << a[u].ans << '\n';
	}
	void insert(int u, int l, int r, int p, Node x) {
		if(l == r) return a[u] = x, void();
		int mid = l + r >> 1; pushdown(u);
		if(p <= mid) insert(ls, l, mid, p, x);
		else insert(rs, mid + 1, r, p, x);
		pushup(u);
	}
}t;

int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), q = read();
	cin >> s + 1;
	s[0] = 'b', s[n + 1] = 'b';
	rep(i, 1, n) {
		if(s[i] == 'a') aa.upd(i, 1);
		else if(s[i] == 'b') bb.upd(i, 1);
		else cc.upd(i, 1);
	}
	t.build(1, 0, n + 1);
//	cout << (t.a[1].ans == inf ? 0 : t.a[1].ans) << '\n';
	rep(i, 1, q) {
//		cout << i << '\n';
		int pos = read(); char c[3]; cin >> c;		
		if(s[pos] == 'a') t.update(1, 0, n + 1, pos + 1, n + 1, {0, -1});
		if(s[pos] == 'b') t.update(1, 0, n + 1, pos + 1, n + 1, {-1, 1});
		if(s[pos] == 'c') t.update(1, 0, n + 1, 0, pos - 1, {-1, 0});
//		cout << i << '\n';
		if(c[0] == 'b') {
//		cout << i << '\n';
			t.insert(1, 0, n + 1, pos, (Node) {aa.qry(1, pos - 1) + cc.qry(pos + 1, n), aa.qry(1, pos - 1) - bb.qry(1, pos - 1), cc.qry(pos + 1, n) + bb.qry(1, pos - 1)});
			t.update(1, 0, n + 1, pos + 1, n + 1, {1, -1});
		}
		else {
			t.insert(1, 0, n + 1, pos, (Node) {inf, inf, inf});
			if(c[0] == 'a') t.update(1, 0, n + 1, pos + 1, n + 1, {0, 1});
			if(c[0] == 'c') t.update(1, 0, n + 1, 0, pos - 1, {1, 0});
		}
//		cout << i << '\n';
		if(s[pos] == 'a') aa.upd(pos, -1);
		else if(s[pos] == 'b') bb.upd(pos, -1);
		else cc.upd(pos, -1);
		s[pos] = c[0];
		if(s[pos] == 'a') aa.upd(pos, 1);
		else if(s[pos] == 'b') bb.upd(pos, 1);
		else cc.upd(pos, 1);
	//	t.build(1, 0, n + 1);
		cout << (t.a[1].ans == inf ? 0 : t.a[1].ans) << '\n';
	}
	return 0;
}