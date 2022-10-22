/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 3e5;
const int mod = 998244353;
int n, a[maxn + 5];
int ans, sum, fac[maxn + 5], inv[maxn + 5];
inline void init() {
	inv[0] = inv[1] = fac[0] = fac[1] = 1;
	rep(i, 2, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
	rep(i, 2, maxn) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	rep(i, 2, maxn) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
}
int c(int n, int m) {
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
inline void upd(int &x) {x = x >= mod ? x - mod : x;}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n), init();
	rep(i, 1, 2 * n) scanf("%d", &a[i]);
	sort(a + 1, a + 2 * n + 1);
	rep(i, 1, 2 * n) upd(a[i]);
	rep(i, 1, n) upd(sum += mod - a[i]);
	rep(i, n + 1, 2 * n) upd(sum += a[i]);
	printf("%d\n", 1ll * sum * c(2 * n, n) % mod);
	return 0;
}