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

	int n = 34 * 6 - 1;
	vi sg(n + 1);
	rep(i, 1, n) {
		vi mark(n + 1);
		rep(j, 1, i) {
			int x = max(0, j - 2);
			int y = max(0, i - j - 1);
			mark[sg[x] ^ sg[y]] = 1;
		}
		rep(x, 0, n) if (mark[x] == 0) {
			sg[i] = x;
			break;
		}
	}
	auto get = [&](int x) {
		if (x < 34 * 3) return sg[x];
		else {
			int off = x - 34 * 3;
			off %= 34;
			return sg[34 * 3 + off];
		}
	};
	int cas; cin >> cas; while (cas--) {
		int n; cin >> n;
		string s; cin >> s;
		int cnt_R = 0, cnt_B = 0;
		for (auto c: s) {
			if (c == 'R') cnt_R++;
			else cnt_B++;
		}
		if (cnt_R > cnt_B) puts("Alice");
		else if (cnt_R < cnt_B) puts("Bob");
		else {
			vi dif(n - 1);
			rep(i, 0, n - 2) {
				dif[i] = s[i] != s[i + 1];
			}
			int ans = 0;
			int len = 0;
			for (auto x: dif) {
				if (x == 0) {
					ans ^= get(len);
					len = 0;
				} else len++;
			}
			ans ^= get(len);
			puts(ans ? "Alice" : "Bob");
		}
	}
	return 0;
}