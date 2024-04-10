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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}
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
poly a, x;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	int n, k; cin >> n >> k;
	a.resize(10, 0); x.resize(1, 1);
	rep(i, k) {
		int d; cin >> d; a[d] = 1;
	}
	n /= 2;
	while (n) {
		if (n & 1)x = multiply(x, a);
		n >>= 1;
		if (n)a = multiply(a, a);
	}
	ll ans = 0;
	rep(i, x.size()) {
		(ans += x[i] * x[i] % mod) %= mod;
	}
	cout << ans << endl;
	//stop
	return 0;
}