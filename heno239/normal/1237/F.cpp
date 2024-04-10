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
typedef pair<int, bool> sP;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

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
perm p(1 << 17);
ll hdp[3601][1803];
ll wdp[3601][1803];
void solve() {
	int h, w, n; cin >> h >> w >> n;
	vector<bool> bh(h,true), bw(w,true);
	rep(i, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		bh[x1] = bh[x2] = false;
		bw[y1] = bw[y2] = false;
	}
	vector<int> vh, vw;
	rep(i, h) {
		if (bh[i])vh.push_back(i);
	}
	rep(i, w) {
		if (bw[i])vw.push_back(i);
	}
	hdp[0][0] = 1;
	rep(i, vh.size()) {
		rep(j, 1801) {
			(hdp[i + 1][j] += hdp[i][j]) %= mod;
			//if (hdp[i + 1][j] >= mod)hdp[i + 1][j] -= mod;
			if (i + 1 < vh.size() && vh[i + 1] == vh[i] + 1) {
				(hdp[i + 2][j + 1] += hdp[i][j]) %= mod;
				//if (hdp[i + 2][j + 1] >= mod)hdp[i + 2][j + 1] -= mod;
			}
		}
	}
	wdp[0][0] = 1;
	rep(i, vw.size()) {
		rep(j, 1801) {
			(wdp[i + 1][j] += wdp[i][j])%=mod;
			//if (wdp[i + 1][j] >= mod)wdp[i + 1][j] -= mod;
			if (i + 1 < vw.size() && vw[i + 1] == vw[i] + 1) {
				(wdp[i + 2][j + 1] += wdp[i][j]) %= mod;
				//if (wdp[i + 2][j + 1] >= mod)wdp[i + 2][j + 1] -= mod;
			}
		}
	}
	//cout << vh.size() << " " << vw.size() << endl;
	ll ans = 0;
	rep(i, 1801) {
		int hrest = (int)vh.size() - 2 * i;
		if (hrest < 0)continue;
		rep(j, 1801) {
			int wrest = (int)vw.size() - 2 * j;
			if (wrest < 0)continue;
			ll hnum = hdp[vh.size()][i] * p.combP(hrest, j) % mod;
			ll wnum = wdp[vw.size()][j] * p.combP(wrest, i) % mod;
			(ans += (hnum*wnum)) %= mod;

		}
	}
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}