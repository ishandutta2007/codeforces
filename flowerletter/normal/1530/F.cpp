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
const int maxn = 21;
const int maxw = 1 << 21;
const int mod = 31607;
const int inv10000 = 3973;
int n, all, ans, a[maxn + 5][maxn + 5], f[maxn + 5][maxw + 5], vis[maxn + 5][maxn + 5], sum[maxn + 5];
inline void upd(int &x) {x = x >= mod ? x - mod : x;}
inline int add(int x) {return x >= mod ? x - mod : x;} 
inline int lg(int x) {return log2(x) + 1;}
inline int count(int x) {
	int res = 0;
	while(x) x ^= lb(x), res ++;
	return res;
}
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n; all = (1 << n) - 1;
	rep(i, 1, n) rep(j, 1, n) cin >> a[i][j], a[i][j] = 1ll * a[i][j] * inv10000 % mod;
	rep(i, 1, n) {
		f[i][0] = sum[i] = 1;
		rep(j, 1, n) sum[i] = sum[i] * a[i][j] % mod;
		rep(s, 1, all) {
			f[i][s] = 1ll * f[i][s ^ lb(s)] * a[lg(lb(s))][i] % mod;
		}
		rep(s, 0, all) upd(f[i][s] += mod - 1);
	}
	all = (1 << n + 2) - 1;
	rep(s, 0, all) {
		int res = 1;
		if(s & (1 << n)) {
			rep(i, 1, n) if(!(s & (1 << i - 1))) res = res * a[i][i] % mod;
		}
		if(s & (1 << n + 1)) {
			rep(i, 1, n) if(!(s & (1 << i - 1)) && !((s & (1 << n)) && 2 * i - 1 == n)) res = res * a[i][n - i + 1] % mod;
		}
		rep(i, 1, n) if(s & (1 << i - 1)) {
			res = res * sum[i] % mod;
		}
		rep(i, 1, n) {
			int t = s & (1 << n) - 1;
			if(s & (1 << n)) t |= 1 << i - 1;
			if(s & (1 << n + 1)) t |= 1 << n - i;
			res = res * f[i][t ^ ((1 << n) - 1)] % mod;
		}
		if(count(s) & 1) upd(ans += mod - res);
		else upd(ans += res);
	} 
	if(n & 1) upd(++ ans);
	else upd(ans = mod + 1 - ans);
	cout << ans << '\n';
	return 0;
}