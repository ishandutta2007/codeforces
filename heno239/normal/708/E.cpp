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

modint dpl[1500][2], dpr[1500][2];
modint nexl[1500][2], nexr[1500][2];
void solve() {
	int n, m; cin >> n >> m;
	int a, b; cin >> a >> b;
	modint p = (modint)a / (modint)b;
	int k; cin >> k;
	vector<modint> ps(m + 1);
	rep(i, k + 1) {
		if (i > m)break;
		ps[i] = comb(k, i) * (modint)mod_pow(p, i) * (modint)mod_pow((modint)1 - p, k - i);
	}
	vector<modint> rps(m + 1);
	rep(i, m)rps[i + 1] = rps[i] + ps[i];
	rep(i, m) {
		dpl[i][0] = ps[i] * rps[m - i];
		dpr[i][0] = ps[m - 1 - i] * rps[i + 1];
	}
	//cout << "? " << dpl[0][0]*(modint)4 << " " << dpl[1][0]*(modint)4 << "\n";
	rep1(i, n - 1) {
		rep(j, m)rep(k, 2)nexl[j][k] = nexr[j][k] = 0;
		modint sum[2] = {};
		rep(j, m)rep(k,2)sum[k] += dpl[j][k];
		rep(j, m) {
			rep(k, 2) {
				nexl[j][k] += sum[k] * ps[j] * rps[m - j];
				nexr[j][k] += sum[k] * ps[m - j - 1] * rps[j + 1];
			}
		}
		//l from l
		rep(k, 2) {
			modint sum = 0;
			for (int j = m - 1; j >= 0; j--) {
				nexl[j][k] += ps[j] * rps[m - j] * sum;
				sum += dpl[j][k ^ 1];
			}
		}
		rep(k, 2) {
			modint sum = 0;
			for (int j = m - 1; j >= 0; j--) {
				nexl[j][k] -= ps[j] * sum;
				sum += dpl[j][k ^ 1] * rps[m - j];
			}
		}
		//r from l
		rep(k, 2) {
			modint sum = 0;
			for (int j = m - 1; j >= 0; j--) {
				nexr[j][k] += ps[m - 1 - j] * rps[j + 1] * sum;
				sum += dpl[j][k ^ 1];
			}
		}
		//l from r
		rep(k, 2) {
			modint sum = 0;
			rep(j, m) {
				nexl[j][k] += ps[j] * rps[m - j] * sum;
				sum += dpr[j][k^1];
			}
		}
		//r from r
		rep(k, 2) {
			modint sum = 0;
			rep(j, m) {
				nexr[j][k] += ps[m - 1 - j] * rps[j + 1] * sum;
				sum += dpr[j][k ^ 1];
			}
		}
		rep(k, 2) {
			modint sum = 0;
			rep(j, m) {
				nexr[j][k] -= ps[m - 1 - j] * sum;
				sum += dpr[j][k ^ 1] * rps[j + 1];
			}
		}
		rep(j, m)rep(k, 2) {
			dpl[j][k] = nexl[j][k];
			dpr[j][k] = nexr[j][k];
		}
	}
	modint c = 0;
	rep(j, m) {
		c += dpl[j][0] - dpl[j][1];
		/*rep(t, 2) {
			cout << dpl[j][t]*(modint)16 << " " << j << " " << t << "\n";
		}*/
	}
	cout << c << "\n";
	/*modint x = 0;
	rep(j, m)rep(t, m) {
		if (j + t >= m)continue;
		x += ps[j] * ps[t];
	}
	x = mod_pow(x, n);
	modint ans = x - c;
	cout << c * (modint)16 << "\n";
	ans *= 16;
	cout << ans << "\n";*/
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}