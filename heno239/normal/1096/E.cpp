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
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

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
perm pm(1 << 17);

void solve() {
	int p, s, r; cin >> p >> s >> r;
	if (p == 1) {
		cout << 1 << endl; return;
	}
	ll ans = 0;
	for (int x = 1; x < p; x++) {
		for (int y = r; y <= s; y++) {
			int rest = s - x * y;
			if (rest < 0)break;
			ll csum = 0;
			for (int z = 0; z <= p - x; z++) {
				int sum = rest - z * y;
				if (sum < 0)break;
				ll pro = pm.comb(p - x, z);
				pro = pro * pm.comb(sum + p - x - 1, sum)%mod;
				if (z % 2) {
					csum -= pro;
				}
				else {
					csum += pro;
				}
			}
			csum = (csum%mod + mod) % mod;
			csum = csum * pm.comb(p - 1, x - 1) % mod*mod_pow(x, mod - 2) % mod;
			ans += csum;
		}
	}
	for (int y = r; y <= s; y++) {
		int rest = s - p * y;
		if (rest == 0) {
			ans += mod_pow(p, mod - 2);
		}
	}
	ans %= mod;
	ll inv = 0;
	for (int y = r; y <= s; y++) {
		inv += pm.comb(s - y + p - 2, s-y);
	}
	inv %= mod;
	//cout << ans << endl;
	ans = ans * mod_pow(inv, mod - 2) % mod;
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//init();
	solve();
	//stop
	return 0;
}