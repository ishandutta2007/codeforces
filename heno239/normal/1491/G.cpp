#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
const int max_n = 2;
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
	int n; cin >> n;
	vector<int> p(n);
	vector<P> ans;
	auto swp = [&](int a, int b) {
		ans.push_back({ a,b });
	};
	rep(i, n) {
		cin >> p[i]; p[i]--;
	}
	vector<vector<int>> v;
	vector<bool> used(n);
	rep(i, n) {
		if (used[i])continue;
		vector<int> cur;
		cur.push_back(i);
		int id = p[i];
		while (id!=i) {
			cur.push_back(id); id = p[id];
		}
		if(cur.size()>=2)v.push_back(cur);
		for (int x : cur)used[x] = true;
	}
	int len = v.size();
	rep(i, len / 2) {
		vector<int> le = v[2 * i];
		vector<int> ri = v[2 * i + 1];
		swp(le[0], ri[0]);
		for (int i = 1; i < ri.size(); i++) {
			swp(le[0], ri[i]);
		}
		for (int i = 1; i < le.size(); i++) {
			swp(ri[0], le[i]);
		}
		swp(le[0], ri[0]);
	}
	if (len % 2) {
		vector<int> c = v.back();
		if (c.size() == 2) {
			int x = -1;
			rep(i, n)if (i != c[0] && i != c[1])x = i;
			swp(x, c[1]);
			swp(x, c[0]);
			swp(x, c[1]);
		}
		else {
			int len = c.size();
			swp(c[0], c[len - 1]);
			swp(c[0], c[1]);
			swp(c[1], c[len - 1]);
			for (int i = 2; i < len - 1; i++) {
				swp(c[0], c[i]);
			}
			swp(c[0], c[len - 1]);
		}
	}
	cout << ans.size() << "\n";
	for (P p : ans) {
		cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i,t)
	solve();
	return 0;
}