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
const int mxlg = 35;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
int n, m;
ll a[maxn + 5], v[maxn + 5];
int f[maxn + 5], g[mxlg + 5][maxn + 5], ans[maxn + 5];
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
	per(i, mxlg, 0) if(x >> i & 1) {
		if(v[i]) x ^= v[i];
		else {
			v[i] = x; break;
		}
	}
}
void fwt(int *a, int n, int type) {
	for(int i = 1; i < n; i <<= 1) {
		for(int j = 0; j < n; j += (i << 1)) {
			for(int k = 0; k < i; k ++) {
				int x = a[j + k], y = a[i + j + k];
				if(type == 1) {
					a[j + k] = add(x, y), a[i + j + k] = sub(x, y);
				}
				else {
					a[j + k] = mul(add(x, y), inv2), a[i + j + k] = mul(sub(x, y), inv2);
				}
			}
		}
	}
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i], ins(a[i]);
	int m1 = 0, m2 = 0, mm = m / 2;
	rep(i, 0, mxlg) if(v[i]) pos.pb(i), m1 += i < mm, m2 += i >= mm;
//	for(auto x : pos) cout << x << ' ' << v[x] << '\n';
//	cout << m1 << ' ' << m2 << '\n';
	rep(s, 0, (1 << m1) - 1) {
		ll x = 0;
		rep(i, 0, m1 - 1) if(s >> i & 1) x ^= v[pos[i]];
		f[x] ++;
//		cout << x << '\n';
	}
	rep(s, 0, (1 << m2) - 1) {
		ll x = 0;
		rep(i, m1, sz(pos) - 1) if(s >> i - m1 & 1) x ^= v[pos[i]];
		int a = x & (1 << mm) - 1, b = x >> mm;
		g[__builtin_popcount(b)][a] ++;
//		cout << __builtin_popcount(b) << ' ' << a << '\n';
	}
	fwt(f, 1 << mm, 1);
	rep(i, 0, m - mm + 1) fwt(g[i], 1 << mm, 1);
	rep(i, 0, m - mm + 1) {
		rep(s, 0, (1 << mm) - 1) g[i][s] = mul(f[s], g[i][s]);
		fwt(g[i], 1 << mm, -1);
//		cout << i << "----\n";
		rep(s, 0, (1 << mm) - 1) upd(ans[i + __builtin_popcount(s)], g[i][s]);//, cout << g[i][s] << '\n';
	}
	rep(i, 0, m) cout << mul(ans[i], fpw(2, n - sz(pos))) << ' ';
	return 0;
}