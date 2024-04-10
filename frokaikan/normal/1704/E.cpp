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

template<const int &mod_> struct Z {
	/// start-hash
	static constexpr const int &mod = mod_;
	int x;
	Z(ll a = 0): x(a % mod) { if (x < 0) x += mod; }

	static int norm(int x) { return x < 0 ? x + mod : x >= mod ? x - mod : x; }
	friend Z operator +(Z a, Z b) { a.x = norm(a.x + b.x); return a; }
	friend Z operator -(Z a, Z b) { a.x = norm(a.x - b.x); return a; }
	friend Z operator *(Z a, Z b) { a.x = 1ll * a.x * b.x % mod; return a; }
	/// end-hash

	// the following are needed for fft and polynomial operations.
	/// start-hash
	Z& operator +=(Z b) { x = norm(x + b.x); return *this; }
	Z& operator -=(Z b) { x = norm(x - b.x); return *this; }
	Z& operator *=(Z b) { x = 1ll * x * b.x % mod; return *this; }

	static Z pow(Z a, ll k) {
		Z res = 1;
		for (; k; k >>= 1, a = a * a) if (k & 1) res = res * a;
		return res;
	}
	friend Z operator /(Z a, Z b) { return a * pow(b, mod - 2); }
	/// end-hash

	friend string to_string(Z a) { return to_string(a.x); } // just for debug.
};

const int mod = 998244353;
using Mint = Z<mod>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int cas; cin >> cas; while (cas--) {
		int n, m; cin >> n >> m;
		vi as(n);
		for (auto &x: as) cin >> x;
		vvi g(n);
		vi outd(n);
		rep(i, 1, m) {
			int x, y; cin >> x >> y;
			x--; y--;
			g[y].push_back(x);
			outd[x]++;
		}
		vi que{};
		rep(i, 0, n - 1) if (outd[i] == 0) que.push_back(i);
		rep(ind, 0, sz(que) - 1) {
			int now = que[ind];
			for (auto v: g[now]) if (--outd[v] == 0) que.push_back(v);
		}
		const int inf = 0x3f3f3f3f;
		vvi cnt(n, vi(n));
		vector<vector<Mint>> cnt_mod(n, vector<Mint>(n));
		int st = que[0];
		cnt[st][0] = 1;
		cnt_mod[st][0] = 1;
		for (auto now: que) {
			for (auto v: g[now]) {
				rep(i, 1, n - 1) {
					cnt_mod[v][i] += cnt_mod[now][i - 1];
					cnt[v][i] += cnt[now][i - 1];
					chmin(cnt[v][i], inf);
				}
			}
			// debug(now, cnt[now], cnt_mod[now]);
		}
		vi ans(n);
		vector<Mint> ans_mod(n);
		rep(i, 0, n - 1) {
			rep(j, 0, n - 1) {
				ans_mod[j] += cnt_mod[i][j] * as[i];
				ans[j] = min(ans[j] + 1ll * cnt[i][j] * as[i], (ll)inf);
			}
		}
		Mint res = 0;
		rep(i, 0, n - 2) {
			if (ans[i] > 0) {
				ans_mod[i + 1] += ans_mod[i] - 1;
				ans[i + 1] += ans[i] - 1;
				chmin(ans[i + 1], inf);
			}
		}
		rep(i, 0, n - 1) {
			if (ans[i] > 0) res = ans_mod[i] + i;
		}
		printf("%d\n", res.x);
	}
	return 0;
}