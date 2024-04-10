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
template<class A> string to_string(const A &v) {
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
template<class H, class... T> void debug_out(const H& h, const T&... t) {
	cerr << " " << to_string(h);
	debug_out(t...);
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

const int inf = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int cas; cin >> cas; while (cas--) {
		int n, m; cin >> n >> m;
		struct node {
			int u, v;
			ll w;
		};
		vector<node> es(m);
		vvi d(n, vi(n, inf));
		for (auto &[x, y, w]: es) {
			cin >> x >> y >> w;
			x--, y--;
			chmin(d[x][y], 1);
			chmin(d[y][x], 1);
		}
		rep(i, 0, n - 1) chmin(d[i][i], 0);
		rep(k, 0, n - 1) rep(i, 0, n - 1) rep(j, 0, n - 1) chmin(d[i][j], d[i][k] + d[k][j]);
		ll ans = 1ll << 60;
		for (auto [x, y, w]: es) {
			int mn = inf; 
			chmin(mn, d[0][x] + d[n - 1][y]);
			chmin(mn, d[0][y] + d[n - 1][x]);
			rep(i, 0, n - 1) {
				chmin(mn, d[x][i] + 1 + d[0][i] + d[n - 1][i]);
				chmin(mn, d[y][i] + 1 + d[0][i] + d[n - 1][i]);
			}
			mn++;
			chmin(ans, 1ll * mn * w);
		}
		printf("%lld\n", ans);
	}
	return 0;
}