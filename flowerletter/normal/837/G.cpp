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
const int maxn = 75000;
const int maxk = 2e5 + 1;
const int mod = 1e9;
const int lg = 40;
struct F {
	ll k, b;
	inline friend F operator + (F x, F y) {return {x.k + y.k, x.b + y.b};} 
	inline friend F operator - (F x, F y) {return {x.k - y.k, x.b - y.b};} 
	ll val(ll x) {
		return x * k + b;
	}
};
struct ChairmanTree {
	F a[maxn * lg];
	int rt[maxn + 5], ls[maxn * lg], rs[maxn * lg];
	int ncnt;
	void update(int &u, int pre, int l, int r, int p, F k) {
		a[u = ++ ncnt] = a[pre] + k; ls[u] = ls[pre], rs[u] =rs[pre];
		if(l == r) return ; 
		int mid = l + r >> 1;
		p <= mid ? update(ls[u], ls[pre], l, mid, p, k) : update(rs[u], rs[pre], mid + 1, r, p, k);
	}
	F query(int u, int v, int l, int r, int ql, int qr) {
		if(l >= ql && r <= qr) return a[v] - a[u];
		int mid = l + r >> 1;
		if(qr <= mid) return query(ls[u], ls[v], l, mid, ql, qr);
		else if(ql > mid) return query(rs[u], rs[v], mid + 1, r, ql, qr);
		else return query(ls[u], ls[v], l, mid, ql, qr) + query(rs[u], rs[v], mid + 1, r, ql, qr);
	}
}ds1, ds2;
int n, m;
int main() {
//	freopen("in.txt", "r", stdin);
	n = read();
	rep(i, 1, n) {
		int x1 = read(), x2 = read(), y1 = read(), a = read(), b = read(), y2 = read();
		ds1.rt[i] = ds1.rt[i - 1], ds2.rt[i] = ds2.rt[i - 1];
		ds1.update(ds1.rt[i], ds1.rt[i], 0, maxk, x1, F{0, y1} + F{-a, -b});
		ds2.update(ds2.rt[i], ds2.rt[i], 0, maxk, x2 + 1, F{0, y2});
		ds1.update(ds1.rt[i], ds1.rt[i], 0, maxk, x2, F{a, b});
	}
	ll lstans = 0;
	m = read();
	rep(i, 1, m) {
		int l = read(), r = read(), x = (read() + lstans) % mod;
		int y = min(maxk, x);
		F u = ds1.query(ds1.rt[l - 1], ds1.rt[r], 0, maxk, y, maxk);
		F v = ds2.query(ds2.rt[l - 1], ds2.rt[r], 0, maxk, 0, y);
		cout << (lstans = (u.val(x) + v.val(x))) << '\n';
	}
	return 0;
}