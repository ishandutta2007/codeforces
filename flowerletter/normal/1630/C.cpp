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
const int maxn = 2e5;
const int inf = 1e9;
int n, a[maxn + 5], p[maxn + 5];
int f[maxn + 5];
vector<int> pos[maxn + 5];
struct Segment {
	#define ls u << 1
	#define rs u << 1 | 1
	int tag[maxn << 2], mx[maxn << 2];
	void pushup(int u) {mx[u] = max(mx[ls], mx[rs]);}
	void seta(int u, int k) {mx[u] += k, tag[u] += k;}
	void pushdown(int u) {
		if(tag[u]) seta(ls, tag[u]), seta(rs, tag[u]), tag[u] = 0;
	}
	void update(int u, int l, int r, int ql, int qr, int k) {
		if(l >= ql && r <= qr) return seta(u, k);
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) update(ls, l, mid, ql, qr, k);
		else if(ql > mid) update(rs, mid + 1, r, ql, qr, k);
		else update(ls, l, mid, ql, qr, k), update(rs, mid + 1, r, ql, qr, k);
		pushup(u); 
	}
	int query(int u, int l, int r, int ql, int qr) {
		if(l >= ql && r <= qr) return mx[u];
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
		else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
	}
}ds1, ds2;
int main() {
// 	freopen("in.txt", "r", stdin);
	n = read();
	rep(i, 1, n) {
		a[i] = read();
		pos[a[i]].pb(i);
	}
	rep(i, 1, n) p[i] = inf;
	vector<P> l;
	rep(i, 1, n) {
		if(sz(pos[i])  > 1) {
			chkmn(p[pos[i].back()], pos[i][0]);
		}
	}
//	f[0] = -inf;
	int ans = 0;
	ds1.update(1, 0, n, 0, 0, 1);
	rep(i, 1, n) {
		f[i] = -inf;
//		cout << p[i] << ' ';
		if(p[i] != inf) {
			chkmx(f[i], ds1.query(1, 0, n, p[i], n) - 1);
//			cout << f[i] << ' ';
			chkmx(f[i], ds2.query(1, 0, n, 0, p[i] - 1) + i - p[i] - 1);
		}
		ds1.update(1, 0, n, i, i, f[i]);
		ds1.update(1, 0, n, 0, i, 1);
		ds2.update(1, 0, n, i, i, f[i]);
		chkmx(ans, f[i]);
//		cout << ds.query(1, 0, n, 0, 0) << ' ';
//		cout << f[i] << '\n';
	}
	cout << ans << '\n';
	return 0;
}