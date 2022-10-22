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

	auto ask = [](vi as) {
		printf("? %d", sz(as));
		for (auto x: as) printf(" %d", x);
		puts(""); fflush(stdout);
		string ans; cin >> ans;
		return ans == "YES";
	};
	auto guess = [](int x) {
		printf("! %d\n", x); fflush(stdout);
		string ans; cin >> ans;
		return ans == ":)";
	};

	auto solve = [&](auto dfs, vi as) -> void {
		// debug(as);
		if (sz(as) <= 2) {
			if (guess(as[0]) == 0) guess(as[1]);
			return;
		}
		int s1 = sz(as) / 3;
		int rem = sz(as) - s1;
		int s2 = rem / 2;
		if (ask(vi(as.begin(), as.begin() + s1)) == 0) {
			if (ask(vi(as.begin(), as.begin() + s1)) == 0) {
				dfs(dfs, vi(as.begin() + s1, as.end()));
			} else {
				if (ask(vi(as.begin() + s1, as.begin() + s1 + s2)) == 0) {
					vi bs;
					bs.insert(bs.end(), as.begin(), as.begin() + s1);
					bs.insert(bs.end(), as.begin() + s1 + s2, as.end());
					dfs(dfs, bs);
				} else {
					dfs(dfs, vi(as.begin(), as.begin() + s1 + s2));
				}
			}
		} else {
			if (ask(vi(as.begin() + s1, as.begin() + s1 + s2)) == 0) {
				vi bs;
				bs.insert(bs.end(), as.begin(), as.begin() + s1);
				bs.insert(bs.end(), as.begin() + s1 + s2, as.end());
				dfs(dfs, bs);
			} else {
				dfs(dfs, vi(as.begin(), as.begin() + s1 + s2));
			}
		}
	};

	int n; cin >> n;
	vi as(n); iota(all(as), 1);
	solve(solve, as);
	return 0;
}