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
const int maxn = 200;
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
int n, ret[maxn + 5][maxn + 5][maxn + 5], siz[maxn + 5], fa[maxn + 5];
int inv[maxn + 5];
vector<int> g[maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline void upd(int &a, int b) {a = add(a, b);}
void dfs(int u, int par) {
	siz[u] = 1, fa[u] = par;
	for(auto v : g[u]) if(v != par) {
		dfs(v, u);
		siz[u] += siz[v];
	}
}
void init() {
	inv[0] = inv[1] = 1;
	rep(i, 2, maxn) inv[i] = mul(mod - mod / i, inv[mod % i]);
}
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	cin >> n;
	rep(i, 1, n) {
		rep(j, 1, i) {
			per(k, i, j) {
				if(j == 1) ret[i][j][k] = 1;
				else if(k == i) ret[i][j][k] = 0;
				else {
					ret[i][j][k] = mul(inv2, add(ret[i][j - 1][k], ret[i][j][k + 1]));
//					cout << ret[i][j][k] <<
				}
			}
		}
	}
//	cout << ret[3][2][2] << '\n';
	rep(i, 2, n) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	int ans = 0;
	rep(i, 1, n) {
		dfs(i, i);
		rep(j, 1, i - 1) {
			vector<int> s;
			int u = j, lst = 0;
			while(u != i) {
				s.pb(siz[u] - lst);
				lst = siz[u], u = fa[u];
			}
			s.pb(siz[u] - lst);
			reverse(all(s));
			rep(k, 0, sz(s) - 1) {
//				cout << i << ',' << j << ':' << s[k] << ' ' << ret[sz(s)][k + 1][k + 1] << '\n';
				upd(ans, mul(s[k], ret[sz(s)][k + 1][k + 1]));
			}
		}
	}
	cout << mul(ans, inv[n]) << '\n';
	return 0;
}