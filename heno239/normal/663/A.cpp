//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
typedef double ld;
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
const int max_n = 1 << 1;
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
	string s; getline(cin, s);
	vector<char> c;
	int n;
	for (int i = 2;; i += 4) {
		if (s[i] == '+') {
			c.push_back(s[i]);
		}
		else if (s[i] == '-') {
			c.push_back(s[i]);
		}
		else if (s[i] == '=') {
			i++; i++;
			string t = s.substr(i, s.size() - i);
			n = stoi(t);
			break;
		}
		else {
			assert(false);
		}
	}
	int cp = 1, cn = 0;
	rep(i, c.size()) {
		if (c[i] == '+')cp++;
		else cn++;
	}
	int le = -n * cn + cp;
	int ri = n * cp - cn;
	if (le <= n && n <= ri) {
		vector<int> l, r;
		rep(i, cp) {
			l.push_back(1);
			r.push_back(n);
		}
		rep(i, cn) {
			l.push_back(-n);
			r.push_back(-1);
		}
		int rest = n;
		vector<int> vp, vn;
		rep(i, l.size()) {
			int z = r[i];
			int mi = 0;
			Rep(j, i + 1, l.size())mi += l[j];
			z = min(z, rest - mi);
			if (z > 0)vp.push_back(z);
			else vn.push_back(z);
			rest -= z;
		}
		string ans;
		ans += to_string(vp.back()); vp.pop_back();
		rep(i, c.size()) {
			ans.push_back(' ');
			ans.push_back(c[i]);
			ans.push_back(' ');
			string ad;
			if (c[i] == '+') {
				ad = to_string(vp.back()); vp.pop_back();
			}
			else {
				ad = to_string(-vn.back()); vn.pop_back();
			}
			ans += ad;
		}
		ans += " = ";
		ans += to_string(n);
		cout << "Possible\n";
		cout << ans << "\n";
	}
	else {
		cout << "Impossible\n";
	}
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}