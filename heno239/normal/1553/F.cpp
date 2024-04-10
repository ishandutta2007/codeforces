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
const int max_n = 1 << 18;
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

using speP = pair<int, ll>;
void addf(speP& a, speP b) {
	a.first += b.first;
	a.second += b.second;
}
struct BIT {
private:
	vector<speP> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, speP{ 0,0 });
	}
	//0-indexed
	void add(int a, speP w) {
		for (int i = a; i < n; i |= i + 1)addf(node[i], w);
	}
	//[0,a)
	speP sum(int a) {
		speP ret = { 0,0 };
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)addf(ret, node[i]);
		return ret;
	}
	speP sum(int a, int b) {
		speP ret = sum(b);
		speP ret2 = sum(a);
		ret.first -= ret2.first;
		ret.second -= ret2.second;
		return ret;
	}
};

const int b = 1000;
void solve(){
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	ll sum = 0;
	vector<ll> ans(n);
	int sz = 0;
	rep(i, n)sz = max(sz, (int)a[i]);
	sz++;
	BIT bt(sz);
	vector<bool> exi(sz);
	rep(i, n) {
		// b
		ll ad = bt.sum(sz).second;
		ll cc = 0;
		for (int j = 1; j * a[i] < sz; j++) {
			int l = a[i] * j;
			int r = a[i] * (j + 1); r = min(r, sz);
			//[l,r)
			ll num = bt.sum(l, r).first;
			cc += j * num;
		}
		ad -= a[i] * cc;

		//a
		ll ad2 = a[i] * i;
		rep1(j, b) {
			if (j >= sz)break;
			if (exi[j]) {
				ad2 -= (ll)j * (a[i] / j);
			}
		}
		rep1(j, b) {
			int l = a[i] / (j + 1);
			int r = a[i] / j;
			//(l,r]
			l++; r++;
			//[l,r)
			l = max(l, b + 1);
			if (l >= r)break;
			speP p = bt.sum(l, r);
			ad2 -= j * p.second;
		}

		//cout << cc<<" "<<ad << " " << ad2 << "\n";
		sum += ad + ad2;
		bt.add(a[i], { 1,a[i] });
		ans[i] = sum;
		exi[a[i]] = true;
	}
	rep(i, n) {
		if (i > 0)cout << " "; cout << ans[i];
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}