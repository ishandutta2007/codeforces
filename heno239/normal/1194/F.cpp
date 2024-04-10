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
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
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
perm p(1 << 19);

void solve() {
	int n; ll t; cin >> n >> t;
	vector<ll> a(n);
	rep(i, n)cin >> a[i]; a.push_back(INF); n++;
	vector<ll> ra(n + 1);
	rep(i, n)ra[i + 1] = ra[i] + a[i];
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ll ri = t - ra[i]; if (ri > i)ri = i;
		ll le = t - ra[i] - (a[i] - 1); if (le < 0)le = 0;
		//cout << i << " " << le << " " << ri << endl;
		ll csum = 0;
		for (ll j = le; j <= ri; j++) {
			csum += p.comb(i, j); if (csum >= mod)csum -= mod;
		}
		ll b = mod_pow(2, i);
		b = mod_pow(b, mod - 2);
		csum = csum * b%mod;
		ans += csum * i%mod; if (ans >= mod)ans -= mod;
		//cout << csum * i%mod << endl;
		ll dif = t - ra[i + 1];
		if (0 <= dif && dif <= i) {
			ll ad = p.comb(i, dif)*b%mod*(1 + mod) / 2 % mod;
			ans += ad * i%mod; if (ans >= mod)ans -= mod;
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
		return 0;
}