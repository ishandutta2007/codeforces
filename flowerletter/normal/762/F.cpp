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
typedef unsigned long long u64;
typedef pair<ll, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1000;
const int maxm = 12;
const int mod = 1e9 + 7;
const int base = 13;
int n, m, f[maxn + 5][maxm + 5];
int val[maxm + 5], fac[maxm + 5];
vector<int> son[maxm + 5];
int ans;
vector<int> G[maxn + 5], g[maxm + 5];
map<u64, int> mp;
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int fpw(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
namespace sub1 {
	u64 hsh[maxm + 5];
	int siz[maxm + 5], dep[maxm + 5];
	u64 init(int u) {
		function<void(int, int)> dfs = [&] (int u, int par) {
			vector<P> s; 
			hsh[u] = (u64) (dep[u] = dep[par] + 1) * base, siz[u] = 1, son[u].clear();
			map<u64, int> mp;
			for(auto v : g[u]) if(v != par) {
				dfs(v, u);
				s.pb({hsh[v], siz[v]});
				son[u].pb(v);
				mp[hsh[v]] ++;
			}
			sort(all(s));
			for(auto x : s) hsh[u] += x.fi * fpw(base, siz[u]), siz[u] += x.se;
			val[u] = 1;
			for(auto x : mp) val[u] = mul(val[u], fac[x.se]);
		};
		dep[u] = 0, dfs(u, u);
		return hsh[u];
	}
}
using sub1::init;
struct Dp {
	int m;
	vector<A<maxm>> a;
	void ins(A<maxm> x) {a.pb(x);}
	int f[(1 << maxm) + 1], g[(1 << maxm) + 1];
	int solve() {
		memset(f, 0, sizeof f);
		f[0] = 1;
		if(sz(a) < m) return 0;
		for(auto x : a) {
			memcpy(g, f, sizeof f);
			rep(i, 0, m - 1) {
				rep(s, 0, (1 << m) - 1) if(s >> i & 1){
					f[s] = add(f[s], mul(x[i], g[s ^ 1 << i]));
				}
			}
		}
		return f[(1 << m) - 1];
	}
	void clear(int _m) {
		m = _m;
		a.clear();
	}
}d;
void solve(int u) {
	u64 rnd = init(u);
//	cout << u << ": " << rnd << '\n';
	if(mp.count(rnd)) return ;
	mp[rnd] = 1;
	memset(f, 0, sizeof f);
	function<void(int, int)> dfs = [&] (int u, int par) {
		for(auto v : G[u]) if(v != par) dfs(v, u);
		rep(i, 1, m) {
			int lim = sz(son[i]);
			d.clear(lim); 
			for(auto v : G[u]) if(v != par) {
				A<maxm> tmp;
				rep(j, 0, lim - 1) tmp[j] = f[v][son[i][j]];
				d.ins(tmp);
			}
			f[u][i] = mul(d.solve(), fpw(val[i], mod - 2));
		}
	};
	dfs(1, 1);
//	cout << u << ":\n";
	rep(i, 1, n) ans = add(ans, f[i][u]);//, cout << f[i][u] << " \n"[i == n];
//	cout << f[5][1] << ' ' << f[5][2] << ' ' << f[5][3] << '\n';
//	cout << f[4][1] << ' ' << f[4][2] << ' ' << f[4][3] << '\n';
//	cout << "---------\n";
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read();
	rep(i, 2, n) {
		int u = read(), v = read();
		G[u].pb(v), G[v].pb(u);
	}
	fac[0] = fac[1] = 1;
	m = read();
	rep(i, 2, m) {
		fac[i] = mul(fac[i - 1], i);
		int u = read(), v = read();
		g[u].pb(v), g[v].pb(u); 
	}
	rep(i, 1, m) solve(i);
	cout << ans << '\n';
	return 0;
}