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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int cas; cin >> cas; while (cas--) {
		int n; cin >> n;
		vector<pii> as(3);
		for (auto &[x, y]: as) cin >> x >> y;
		pii t; cin >> t.first >> t.second;
		int ok = 0;
		for (auto [x, y]: as) {
			if ((x - t.first) % 2 == 0 && (y - t.second) % 2 == 0) ok = 1;
		}
		if (ok) {
			auto [x, y] = t;
			set<pii> S(all(as));
			if (S.count({1, 1}) && S.count({1, 2}) && S.count({2, 1})) {
				if (x != 1 && y != 1) ok = 0;
			}
			if (S.count({1, n}) && S.count({1, n - 1}) && S.count({2, n})) {
				if (x != 1 && y != n) ok = 0;
			}
			if (S.count({n, n}) && S.count({n, n - 1}) && S.count({n - 1, n})) {
				if (x != n && y != n) ok = 0;
			}
			if (S.count({n, 1}) && S.count({n, 2}) && S.count({n - 1, 1})) {
				if (x != n && y != 1) ok = 0;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}