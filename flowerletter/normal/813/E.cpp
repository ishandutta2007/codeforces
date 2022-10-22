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
const int maxn = 1e5;
const int lg = 40;
int n, k, q, a[maxn + 5];
vector<int> p[maxn + 5];
struct ChairmanTree {
	int rt[maxn + 5], ncnt, ls[maxn * lg + 5], rs[maxn * lg + 5];
	int sum[maxn * lg + 5];
	void update(int &u, int pre, int l, int r, int p, int k) {
		sum[u = ++ncnt] = sum[pre] + k, ls[u] = ls[pre], rs[u] = rs[pre];
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) update(ls[u], ls[pre], l, mid, p, k);
		else update(rs[u], rs[pre], mid + 1, r, p, k);
	}
	int query(int u, int l, int r, int ql, int qr) {
		if(l >= ql && r <= qr) return sum[u];
		int mid = l + r >> 1;
		if(qr <= mid) return query(ls[u], l, mid, ql, qr);
		else if(ql > mid) return query(rs[u], mid + 1, r, ql, qr);
		else return query(ls[u], l, mid, ql, qr) + query(rs[u], mid + 1, r, ql, qr);
	}
}ds;
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), k = read();
	rep(i, 1, n) p[a[i] = read()].pb(i);
	rep(i, 1, n) {
		int id = lower_bound(all(p[a[i]]), i) - p[a[i]].begin();
		int lim = 1;
		if(id >= k) {
			lim = p[a[i]][id - k] + 1;
		}
		ds.rt[i] = ds.rt[i - 1];
		ds.update(ds.rt[i], ds.rt[i], 1, n, lim, 1);
		if(i != n) ds.update(ds.rt[i], ds.rt[i], 1, n, i + 1, -1);
	}
	q = read();
	int lstans = 0;
	rep(i, 1, q) {
		int l = (read() + lstans) % n + 1, r = (read() + lstans) % n + 1;
		if(l > r) swap(l, r);
		cout << (lstans = ds.query(ds.rt[r], 1, n, 1, l)) << '\n'; 
	}
	return 0;
}