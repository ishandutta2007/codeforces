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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e5;
const int maxk = 200;
const int mod = 1e9 + 7;
int n, k, u, v, dp[maxn + 5][maxk + 5], s[maxk + 5][maxk + 5], tmp[maxk + 5], ans[maxk + 5];
int cnt, head[maxn + 5], size[maxn + 5];
struct Edge {
	int to, next;
}e[maxn * 2 + 5];
inline void add(int u, int v) {
	e[++cnt] = (Edge) {v, head[u]}, head[u] = cnt;
}
void upd(int &x) {x = x >= mod ? x - mod : x;}
void dfs(int u, int par) {
	size[u] = 1, dp[u][0] = 2;
	trv(i, u, v) if(v != par) {
		dfs(v, u);
		rep(i, 0, k) tmp[i] = dp[u][i], dp[u][i] = 0;
		rep(i, 0, min(size[u], k)) rep(j, 0, min(size[v], k - i)) {
			upd(dp[u][i + j] += 1ll * tmp[i] * dp[v][j] % mod);
			upd(dp[u][i + j + 1] += 1ll * tmp[i] * dp[v][j] % mod);
		}
		rep(i, 1 ,k) upd(dp[u][i] += mod - tmp[i - 1]);
		rep(i, 0, k) upd(ans[i] += mod - dp[v][i]);
		rep(i, 1, k) upd(ans[i] += mod - dp[v][i - 1]); 
		size[u] += size[v], upd(++ans[1]);
	}
	rep(i, 1, k) upd(ans[i] += dp[u][i]);
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	rep(i, 2, n) scanf("%d%d", &u, &v), add(u, v), add(v, u);
	s[1][1] = 1;
	rep(i, 2, k) rep(j, 1, i) upd(s[i][j] = s[i - 1][j - 1] + 1ll * j * s[i - 1][j] % mod);
	dfs(1, 1);
	int fac = 1, res = 0;
	rep(i, 1, k) upd(res += 1ll * (fac = 1ll * fac * i % mod) * s[k][i] % mod * ans[i] % mod);
	printf("%d\n", res);
	return 0;
}