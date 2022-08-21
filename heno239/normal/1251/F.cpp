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
#include<utility>
#include<set>

using namespace std;

//#define int long long

using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll INF = (1e+18) + 100;
const ll mod = 998244353;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repl(i, l, n) for(int i=l;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

typedef long double ld;
const ld eps = 1e-8;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}
struct perm {
private:
	int sz;
	vector<ll> p, invp;
public:
	perm(int n) {
		sz = n + 1;
		p.resize(sz), invp.resize(sz);
		p[0] = 1;
		rep1(i, sz - 1) {
			p[i] = p[i - 1] * i%mod;
		}
		invp[sz - 1] = 1;
		ll cop = mod - 2, x = p[sz - 1];
		while (cop) {
			if (cop % 2)invp[sz - 1] = invp[sz - 1] * x%mod;
			cop >>= 1; x = x * x % mod;
		}
		per(i, sz - 1) {
			invp[i] = invp[i + 1] * (i + 1) % mod;
		}
	}
	ll comb(ll x, ll y) {
		if (x < y || y < 0)return 0;
		ll ret = p[x];
		(ret *= invp[y]) %= mod;
		(ret *= invp[x - y]) %= mod;
		return ret;
	}
	ll combP(ll x, ll y) {
		if (x < y || y < 0)return 0;
		return p[x] * invp[x - y] % mod;
	}
};
perm pm(1 << 20);
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
	poly gg = dft(g);
	poly hh = dft(h);
	poly ff; ff.resize(n);
	rep(i, n) {
		ff[i] = gg[i] * hh[i] % mod;
	}
	return dft(ff, true);
}

int ans[5][600010];
int dp[600010];
void solve() {
	init();
	int n, k; cin >> n >> k;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<P> nex;
	rep(i, n) {
		int le = i;
		while (i + 1 < n&&a[i] == a[i + 1])i++;
		nex.push_back({ a[i],min(2,i - le + 1) });
	}
	vector<int> b(k);
	rep(i, k) {
		cin >> b[i];
	}
	poly c1 = { 1,2 };
	poly c2 = { 1,2,1 };
	poly e = { 1 };
	rep(i, k) {
		int cnt1 = 0, cnt2 = 0;
		int num = 0;
		rep(j, nex.size()) {
			if (nex[j].first >= b[i])break;
			if (nex[j].second == 1)cnt1++;
			else cnt2++;
			num += nex[j].second;
		}
		int ri = min(num + 1, 600000 - b[i]);
		poly r1(ri);
		ll s = 1;
		rep(i, ri) {
			ll c = pm.comb(cnt1, i);
			r1[i] = c * s%mod;
			s = s * 2 % mod;
		}
		poly r2(ri);
		rep(i, ri) {
			r2[i] = pm.comb(2 * cnt2,i);
		}
		poly z = multiply(r1, r2);
		z.resize(ri);
		for (int t = 1; t <= ri; t++) {
			ans[i][t + b[i]] = z[t - 1];
		}
	}
	int q; cin >> q;
	rep(i, q) {
		int x; cin >> x; x /= 2;
		ll out = 0;
		rep(j, k)out += ans[j][x];
		cout << out % mod << "\n";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	solve();
	//stop
	return 0;
}