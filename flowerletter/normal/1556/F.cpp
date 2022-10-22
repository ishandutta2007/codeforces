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
const int maxn = 14;
const int maxs = 1 << 14;
const int mod = 1e9 + 7;
int n, ans, a[maxn + 5], inv[maxn + 5][maxn + 5], to[maxn + 5][maxs + 5], dp[maxs + 5], cnt[maxs + 5];
inline int add(int x, int y) {return (x += y) >= mod ? x - mod : x;}
inline int sub(int x, int y) {return (x -= y) < 0 ? x + mod : x;}
inline int mul(int x, int y) {return 1ll * x * y % mod;}
inline int fpw(int x, int y, int ans = 1) {
	for(; y; y >>= 1, x = mul(x, x)) if(y & 1) ans = mul(ans, x);
	return ans;
}
inline int f(int s, int t) {
	int res = 1;
	rep(i, 1, n) if(s >> i - 1 & 1) res = mul(res, to[i][t]);
	return res;
}
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) rep(j, 1, n) inv[i][j] = fpw(add(a[i], a[j]), mod - 2);
	rep(i, 1, n) {
		rep(s, 0, (1 << n) - 1) {
			to[i][s] = 1;
			rep(j, 1, n) if(s >> j - 1 & 1) to[i][s] = mul(to[i][s], mul(a[i], inv[i][j]));
		}
	}
	rep(s, 1, (1 << n) - 1) {
		dp[s] = 1;
		for(int t = s & (s - 1); t; t = (t - 1) & s) {
			dp[s] = sub(dp[s], mul(dp[t], f(t, s ^ t)));
		}
	}
	rep(s, 1, (1 << n) - 1) cnt[s] = cnt[s ^ lb(s)] + 1, ans = add(ans, mul(mul(cnt[s], dp[s]), f(s, (1 << n) - 1 ^ s)));
	cout << ans << '\n';
	return 0;
}