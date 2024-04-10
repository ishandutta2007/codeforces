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

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 2e5;
const ll inf = 1e18;
int n;
ll h[maxn + 5], a[maxn + 5];
ll fmx[maxn + 5], fsum[maxn + 5], gmx[maxn + 5], gsum[maxn + 5], ok[maxn + 5];
ll premx[maxn + 5], presum[maxn + 5], sufmx[maxn + 5], sufsum[maxn + 5];
vector<int> g[maxn + 5];
void dfs1(int u, int par) {
	for(auto v : g[u]) if(v != par) {
		dfs1(v, u);
		chkmx(fmx[u], fmx[v]);
		fsum[u] += fsum[v];
	}
	fsum[u] += (ok[u] = max(0ll, h[u] - fmx[u]));
	chkmx(fmx[u], h[u]);
}
void dfs2(int u, int par) {
	vector<int> son;
	son.pb(0);
	for(auto v : g[u]) if(v != par) son.pb(v);
	sufmx[sz(son)] = sufsum[sz(son)] = 0;
	rep(i, 1, sz(son) - 1) premx[i] = max(premx[i - 1], fmx[son[i]]), presum[i] = presum[i - 1] + fsum[son[i]];
	per(i, sz(son) - 1, 1) sufmx[i] = max(sufmx[i + 1], fmx[son[i]]), sufsum[i] = sufsum[i + 1] + fsum[son[i]];
	rep(i, 1, sz(son) - 1) {
		gmx[son[i]] = max({gmx[u], premx[i - 1], sufmx[i + 1]});
		gsum[son[i]] = presum[i - 1] + sufsum[i + 1] + gsum[u];
		gsum[son[i]] += max(0ll, h[u] - gmx[son[i]]);
		chkmx(gmx[son[i]], h[u]);
	}
	rep(i, 1, sz(son) - 1) {
		dfs2(son[i], u);
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read();
	rep(i, 1, n) {
		h[i] = read();
		a[i] = h[i];
	}
	rep(i, 2, n) {
		int u = read(), v = read();
		g[u].pb(v) ,g[v].pb(u);
	}
	sort(a + 1, a + n + 1);
	ll cur = 2 * a[n], ans = inf;
	dfs1(1, 1), dfs2(1, 1); 
	rep(u, 1, n) chkmn(ans, gsum[u] + fsum[u] + cur - ok[u] - max(0ll, max(fmx[u] - ok[u], gmx[u])));
	cout << ans << '\n';
	return 0;
}