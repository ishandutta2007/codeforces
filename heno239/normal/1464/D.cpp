#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

typedef modint Data;
typedef vector<Data> Array;
typedef vector<Array> mat;

bool is_zero(Data dat) { return abs(dat) < eps; }
mat operator-(mat a) {
	rep(i, a.size())rep(j, a[0].size())a[i][j] = -a[i][j];
	return a;
}
mat operator+(mat lhs, mat& rhs) {
	rep(i, lhs.size())rep(j, lhs[0].size())lhs[i][j] += rhs[i][j];
	return lhs;
}
mat operator-(mat lhs, mat& rhs) {
	rep(i, lhs.size())rep(j, lhs[0].size())lhs[i][j] -= rhs[i][j];
	return lhs;
}
mat operator*(const mat& lhs, const mat& rhs) {
	mat ret(lhs.size(), Array(rhs[0].size(), 0));
	rep(i, lhs.size())rep(j, rhs[0].size())rep(k, rhs.size()) {
		ret[i][j] += lhs[i][k] * rhs[k][j];
	}
	return ret;
}

int specalc(int ad,int r1,int r2,int r4, int c3) {
	int res = ad;
	if (r4 > 0) {
		r4--;
	}
	else if (r2 >= 2) {
		r2 -= 2; res++;
	}
	else {
		res++; r1--;
	}
	res += r4; r1 += r4;
	int m = min(r1, r2);
	res += m; r1 -= m; r2 -= m;
	res += 2 * (r1 / 3);
	res += 3 * (r2 / 3);
	return res;
}
int calc(int ad, int r1, int r2, int r4, int c3, int c2) {
	int res = ad;
	res += r4; r1 += r4; r4 = 0;
	int m = min(r2, c2);
	r2 -= m; c2 -= m;
	res += c2; r1 -= 2 * c2;
	if (r1 < 0)r1 = 0;
	m = min(r1, r2);
	res += m; r1 -= m; r2 -= m;
	res += 2 * (r1 / 3);
	res += 3 * (r2 / 3);
	return res;
}

int dp[3][3];
int cop[3][3];
void solve() {
	int n; cin >> n;
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i]; p[i]--;
	}
	vector<int> cs;
	vector<bool> used(n);
	rep(i, n) {
		if (used[i])continue;
		used[i] = true;
		int tmp = 1;
		int cur = p[i];
		while (cur != i) {
			tmp++;
			used[cur] = true;
			cur = p[cur];
		}
		cs.push_back(tmp);
	}
	int c2, c3;
	if (n % 3 == 0) {
		c2 = 0, c3 = n / 3;
	}
	else if (n % 3 == 1) {
		c2 = 2, c3 = n / 3 - 1;
	}
	else if (n % 3 == 2) {
		c2 = 1, c3 = n / 3;
	}
	modint ans1 = 1;
	int ad = 0;
	int r1 = 0, r2 = 0, r4 = 0;
	for (int c : cs) {
		if (c >= 6) {
			ad += (c - 3) / 3;
			c -= 3 * ((c - 3) / 3);
		}
		if (c == 5) {
			ad++; c -= 3;
		}
		if (c == 1)r1++;
		else if (c == 2)r2++;
		else if (c == 4)r4++;
	}
	rep(i, c2)ans1 *= 2;
	rep(i, c3)ans1 *= 3;
	//cout << "! " << ad << " " << r1 << " " << r2 << " " << r4 << "\n";
	int ans2 = calc(ad, r1, r2, r4, c3, c2);
	if (n % 3 == 1) {
		ans2 = min(ans2, specalc(ad, r1, r2, r4, c3));
	}
	cout << ans1 << " " << ans2 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
		solve();
	return 0;
}