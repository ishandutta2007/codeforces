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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
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


int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


vector<int> x[1 << 17], y[1 << 17];
void solve() {
	int h, w, n; cin >> h >> w >> n;
	int id = 0;
	vector<P> memo;
	bool exi = false;
	rep(i, n) {
		int a, b; cin >> a >> b; a--; b--;
		x[a].push_back(b);
		y[b].push_back(a);
		memo.push_back({ a,b });
		if (a == 0 && b == 1)exi = true;
	}

	ll num = (ll)h*w - n;
	rep(i, h)sort(all(x[i]));
	rep(i, w)sort(all(y[i]));
	if (exi||w==1) {
		ll sum = h;
		if (y[0].size())sum = y[0][0];
		if (num == sum) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		return;
	}
	int lex = 1, rix = h - 1;
	int ley = 0, riy = w - 1;
	int cx = 0, cy = 0;
	ll sum = 1;
	while (true) {
	//	cout << cx << " " << cy << endl;
		if (id == 0) {
			int ny = riy;
			auto itr = lower_bound(all(x[cx]), cy);
			if (itr != x[cx].end())ny = min(ny, *itr-1);
			if (cy == ny)break;
			sum += ny - cy;
			cy = ny;
			riy = ny - 1;
			id = 1;
		}
		else if (id == 1) {
			int nx = rix;
			auto itr = lower_bound(all(y[cy]), cx);
			if (itr != y[cy].end())nx = min(nx, *itr-1);
			if (cx == nx)break;
			sum += nx - cx;
			cx = nx;
			rix = nx - 1;
			id = 2;
		}
		else if (id == 2) {
			int ny = ley;
			auto itr = lower_bound(all(x[cx]), cy);
			if (itr != x[cx].begin())ny = max(ny, *--itr+1);
			if (cy == ny)break;
			sum += cy - ny;
			cy = ny;
			ley = ny + 1;
			id = 3;
		}
		else {
			int nx = lex;
			auto itr = lower_bound(all(y[cy]), cx);
			if (itr != y[cy].begin())nx = max(nx, *--itr+1);
			if (cx == nx)break;
			sum += cx - nx;
			cx = nx;
			lex = nx + 1;
			id = 0;
		}
	}
	if (sum == num) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init_f();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}