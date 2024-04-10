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

//#define int long long
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
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

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
ll mod_inverse(ll x) {
	int n = mod - 2;
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}

int trans(char t) {
	if ('a' <= t && t <= 'z')return t - 'a';
	return 26 + t - 'A';
}

int c[52];

ll dp[1 << 17], cop[1 << 17];

ll ans[52][52];

ll dp2[1 << 17];
ll dp3[1 << 17];
//ll past[1 << 17];
ll ainv[1 << 17];
void init() {
	rep(i, (1 << 17)) {
		ainv[i] = mod_inverse(i);
	}
}
void solve() {
	string s; cin >> s;
	int n = s.length();
	rep(i, n) {
		c[trans(s[i])]++;
	}
	dp[0] = 1;
	int sum = 0;
	rep(i, 52) {
		if (c[i] == 0)continue;
		sum += c[i];
		rep(j, n + 1) {
			cop[j] = 0;
		}
		rep(j, sum + 1) {
			if (dp[j] == 0)continue;
			ll pro;
			//same
			pro = p.comb(j + c[i], j);
			(cop[j + c[i]] += dp[j] * pro) %= mod;
			//another
			int num = sum - c[i] - j;
			pro = p.comb(num + c[i], c[i]);
			(cop[j] += dp[j] * pro) %= mod;
		}
		rep(j, n + 1) {
			dp[j] = cop[j];
		}
	}
	ll memo = dp[n / 2] % mod;
	//cout << "! " << memo << endl;
	rep(x, 52) {
		ans[x][x] = memo;
		if (c[x] == 0)continue;
		ll inv = mod_inverse(p.comb(n, c[x]));
		int len = n / 2 - c[x] + 1;
		rep(i, len) {
			if (i - c[x] < 0) {
				dp2[i] = dp[i] * inv%mod;
			}
			else {
				dp2[i] = dp[i] - dp2[i - c[x]] * p.comb(i, c[x]);
				dp2[i] = dp2[i] % mod + mod;
				dp2[i] = dp2[i] * inv%mod;
			}
			inv = inv * (n - i) % mod;
			inv = inv * ainv[n - i - c[x]] % mod;
		}
		Rep(y, x + 1, 52) {
			if (c[y] == 0)continue;
			if (c[x] + c[y] > n / 2)continue;
			
			//cout << endl;

			inv = mod_inverse(p.comb(n - c[x], c[y]));
			len = n / 2 - c[x] - c[y]+1;
			int sup = n / 2 - c[x] - c[y];
			rep(i, len) {
				if ((sup - i) % c[y] == 0) {
					if (i < c[y]) {
						dp3[i] = dp2[i] * inv%mod;
					}
					else {
						dp3[i] = dp2[i] - dp3[i - c[y]] * p.comb(i, c[y]);
						dp3[i] = dp3[i] % mod + mod;
						dp3[i] = dp3[i] * inv%mod;
					}
				}
				inv = inv * (n - c[x] - i) % mod;
				inv = inv * ainv[n - c[x] - c[y] - i] % mod;
			}
			ans[x][y] = 2 * dp3[n / 2 - c[x] - c[y]] * p.comb(n / 2, c[x] + c[y]) % mod;
			ans[x][y] = ans[x][y] * p.comb(c[x] + c[y], c[x]) % mod;

		}
	}
	int q; cin >> q;
	rep(aa, q) {
		int x, y; cin >> x >> y; x--; y--;
		int cx = trans(s[x]), cy = trans(s[y]);
		if (cx > cy)swap(cx, cy);
		cout << ans[cx][cy] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}