#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
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
	
	int getcomp(int x) { return fa[x] == x ? x : fa[x] = getcomp(fa[x]); }

	// return 1 if x and y are in different component and merge.
	bool merge(int x, int y) {
		int fx = getcomp(x), fy = getcomp(y);
		if (fx == fy) return 0;
		if (siz[fx] < siz[fy]) swap(fx, fy);
		fa[fy] = fx;
		siz[fx] += siz[fy];
		return 1;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int cas; cin >> cas; while (cas--) {
		int n, m; cin >> n >> m;
		vector<pii> es(m);
		for (auto &[x, y]: es) {
			cin >> x >> y;
			x--, y--;
		}
		
		vector<pii> bs;
		vector<pii> gs;
		vi mark(m);
		auto solve = [&]() {
			DSU dsu(n);
			bs.clear();
			gs.clear();
			mark.assign(m, 0);
			rep(i, 0, m - 1) {
				auto [x, y] = es[i];
				if (dsu.merge(x, y) == 0) bs.emplace_back(x, y), mark[i] = 1;
				else gs.emplace_back(x, y);
			}
		};
		solve();

		int ok = 1;
		DSU bac(n);
		for (auto [x, y]: bs) {
			if (bac.merge(x, y) == 0) ok = 0;
		}
		if (ok) {
			for (auto x: mark) printf("%d", x);
			puts("");
		} else {
			map<pii, int> id;
			rep(i, 0, m - 1) id[es[i]] = i;
			es.clear();
			es.insert(es.end(), all(gs));
			es.insert(es.end(), all(bs));
			rotate(es.begin(), es.begin() + m - 1, es.end());
			solve();
			mark.assign(m, 0);
			for (auto it: bs) mark[id[it]] = 1;
			for (auto x: mark) printf("%d", x);
			puts("");
		}
	}
	return 0;
}