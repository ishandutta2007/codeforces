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

const int maxn = 2e5;
int n, m, q, u, v, w, cnt, head[maxn + 5];
int num, dfn[maxn + 5], low[maxn + 5], in[maxn + 5], col[maxn + 5];
ll dep[maxn + 5], gcd[maxn + 5];
stack<int> s;
struct Edge {
	int to, next, w;
}e[maxn * 2 + 5];
inline void add(int u, int v, int w) {
	e[++cnt] = (Edge) {v, head[u], w}, head[u] = cnt;
}
void tarjan(int u) {
	static int ts = 0;
	low[u] = dfn[u] = ++ ts, s.push(u), in[u] = 1;
	trv(i, u, v) if(e[i].w > 0) {
		if(!dfn[v]) tarjan(v), chkmn(low[u], low[v]);
		else if(in[v]) chkmn(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		col[u] = ++num, in[u] = 0;
		while(s.top() != u ) {
			in[s.top()] = 0, col[s.top()] = num;
			s.pop();
		}
		s.pop();
	}
}
void dfs(int u) {
	dfn[u] = 1;
	trv(i, u, v) if(col[v] == col[u]) {
		if(!dfn[v]) dep[v] = dep[u] + e[i].w, dfs(v);
		else gcd[col[u]] = __gcd(gcd[col[u]], dep[u] - dep[e[i].to] + e[i].w);
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d%d", &u, &v, &w), add(u, v, w), add(v, u, -w);
	rep(i, 1, n) if(!dfn[i]) tarjan(i);
	rep(i, 1, n) dfn[i] = 0;
	rep(i, 1, n) if(!dfn[i]) dfs(i);
	for(scanf("%d", &q); q; q--) {
		scanf("%d%d%d", &u, &v, &w);
		puts(v % __gcd((ll)w, gcd[col[u]]) ? "NO" : "YES");
	}
	return 0;
}