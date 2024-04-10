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
const ll mod = 998244353;
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
	if (x == 0)return 0;
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
const int max_n = 1 << 20;
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void solve(){
	int n, m;ll t; cin >> n >> m >> t;
	vector<int> x(n);
	vector<char> c(n);
	rep(i, n) {
		cin >> x[i] >> c[i];
	}
	vector<P> vp;
	vector<int> rev(n);
	rep(i, n) {
		vp.push_back({ x[i],i });
	}
	sort(all(vp));
	rep(i, n) {
		int id = vp[i].second;
		rev[i] = id;
	}
	{
		vector<int> nx(n);
		vector<char> nc(n);
		rep(i, n) {
			nx[i] = x[rev[i]];
			nc[i] = c[rev[i]];
		}
		swap(x, nx);
		swap(c, nc);
	}
	bool bb = false;
	if (c[0] == 'L') {
		rep(i, n) {
			x[i] = m - x[i];
			c[i] = 'L' + 'R' - c[i];
		}
		for (int i = 1;; i++) {
			int j = n - i;
			if (i >= j)break;
			swap(rev[i], rev[j]);
			swap(x[i], x[j]);
			swap(c[i], c[j]);
		}
		bb = true;
	}
	vector<int> ts;
	rep(i, n)if (c[i] != c[0]) {
		int dist = x[i] - x[0]; if (dist < 0)dist += m;
		ts.push_back((dist+1)/2);
		ts.push_back((dist + m + 1) / 2);
	}
	sort(all(ts));
	ll ad = 0;
	ad += (t / m) * ts.size();
	rep(i, ts.size()) {
		if (ts[i] <= t % m)ad++;
	}
	vector<int> lass;
	rep(i, n) {
		ll loc = x[i];
		if (c[i] == 'L')loc -= t;
		else loc += t;
		loc %= m; if (loc < 0)loc += m;
		lass.push_back(loc);
		lass.push_back(loc + m);
	}
	sort(all(lass));
	ll sloc = (x[0] + t) % m;
	//cout << "? " << ad << "\n";
	int z = upper_bound(all(lass), sloc) - lass.begin(); z--;
	vector<int> ans(n);
	rep(i, n) {
		int id = (i + ad) % n;
		id = rev[id];
		//cout << id << "\n";
		ans[id] = lass[z + i] % m;
	}
	if (bb)rep(i, n)ans[i] = m- ans[i];
	rep(i, n) {
		if (ans[i] == 0)ans[i] = m;
		if (i > 0)cout << " ";
		cout << ans[i];
	}cout << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}