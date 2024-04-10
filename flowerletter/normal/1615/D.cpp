#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int inf = 1e9;
const int maxn = 2e5;
vector<P> G[maxn + 5];
int n, m, flg, a[maxn + 5], vis[maxn + 5];
struct Edge {
	int to, nxt, w;
}e[maxn * 4 + 5];
int cnt, head[maxn + 5];
vector<A<3>> ans;
void add(int u, int v, int w) {
	e[++cnt] = (Edge){v, head[u], w}, head[u] = cnt;
}
void dfs(int u) {
	vis[u] = 1;
	trv(i, u, v) {
		if(vis[v]) {
			if(a[v] != (a[u] ^ e[i].w)) flg = 0;
		}
		else {
			a[v] = (a[u] ^ e[i].w);
			dfs(v);
		}
	}
}
void getans(int u, int par) {
	for(auto v : G[u]) if(v.fi != par) {
		getans(v.fi, u);
		int w = (v.se == -1 ? (a[v.fi] ^ a[u]) : v.se);
		ans.pb({u, v.fi, w});
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read(), m = read(), ans.clear();
		rep(i, 1, n) vis[i] = head[i] = a[i] = 0, G[i].clear();
		cnt = 0, flg = 1;
		rep(i, 2, n) {
			int u = read(), v = read(), w = read();
			G[u].pb({v, w}), G[v].pb({u, w});
			if(w != -1) add(u, v, __builtin_popcount(w) & 1), add(v, u, __builtin_popcount(w) & 1);
		}
		rep(i, 1, m) {
			int u = read(), v = read(), w = read();
			add(u, v, w), add(v, u, w);
		}
		rep(i, 1, n) if(!vis[i]) dfs(i);
		if(!flg) cout << "NO\n";
		else {
			cout << "YES\n";
			int rt = -1;
			rep(i, 1, n) if(!a[i]) rt = i;
			assert(rt != -1);
			getans(rt, rt);
			for(auto x : ans) cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n'; 
		}
	}
	return 0;
}