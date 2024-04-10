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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	const int maxn = 60;
	vector<ll> fib(maxn + 1);
	fib[0] = fib[1] = 1;
	rep(i, 2, maxn) fib[i] = fib[i - 1] + fib[i - 2];
	vector<ll> ps = fib;
	rep(i, 1, maxn) ps[i] += ps[i - 1];

	int cas; cin >> cas; while (cas--) {
		int n; cin >> n;
		vector<ll> as(n);
		for (auto &x: as) cin >> x;
		ll sum = accumulate(all(as), 0);
		if (*lower_bound(all(ps), sum) != sum) puts("NO");
		else {
			int N = lower_bound(all(ps), sum) - ps.begin() + 1;
			int last = -1;
			int ok = 1;
			set<pii> S;
			rep(i, 0, n - 1) S.insert({as[i], i});
			revrep(i, 0, N - 1) {
				int x = fib[i];
				auto it = --S.end();
				if (last == it->second) {
					if (it == S.begin()) {
						ok = 0;
						break;
					} else it--;
				}
				if (it->first < x) {
					ok = 0;
					break;
				}
				auto [y, id] = *it;
				S.erase(it);
				S.insert({y - x, id});
				last = id;
			}
			puts(ok ? "YES" : "NO");
		}
	}
	return 0;
}