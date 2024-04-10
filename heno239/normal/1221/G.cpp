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
const int max_n = 1 << 19;
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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}


bool exi[40][40];

int cnt0[8][1 << 20];
int cnt1[8][1 << 20];
int cntspe[8][1 << 20];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		exi[a][b] = exi[b][a] = true;
	}
	int d1 = n / 2;
	int d2 = n - d1;
	vector<int> with2(d2);
	rep(j, d2) {
		rep(i, d2)if (exi[i + d1][j + d1])with2[j] |= (1 << i);
	}
	vector<int> ste(d2);
	int ex = 0;
	rep(j, d2) {
		bool e = false;
		rep(i, d1)if (exi[i][j+d1])e = true;
		if (e)ex |= (1 << j);
	}
	rep(i, (1 << d2)) {
		int s0 = 0, s1 = 0;
		rep(j, d2) {
			if (i & (1 << j)) {
				ste[j] = 1;
				s1 |= (1 << j);
			}
			else {
				ste[j] = 0;
				s0 |= (1 << j);
			}
		}
		int s = 0;
		rep(j, d2) {
			if (ste[j] == 0) {
				if (with2[j] & s0)s |= (1 << 0);
				if (with2[j] & s1)s |= (1 << 1);
			}
			else {
				if (with2[j] & s0)s |= (1 << 1);
				if (with2[j] & s1)s |= (1 << 2);
			}
		}
		cnt0[s][(1 << d2) - 1-i]++;
		cnt1[s][i]++;
		cntspe[s][i & ex]++;
	}
	rep(i, 8) {
		rep(j, d2)rep(k, (1 << d2)) {
			if (k & (1 << j)) {
				cnt0[i][k ^ (1 << j)] += cnt0[i][k];
				cnt1[i][k ^ (1 << j)] += cnt1[i][k];
			}
		}
	}
	vector<int> with1(d1,0);
	rep(i, d1) {
		rep(j, d1) {
			if (exi[i][j])with1[i] |= (1 << j);
		}
	}
	vector<int> with12(d1, 0);
	rep(i, d1)rep(j, d2) {
		if (exi[i][j + d1])with12[i] |= (1 << j);
	}
	ste.resize(d1);
	ll ans = 0;
	rep(i, (1 << d1)) {
		int s = 0;
		int s0 = 0, s1 = 0;
		rep(j, d1) {
			if (i & (1 << j)) {
				ste[j] = 1;
				s1 |= (1 << j);
			}
			else {
				ste[j] = 0;
				s0 |= (1 << j);
			}
		}
		int t0 = 0, t1 = 0;
		rep(j, d1) {
			if (ste[j] == 0) {
				if (with1[j] & s0)s |= (1 << 0);
				if (with1[j] & s1)s |= (1 << 1);
				t0 |= with12[j];
			}
			else {
				if (with1[j] & s0)s |= (1 << 1);
				if (with1[j] & s1)s |= (1 << 2);
				t1 |= with12[j];
			}
		}
		rep(t, 8) {
			ll csum = 0;
			int st = s | t;
			csum += cnt0[t][0];
			if ((st & 1) == 0) {
				csum -= cnt1[t][t0];
			}
			if ((st & 2) == 0) {
				if ((t0 & t1) == 0) {
					csum -= cntspe[t][t1];
				}
			}
			if ((st & 4) == 0) {
				csum -= cnt0[t][t1];
			}
			if ((st & 3) == 0) {
				if (t0 == 0) {
					csum += cnt1[t][t1];
				}
			}
			if ((st & 6) == 0) {
				if (t1 == 0) {
					csum += cnt0[t][t0];
				}
			}
			if ((st & 5) == 0) {
				if ((t0 & t1) == 0) {
					csum += cntspe[t][t0];
				}
			}
			if ((st & 7) == 0) {
				if (t0 == 0 && t1 == 0) {
					csum -= cnt0[t][0];
				}
			}
			//cout << t1<<" "<<cnt0[t][t1] << "\n";
			//cout << i << " " << t << " " << csum << "\n";
			ans += csum;
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}