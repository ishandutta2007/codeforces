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
const int maxn = 100;
const int maxm = 2e4;
const int maxs = 1e5;
const int mod = 1e9 + 7;
int n, q, c[maxn + 5], b[maxn + 5], w1[maxn + 5][maxn + 5], w2[maxn + 5][maxn + 5];
int f[maxn + 5][maxs + 5], g[maxn + 5][maxm + 5];
vector<P> s;
int id[maxm + 5][maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline void upd(int &a, int b) {a = add(a, b);}
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> c[i];
	}
	rep(i, 1, n - 1) {
		cin >> b[i];
	}
//	rep(i, -n * 100, n * 100) rep(j, 1, n) {
//		if(abs(__gcd(i, j)) != 1) continue;
//		s.pb({i, j});
//	}
//	sort(all(s), [&] (P x, P y) {return x.fi * y.se < x.se * y.fi;});
//	rep(i, 0, sz(s) - 1) id[s[i].fi + 10000][s[i].se] = i, f[n + 1][i] = 1;
//	rep(i, 1, n) {
//		rep(j, i, n) {
//			rep(k, i, j - 1) {
//				upd(w1[i][j], mul(b[k], j - k));
//				upd(w2[i][j], mul(b[k], k - i + 1));
//			}
//		}
//	}
//	return 0;
//	f[n + 1][id[0][1]
	cin >> q;
	rep(i, 1, q) {
		int x;
		cin >> x;
		memset(g, 0, sizeof g);
		g[0][0] = 1;
		int lim  = 0; 
		rep(i, 1, n) {
			rep(k, 0, lim) {
				rep(x, 0, c[i]) {
					upd(g[i][k + x], g[i - 1][k]);
				}
			}
			lim += c[i];
			int cur = i * x;
			rep(j, 1, i) {
				cur += (i - j) * b[j];
			}
			rep(k, 0, cur - 1) g[i][k] = 0;
		}
		int ans = 0;
		rep(i, 0, lim) {
			upd(ans, g[n][i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
//(s1 + i * b[i]) / i < s2 + w[i][n] / n - i  + 1