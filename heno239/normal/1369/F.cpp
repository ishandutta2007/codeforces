#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % mod;
		x = x * x % mod; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}



bool towin(ll s,ll g) {
	if (s == g)return false;
	ll cur = g+1;
	bool f = true;
	bool fp = true;

	while (true) {
		ll d = (cur+1) / 2;

		bool mp = false;
		if (!f)mp = true;
		if (cur % 2 == 0)if (!f)mp = true;
		if (cur % 2)if (!fp)mp = true;

		bool mp2 = false;
		if (!mp)mp2 = true;
		if (cur % 2 == 0)if (!f)mp2 = true;
		if (cur % 2)if (!fp)mp2 = true;

		if ((d + cur) % 2) {
			f = mp;
			fp = mp2;
		}
		else {
			f = mp2;
			fp = mp;
		}
		cur = d;

		if (s >= cur) {
			if ((s - cur) % 2)return fp;
			else return f;
		}
	}
}
bool tolose(ll s, ll g) {
	if (s == g)return true;
	ll cur = g+1;
	bool f = false;
	bool fp = false;

	while (true) {
		ll d = (cur + 1) / 2;

		bool mp = false;
		if (!f)mp = true;
		if (cur % 2 == 0)if (!f)mp = true;
		if (cur % 2)if (!fp)mp = true;

		bool mp2 = false;
		if (!mp)mp2 = true;
		if (cur % 2 == 0)if (!f)mp2 = true;
		if (cur % 2)if (!fp)mp2 = true;

		if ((d + cur) % 2) {
			f = mp;
			fp = mp2;
		}
		else {
			f = mp2;
			fp = mp;
		}
		cur = d;

		if (s >= cur) {
			if ((s - cur) % 2)return fp;
			else return f;
		}
	}
}
void solve() {

	/*cout << towin(1,2) << "\n";
	cout << tolose(1, 2) << "\n";
	cout << towin(2, 8) << "\n";
	cout << tolose(2,8) << "\n";*/

	int n; cin >> n;
	vector<ll> s(n), g(n);
	rep(i, n)cin >> s[i] >> g[i];
	bool bcan[2] = {};
	bcan[0] = true;
	rep(i, n) {
		bool nbcab[2] = {};
		if (bcan[0]) {
			if (towin(s[i], g[i])) {
				nbcab[1] = true;
			}
			if (tolose(s[i], g[i])) {
				nbcab[0] = true;
			}
		}
		if (bcan[1]) {
			if (!towin(s[i], g[i])) {
				nbcab[1] = true;
			}
			if (!tolose(s[i], g[i])) {
				nbcab[0] = true;
			}
		}
		rep(j, 2)bcan[j] = nbcab[j];
	}
	cout << bcan[1] << " " << bcan[0] << "\n";
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}