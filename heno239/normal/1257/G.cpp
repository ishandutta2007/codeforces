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
const ll mod = 998244353;
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

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

ll mod_inverse(ll a) {
	return mod_pow(a, mod - 2);
}
ll root[24], invroot[24];
void init() {
	rep(i, 24) {
		int n = (1 << i);
		root[i] = mod_pow(3, (mod - 1) / n);
		invroot[i] = mod_inverse(root[i]);
	}
}
typedef vector <ll> poly;
poly dft(poly f, bool inverse = false) {
	int n = f.size(); int i, j, k;
	//bit
	for (i = 0, j = 1; j < n - 1; j++) {
		for (k = n >> 1; k >(i ^= k); k >>= 1);
		if (i > j)swap(f[i], f[j]);
	}
	for (int j = 1; (1 << j) <= n; j++) {
		int m = 1 << j;
		ll zeta = root[j];
		if (inverse)zeta = invroot[j];
		for (i = 0; i < n; i += m) {
			ll powzeta = 1;
			for (k = i; k < i + m / 2; k++) {
				ll t1 = f[k], t2 = powzeta * f[k + m / 2] % mod;
				f[k] = t1 + t2; while (f[k] >= mod)f[k] -= mod;
				f[k + m / 2] = t1 - t2 + mod; while (f[k + m / 2] >= mod)f[k + m / 2] -= mod;
				(powzeta *= zeta) %= mod;
			}
		}
	}
	if (inverse) {
		ll rv = mod_inverse(n);
		for (i = 0; i < n; i++) {
			(f[i] *= rv) %= mod;
		}
	}
	return f;
}
poly multiply(poly g, poly h) {
	int n = 1;
	int pi = 0, qi = 0;
	rep(i, g.size())if (g[i])pi = i;
	rep(i, h.size())if (h[i])qi = i;
	int sz = pi + qi + 2;
	while (n < sz)n *= 2;
	g.resize(n); h.resize(n);
	/*while (g.size() < n) {
	g.push_back(0);
	}
	while (h.size() < n) {
	h.push_back(0);
	}*/
	poly gg = dft(g);
	poly hh = dft(h);
	poly ff; ff.resize(n);
	rep(i, n) {
		ff[i] = gg[i] * hh[i] % mod;
	}
	return dft(ff, true);
}

poly powply(poly x, int n) {
	if (n == 1)return x;
	poly res = { 1 };
	while (n > 0) {
		if (n & 1)res = multiply(res, x);
		n >>= 1;
		if (n > 0)x = multiply(x, x);
	}
	return res;
}

using speP = pair<ll, poly>;
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> c;
	rep(i, n) {
		int le = i;
		while (i + 1 < n&&a[i] == a[i + 1])i++;
		c.push_back(i - le + 1);
	}
	sort(c.begin(), c.end());
	poly dp = { 1 };
	
	priority_queue<speP, vector<speP>, greater<speP>> q;
	q.push({ 1,dp });
	rep(i, c.size()) {
		int le = i;
		while (i + 1 < c.size() && c[i] == c[i + 1])i++;
		poly e = { 1 }; rep(j, c[i])e.push_back(1);
		int len = i - le + 1;
		while (len > 0) {
			if (len & 1)q.push({ e.size(),e });
			len >>= 1; if (len == 0)break;
			e = multiply(e, e); if (e.size() > n / 2 + 1)e.resize(n / 2 + 1);
		}
	}
	while (q.size() >= 2) {
		poly a = q.top().second; q.pop();
		poly b = q.top().second; q.pop();
		a = multiply(a, b);
		q.push({ a.size(),a });
	}
	dp = q.top().second;
	cout << dp[n / 2] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}