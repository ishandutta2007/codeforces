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

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 4e5;
const int inf = 1e9;
int n, k;
P f[maxn + 5], g[maxn + 5], pre[maxn + 5], suf[maxn + 5];
vector<int> G[maxn + 5];
P operator + (P x, P y) {
	P ans;
	if(x.fi < y.fi) ans.fi = y.fi, ans.se = max(x.fi, y.se);
	else ans.fi = x.fi, ans.se = max(x.se, y.fi); 
	return ans;
}
P operator + (P x, int y) {
	if(y > x.fi) return P{y, x.fi};
	else return P{x.fi, max(y, x.se)}; 
}
P add(P x, int y) {
	return P{x.fi + y, x.se + y};
}
void dfs1(int u, int par) {
	f[u] = {-inf, -inf};
	for(auto v : G[u]) if(v != par) {
		dfs1(v, u), f[u] = f[u] + f[v].fi;
	}
	f[u] = add(f[u], 1);
	if(u != par && sz(G[u]) == 1) f[u] = P{0, -inf};
}
void dfs2(int u, int par) {
	if(u == par) g[u] = sz(G[u]) <= 1 ? P{0, -inf} : P{-inf, -inf};
	int lim = sz(G[u]) - 1;
	suf[lim + 1] = {-inf, -inf};
	rep(i, 0, lim) {
		int v = G[u][i];
		if(v != par) pre[i] = (i ? pre[i - 1] : P{-inf, -inf}) + f[v];
		else pre[i] = i ? pre[i - 1] : P{-inf, -inf};
	}
	per(i, lim, 0) {
		int v = G[u][i];
		if(v != par) suf[i] = suf[i + 1] + f[v];
		else suf[i] = suf[i + 1];
	}
	rep(i, 0, lim) {
		int v = G[u][i];
		if(v != par) g[v] = add(g[u], 1) + (i ? add(pre[i - 1], 2) : P{-inf, -inf}) + add(suf[i + 1], 2);
	}
	rep(i, 0, lim) {
		int v = G[u][i];
		if(v != par) dfs2(v, u);
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(), cse = 1; T; T --, cse ++) {
		n = read(), k = read();
		rep(i, 1, n) G[i].clear();
		rep(i, 2, n) {
			int u = read(), v = read();
			G[u].pb(v), G[v].pb(u);
		}
		dfs1(n, n), dfs2(n, n);
		int ans = 0;
		rep(i, 1, n) if((f[i] + g[i].fi).se >= k) ans ++;
		cout << ans << '\n';
	}
	return 0;
}