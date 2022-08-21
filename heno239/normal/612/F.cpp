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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;

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
const ld eps = 1e-4;
const ld pi = acosl(-1.0);

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
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
const int max_n = 1 << 10;
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

vector<int> loc[1 << 11];
vector<vector<int>> dp;
void solve() {
	int n, s; cin >> n >> s; s--;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	rep(i, s)a.push_back(a[i]);
	a.erase(a.begin(), a.begin() + s);
	vector<int> va = a; sort(all(va)); va.erase(unique(all(va)), va.end());
	rep(i, n)a[i] = lower_bound(all(va), a[i]) - va.begin();
	rep(i, n)loc[a[i]].push_back(i);
	dp.resize(va.size());
	rep(i, va.size())dp[i].resize(loc[i].size(),mod);
	vector<vector<int>> pre = dp;
	auto calcdist = [&](int a, int b) {
		int res = abs(a - b);
		return min(res, n - res);
	};
	auto calc1 = [&](int pre, int dep, int nid) {
		int val = 0;
		int prenid = nid == 0 ? loc[dep].size() - 1 : nid - 1;
		val += calcdist(loc[dep][prenid],pre);
		int dif = loc[dep][nid] - loc[dep][prenid];
		if (dif < 0)dif += n;
		val += n - dif;
		return val;
	};
	auto calc2 = [&](int pre, int dep, int nid) {
		int val = 0;
		int nexid = nid + 1 == loc[dep].size() ? 0 : nid + 1;
		val += calcdist(loc[dep][nexid],pre);
		int dif = loc[dep][nexid] - loc[dep][nid];
		if (dif < 0)dif += n;
		val += n - dif;
		return val;
	};
	auto calc = [&](int pre, int dep, int nid) {
		if (loc[dep].size() == 1)return calcdist(pre,loc[dep][nid]);
		int res = mod;
		int val;
		//clock->cclock
		res = min(res, calc1(pre, dep, nid));
		//cclock->clock
		res = min(res, calc2(pre, dep, nid));
		return res;
	};
	rep(i, dp[0].size()) {
		dp[0][i] = calc(0, 0, i);
	}
	rep(i, va.size() - 1) {
		rep(j, dp[i].size()) {
			rep(k, dp[i + 1].size()) {
				int nd = dp[i][j] + calc(loc[i][j], i + 1, k);
				if (nd < dp[i + 1][k]) {
					dp[i + 1][k] = nd;
					pre[i + 1][k] = j;
				}
			}
		}
	}
	int ans = mod;
	int chk = -1;
	rep(i, dp.back().size()) {
		if (dp.back()[i] < ans) {
			ans = dp.back()[i];
			chk = i;
		}
	}
	int cur = chk;
	int dep = va.size() - 1;
	vector<int> ids;
	while (dep > 0) {
		int pcur = pre[dep][cur];
		int dif = dp[dep][cur] - dp[dep - 1][pcur];
		if (calc1(loc[dep - 1][pcur], dep, cur) == dif) {
			rep(j, loc[dep].size()) {
				int id = j + cur;
				if (id >= loc[dep].size())id -= loc[dep].size();
				ids.push_back(loc[dep][id]);
			}
		}
		else {
			rep(j, loc[dep].size()) {
				int id = cur-j;
				if (id < 0)id += loc[dep].size();
				ids.push_back(loc[dep][id]);
			}
		}
		cur = pcur;
		dep--;
	}
	int dif = dp[dep][cur];
	if (calc1(0, dep, cur) == dif) {
		rep(j, loc[dep].size()) {
			int id = j + cur;
			if (id >= loc[dep].size())id -= loc[dep].size();
			ids.push_back(loc[dep][id]);
		}
	}
	else {
		rep(j, loc[dep].size()) {
			int id = cur - j;
			if (id < 0)id += loc[dep].size();
			ids.push_back(loc[dep][id]);
		}
	}
	reverse(all(ids));
	vector<string> anss;
	int nw = 0;
	rep(i, ids.size()) {
		int nloc = ids[i];
		if (nw == nloc) {
			anss.push_back("+0");
		}
		else {
			//+
			int difp = nloc - nw; if (difp < 0)difp += n;
			//-
			int difn = nw - nloc; if (difn < 0)difn += n;
			string ad;
			if (difp <= difn) {
				ad.push_back('+');
				ad += to_string(difp);
			}
			else {
				ad.push_back('-');
				ad += to_string(difn);
			}
			anss.push_back(ad);
		}
		nw = nloc;
	}
	cout << ans<< "\n";
	rep(i, anss.size())cout << anss[i] << "\n";
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}