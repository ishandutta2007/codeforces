
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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
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
const ld eps = 1e-8;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
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
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

vector<int> sup = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
void solve() {
	vector<int> v(6);
	rep(i, 6)cin >> v[i];
	auto isulu = [&](int y) {
		if (y % 400 == 0)return true;
		else if (y % 100 == 0)return false;
		else if (y % 4 == 0)return true;
		else return false;
	};
	auto calc = [&](int y) {
		int cnt = 365;
		if (isulu(y))cnt++;
		return 86400 * cnt;
	};
	auto nextyear = [&](int& d1, int& y) {
		if (isulu(y)) {
			d1 += 366%7;
		}
		else {
			d1 += 365%7;
		}
		if (d1 > 7)d1 -= 7;
		y++;
	};
	auto nextday = [&](int& d1, int& d2, int& mo, int& y) {
		d1++; if (d1 > 7)d1 = 1;
		d2++;
		int s = sup[mo];
		if (mo == 2 && isulu(y))s++;
		if (d2 > s) {
			d2 = 1;
			mo++;
			if (mo == 13) {
				mo = 1; y++;
			}
		}
	};
	auto validday = [&](int& d1, int& d2, int& mo, int& y) {
		if (v[5] >= 0)if (mo != v[5])return false;
		if (v[3] >= 0 && v[4] >= 0) {
			if (d1 == v[3] || d2 == v[4])return true;
			else return false;
		}
		else if (v[3] >= 0) {
			return d1 == v[3];
		}
		else if (v[4] >= 0) {
			return d2 == v[4];
		}
		else {
			return true;
		}
	};
	auto nextsec = [&](int& s, int& m, int& h, int& d1, int& d2, int& mo, int& y) {
		s++;
		if (s == 60) {
			s = 0;
			m++;
			if (m == 60) {
				m = 0;
				h++;
				if (h == 24) {
					h = 0;
					nextday(d1, d2, mo, y);
				}
			}
		}
	};
	auto validsec = [&](int& s, int& m, int& h) {
		if (v[0] >= 0) {
			if (s != v[0])return false;
		}
		if (v[1] >= 0) {
			if (m != v[1])return false;
		}
		if (v[2] >= 0) {
			if (h != v[2])return false;
		}
		return true;
	};

	int n; cin >> n;
	rep(i, n) {
		ll t; cin >> t; t++;
		ll ans = t;
		int s = 0, m = 0, h = 0, d1 = 4, d2 = 1, mo = 1;
		int y = 1970;
		while (true) {
			ll nex = calc(y);
			if (t < nex) {
				break;
			}
			else {
				t -= nex;
				nextyear(d1, y);
			}
		}
		while (t >= 86400) {
			t -= 86400;
			nextday(d1, d2, mo, y);
		}
		h = t / 3600; t %= 3600;
		m = t / 60; t %= 60;
		s = t;

		while (s != 0 || m != 0 || h != 0) {
			if (validsec(s, m, h) && validday(d1, d2, mo, y))break;
			ans++;
			nextsec(s, m, h, d1, d2, mo, y);
		}
		//cout << "?? " << ans << "\n";
		while (!validsec(s,m,h)) {
			nextsec(s, m, h, d1, d2, mo, y);
			ans++;
		}
		while (!validday(d1, d2, mo, y)) {
			nextday(d1, d2, mo, y);
			ans += 86400;
		}
		//cout << "ans is ";
		cout << ans << "\n";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i, t)
	solve();
	return 0;
}