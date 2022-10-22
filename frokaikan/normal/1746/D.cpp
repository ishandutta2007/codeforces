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
		int n, k; cin >> n >> k;
		vvi g(n);
		rep(i, 1, n - 1) {
			int p; cin >> p; p--;
			g[p].push_back(i);
		}
		vi ss(n);
		for (auto &x: ss) cin >> x;
		vi dep(n);
		ll ans = 0;
		auto dfs = [&](auto &dfs, int now, int fa, int cnt) -> int {
			dep[now] = (fa == -1 ? 0 : dep[fa]) + ss[now];
			int sons = sz(g[now]);
			if (sons == 0) {
				ans += 1ll * cnt * dep[now];
				return dep[now];
			}
			vi nums;
			for (auto v: g[now]) if (v != fa) {
				nums.push_back(dfs(dfs, v, now, cnt / sons));
			}
			int rem = cnt % sons;
			sort(all(nums));
			reverse(all(nums));
			rep(i, 0, rem - 1) ans += nums[i];
			return nums[rem];
		};
		dfs(dfs, 0, -1, k);
		printf("%lld\n", ans);
	}
	return 0;
}