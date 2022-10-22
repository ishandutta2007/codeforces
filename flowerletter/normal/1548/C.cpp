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
const int mod = 1e9 + 7;
const int maxn = 3e6 + 1;
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;} 
inline int fpw(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
int n, q, x, inv3, f[maxn + 5][3]; 
int fac[maxn + 5], inv[maxn + 5], ifac[maxn + 5];
void init() {
	inv[0] = inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, maxn) inv[i] = mul(mod - mod / i, inv[mod % i]);
	rep(i, 2, maxn) fac[i] = mul(fac[i - 1], i);
	rep(i, 2, maxn) ifac[i] = mul(ifac[i - 1], inv[i]);
}
inline int c(int n, int m) {
	if(n < m) return 0;
	return mul(mul(fac[n], ifac[m]), ifac[n - m]);
}
int main() {
// 	freopen("in.txt", "r", stdin);
	init();
	n = read(), q = read(), inv3 = fpw(3, mod - 2);
	f[0][0] = f[0][1] = f[0][2] = n;
	rep(i, 1, 3 * n) {
		int w0 = f[i - 1][2], w1 = sub(add(i == 1, f[i - 1][0]), add(c(3 * n, i), c(3 * n, i - 1))), w2 = f[i - 1][1], s = c(3 * n + 1, i + 1); 
//		x0 = x2 + w0, x1 = x0 + w1, x2 = x1 + w2;
//		2x1 = s - (x1 + w2)+ w1
//		3x0 = s - w1 + w0'
		f[i][0] = mul(inv3, add(s, sub(w0, w1)));
		f[i][1] = mul(inv3, add(s, sub(w1, w2)));
		f[i][2] = mul(inv3, add(s, sub(w2, w0)));
//		int k = 0;
//		rep(j, 1, 3 * n) if(j % 3 == 2) k += c(j, i);
//		cout << k << '\n';
//		cout << w0 << ' ' << w1 << ' ' << w2 << ' ' << s << '\n'; 
//		cout << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << '\n';
//		if(i == 2) break;
	}
	rep(i, 1, q) {
		x = read();
		cout << f[x][0] << '\n';
	}
	return 0;
}
/*

c(1, 2) + c(4, 2)
= c(3, 1) + c(3, 2) + 
6 = 18 - 15 + 5 ?
*/