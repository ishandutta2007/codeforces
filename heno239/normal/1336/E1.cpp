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
const ll mod = 998244353;
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
const ld pi = acos(-1.0);

ll mod_pow(ll a, ll n, ll m = mod) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
const int max_n = 10000;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

using mat = vector<vector<int>>;
int Gaussian_elimination(mat &A) {
	int n = A.size(); int m = A[0].size();
	int le = 0;
	rep(j, m) {
		Rep(i, le, n) {
			if (A[i][j]) {
				swap(A[le], A[i]);
				Rep(i2, le + 1, n) {
					if (A[i2][j]) {
						rep(k, m) {
							A[i2][k] ^= A[le][k];
						}
					}
				}
				le++; break;
			}
		}
	}
	return le;
}

modint dp[19][19][1 << 17];
void solve() {
	int n, m; cin >> n >> m;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	mat A(n, vector<int>(m,0));
	rep(i, n) {
		rep(j, m) {
			if ((a[i] >> j) & 1) {
				A[i][j] = 1;
			}
		}
	}
	int r = Gaussian_elimination(A);
	int d = m / 2;
	ll mid = (ll)1 << d;
	vector<ll> up,dow;
	rep(i, n) {
		ll s = 0;
		rep(j, m)if (A[i][j]) {
			s += (ll)1 << (m - 1 - j);
		}
		if (s > 0) {
			if (s >= mid)up.push_back(s);
			else dow.push_back(s);
		}
	}
	int len = up.size();
	rep(i, (1 << len)) {
		ll s = 0;
		rep(j, len)if (i&(1 << j)) {
			s ^= up[j];
		}
		int tmp = 0;
		for (int j = d; j < m; j++)if ((s >> j) & 1) {
			tmp++;
		}
		dp[0][tmp][s%mid]+=1;
	}
	rep(i, dow.size()) {
		ll val = dow[i];
		rep(j, 19) {
			rep(k, mid) {
				dp[i + 1][j][k] += dp[i][j][k];
				dp[i + 1][j][k^val] += dp[i][j][k];
			}
		}
	}
	vector<modint> ans(m + 1);
	rep(j, 19)rep(k, mid) {
		if (dp[dow.size()][j][k] != (modint)0) {
			int num = 0;
			num += j;
			rep(l, d)if ((k >> l) & 1)num++;
			ans[num] += dp[dow.size()][j][k];
		}
	}
	rep(i, n - r) {
		rep(j, m + 1)ans[j] *= 2;
	}
	rep(j, m + 1) {
		if (j > 0)cout << " ";
		cout << ans[j];
	}
	cout << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//experi();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}