#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) { a = b; return 1; } return 0; }
using namespace std;

template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A> string to_string(A v) {
	bool first = 1;
	string res = "{";
	for (const auto &x: v) {
		if (!first) res += ", ";
		first = 0;
		res += to_string(x);
	}
	res += "}";
	return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

struct DSU {
	vi fa, siz;

	DSU(int n): fa(n), siz(n, 1) { iota(all(fa), 0); }
	
	int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }

	bool check(int x, int y) { return getfa(x) != getfa(y); }

	// return 1 if x and y are in different component and merge.
	bool merge(int x, int y) {
		int fx = getfa(x), fy = getfa(y);
		if (fx == fy) return 0;
		if (siz[fx] < siz[fy]) swap(fx, fy);
		fa[fy] = fx;
		siz[fx] += siz[fy];
		return 1;
	}
};

struct HLD {
	int n;
	vi par, hson, dfn, dfn_out, dep, top;
	HLD(vvi &g, int rt = 0): n(sz(g)), par(n, -1), hson(n, -1), dfn(n), dfn_out(n), dep(n, 0), top(n) {
		vi siz(n);
		function<void(int, int)> dfs = [&](int now, int fa) {
			siz[now] = 1;
			int mx = 0;
			for (auto v: g[now]) if (v != fa) {
				dep[v] = dep[now] + 1;
				par[v] = now;
				dfs(v, now);
				siz[now] += siz[v];
				if (mx < siz[v]) mx = siz[v], hson[now] = v;
			}
		};
		dfs(rt, -1);

		int cnt = 0;
		function<void(int, int)> getdfn = [&](int now, int sp) {
			top[now] = sp;
			dfn[now] = cnt++;
			if (hson[now] == -1) {
				dfn_out[now] = cnt - 1;
				return;
			}
			getdfn(hson[now], sp);
			for (auto v: g[now]) if(v != hson[now] && v != par[now]) getdfn(v, v);
			dfn_out[now] = cnt - 1;
		};
		getdfn(rt, rt);
	}

	int lca(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) swap(u, v);
			u = par[top[u]];
		}
		if (dep[u] < dep[v]) return u;
		else return v;
	}
	int se_lca(int u, int v) {
		// us is lca of v;
		int d = dep[u] + 1;
		while (dep[v] != d) {
			if (top[u] != top[v]) {
				v = top[v];
				if (dep[v] == d) return v;
				v = par[v];
			}
			else v = hson[u];
		}
		return v;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int cas = 1; while (cas--) {
		int n, m; cin >> n >> m;

		vvi g(n);
		DSU dsu(n);
		vector<pii> bad;
		rep(i, 1, m) {
			int u, v; cin >> u >> v;
			u--, v--;
			if (dsu.merge(u, v)) {
				g[u].push_back(v);
				g[v].push_back(u);
			} else bad.push_back({u, v});
		}
// debug(g);
		HLD hld(g);
		auto &in = hld.dfn;
		auto &out = hld.dfn_out;
		vi ps(n + 1);
		auto add = [&](int u, int val) {
			int x = in[u];
			int y = out[u];
			ps[x] += val;
			ps[y + 1] -= val;
		};
		// rep(i, 0, n - 1) debug(i, in[i], out[i]);
		for (auto [u, v]: bad) {
			int l = hld.lca(u, v);
			// debug(u, v, l);
			if (l == u || l == v) {
				if (l == v) swap(u, v);
				int se = hld.se_lca(u, v);
				add(se, 1);
				add(v, -1);
			} else {
				add(0, 1);
				add(u, -1);
				add(v, -1);
			}
		}
		rep(i, 1, n) ps[i] += ps[i - 1];
		rep(i, 0, n - 1) {
			putchar(ps[in[i]] == 0 ? '1' : '0');
		}
		puts("");
	}
	return 0;
}