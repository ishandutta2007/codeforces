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
const int maxn = 2e5;
const int maxm = 53;
const int maxs = 1 << 13;
const int mod = 998244353;
int n, m;
ll a[maxn + 5], v[maxm + 5], s1[maxs + 5], s2[maxs + 5];
int ans[maxm + 5];
ll w[maxm + 5];
int f[maxm + 5], c[maxm + 5][maxm + 5], g[maxm + 5][maxm + 5];
vector<int> pos;
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline void upd(int &a, int b) {a = add(a, b);}
inline int fpw(int a, int b) {
	int ans = 1;
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
void ins(ll x) {
	per(i, m - 1, 0) if(x >> i & 1) {
		if(v[i]) x ^= v[i];
		else {
			per(j, i - 1, 0) if(v[j] && (x >> j & 1)) x ^= v[j];
			rep(j, i + 1, maxm) if(v[j] >> i & 1) v[j] ^= x;
			v[i] = x; 
			break;
		}
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i], ins(a[i]);
	rep(i, 0, m) if(v[i]) pos.pb(i);
	int m1 = sz(pos);
	if(m1 <= 26) {
		int t1 = m1 / 2, t2 = m1 - m1 / 2;
		rep(s, 1, (1 << t1) - 1) {
			s1[s] = s1[s ^ lb(s)] ^ v[pos[__builtin_ctz(s)]];
		}
		rep(s, 1, (1 << t2) - 1) {
			s2[s] = s2[s ^ lb(s)] ^ v[pos[t1 + __builtin_ctz(s)]];
		}
		rep(s, 0, (1 << m1) - 1) {
			ll x = s1[s & (1 << t1) - 1], y = s2[s >> t1];
			upd(ans[__builtin_popcountll(x ^ y)], 1);
		}
		rep(i, 0, m) cout << mul(ans[i], fpw(2, n - m1)) << ' ';
		return 0;
	}
	else {
		pos.clear();
		rep(i, 0, m - 1) if(!v[i]) {
			rep(j, 0, m - 1) {
				if(!v[j]) w[i] |= (ll)(i == j) << j;
				else w[i] |= (ll)(v[j] >> i & 1) << j;
			}
			pos.pb(i);
		}
		int m2 = sz(pos), t = mul(fpw(2, n), fpw(2, mod - 1 - m));
		int t1 = m2 / 2, t2 = m2 - m2 / 2;
		rep(s, 1, (1 << t1) - 1) {
			s1[s] = s1[s ^ lb(s)] ^ w[pos[__builtin_ctz(s)]];
		}
		rep(s, 1, (1 << t2) - 1) {
			s2[s] = s2[s ^ lb(s)] ^ w[pos[t1 + __builtin_ctz(s)]];
		}
		rep(s, 0, (1 << m2) - 1) {
			ll x = s1[s & (1 << t1) - 1], y = s2[s >> t1];
			upd(f[__builtin_popcountll(x ^ y)], t);
		}
		rep(i, 0, m) {
			c[i][0] = 1;
			rep(j, 1, i) {
				c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
			}
		}
		rep(i, 0, m) {
			rep(j, 0, m) {
				int d = 1;
				rep(k, 0, m) {
					upd(g[i][j], mul(d, mul(c[i][k], c[m - i][j - k])));
					d = mod - d;
				}
			}
		}
		rep(i, 0, m) {
			rep(j, 0, m) {
				upd(ans[i], mul(f[j], g[j][i]));
			}
		}
		rep(i, 0, m) cout << ans[i] << ' ';
	}
	return 0;
}