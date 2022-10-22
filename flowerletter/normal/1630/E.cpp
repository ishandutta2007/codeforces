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
const int maxn = 1e6;
const int mod = 998244353;
int n, a[maxn + 5], cnt[maxn + 5], f[maxn + 5], g[maxn + 5], h[maxn + 5], l[maxn + 5];
int fac[maxn + 5], inv[maxn + 5], ifac[maxn + 5];
int pri[maxn + 5], vis[maxn + 5], mu[maxn + 5], tot;
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;} 
inline int fpw(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
inline int c(int n, int m) {
	if(n < m) return 0;
	return mul(mul(fac[n], ifac[m]), ifac[n - m]);
}
void init() {
	mu[1] = 1;
	rep(i, 2, maxn) {
		if(!vis[i]) pri[++ tot] = i, mu[i] = -1;
		for(int j = 1; j <= tot && pri[j] * i <= maxn; j ++) {
			vis[pri[j] * i] = 1;
			if(i % pri[j] == 0) break;
			mu[pri[j] * i] = - mu[i];
		}
	}
	inv[0] = inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, maxn) inv[i] = mul(mod - mod / i, inv[mod % i]);
	rep(i, 2, maxn) fac[i] = mul(fac[i - 1], i);
	rep(i, 2, maxn) ifac[i] = mul(ifac[i - 1], inv[i]);
	rep(i, 1, maxn) mu[i] = add(mu[i], mod); 
}
int main() {
// 	freopen("in.txt", "r", stdin);
	init();
	for(int T = read(); T; T --) {
		n = read();
		rep(i, 1, n) cnt[i] = 0;
		rep(i, 1, n) {
			cnt[a[i] = read()] ++;
		}
		if(cnt[a[1]] == n) {
			cout << 1 << '\n';
			continue;
		}
		int gcd = 0;
		rep(i, 1, n) gcd = __gcd(gcd, cnt[i]);
		//cout << gcd << '\n'; 
		vector<int> fact;
		rep(i, 1, gcd) if(gcd % i == 0) fact.pb(i);
		for(auto x : fact) {
			g[x] = 0;
			h[x] = fac[n / x];
			rep(i, 1, n) if(cnt[i] >= 2) g[x] = add(g[x], mul(mul(inv[n / x  - 1], inv[n / x]), mul(cnt[i] / x, cnt[i] / x - 1)));
			rep(i, 1, n) h[x] = mul(h[x], ifac[cnt[i] / x]);
			g[x] = mul(n, mul(h[x], g[x]));
//			cout << g[x] << ' ' << h[x] << '\n';
		}
		int ans1 = 0, ans2 = 0;
		for(auto x : fact) {
			f[x] = 0, l[x] = 0;
			for(auto y : fact) if(y % x == 0) {
				f[x] = add(f[x], mul(g[y], mu[y / x]));
				l[x] = add(l[x], mul(h[y], mu[y / x]));
			}
			ans1 = add(ans1, mul(f[x], x));
			ans2 = add(ans2, mul(l[x], x));
		}
		ans1 = mul(ans1, fpw(ans2, mod - 2));
		ans1 = sub(n, ans1);
		cout << ans1 << '\n';
//		return 0;
	}
	return 0;
}