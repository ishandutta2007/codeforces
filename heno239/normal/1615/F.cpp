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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-4;
const ld pi = acosl(-1.0);

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int calc(string a, string b) {
	vector<int> va, vb;
	rep(i, a.size()) {
		if (i % 2)a[i] = '0' + '1' - a[i];
		if (a[i] == '1') {
			va.push_back(i);
		}
	}
	rep(i, b.size()) {
		if (i % 2)b[i] = '0' + '1' - b[i];
		if (b[i] == '1') {
			vb.push_back(i);
		}
	}
	if (va.size() != vb.size())return 0;
	int res = 0;
	rep(i, va.size())res += abs(va[i] - vb[i]);
	return res;
}
void expr() {
	int n; cin >> n;
	string a, b; cin >> a >> b;
	vector<int> qa, qb;
	rep(i, n) {
		if (a[i] == '?')qa.push_back(i);
		if (b[i] == '?')qb.push_back(i);
	}
	int ans = 0;
	rep(i, (1 << qa.size()))rep(j, (1 << qb.size())) {
		string copa = a;
		string copb = b;
		rep(k, qa.size()) {
			if (i & (1 << k))copa[qa[k]] = '1';
			else copa[qa[k]] = '0';
		}
		rep(k, qb.size()) {
			if (j & (1 << k))copb[qb[k]] = '1';
			else copb[qb[k]] = '0';
		}
		ans += calc(copa, copb);
	}
	cout << ans << "\n";
}

modint dp[2005][4005];
modint sumdp[2005][4005];
void solve() {
	int n; cin >> n;
	const int ad = n;
	rep(i, n+1) {
		for (int j = ad - n; j <= ad + n; j++) {
			dp[i][j] = 0;
			sumdp[i][j] = 0;
		}
	}
	string a, b; cin >> a >> b;
	rep(i, n) {
		if (i % 2) {
			if (a[i] != '?')a[i] = '0' + '1' - a[i];
			if (b[i] != '?')b[i] = '0' + '1' - b[i];
		}
	}
	dp[0][ad] = 1;
	rep(i, n) {
		for (int j = ad - (i + 1); j <= ad + (i + 1); j++) {
			rep(x, 2)rep(y, 2) {
				if (x == 0 && a[i] == '1')continue;
				if (x == 1 && a[i] == '0')continue;
				if (y == 0 && b[i] == '1')continue;
				if (y == 1 && b[i] == '0')continue;
				if (x == y) {
					dp[i + 1][j] += dp[i][j];
					sumdp[i + 1][j] += sumdp[i][j];
				}
				else if (x) {
					modint coef;
					if (j >= ad) {
						coef = -i;
					}
					else {
						coef = i;
					}
					dp[i + 1][j + 1] += dp[i][j];
					sumdp[i + 1][j + 1] += sumdp[i][j] + coef * dp[i][j];

					/*if (i == 1 && j == ad - 1) {
						cout << "? " << dp[i][j] << "\n";
						cout << coef * dp[i][j] << "\n";
					}*/
				}
				else {
					modint coef;
					if (j <= ad) {
						coef = -i;
					}
					else {
						coef = i;
					}
					dp[i + 1][j - 1] += dp[i][j];
					sumdp[i + 1][j - 1] += sumdp[i][j] + coef * dp[i][j];
				}
			}
		}
	}
	//cout << dp[1][ad] << "\n";
	//cout << "ans is ";
	cout << sumdp[n][ad] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	//init_f();
	//init();
	//while(true)
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}