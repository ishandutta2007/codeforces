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
template <int T> using A = array<ll, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 3e5;
const ll inf = 1e18;
int n, a[maxn + 5];
struct Segment {
	#define ls u << 1
	#define rs u << 1 | 1
	ll mx[maxn * 4], mxid[maxn * 4], mxcnt[maxn * 4];
	ll mn[maxn * 4], mnid[maxn * 4], mncnt[maxn * 4];
	A<2> tag[maxn * 4];
	void pushup(int u) {
		mxcnt[u] = mncnt[u] = 0;
		mx[u] = max(mx[ls], mx[rs]);
		mn[u] = min(mn[ls], mn[rs]);
		if(mx[ls] == mx[u]) mxid[u] = mxid[ls], mxcnt[u] += mxcnt[ls];
		if(mn[ls] == mn[u]) mnid[u] = mnid[ls], mncnt[u] += mncnt[ls];
		if(mx[rs] == mx[u]) mxid[u] = mxid[rs], mxcnt[u] += mxcnt[rs];
		if(mn[rs] == mn[u]) mnid[u] = mnid[rs], mncnt[u] += mncnt[rs];
	}
	void seta(int u, A<2> k) {
		if(k[0]) {
			swap(mx[u], mn[u]);
			swap(mxid[u], mnid[u]);
			swap(mxcnt[u], mncnt[u]);
			mx[u] *= -1, mn[u] *= -1;
			tag[u][0] ^= 1;
			tag[u][1] *= -1;
		}
		if(k[1]) {
			mx[u] += k[1], mn[u] += k[1];
			tag[u][1] += k[1];
		}
	}
	void pushdown(int u) {
		if(tag[u][0] || tag[u][1]) {
			seta(ls, tag[u]);
			seta(rs, tag[u]);
			tag[u][0] = tag[u][1] = 0;
		}
	}
	void erase(int u, int l, int r, int p) {
		if(l == r) return mn[u] = inf, mx[u] = -inf, void();
		int mid = l + r >> 1; pushdown(u);
		if(p <= mid) erase(ls, l, mid, p);
		else if(p > mid) erase(rs, mid + 1, r, p);
		pushup(u); 
	}
	void update(int u, int l, int r, int ql, int qr, A<2> k) {
		if(l >= ql && r <= qr) return seta(u, k), void(); 
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) update(ls, l, mid, ql, qr, k);
		else if(ql > mid) update(rs, mid + 1, r, ql, qr, k);
		else update(ls, l, mid, ql, qr, k), update(rs, mid + 1, r, ql, qr, k);
		pushup(u); 
	}
	void build(int u, int l, int r) {
		tag[u] = {0, 0}, mn[u] = mx[u] = 0;
		if(l == r) return mxid[u] = mnid[u] = l, mxcnt[u] = mncnt[u] = 1, void();
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(u);
	}
	#undef ls
	#undef rs
}ds;
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		rep(i, 1, n) a[i] = read();
		ds.build(1, 1, n);
		ll ans = 0;
		rep(i, 1, n) {
			while(ds.mx[1] > a[i]) ds.erase(1, 1, n, ds.mxid[1]);
			ds.update(1, 1, n, 1, i, {1, a[i]});
			ans += ds.mn[1] == 0 ? (ds.mncnt[1] - (n - i)) : 0;
		}
		cout << ans << '\n';
	}
	return 0;
}