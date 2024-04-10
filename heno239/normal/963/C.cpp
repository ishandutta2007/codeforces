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
const ll mod = 1000000009;
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

vector<int> multi(ll a, ll b) {
	vector<int> v1, v2;
	while (a > 0) {
		v1.push_back(a % 10); a /= 10;
	}
	while (b > 0) {
		v2.push_back(b % 10); b /= 10;
	}
	vector<int> res(v1.size() + v2.size() + 3);
	rep(i, v1.size())rep(j, v2.size()) {
		res[i + j] += v1[i] * v2[j];
	}
	int c = 0;
	rep(i, res.size()) {
		c += res[i];
		res[i] = c % 10; c /= 10;
	}
	while (res.size() && res.back() == 0)res.pop_back();
	return res;
}
void solve() {
	int n; cin >> n;
	vector<ll> w(n), h(n), c(n);
	map<LP, ll> mp;
	rep(i, n) {
		cin >> w[i] >> h[i] >> c[i];
		mp[{w[i], h[i]}] = c[i];
	}
	vector<ll> vx, vy;
	rep(i, n)vx.push_back(w[i]);
	rep(i, n)vy.push_back(h[i]);
	sort(all(vx));
	sort(all(vy));
	vx.erase(unique(all(vx)), vx.end());
	vy.erase(unique(all(vy)), vy.end());
	int ch = vx.size(); int cw = vy.size();
	if (ll(ch*cw) != n) {
		cout << 0 << "\n"; return;
	}
	vector<vector<ll>> a(ch, vector<ll>(cw));
	rep(i, ch)rep(j, cw) {
		a[i][j] = mp[{vx[i], vy[j]}];
	}
	if (ch < cw) {
		vector<vector<ll>> b(cw, vector<ll>(ch));
		rep(i, ch)rep(j, cw) {
			b[j][i] = a[i][j];
		}
		swap(ch, cw); swap(a, b);
	}

	bool valid = true;
	rep(i, ch - 1)rep(j, cw - 1) {
		ll a1 = a[i][j], a2 = a[i + 1][j + 1];
		ll a3 = a[i][j + 1], a4 = a[i + 1][j];

		if (multi(a1, a2) != multi(a3, a4)) {
			valid = false;
		}
	}
	if (!valid) {
		cout << 0 << "\n"; return;
	}
	vector<ll> gs(cw, 0);
	rep(j, cw) {
		rep(i, ch) {
			gs[j] = gcd(gs[j], a[i][j]);
		}
	}
	ll g = 0;
	rep(j, cw)g = gcd(g, a[0][j]);
	vector<ll> ds;
	ll k = sqrt(g);
	rep1(i, k + 1) {
		if (g%i == 0) {
			ds.push_back(i);
			ds.push_back(g / i);
		}
	}
	sort(all(ds));
	ds.erase(unique(all(ds)), ds.end());
	int ans = 0;
	for (ll d : ds) {
		valid = true;
		rep(j, cw) {
			if (gs[j] % (a[0][j] / d))valid = false;
		}
		if (valid)ans++;
	}
	cout << ans << "\n";
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