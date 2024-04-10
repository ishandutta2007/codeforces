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
const ll mod = 1000000007;
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
const int max_n = 1 << 10;
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


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int to[2000][1000];
int id[2000][2000];
void solve() {
	int n, m, k; cin >> n>>m >> k;
	vector<P> vp;
	vector<int> d(n + m);
	rep(i, k) {
		int a, b; cin >> a >> b; a--; b--;
		b += n;
		vp.push_back({ a,b });
		d[a]++;
		d[b]++;
		id[a][b] = id[b][a] = i;
	}
	int x = 0;
	rep(i, n + m)x = max(x, d[i]);
	rep(i, n + m)rep(j, x)to[i][j] = -1;
	vector<int> ans(k);
	rep(i, vp.size()) {
		int a = vp[i].first;
		int b = vp[i].second;
		bool upd = false;
		int c1 = -1, c2 = -1;
		rep(j, x) {
			if (to[a][j] < 0 && to[b][j] < 0) {
				to[a][j] = b;
				to[b][j] = a;
				upd = true; break;
			}
			if (to[a][j] < 0 && to[b][j] >= 0)c2 = j;
			if (to[a][j] >= 0 && to[b][j] < 0)c1 = j;
		}
		if (upd)continue;
		assert(c1 >= 0 && c2 >= 0);
		int cur = b;
		int col = c2;
		vector<pair<P, int>> vp;
		vp.push_back({ {a,b},c2 });
		while (true) {
			int nex = to[cur][col];
			if (nex < 0)break;
			to[cur][col] = to[nex][col] = -1;
			vp.push_back({ {cur,nex},c1 + c2 - col });
			col = c1 + c2 - col;
			cur = nex;
		}
		for (auto p : vp) {
			int a = p.first.first;
			int b = p.first.second;
			int c = p.second;
			to[a][c] = b;
			to[b][c] = a;
		}
	}
	rep(i, n)rep(j, x) {
		if (to[i][j] >= 0) {
			ans[id[i][to[i][j]]] = j + 1;
		}
	}
	cout << x << "\n";
	rep(i, k) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}