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
const int max_n = 1 << 15;
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

const int m = 31607;
int p[21][21];
int q[21][21];
int pq[21][21];
bool ist[21][21];
int prei[1 << 21];
void init() {
	rep(i, (1 << 21)) {
		rep(j, 21)if (i & (1 << j)) {
			prei[i] = j;
		}
	}
}

modint calc(int n) {
	vector<int> val(1 << n,1);
	vector<int> mem(1 << n);
	rep(j, n) {
		vector<int> chks;
		rep(i, n)if (ist[i][j])chks.push_back(i);
		fill(all(mem), 0);
		int dec = 1;
		rep(i, n) {
			dec *= p[i][j]; dec %= m;
		}
		mem[0] = 1;
		rep(i, (1 << n)) {
			if (i > 0) {
				int c = prei[i];
				int pre = i ^ (1 << c);
				mem[i] = mem[pre] * p[c][j] % m;
			}
			int v = mem[i];
			for (int chk : chks){
				if (i & (1 << chk)) {
					//
				}
				else {
					v *= p[chk][j]; v %= m;
				}
			}
			v -= dec; if (v < 0)v += m;
			val[i] *= v; val[i] %= m;
		}
	}
	rep(j, n)rep(i, (1 << n)) {
		if (i & (1 << j)) {
			//
		}
		else {
			val[i] -= val[i ^ (1 << j)];
			if (val[i] < 0)val[i] += m;
		}
	}
	return val[0];
}
void solve() {
	int n; cin >> n;
	rep(i, n)rep(j, n) {
		ll in; cin >> in;
		p[i][j] = in * mod_pow(10000, m - 2, m) % m;
		q[i][j] = 1 - p[i][j]; if (q[i][j] < 0)q[i][j] += m;
		pq[i][j] = p[i][j]*mod_pow(q[i][j],m-2,m)%m;
	}
	int ans = calc(n);
	rep(i, n)ist[i][i] = 1;
	int ans1 = calc(n);
	rep(i, n) {
		ist[i][i] = 0;
	}
	rep(i, n)ist[i][n - 1 - i] = 1;
	int ans2 = calc(n);
	rep(i, n)ist[i][i] = 1;
	int ans12 = calc(n);
	//cout << ans << " " << ans1 << " " << ans2 << " " << ans12 << "\n";
	ans = ans - ans1 - ans2 + ans12;
	ans %= m; if (ans < 0)ans += m;
	ans = 1 - ans; if (ans < 0)ans += m;
	cout << ans << "\n";

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init_f();
	init();
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}