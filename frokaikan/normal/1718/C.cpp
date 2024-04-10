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

	const int maxn = 200'000;
	vi maxp(maxn + 1);
	rep(i, 2, maxn) if (maxp[i] == 0) {
		for (int j = i; j <= maxn; j += i) maxp[j] = i;
	}

	int cas; cin >> cas; while (cas--) {
		int n, q; cin >> n >> q;
		vector<ll> as(n);
		for (auto &x: as) cin >> x;
		multiset<ll> S;
		int now = n;
		vi ps;
		while (now != 1) {
			ps.push_back(maxp[now]);
			now /= maxp[now];
		}
		sort(all(ps));
		ps.erase(unique(all(ps)), ps.end());
		int N = sz(ps);
		vector<vector<ll>> sum(N);
		rep(i, 0, N - 1) {
			int p = ps[i], len = n / p;
			sum[i].resize(len);
			rep(j, 0, n - 1) {
				sum[i][j % len] += as[j];
			}
			for (auto x: sum[i]) S.insert(x * len);
		}
		printf("%lld\n", *S.rbegin());
		while (q--) {
			int pos; ll x; cin >> pos >> x;
			pos--;
			rep(i, 0, N - 1) {
				int p = ps[i], len = n / p;
				S.erase(S.find(sum[i][pos % len] * len));
				sum[i][pos % len] += x - as[pos];
				S.insert(sum[i][pos % len] * len);
			}
			as[pos] = x;
			printf("%lld\n", *S.rbegin());
		}
	}
	return 0;
}