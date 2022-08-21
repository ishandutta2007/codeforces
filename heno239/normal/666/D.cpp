#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 1;
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

void solve() {
	vector<int> x(4), y(4);
	rep(i, 4)cin >> x[i] >> y[i];
	vector<P> vp;
	rep(i, 4)vp.push_back({ x[i],y[i] });
	vector<pair<P, int>> vpp;
	rep(i, 4) {
		vpp.push_back({ {x[i],y[i]},i });
	}
	sort(all(vpp));
	int ans = mod;
	vector<P> ansv;
	auto calc = [&](int lx, int rx, int ly, int ry)->int {
		vector<int> cx = { lx,lx,rx,rx };
		vector<int> cy = { ly,ry,ly,ry };
		sort(all(vp));
		int res = mod;
		do {
			int val = 0;
			rep(i, 4) {
				int x = vpp[i].first.first, y = vpp[i].first.second;
				if (cx[i] != x && cy[i] != y) {
					val = mod;
				}
				else {
					int dist = max(abs(cx[i] - x), abs(cy[i] - y));
					val = max(val, dist);
				}
			}
			res = min(res, val);
			if (ans > val) {
				ansv.resize(4);
				rep(i, 4) {
					int id = vpp[i].second;
					ansv[id] = { cx[i],cy[i] };
				}
				ans = val;
			}
		} while (next_permutation(all(vpp)));
		return res;
	};
	rep(s, 1 << 4) {
		vector<int> vx, vy;
		rep(i, 4) {
			if (s & (1 << i)) {
				vx.push_back(x[i]);
			}
			else {
				vy.push_back(y[i]);
			}
		}
		sort(all(vx)); vx.erase(unique(all(vx)), vx.end());
		sort(all(vy)); vy.erase(unique(all(vy)), vy.end());
		if (vx.empty()) {
			if (vy.size() != 2)continue;
			int cnt = 0;
			rep(i, 4)if (y[i] == vy[0])cnt++;
			if (cnt != 2)continue;
			int lx = -mod, rx = mod;
			while (rx - lx > 3) {
				int ml = (lx + rx) / 2;
				int mr = ml + 1;
				int cl = calc(ml, ml + vy[1] - vy[0], vy[0], vy[1]);
				int cr = calc(mr, mr + vy[1] - vy[0], vy[0], vy[1]);
				if (cl < cr) {
					rx = mr;
				}
				else {
					lx = ml;
				}
			}
			Rep1(i, lx, rx) {
				ans = min(ans, calc(i, i + vy[1] - vy[0], vy[0], vy[1]));
			}
		}
		else if (vy.empty()) {
			if (vx.size() != 2)continue;
			int cnt = 0;
			rep(i, 4)if (x[i] == vx[0])cnt++;
			if (cnt != 2)continue;
			int ly = -mod, ry = mod;
			while (ry - ly > 3) {
				int ml = (ly + ry) / 2;
				int mr = ml + 1;
				int cl = calc(vx[0], vx[1],ml, ml + vx[1] - vx[0]);
				int cr= calc(vx[0], vx[1], mr, mr + vx[1] - vx[0]);
				if (cl < cr) {
					ry = mr;
				}
				else {
					ly = ml;
				}
			}
			Rep1(i, ly, ry) {
				ans = min(ans, calc(vx[0], vx[1], i, i + vx[1] - vx[0]));
			}
		}
		else if (vx.size() == 2 && vy.size() == 2) {
			if (vx[1] - vx[0] == vy[1] - vy[0])ans = min(ans, calc(vx[0], vx[1], vy[0], vy[1]));
		}
		else if (vx.size() == 1 && vy.size() == 2) {
			int d = vy[1] - vy[0];
			ans = min(ans, calc(vx[0] - d, vx[0], vy[0], vy[1]));
			ans = min(ans, calc(vx[0], vx[0] + d, vy[0], vy[1]));
		}
		else if (vx.size() == 2 && vy.size() == 1) {
			int d = vx[1] - vx[0];
			ans = min(ans, calc(vx[0], vx[1], vy[0] - d, vy[0]));
			ans = min(ans, calc(vx[0], vx[1], vy[0], vy[0] + d));
		}
	}
	if (ans == mod)ans = -1;
	cout << ans << "\n";
	if (ans >= 0) {
		rep(i, 4) {
			cout << ansv[i].first << " " << ansv[i].second << "\n";
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	int t; cin >> t;rep(i, t)
	solve();
	return 0;
}