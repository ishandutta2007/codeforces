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


int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

ll dp[1 << 14][14][1 << 6];

bool b[14][14];
ll ans[1 << 7][1 << 6];
ll tans[1 << 13];

void solve() {
	int n; cin >> n;
	rep(i, n)rep(j, n) {
		char in; cin >> in;
		if (in == '1')b[i][j] = true;
	}
	rep(i, n) {
		dp[1<<i][i][0] = 1;
	}
	int d1 = (n + 1) / 2;
	int d2 = n - d1;
	rep(i, (1 << n)) {
		int tmp = 0;
		rep(j, n)if (i&(1 << j))tmp++;
		if (tmp < 1 || tmp >= d1)continue;
		rep(j, n) {
			if (i&(1 << j)) {
				rep(k, n) {
					if (i&(1 << k))continue;
					int ni = i ^ (1 << k);
					int ad = 0;
					if (b[j][k])ad += (1 << tmp - 1);
					rep(s, (1 << tmp - 1)) {
						dp[ni][k][s + ad] += dp[i][j][s];
					}
				}
			}
		}
	}
	//cout << dp[2][1][1] << endl;
	//cout << dp[3][0][1] << endl;
	rep(i, (1 << n)) {
		int tmp = 0;
		rep(j, n)if (i&(1 << j))tmp++;
		if (tmp!=d1)continue;
		int x = i, rx = ((1 << n) - 1) ^ i;
		rep(j, n) {
			if (i&(1 << j)) {
				rep(k, n) {
					if (i&(1 << k))continue;
					int ad = 0;
					if (b[j][k])ad = 1 << d1 - 1;
					rep(s, (1 << d1 - 1)) {
						int ns = s | ad;
						rep(t, (1 << d2 - 1)) {
							ans[ns][t] += dp[x][j][s] * dp[rx][k][t];
						}
					}
				}
			}
		}
	}
	rep(i, 1 << d1) {
		rep(j, 1 << d2 - 1) {
			int c = 0;
			rep(k, d2 - 1) {
				if (j&(1 << k)) {
					c += 1 << (d2 - 2 - k);
				}
			}
			tans[i+(c<<d1)] += ans[i][j];
		}
	}
	rep(i, (1 << n - 1)) {
		if (i > 0)cout << " ";
		cout << tans[i];
	}
	cout << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}