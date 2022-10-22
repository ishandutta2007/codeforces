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

/**
 * Author: Yuhao Yao
 * Date: 22-08-14
 * Description: Modular integer with $mod \le 2^{30} - 1$. Note that there are several advantages to use this code:
   1. You do not need to keep writing \% $mod$;
   2. It is good to use this struct when doing Gaussian Elimination / Fast Walsh-Hadamard Transform;
   3. Sometimes the input number is greater than $mod$ and this code handles it.
  Do not write things like Mint{1 / 3}.pow(10) since 1 / 3 simply equals 0.
  Do not write things like Mint{a * b} where $a$ and $b$ are int since you might first have integer overflow.
 * Usage: $mod$ should be a global variable (either const int or int) and should satisfy $mod \le 2^{30} - 1$. for exmaple you can use like this:
   const int mod = 998244353;
   using Mint = Z<mod>;
 * Status: tested on https://ac.nowcoder.com/acm/contest/33191/F.
 */

template<const int &mod> struct Z {
	/// start-hash
	int x;
	Z(ll a = 0): x(a % mod) { if (x < 0) x += mod; }
	explicit operator int() const { return x; }

	Z& operator +=(Z b) { x += b.x; if (x >= mod) x -= mod; return *this; }
	Z& operator -=(Z b) { x -= b.x; if (x < 0) x += mod; return *this; }
	Z& operator *=(Z b) { x = 1ll * x * b.x % mod; return *this; }
	friend Z operator +(Z a, Z b) { return a += b; }
	friend Z operator -(Z a, Z b) { return a -= b; }
	friend Z operator *(Z a, Z b) { return a *= b; }
	/// end-hash

	// the followings are needed for ntt and polynomial operations.
	/// start-hash
	Z pow(ll k) const {
		Z res = 1, a = *this;
		for (; k; k >>= 1, a = a * a) if (k & 1) res = res * a;
		return res;
	}
	Z& operator /=(Z b) {
		assert(b.x != 0);
		*this = *this * b.pow(mod - 2);
		return *this;
	}
	friend Z operator /(Z a, Z b) { return a /= b; }

	static int getMod() { return mod; } // ntt need this.
	/// end-hash

	friend string to_string(Z a) { return to_string(a.x); } // just for debug.
};
const int mod = 1e9 + 7;
using Mint = Z<mod>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	const int maxn = 1e6 + 5;
	vector<Mint> pw(maxn + 1);
	pw[0] = 1;
	rep(i, 1, maxn) pw[i] = pw[i - 1] * 2;

	int cas; cin >> cas; while (cas--) {
		int n; cin >> n;
		vector<Mint> f(n + 1), g(n + 1);
		int j = 0;
		Mint sum = 1;
		rep(i, 1, n) {
			while (j + 1 < i && (j + 1) <= (i - (j + 1))) {
				j++;
				sum += pw[j - 1];
			}
			f[i] = sum;
		}
		int r = n;
		sum = 1;
		g[n] = 1;
		revrep(i, 1, n - 1) {
			while (r > i && r >= i * 2) {
				sum -= g[r];
				r--;
			}
			g[i] = sum;
			sum += g[i];
		}
		// rep(i, 1, n) debug(i, f[i], g[i]);
		Mint inv = Mint{1} / Mint{2}.pow(n - 1);
		rep(i, 1, n) {
			Mint ans = f[i] * g[i] * inv;
			printf("%d\n", (int) ans);
		}
	}
	return 0;
}