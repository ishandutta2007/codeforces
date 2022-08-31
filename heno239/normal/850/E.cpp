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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}


vector<ll> hadamard_trans(vector<ll>& v, bool rev = false) {
	vector<ll> res = v;
	int n = v.size();
	for (int i = 1; i < n; i <<= 1) {
		for (int j = 0; j < n; j += 2 * i) {
			for (int k = 0; k < i; k++) {
				ll le = res[j + k];
				ll ri = res[j + k + i];
				res[j + k] = le + ri;
				if (res[j + k] >= mod)res[j + k] -= mod;
				res[j + k + i] = le - ri;
				if (res[j + k + i] < 0)res[j + k + i] += mod;
			}
		}
	}
	if (rev) {
		ll inv = mod_pow(n, mod - 2);
		for (int i = 0; i < n; i++) {
			res[i] = res[i] * inv % mod;
		}
	}
	return res;
}
vector<ll> mul(vector<ll> a, vector<ll> b) {
	int sm = (int)a.size() + (int)b.size() - 1, sz = 1;
	while (sz < sm)sz *= 2;
	a.resize(sz); b.resize(sz);
	a = hadamard_trans(a);
	b = hadamard_trans(b);
	rep(i, sz) {
		a[i] = a[i] * b[i] % mod;
	}
	a = hadamard_trans(a, true);
	a.resize(sm); return a;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<ll> a(1 << n);
	rep(i, (1 << n)) {
		a[i] = (s[i] - '0');
	}
	a = mul(a, a);
	ll ans = 0;
	rep(i, (1 << n)) {
		int cnt = 0;
		rep(j, n)if (i & (1 << j))cnt++;
		ll z = 1;
		rep(i, n - cnt)z *= 2;
		(ans += z * a[i]) %= mod;
	}
	ans = ans * 3 % mod;
	cout << ans << "\n";
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