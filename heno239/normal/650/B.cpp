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
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m) {
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

void solve() {
	int n; ll a, b, t; cin >> n >> a >> b >> t;
	int ri = 0;
	string s; cin >> s;
	string x = s; x.erase(x.begin());
	string y = x; reverse(all(y));
	vector<ll> costx(x.size() + 1);
	vector<ll> costy(y.size() + 1);
	t -= 1; if (s[0] == 'w')t -= b;
	costx[0] = costy[0] = 0;
	rep(i, x.size()) {
		costx[i + 1] = costx[i] + 1 + a;
		if (x[i] == 'w')costx[i + 1] += b;
	}
	rep(i, y.size()) {
		costy[i + 1] = costy[i] + 1 + a;
		if (y[i] == 'w')costy[i + 1] += b;
	}
	int ans = 0;

	//x>=y
	int loc = -1;
	for (int i = x.size(); i >= 0;i--) {
		while (loc+1 <= y.size() && costx[i] + costy[loc+1] + (loc+1) * a <= t) {
			loc++;
		}
		if (loc < 0)continue;
		ans = max(ans, 1 + i + min(i, loc));
	}
	//y>=x
	loc = -1;
	for (int i = y.size(); i >= 0; i--) {
		while (loc + 1 <= x.size() && costy[i] + costx[loc + 1] + (loc + 1) * a <= t) {
			loc++;
		}
		if (loc < 0)continue;
		ans = max(ans, 1 + i + min(i, loc));
	}

	//cout << costx[0] << " " << costy[0] << " " << t << "\n";
	ans = min(ans, n);
	cout << ans << "\n";
	
}

signed main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}