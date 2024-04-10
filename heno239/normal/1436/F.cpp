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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	x %= m;
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

const int max_n = 1 << 2;
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

modint calc(vector<LP> v) {
	ll s = 0;
	rep(i, v.size())s += v[i].second;
	if (s <= 1)return 0;
	modint c2 = (modint)s * (modint)mod_pow(2, s - 3); c2 *= 2;
	modint c1 = (modint)(s - 1) * (modint)mod_pow(2, s - 2);
	modint sum2 = 0;
	modint al2 = 0;
	rep(i, v.size()) {
		modint val = v[i].first;
		modint num = v[i].second * (v[i].second - 1) / 2;
		sum2 += num * val * val;
		sum2 += al2 * val * (modint)v[i].second;
		al2 += val * (modint)v[i].second;
	}
	modint sum1 = 0;
	rep(i, v.size()) {
		modint val = v[i].first;
		modint num = v[i].second;
		sum1 += val * val * num;
	}
	modint res = 0;
	res += c2 * sum2;
	res += c1 * sum1;
	//if (res != (modint)0)cout << c2 << " " << c1 << " " << sum2 << " " << sum1 << "\n";
	return res;
}


vector<int> ch[1 << 17];
bool isp[1 << 17];
int meb[1 << 17];
void init() {
	for (int i = 1; i < (1 << 17); i++) {
		for (int j = i; j < (1 << 17); j += i) {
			ch[j].push_back(i);
		}
	}
	fill(isp + 2, isp + (1 << 17), true);
	fill(meb + 1, meb + (1 << 17), 1);
	for (int i = 2; i < (1 << 17); i++) {
		if (!isp[i])continue;
		for (int j = i; j < (1 << 17); j += i) {
			meb[j] *= -1;
			if ((j / i) % i == 0)meb[j] = 0;
			isp[j] = false;
		}
	}
}
vector<LP> memo[1 << 17];
void solve() {
	//rep1(i, 20)cout << i << " " << meb[i] << "\n";
	int n; cin >> n;
	vector<int> a(n), f(n);
	rep(i, n)cin >> a[i] >> f[i];
	rep(i, n) {
		for (int d : ch[a[i]]) {
			memo[d].push_back({ a[i],f[i] });
		}
	}
	modint ans = 0;
	for (int i = 1; i < (1 << 17); i++) {
		if (meb[i] == 0)continue;
		modint score = calc(memo[i]);
		//if(score!=(modint)0)cout << i << " " << score << "\n";
		ans += (modint)meb[i] * score;
	}cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}