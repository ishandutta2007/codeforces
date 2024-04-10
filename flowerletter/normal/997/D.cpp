/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
 
const int maxn = 4000;
const int maxk = 75;
const int mod = 998244353;
 
int n1, n2, k, u, v;
int ans, c[maxk + 5][maxk + 5];
inline void red(int &x) {x -= mod, x += x >> 31 & mod;}
struct Dp {
	int n, head[maxn +5], cnt, fa[maxn + 5];
	int f[maxn + 5][maxk + 5], g[maxn + 5][maxk + 5], h[maxn + 5][maxk + 5], d[maxn + 5][maxk + 5]; 
	int sum[maxk + 5];
	struct Edge {
		int to, next;
	}e[maxn * 2 + 5];
	void add(int u, int v) {
		e[++cnt] = (Edge) {v, head[u]}, head[u] = cnt;
		e[++cnt] = (Edge) {u, head[v]}, head[v] = cnt;
	}
	void dfs1(int u, int par) {
		g[u][0] = 1, fa[u] = par;
		trv(i, u) {
			int v = e[i].to;
			if(v == par) continue;
			dfs1(v, u);
			rep(j, 2, k) red(f[u][j] += g[v][j - 2]);
		}
		rep(i, 1, k) rep(j, 2, i) red(g[u][i] += 1ll * g[u][i - j] * f[u][j] % mod);
		//cout << u <<  ":\n";
		//rep(i, 0, k) cout << f[u][i] << " \n"[i == k];
		//rep(i, 0, k) cout << g[u][i] << " \n"[i == k];
	}
	void dfs2(int u, int par) {
		if(u != par) {
			rep(i, 2, k) red(h[u][i] = f[par][i] + h[par][i]), red(h[u][i] += mod - g[u][i - 2]);
			//cout << u <<  ":\n";
			//rep(i, 0, k) cout << h[u][i] << " \n"[i == k];
			d[u][0] = 1;
			rep(i, 1, k) rep(j, 2, i) red(d[u][i] += 1ll * d[u][i - j] * h[u][j] % mod);
			rep(i, 2, k) red(h[u][i] = d[u][i - 2]);
			d[u][0] = 1;
			rep(i, 1, k) d[u][i] = 0;
			rep(i, 1, k) rep(j, 2, i) red(d[u][i] += 1ll * d[u][i - j] * h[u][j] % mod);
			//cout << u <<  ":\n";
			//rep(i, 0, k) cout << d[u][i] << " \n"[i == k];
			//rep(i, 0, k) cout << h[u][i] << " \n"[i == k];
		}
		trv(i, u) {
			int v = e[i].to;
			if(v == par) continue;
			dfs2(v, u);
		}
		rep(i, 0, k) red(h[u][i] += f[u][i]), g[u][i] = 0;
		g[u][0] = 1;
		rep(i, 1, k) rep(j, 2, i) red(g[u][i] += 1ll * g[u][i - j] * h[u][j] % mod);
		rep(i, 0, k) red(sum[i] += g[u][i]);
	}
	void work(int n_) {
		n = n_;dfs1(1, 1), dfs2(1, 1);
		//rep(i, 0, k) printf("%d%c", sum[i], " \n"[i == k]);
	}
}mjy, hlt;
int main() {
//	freopen("in.txt", 	"r", stdin);
	scanf("%d%d%d", &n1, &n2, &k);
	rep(i, 1, n1 - 1) scanf("%d%d", &u, &v), mjy.add(u, v);
	rep(i, 1, n2 - 1) scanf("%d%d", &u, &v), hlt.add(u, v);
	mjy.work(n1);hlt.work(n2);
	c[0][0] = 1;
	rep(i, 1, k) rep(j, 0, i) red(c[i][j] += c[i - 1][j] + (!j ? 0 : c[i - 1][j - 1]));
	rep(i, 0, k) red(ans += 1ll * mjy.sum[i] * hlt.sum[k - i] % mod * c[k][i] % mod);
	printf("%d\n", ans);
	return 0;
}