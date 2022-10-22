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

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

const int maxn = 3e5 + 10;

int n, m, q, u, v, lastans, x[maxn + 5], e[maxn +5][2];
vector<int> G[maxn + 5], T[maxn + 5];
struct Graph {
	struct Edge {
		int to, next;
	}e[maxn * 2 + 5];
	int head[maxn + 5], dfn[maxn + 5], low[maxn + 5], col[maxn + 5];
	int num, ts, cnt;
	stack<int> S;
	void add(int u, int v) {
		e[++cnt] = (Edge) {v, head[u]}, head[u] = cnt;
		e[++cnt] = (Edge) {u, head[v]}, head[v] = cnt;
	}
	void tarjan(int u, int fa) {
		dfn[u] = low[u] = ++ts;
		S.push(u);
		trv(i, u) {
			if(i/2 == fa/2) continue;
			int v = e[i].to;
			if(!dfn[v]) {
				tarjan(v, i);
				chkmin(low[u], low[v]);
			}
			else chkmin(low[u], dfn[v]);
		}
		if(low[u] == dfn[u]) {
			col[u] = ++num;
			while(S.top() != u) {
				col[S.top()] = num;
				S.pop();
			}
			S.pop();	
		}
	}
	void work(vector<int> node, vector<P> edge) {
		num = ts = 0, cnt = 1;
		for(auto u : node) low[u] = dfn[u] = col[u] = head[u] = 0;
		for(auto u : edge) add(u.fi, u.se);
		for(auto u : node) if(!dfn[u]) tarjan(u, -1);
	}
}g1, g2;
struct Tree {
	struct Edge {
		int to, next;
	}e[maxn * 2 + 5];
	int cnt, head[maxn +5];
	int fa[maxn + 5], top[maxn + 5], son[maxn + 5], size[maxn + 5], dep[maxn + 5], dfn[maxn + 5];
	void add(int u, int v) {
		e[++cnt] = (Edge) {v, head[u]}, head[u] = cnt;
		e[++cnt] = (Edge) {u, head[v]}, head[v] = cnt;
	}
	void dfs1(int u, int par) {
		size[u] = 1, fa[u] = par, dep[u] = dep[par] + 1;
		trv(i, u) {
			int v = e[i].to;
			if(v == par) continue;
			dfs1(v, u);
			size[u] += size[v];
			if(size[v] > size[son[u]]) son[u] = v;
		} 
	}
	void dfs2(int u, int topf) {
		static int ts = 0;
		top[u] = topf, dfn[u] = ++ts;
		if(son[u]) dfs2(son[u], topf);
		trv(i, u) {
			int v = e[i].to;
			if(v == fa[u] || v == son[u]) continue;
			dfs2(v, v);
		}
	}
	int lca(int u, int v) {
		while(top[u] != top[v]) {
			if(dep[top[u]] < dep[top[v]]) swap(u, v);
			u = fa[top[u]];
			if(!u) return 0; 
		}
		return dep[u] < dep[v] ? u : v;
	}
	void init() {
		rep(i, 1, n) if(!dep[i]) dfs1(i, 0), dfs2(i, i);
	}
	vector<P> build(vector<int> &node) {
		sort(all(node),[=](int x, int y) {return dfn[x] < dfn[y];});
		per(i, sz(node) - 1, 1) if(lca(node[i], node[i - 1])) node.emplace_back(lca(node[i], node[i - 1]));
		sort(all(node),[=](int x, int y) {return dfn[x] < dfn[y];});
		node.erase(unique(all(node)),node.end());
		vector<P> edge;stack<int> S;
		for(auto u : node) {
			while(!S.empty() && dfn[u] >= dfn[S.top()] + size[S.top()]) S.pop();
			if(!S.empty()) edge.push_back({u, S.top()});
			S.push(u);
		}
		return edge;
	}
}t;
inline void upd(int &x) {x += lastans, x = x % n ? x % n : n, x = g1.col[x];}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &q);
	vector<P> edge;
	rep(i, 1, m) {
		scanf("%d%d", &u, &v);
		G[u].emplace_back(v), G[v].emplace_back(u);
		edge.push_back({u, v});
	}
	auto get = [] (int n) {vector<int> s; rep(i, 1, n) s.emplace_back(i); return s;};
	g1.work(get(n), edge);
	rep(u, 1, n) for(auto v : G[u]) {
		static int *c = g1.col;
		if(c[u] < c[v]) T[c[u]].emplace_back(c[v]);
	}
	rep(i, 1, n) sort(all(T[i])), T[i].erase(unique(all(T[i])), T[i].end());
	rep(u, 1, n) for(auto v : T[u]) t.add(u, v);
	t.init();
	rep(i, 1, q) {
		int _n, _m;
		vector<int> node;
		scanf("%d%d", &_n, &_m);
		rep(i, 1, _n) scanf("%d", &x[i]), upd(x[i]), node.emplace_back(x[i]);
		rep(i, 1, _m) scanf("%d%d", &e[i][0], &e[i][1]), upd(e[i][0]), upd(e[i][1]), node.emplace_back(e[i][0]), node.emplace_back(e[i][1]);
		sort(all(node)),node.erase(unique(all(node)),node.end());
		vector<P> edge = t.build(node);
		rep(i, 1, _m) if(e[i][0] != e[i][1]) edge.push_back({e[i][0], e[i][1]});
		g2.work(node, edge);
		int flag = 1;
		rep(i, 2, _n) if(g2.col[x[1]] != g2.col[x[i]]) {flag = 0; break;}
		puts(flag ? "YES" : "NO");
		lastans += i * flag, lastans %= n;	
	}
	return 0;
}