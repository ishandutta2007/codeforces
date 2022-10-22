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
	
	int cas; cin >> cas; while (cas--) {
		int n; cin >> n;
		vi bs(n);
		for (auto &x: bs) {
			cin >> x;
			x--;
		};
		int k = n;
		rep(i, 0, n - 1) if (bs[i] < i) {
			k = i;
			break;
		}
		k--;
		vi as;
		set<int> S(all(bs));
		map<int, vi> mp;
		rep(i, 0, n - 1) {
			int x = bs[i];
			mp[x].push_back(i);
		}
		int now = S.count(-1) ? -1 : n;
		while (1) {
			assert(mp.count(now));
			auto &vec = mp[now];
			int found = -1;
			rep(i, 0, sz(vec) - 1) {
				if (S.count(vec[i])) {
					found = i;
					break;
				}
			}
			if (found != -1) {
				rotate(vec.begin(), vec.begin() + found, vec.end());
				reverse(all(vec));
			}
			as.insert(as.end(), all(vec));
			if (found == -1) break;
			else now = vec.back();
		}
		printf("%d\n", k + 1);
		rep(i, 0, n - 1) printf("%d%c", as[i] + 1, " \n"[i == n - 1]);
	}
	return 0;
}