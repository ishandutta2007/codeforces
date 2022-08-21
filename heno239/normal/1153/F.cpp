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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
ll mod_inverse(ll x) {
	ll n = mod - 2;
	ll ret = 1;
	while (n) {
		if (n & 1)ret = ret * x%mod;
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
	ll pl(int x) {
		return p[x];
	}
	ll invpl(int x) {
		return invp[x];
	}
};
ll inv[10001];
vector<ll> v;
void init() {
	v.push_back(1); v.push_back(0);
	ll s = 1;
	for (int i = 3; i < 4053; i += 2) {
		v.push_back(s);
		v.push_back(0);
		s = s * i%mod;
	}
	rep1(i, 10000)inv[i] = mod_inverse(i);
}
void solve() {
	init();
	perm p(10000);
	int k, n; ll l; cin >> n >> k >> l;
	ll ans = 0;

	ll zz = mod_inverse(v[2 * n]);
	rep(i, 2 * n-1) {
		int le = i + 1; int ri = 2 * n - le;
		Rep1(j, k, n) {
			if (j > min(le, ri))break;
			if ((le - j) % 2)continue;
			ll c = p.comb(le, j)*p.comb(ri, j) % mod*v[le - j] % mod*v[ri - j] % mod;
			c = c * p.pl(j)%mod;
			c = c * zz%mod;
			//c = c * mod_inverse(le + ri + 1) % mod;
			rep1(aa, 3) {
				if (le + ri + aa - 2 <= 0)continue;
				c = c * inv[le + ri + aa - 2] % mod;
			}
			c = c * 2 * n%mod*(2 * n - 1) % mod;
			
			ans = (ans + c) % mod;
		}
	}
	ans = ans * l%mod;
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}