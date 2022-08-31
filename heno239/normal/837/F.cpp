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
const ll mod = 1000000007;
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

ll mod_pow(ll a, ll n, ll m) {
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
using mP = pair<modint, modint>;

vector<ll> makenext(vector<ll> &a) {
	vector<ll> res;
	ll sum = 0;
	res.push_back(sum);
	rep(i, a.size()) {
		sum += a[i];
		if (sum > INF)sum = INF;
		res.push_back(sum);
	}
	return res;
}
int cnt(vector<ll> &a) {
	int res = 0;
	rep(i, a.size())if (a[i] > 0)res++;
	return res;
}

typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

ll mul(ll a, ll b) {
	if (a == 0)return 0;
	if (INF / a < b)return INF;
	return a * b;
}
mat mtmul(mat &A, mat &B) {
	mat C(A.size(), vec(B[0].size()));
	rep(i, (int)A.size()) {
		rep(k, (int)B.size()) {
			rep(j, (int)B[0].size()) {
				C[i][j] += mul(A[i][k], B[k][j]);
				if (C[i][j] > INF)C[i][j] = INF;
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
		if (n&(ll)1)B = mtmul(B, A);
		A = mtmul(A, A);
		n >>= 1;
	}
	return B;
}
void solve() {
	int n; cin >> n; ll k; cin >> k;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	rep(i, n) {
		if (a[i] >= k) {
			cout << 0 << endl; return;
		}
	}
	int ans = 1;
	a = makenext(a);
	rep(i, a.size())if (a[i] >= k) {
		cout << 1 << endl; return;
	}
	int num = cnt(a);
	if (num >= 6) {
		while (true) {
			ans++;
			a = makenext(a);
			rep(i, a.size())if (a[i] >= k) {
				cout << ans << endl; return;
			}
		}
	}
	else {
		vector<ll> las;
		per(i, a.size())if (a[i] > 0)las.push_back(a[i]);
		mat bs(num,vector<ll>(num,0));
		rep(i, num)rep(j, num) {
			if(i<=j)bs[i][j] = 1;
		}
		/*rep(i, num) {
			rep(j, num)cout << bs[i][j];
			cout << endl;
		}*/
		ll le = -1, ri = INF;
		while (ri - le > 1) {
			ll mid = (le + ri) / 2;
			mat z = mtpow(bs, mid);
			vector<ll> res(num);
			rep(i, num) {
				rep(j, num) {
					res[i] += mul(z[i][j], las[j]);
					if (res[i] > INF)res[i] = INF;
				}
			}
			if (res[0] >= k)ri = mid;
			else le = mid;
		}

		cout << ans+ri << endl;

		/*ll ad = 0;
		ll las = 0;
		rep(i, a.size()) {
			if (a[i] > 0) {
				ad = a[i]; break;
			}
		}
		per(i, a.size()) {
			if (a[i] > 0) {
				las = a[i]; break;
			}
		}
		ll dif = k - las;
		ll plu = (dif + ad - 1) / ad;
		cout << ans + plu << endl;*/
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}