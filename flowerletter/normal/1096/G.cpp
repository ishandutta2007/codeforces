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
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int mod = 998244353;
const int maxn = 1 << 21;
int n, k, m, a[maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int fpw(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
namespace poly {
	const int inv2 = (mod + 1) / 2;
	int lg[maxn + 5], inv[maxn + 5], w[maxn + 5], rev[maxn + 5];
	void init() {
		lg[1] = 0, w[0] = 1, w[1] = fpw(3, (mod - 1) / maxn);
		rep(i, 2, maxn) lg[i] = lg[i + 1 >> 1] + 1, w[i] = mul(w[i - 1], w[1]);
		inv[0] = inv[1] = 1;
		rep(i, 2, maxn) inv[i] = mul(mod - mod / i, inv[mod % i]);
	}
	void ntt(int *a, int len, int type) {
		rep(i, 0, len - 1) {
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg[len] - 1);
			if(rev[i] < i) swap(a[i], a[rev[i]]);
		}
		for(int i = 1; i < len; i <<= 1) {
			int s = maxn / (i << 1);
			for(int j = 0; j < len; j += (i << 1)) {
				for(int k = 0, *p = w; k < i; k ++, p += s) {
					int x = a[j + k], y = mul(*p, a[j + k + i]);
					a[j + k] = add(x, y);
					a[j + k + i] = sub(x, y);
				}
			} 
		}
		if(!type) {
			int inv = fpw(len, mod - 2);
			rep(i, 0, len - 1) a[i] = mul(a[i], inv);
			reverse(a + 1, a + len); 
		}
	}
	void copy(int *f,int *g, int len, int mxlen) {
		rep(i, 0, len - 1) g[i] = f[i];
		rep(i, len, mxlen - 1) g[i] = 0;
	}
	void polymul(int *f, int *g, int *h, int len) {
		static int a[maxn + 5], b[maxn + 5];
		int mxlen = 1 << lg[len];
		copy(f, a, len, mxlen), copy(g, b, len, mxlen);
		ntt(a, mxlen, 1), ntt(b, mxlen, 1);
		rep(i, 0, mxlen - 1) a[i] = mul(a[i], b[i]);
		ntt(a, mxlen, 0); 
		copy(a, h, len, len);
	}
	void polyinv(int *f, int *g, int len) {
		if(len == 1) return g[0] = fpw(f[0], mod - 2), void();
		static int a[maxn + 5], b[maxn + 5];
		int mid = len + 1 >> 1, mxlen = 1 << lg[len << 1];
		polyinv(f, g, mid);
		copy(g, a, mid, mxlen);
		copy(f, b, len, mxlen);
		ntt(a, mxlen, 1), ntt(b, mxlen, 1);
		rep(i, 0, mxlen - 1) a[i] = sub(add(a[i], a[i]), mul(mul(a[i], a[i]), b[i]));
		ntt(a, mxlen, 0);
		copy(a, g, len, len);
	}
	void polysqrt(int *f, int *g, int len) {
		if(len == 1) return g[0] = 1, void();
		static int a[maxn + 5], b[maxn + 5];
		int mid = len + 1 >> 1, mxlen = 1 << lg[len << 1];
		polysqrt(f, g, mid);
		copy(g, a, mid, mxlen);
		polyinv(a, b, len);
		copy(f, a, len, mxlen);
		ntt(a, mxlen, 1), ntt(b, mxlen, 1);
		rep(i, 0, mxlen - 1) a[i] = mul(a[i], b[i]);
		ntt(a, mxlen, 0);
		rep(i, 0, mid - 1) a[i] = add(a[i], g[i]); 
		rep(i, 0, len - 1) a[i] = mul(a[i], inv2);
		copy(a, g, len, len);
	}
	void polyint(int *f, int *g, int len) {
		rep(i, 1, len - 1) g[i] = mul(f[i - 1], inv[i]);
		g[0] = 0;
	} 
	void polyder(int *f, int *g, int len) {
		rep(i, 0, len - 2) g[i] = mul(f[i + 1], i + 1);
		g[len - 1] = 0;
	}
	void polyln(int *f, int * g, int len) {
		static int a[maxn + 5], b[maxn + 5];
		int mxlen = 1 << lg[len << 1];
		polyder(f, a, len);
		polyinv(f, b, len);
		copy(a, a, len, mxlen);
		copy(b, b, len, mxlen);
		ntt(a, mxlen, 1), ntt(b, mxlen, 1);
		rep(i, 0, mxlen - 1) a[i] = mul(a[i], b[i]);
		ntt(a, mxlen, 0);
		polyint(a, g, len);
	}
	void polyexp(int *f, int *g, int len) {
		if(len == 1) return g[0] = 1,void(); 
		int mid = len + 1 >> 1, mxlen = 1 << lg[len << 1];
		static int a[maxn + 5], b[maxn + 5];
		polyexp(f, g, mid);
		polyln(g, a, len);
		copy(a, a, len, mxlen);
		rep(i, 0, len - 1) a[i] = sub(f[i], a[i]);
		a[0] = add(a[0], 1);
		copy(g, b, len, mxlen);
		ntt(a, mxlen, 1), ntt(b, mxlen, 1);
		rep(i, 0, mxlen - 1) a[i] = mul(a[i], b[i]);
		ntt(a, mxlen, 0);
		copy(a, g, len, len); 
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), k = read(), m = n / 2 * 9 + 1;
	poly::init();
	rep(i, 1, k) a[read()] = 1;
	int mxlen = 1 << poly::lg[m];
	poly::ntt(a, mxlen, 1);
	rep(i, 0, mxlen - 1) a[i] = fpw(a[i], n / 2);
	poly::ntt(a, mxlen, 0);
	int ans = 0;
	rep(i, 0, m - 1) ans = add(ans, mul(a[i], a[i])); 
	cout << ans << '\n'; 
	return 0;
}