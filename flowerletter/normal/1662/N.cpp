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
const int maxn = 1500;
int n, a[maxn + 5][maxn + 5];
int f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) rep(j, 1, n) cin >> a[i][j];
	rep(i, 1, n) {
		vector<P> s, t;
		rep(j, 1, n) s.pb({a[i][j], j}), t.pb({a[j][i], j});
		sort(all(s)), sort(all(t));
		rep(j, 0, n - 1) f[i][s[j].se] = j, g[t[j].se][i] = j;
	}
	ll ans = 0;
	rep(i, 1, n) rep(j, 1, n) ans += 1ll * f[i][j] * g[i][j];
	ans -= 1ll * n * (n - 1) / 2 * n * (n - 1) / 2;
	ans = 1ll * n * (n - 1) / 2 * n * (n - 1) / 2 - ans;
	cout << ans << '\n';
	return 0;
}