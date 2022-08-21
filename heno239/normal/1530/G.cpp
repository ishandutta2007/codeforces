#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
constexpr ll mod = 998244353;
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
const int max_n = 1 << 15;
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

void solve() {
	int n, k; cin >> n >> k;
	string a, b; cin >> a >> b;
	int ca = 0, cb = 0;
	rep(i, n) {
		if (a[i] == '1')ca++;
		if (b[i] == '1')cb++;
	}
	if (ca != cb) {
		cout << -1 << "\n"; return;
	}
	if (k == 0||ca<k) {
		if (a == b) {
			cout << 0 << "\n";
		}
		else {
			cout << -1 << "\n";
		}
		return;
	}

	vector<P> mem;
	auto yaru = [&](int l, int r, string& s) {
		mem.push_back({ l,r });
		int len = r - l + 1;
		rep(i, len / 2) {
			swap(s[l + i], s[r - i]);
		}
	};
	auto normalize = [&](string s) {
		int c = 0;
		rep(i, s.size())if (s[i] == '1')c++;
		if (c == k) {
			int las = 0;
			rep(i, s.size())if (s[i] == '1')las = i;
			yaru(0, las, s);
			rep(i, s.size())if (s[i] == '1')las = i;
			string t = s.substr(0, las + 1);
			string u = t; reverse(all(u));
			if (u < t) {
				yaru(0, las, s);
			}
			return s;
		}
		else {
			for (int i = 0; i<c - (k + 1); i++) {
				vector<int> v;
				rep(j, n)if (s[j] == '1')v.push_back(j);
				yaru(i, v[i + k - 1], s);
			}
			int ss = c - (k + 1);
			rep(i, k) {
				vector<int> v;
				Rep(j, c - (k + 1), n)if (s[j] == '1')v.push_back(j);
				if (i % 2 == 0) {
					yaru(v[0], v[k] - 1, s);
				}
				else {
					yaru(v[0] + 1, v[k], s);
				}
			}
			vector<int> v;
			Rep(j, c - (k + 1), n)if (s[j] == '1')v.push_back(j);

			if (k % 2) {
				int le = ss;
				int ri = v[k];
				rep(i, k + 1) {
					if (i % 2 == 0)yaru(le, ri - 1, s);
					else yaru(le + 1, ri, s);
				}
			}
			else {
				yaru(ss, v[k]-1, s);
			}
			return s;
		}
	};
	string ala = normalize(a);
	vector<P> ord1 = mem; mem.clear();
	string alb = normalize(b);
	vector<P> ord2 = mem;
	if (ala != alb) {
		cout << -1 << "\n";
	}
	else {
		vector<P> ans;
		for (P p : ord1)ans.push_back(p);
		reverse(all(ord2));
		for (P p : ord2)ans.push_back(p);
		cout << ans.size() << "\n";
		for (P p : ans) {
			cout << p.first + 1 << " " << p.second + 1 << "\n";
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init_f();
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
		solve();
	return 0;
}