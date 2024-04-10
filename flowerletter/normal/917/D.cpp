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
const int maxn = 100;
const int mod = 1e9 + 7;
int n, nn, invnn, u, v, k, size[maxn + 5], inv[maxn + 5], fac[maxn + 5], ifac[maxn + 5];
int dp[maxn + 5][maxn + 5], tmp[maxn + 5], val[maxn + 5], f[maxn + 5], g[maxn + 5];
int all[maxn + 5], nw[maxn + 5], sum[maxn + 5];
vector<int> e[maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int fpw(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
void dfs(int u, int par) {
	dp[u][0] = 0, dp[u][1] = invnn, size[u] = 1;
	for(auto v : e[u]) if(v != par) {
		dfs(v, u);
		rep(i, 0, size[u] + size[v]) tmp[i] = dp[u][i], dp[u][i] = 0;
		rep(i, 0, size[u]) rep(j, 0, size[v]) dp[u][i + j] = add(dp[u][i + j], mul(nn, mul(tmp[i], dp[v][j])));
		size[u] += size[v];
	} 
	rep(i, 0, size[u]) tmp[i] = dp[u][i];
	rep(i, 0, size[u]) dp[u][i] = mul(k, dp[u][i]);
	rep(i, 1, size[u]) dp[u][0] = add(dp[u][0], mul(tmp[i], mul(i, n)));
}
void init() {
	nn = mul(n, n), invnn = fpw(nn, mod - 2);
	all[0] = 1;
	rep(i, 1, n) {
		per(j, n, 1) all[j] = sub(all[j - 1], mul(i, all[j]));
		all[0] = mul(all[0], mod - i);
	}
	inv[0] = inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, maxn) inv[i] = mul(mod - mod / i, inv[mod % i]);
	rep(i, 2, maxn) fac[i] = mul(fac[i - 1], i);
	rep(i, 2, maxn) ifac[i] = mul(ifac[i - 1], inv[i]);
	rep(i, 1, n) val[i] = fpw(2, i * (i - 1) / 2 - i + 1);
}
inline int c(int n, int m) {return mul(mul(fac[n], ifac[m]), ifac[n - m]);}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n, init();
	rep(i, 2, n) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	rep(i, 1, n) {
		k = i, dfs(1, 1);
		int res = 1;
		rep(j, 1, n) if(j != i) res = mul(res, sub(i, j));
		nw[0] = mul(all[0],  mod - inv[i]);
		rep(j, 1, n) nw[j] = mul(sub(nw[j - 1], all[j]), inv[i]);
		res = mul(dp[1][0], fpw(res, mod - 2));
		rep(j, 0, n) sum[j] = add(sum[j], mul(nw[j], res));
	}
	rep(i, 0, n - 1) f[i] = sum[i];
	rep(i, 0, n - 1) {
		int d = 1;
		rep(j, i, n - 1) g[i] = add(g[i], mul(d, mul(c(j, i), f[j]))), d = mod - d;
		cout << g[i] << ' ';
	}
	return 0;
}