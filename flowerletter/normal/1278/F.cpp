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
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e7;
const int mod = 998244353;
int n, p, k, ans, fac[maxn + 5], inv[maxn + 5], f[maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int fpw(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
void init() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	rep(i, 2, maxn) fac[i] = mul(fac[i - 1], i);
	rep(i, 2, maxn) inv[i] = mul(mod - mod / i,  inv[mod % i]);
	//rep(i, 2, maxn) inv[i] = mul(inv[i - 1], inv[i]);
}
int main() {
	//freopen("in.txt", "r", stdin);
	init();
	cin >> n >> p >> k;
	if(p == 1) return cout << fpw(n, k) << '\n', 0;
	p = fpw(p, mod - 2);
	int cni = 1, cniki = 1, cni1ki1 = 1;
	rep(i, 1, k) cniki = mul(cniki, mul(inv[i], n - i + 1));
	rep(i, 0, k) f[0] = add(f[0], mul(cni, fpw(mod - p, i))), cni = mul(cni, mul(n - i, inv[i + 1]));
	rep(i, 1, k) {
		cni1ki1 = cniki;
		cniki = mul(cniki, mul(fpw(n - i + 1, mod - 2), k - i + 1));
		f[i] = mul(fpw(mod + 1 - p, mod - 2), add(f[i - 1], mul(fpw(mod - p, k - i + 1), sub(cniki, cni1ki1))));
	}
	cni = 1;
	rep(i, 0, k) ans = add(ans, mul(mul(mul(fpw(i, k), cni), fpw(p, i)), f[i])), cni = mul(cni, mul(n - i, inv[i + 1]));
	cout << ans << '\n';
	return 0;
}