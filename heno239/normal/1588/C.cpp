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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;

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
const int max_n = 1 << 10;
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

struct SegT {
private:
	int sz; vector<ll> node;
	const ll init_c = INF;
public:
	SegT(vector<ll> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	ll f(ll a, ll b) {
		return min(a, b);
	}
	void update(int k, ll a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	//[l,sz),ad+node[k]<0
	int find_loc(int l,ll ad) {
		if (l >= sz)return sz;
		int k = l + sz - 1;

		if (node[k] + ad < 0)return l;
		while (k > 0) {
			int mem = k;
			k = (k - 1) / 2;
			if (2 * k + 1 == mem) {
				if (node[2 * k + 2] + ad < 0) {
					k = 2 * k + 2;
					break;
				}
			}
		}
		if (k == 0)return sz;
		while (k<sz-1) {
			if (node[2 * k + 1] + ad < 0) {
				k = 2 * k + 1;
			}
			else {
				k = 2 * k + 2;
			}
		}
		return k - (sz - 1);
	}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<ll> ori(n);
	rep(i, n) {
		ori[i] = a[i];
		if (i > 0)ori[i] -= ori[i - 1];
	}
	vector<ll> val[2];
	rep(i, n) {
		val[i % 2].push_back(ori[i]);
	}
	SegT stev(val[0]), stod(val[1]);
	ll adev = 0, adod = 0;
	map<ll, vector<int>> mp[2];
	rep(i, n) {
		mp[i % 2][ori[i]].push_back(i);
	}
	ll ans = 0;
	rep(l, n) {
		int r = n;
		int evr = stev.find_loc((l + 1) / 2,adev);
		int odr = stod.find_loc(l / 2, adod);
		r = min(r, 2 * evr);
		r = min(r, 2*odr+1);
		//[l,r)
		rep(j, 2) {
			ll x = -adev;
			if (j)x = -adod;
			vector<int>& v = mp[j][x];
			ans += lower_bound(all(v), r) - lower_bound(all(v), l);
		}
		if (l % 2 == 0) {
			adev -= a[l];
			adod += a[l];
		}
		else {
			adev += a[l];
			adod -= a[l];
		}
	}
	cout << ans << "\n";
}



signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}