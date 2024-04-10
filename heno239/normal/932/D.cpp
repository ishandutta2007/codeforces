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
constexpr ll mod = 1000000009;
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

const int max_n = 1 << 18;
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int par[400005][19];
ll sum[400005][19];
ll wei[400005];
void solve() {
	rep(j, 19)par[0][j] = -1;
	rep(j, 19)sum[0][j] = INF;
	wei[0] = 0;

	int tmp = 1;
	int q; cin >> q;
	ll las = 0;
	rep(i, q) {
		ll t, r, w;
		cin >> t >> r >> w;
		r ^= las; w ^= las; r--;
		if (t == 1) {
			wei[tmp] = w;
			if (wei[r] >= w) {
				par[tmp][0] = r;
			}
			else {
				int cur = r;
				per(j, 19) {
					int pp = par[cur][j];
					if (pp >= 0 && wei[pp] < w) {
						cur = pp;
					}
				}
				par[tmp][0] = par[cur][0];
			}
			if (par[tmp][0] >= 0)sum[tmp][0] = wei[par[tmp][0]];
			else sum[tmp][0] = INF;
			rep(j, 18) {
				if (par[tmp][j] < 0) {
					par[tmp][j + 1] = -1;
					sum[tmp][j + 1] = INF;
				}
				else {
					par[tmp][j + 1] = par[par[tmp][j]][j];
					sum[tmp][j + 1] = sum[tmp][j] + sum[par[tmp][j]][j];
				}
			}
			tmp++;
		}
		else {
			ll ans = 0;
			if (wei[r] > w) {
				ans = 0;
			}
			else {
				w -= wei[r];
				ans = 1;

				int cur = r;
				per(j, 19) {
					ll c = sum[cur][j];
					if (c <= w) {
						ans += (1 << j);
						w -= c;
						cur = par[cur][j];
					}
				}
			}
			cout << ans << "\n";
			las = ans;
		}
	}
	//cout << par[2][0] << "\n";
	//cout << sum[2][0] << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(6);
	//init_f();
	//init();
	//int t; cin >> t;rep(i,t)
	solve();
	stop
		return 0;
}