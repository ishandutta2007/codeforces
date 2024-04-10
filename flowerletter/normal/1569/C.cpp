
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
const int maxn = 2e5;
const int mod = 998244353;
int T, n, a[maxn + 5], fac[maxn + 5], inv[maxn + 5];
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
void init() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	rep(i, 2, maxn) fac[i] = mul(fac[i - 1], i);
	rep(i, 2, maxn) inv[i] = mul(mod - mod / i, inv[mod % i]);
}
int main() {
	//freopen("in.txt", "r", stdin);
	init();
	for(cin >> T; T; T --) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		int *p = max_element(a + 1, a + n + 1);
		int mx = *p, smx = max(p - a == 1 ? 0 : *max_element(a + 1, p), p - a == n ? 0 : *max_element(p + 1, a + n + 1));
		if(mx > smx + 1) puts("0");
		else if(mx == smx) cout << fac[n] << '\n';
		else {
			int cnt = 0;
			rep(i, 1, n) cnt += a[i] == smx;
			cout << mul(mul(fac[n], inv[cnt + 1]), cnt) << '\n';
		}
	}
	return 0;
}