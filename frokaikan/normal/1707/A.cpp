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
		int n, q; cin >> n >> q;
		vi as(n);
		for (auto &x: as) cin >> x;
		auto cal = [&](int t) {
			vi ans;
			int now = q;
			rep(i, 0, t - 1) {
				ans.push_back(as[i] <= now);
			}
			rep(i, t, n - 1) {
				if (now > 0) {
					ans.push_back(1);
					if (as[i] > now) now--;
				}
				else ans.push_back(0);
			}
			return make_pair(now, ans);
		};
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (cal(mid).first > 0) r = mid;
			else l = mid + 1;
		}
		auto ans1 = cal(r - 1).second;
		auto ans2 = cal(r).second;
		int cnt1 = 0;
		int cnt2 = 0;
		for (auto &x: ans1) cnt1 += x;
		for (auto &x: ans2) cnt2 += x;
		if (cnt2 > cnt1) ans1 = ans2;
		for (auto x: ans1) printf("%d", x);
		puts("");
	}
	return 0;
}