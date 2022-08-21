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

modint sdp[1 << 20];
modint dp[1 << 20][4];
void solve() {
	int n; cin >> n;
	modint inv2 = (1 + mod) / 2;
	modint inv6 = (modint)1 / (modint)6;
	sdp[0] = 1;
	for (int i = 1; i <= n; i++) {
		//0
		sdp[i] += 1;
		//1
		sdp[i] += sdp[i - 1];
		//2
		sdp[i] += sdp[i - 1] * (sdp[i - 1] + (modint)1) * inv2;
	}
	auto calc3 = [&](modint x) {
		return x * (x + (modint)1) * (x + (modint)2) * inv6;
	};
	auto calc2 = [&](modint x) {
		return x * (x + (modint)1) * inv2;
	};
	auto calc = [&](int x)->modint {
		if (x == 0)return 1;
		modint res = 0;
		//0
		res += 1;
		//1
		res += sdp[x - 1];
		//2
		res += sdp[x - 1] * (sdp[x - 1] + (modint)1) * inv2;
		//3
		res += sdp[x - 1] * (sdp[x - 1] + (modint)1) * (sdp[x - 1] + (modint)2) * inv6;
		for (int c = 1; c <= x; c++) {
			//3
			res += calc3(sdp[c - 1]);
			if (c >= 2) {
				res -= calc3(sdp[c - 2]);
			}
			//2
			modint cl = sdp[c - 1] * (sdp[c - 1] + (modint)1) * inv2;
			if (c >= 2) {
				cl -= calc2(sdp[c - 2]);
			}
			modint cr = 0;
			////0
			cr += 1;
			////1
			if (c + 1 <= x)cr += sdp[x - (c + 1)];
			res += cl * cr;
		}
		return res;
	};
	//cout << calc(0) << " " << calc(1) << "\n";
	//cout << calc(n - 1) << " " << calc(n) << "\n";
	modint ans = calc(n) - calc(n - 1);
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i, t)
	solve();
	return 0;
}