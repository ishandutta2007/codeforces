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


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int cas; cin >> cas; while (cas--) {
		int n; cin >> n;

		auto norm = [&](vector<pii> &vec) {
			sort(all(vec));
			vector<pii> bs;
			int last = -1;
			for (auto [x, c]: vec) {
				if (x != last) bs.push_back({x, 0});
				last = x;
				bs.back().second += c;
			}
			vec = bs;
		};

		vector<pii> as(n);
		for (auto &[x, y]: as) cin >> x, y = 1;
		norm(as);

		auto solve = [&](vector<pii> &as) {
			vector<pii> bs;
			int last = -1;
			for (auto [x, c]: as) {
				if (last != -1) {
					bs.push_back({x - last, 1});
				}
				if (c > 1) bs.push_back({0, c - 1});
				last = x;
			}
			norm(bs);
			as = bs;
		};
		rep(t, 1, n - 1) {
			solve(as);
		}
		assert(sz(as) == 1 && as[0].second == 1);
		printf("%d\n", as[0].first);
	}
	return 0;
}