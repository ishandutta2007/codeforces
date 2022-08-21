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
const ld pi = acos(-1.0);

ll mod_pow(ll a, ll n, ll m = mod) {
	a %= m;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

using mat = vector<vector<int>>;
void Gauss_elim(mat &A, int sup,vector<int> &ri) {
	int le = 0;
	int n = A.size();
	int m = A[0].size();

	int r = 0;
	rep(j, m-1) {
		Rep(i, le, min(n,le+sup)) {
			if (A[i][j] != (modint)0) {
				swap(A[i], A[le]);
				swap(ri[i], ri[le]);

				r = max(r, ri[le]);

				Rep(k, le,min(n,le+sup)) {
					if (k == le)continue;
					if (A[k][j] == 0)continue;
					int c = (ll)A[k][j] * mod_pow(A[le][j], mod - 2) % mod;
					Rep(l, j, r+1) {
						A[k][l] -= (ll)A[le][l] * c%mod;
						if (A[k][l] < 0)A[k][l] += mod;
					}
					A[k].back() -= (ll)A[le].back()*c%mod;
					if (A[k].back() < 0)A[k].back() += mod;
				}
				int c = mod_pow(A[le][j], mod - 2);
				for (int l = j; l < m; l++) {
					A[le][l] = (ll)A[le][l]*c%mod;
				}
				le++;
				break;
			}
		}
	}
}

void solve() {
	int r; cin >> r;
	int pd[4];
	int a[4]; rep(i, 4)cin >> a[i];
	int sum = a[0] + a[1] + a[2] + a[3];

	int invsum = mod_pow(sum, mod - 2);
	pd[0] = (ll)a[3]*invsum%mod;
	pd[1] = (ll)a[2] * invsum%mod;
	pd[2] = (ll)a[1]*invsum%mod;
	pd[3] = (ll)a[0]*invsum%mod;

	map<P, int> mp;
	int tmp = 0;
	for (int x = -50; x <= 50;x++) {
		for (int y = -50; y <= 50; y++) {
			int d = x * x + y * y;
			if (d <= r * r) {
				mp[{x, y}] = tmp; tmp++;
			}
		}
	}
	mat A(tmp, vector<int>(tmp+1, (modint)0));
	vector<int> ri(tmp);
	for (int x = -50; x <= 50; x++) {
		for (int y = -50; y <= 50; y++) {
			int d = x * x + y * y;
			if (d <= r * r) {
				int id = mp[{x, y}];
				A[id].back() = mod-1;
				A[id][id] = 1;

				ri[id] = id;
				rep(d, 4) {
					int nx = x + dx[d], ny = y + dy[d];
					if (mp.find({ nx,ny }) != mp.end()) {
						int to = mp[{nx, ny}];
						A[id][to] = mod-pd[d];
						ri[id] = max(ri[id], to);
					}
				}
			}
		}
	}
	Gauss_elim(A, 105,ri);
	vector<int> ex(tmp);
	per(i, tmp) {
		//assert(A[i][i] == 1);
		for (int j = i + 1; j < min(tmp,i+105); j++) {
			ex[i] -= (ll)ex[j] * A[i][j]%mod;
			if (ex[i] < 0)ex[i] += mod;
		}
		ex[i] -= A[i].back();
		if (ex[i] < 0)ex[i] += mod;
	}
	cout << ex[mp[{0, 0}]] << "\n";
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