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
const int max_n = 1 << 22;
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

typedef vector<vector<modint>> mat;
typedef vector<modint> vec;
mat mtmul(mat& A, mat& B) {
	mat C(A.size(), vec(B[0].size()));
	rep(i, (int)A.size()) {
		rep(k, (int)B.size()) {
			rep(j, (int)B[0].size()) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}
mat mtpow(mat A, ll n) {
	mat B(A.size(), vec(A.size()));
	rep(i, (int)A.size()) {
		B[i][i] = 1;
	}
	while (n > 0) {
		if (n & (ll)1)B = mtmul(B, A);
		A = mtmul(A, A);
		n >>= 1;
	}
	return B;
}
void solve() {
	int n, m; cin >> n >> m;
	vector<string> s(n);
	rep(i, n)cin >> s[i];
	vector<int> ad(n);
	int c = 0;
	rep(i, n) {
		ad[i] = c; c += s[i].size();
	}
	int t = c + 1;
	mat A(5*t,vector<modint>(5*t));
	for (int i = t; i < 5 * t; i++) {
		A[i - t][i] = 1;
	}
	rep(i, n)rep(j, s[i].size()) {
		rep(k, n) {
			string sl = s[i].substr(j, s[i].size() - j);
			string sr = s[k];
			if (sl.size() < sr.size()) {
				string sx = sr.substr(0, sl.size());
				if (sl == sx) {
					int fr = ad[i] + j;
					int sc = ad[k] + sl.size()+(sl.size()-1)*t;
					A[sc][fr] += 1;
				}
			}
			else if (sl.size() > sr.size()) {
				string sx = sl.substr(0, sr.size());
				if (sr == sx) {
					int fr = ad[i] + j;
					int sc = ad[i] + j + sr.size() + (sr.size() - 1) * t;
					A[sc][fr] += 1;
				}
			}
			else {
				if (sl == sr) {
					int fr = ad[i] + j;
					int sc = c+(sl.size() - 1) * t;
					//cout << 5 * t << " " <<sc <<" "<<fr<< "\n";
					A[sc][fr] += 1;
				}
			}
		}
	}
	rep(i, n)rep(j, n) {
		string sl = s[i];
		string sr = s[j];
		if (sl.size() < sr.size()) {
			string sx = sr.substr(0, sl.size());
			if (sl == sx) {
				int fr = c;
				int sc = ad[j] + sl.size() + (sl.size() - 1) * t;
				A[sc][fr] += 1;
			}
		}
		else if (sl.size() > sr.size()) {
			string sx = sl.substr(0, sr.size());
			if (sr == sx) {
				int fr = c;
				int sc = ad[i] + sr.size() + (sr.size() - 1) * t;
				A[sc][fr] += 1;
			}
		}
		else {
			if (sl == sr) {
				int fr = c;
				int sc = c + (sl.size() - 1) * t;
				A[sc][fr] += 1;
			}
		}
	}
	A = mtpow(A, m);
	cout << A[c][c] << "\n";
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