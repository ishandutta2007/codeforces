#pragma GCC target("avx2")
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
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

const int sup = 300005;
bool isp[sup];
vector<int> chp[sup];


modint t2[sup];
void init() {
	fill(isp + 2, isp + sup, true);
	for (int i = 2; i < sup; i++) {
		if (!isp[i])continue;
		chp[i].push_back(i);
		for (int j = 2 * i; j < sup; j += i) {
			isp[j] = false;
			chp[j].push_back(i);
		}
	}

	t2[0] = 1;
	rep(i, sup - 1)t2[i + 1] = t2[i] * (modint)2;
}

modint mem[3][sup];
modint rmem[3][sup];
vector<int> cs[sup];
void solve() {
	init_f();
	int n; cin >> n;
	vector<int> t(n);
	rep(i, n)cin >> t[i];
	rep(i, n) {
		int cop = t[i];
		for (int p : chp[t[i]]) {
			int cnt = 0;
			while (cop % p == 0) {
				cop /= p; cnt++;
			}
			cs[p].push_back(cnt);
		}
	}
	rep(i, 3) {
		rep(j, n) {
			mem[i][j] = comb(n - 2, j+i);
			rmem[i][j + 1] = rmem[i][j] + mem[i][j];
		}
	}
	modint ans = 0;
	rep(i, sup)if (isp[i]) {
		vector<int> v;
		int ma = 0;
		rep(j, cs[i].size())ma = max(ma, cs[i][j]);
		v.resize(ma + 1);
		rep(j, cs[i].size())v[cs[i][j]]++;
		v[0] = n - cs[i].size();
		vector<int> rv(v.size() + 1);
		rep(i, v.size())rv[i + 1] = rv[i] + v[i];
		rep(j, v.size()) {
			Rep(k, j + 1, v.size()) {
				int le = rv[k] - 1;
				int ri = le + v[k];
				modint num = rmem[1][ri] - rmem[1][le];
				num *= v[j];
				ans += num * (modint)(k - j);
				num = rmem[2][ri] - rmem[2][le];
				num *= v[j];
				ans += num * (modint)(k - j);
			}
		}
		rep(j, v.size())rep(k, j) {
			int le = n - rv[k + 1] - 1;
			int ri = le + v[k];
			modint num = rmem[1][ri] - rmem[1][le];
			num *= v[j];
			ans += num * (modint)(j - k);
			num = rmem[0][ri] - rmem[0][le];
			num *= v[j];
			ans += num * (modint)(j - k);
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	init();
	//expr();

	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}