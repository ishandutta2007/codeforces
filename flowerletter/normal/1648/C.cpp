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
const int mod = 998244353;
int n, m, s[maxn + 5], t[maxn + 5];
int cnta[maxn + 5], cntb[maxn + 5];
int fac[maxn + 5], inv[maxn + 5], ifac[maxn + 5];
int cur;
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;} 
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline void upd(int &a, int b) {a = add(a, b);}
inline int fpw(int a, int b) {
	int ans = 1;
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
void init() {
	fac[0] = fac[1] = inv[0] = inv[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, maxn) fac[i] = mul(fac[i - 1], i);
	rep(i, 2, maxn) inv[i] = mul(inv[mod % i], mod - mod / i);
	rep(i, 2, maxn) ifac[i] = mul(ifac[i - 1], inv[i]); 
}
struct Segment {
	#define ls u << 1
	#define rs u << 1 | 1
	int sum[maxn + 5 << 2], tag[maxn + 5 << 2];
	void pushup(int u) {sum[u] = add(sum[ls], sum[rs]);}
	void seta(int u, int k) {sum[u] = mul(sum[u], k), tag[u] = mul(tag[u], k);}
	void pushdown(int u) {
		if(tag[u] != 1) {
			seta(ls, tag[u]);
			seta(rs, tag[u]);
			tag[u] = 1;
		}
	}
	void build(int u, int l, int r) {
		tag[u] = 1;
		if(l == r) {
			sum[u] = mul(mul(cnta[l], cur), fac[n - 1]);
			return ;
		}
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(u); 
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
		if(l >= ql && r <= qr) return sum[u];
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
		else return add(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
	}
}ds;
int main() {
// 	freopen("in.txt", "r", stdin);
	init();
	n = read(), m = read();
	rep(i, 1, n) cnta[s[i] = read()] ++;
	rep(i, 1, m) cntb[t[i] = read()] ++;
	int ans = 0;
	cur = 1;
	rep(i, 1, maxn) cur = mul(cur, ifac[cnta[i]]);
	ds.build(1, 1, maxn);
	rep(i, 1, min(n, m)) {
		if(t[i] > 1) upd(ans, ds.query(1, 1, maxn, 1, t[i] - 1));
		if(!cnta[t[i]]) break;
		if(t[i] > 1) ds.update(1, 1, maxn, 1, t[i] - 1, mul(inv[n - i], cnta[t[i]]));
		if(t[i] < maxn) ds.update(1, 1, maxn, t[i] + 1, maxn, mul(inv[n - i], cnta[t[i]]));
		ds.update(1, 1, maxn, t[i], t[i], mul(inv[n - i], cnta[t[i]] - 1));
		cnta[t[i]] --;
	}
	int flg = n < m;
	rep(i, 0, maxn) flg &= cnta[i] == 0;
	cout << add(ans, flg) << '\n';
	return 0;
}