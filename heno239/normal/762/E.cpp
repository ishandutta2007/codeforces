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
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
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
const int max_n = 1 << 20;
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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

template<typename T>
struct BIT {
private:
	vector<T> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, T w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	T sum(int a) {
		T ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	T sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

const int mn = 10005;
vector<int> vf[mn];
void solve(){
	int n, k; cin >> n >> k;
	vector<int> x(n), r(n), f(n);
	rep(i, n)cin >> x[i] >> r[i] >> f[i];
	vector<int> vx;
	rep(i, n) {
		vx.push_back(x[i]);
		vx.push_back(x[i] - r[i]);
		vx.push_back(x[i] + r[i]);
	}
	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	vector<int> le(n), ri(n);
	rep(i, n) {
		le[i] = lower_bound(all(vx), x[i] - r[i]) - vx.begin();
		ri[i] = lower_bound(all(vx), x[i] + r[i]) - vx.begin();
		x[i] = lower_bound(all(vx), x[i]) - vx.begin();
	}
	rep(i, n) {
		vf[f[i]].push_back(i);
	}
	BIT<int> bt(vx.size());
	auto comp = [&](int i, int j) {
		return r[i] > r[j];
	};
	ll ans = 0;
	vector<ll> memo(mn);
	rep(i, mn) {
		if (vf[i].empty())continue;
		sort(all(vf[i]), comp);
		for (int id : vf[i]) {
			memo[i] += bt.sum(le[id], ri[id] + 1);
			bt.add(x[id], 1);
		}
		for (int id : vf[i])bt.add(x[id], -1);
		ans += memo[i];
	}
	//cout << ans << "\n";
	rep(i, mn) {
		if (vf[i].empty())continue;
		for (int j = i - 1; j >= i - k; j--) {
			if (j < 0)continue;
			if (vf[j].empty())continue;
			vector<int> ids;
			int id0 = 0, id1 = 0;
			while (id0 < vf[j].size() && id1 < vf[i].size()) {
				if (r[vf[j][id0]] > r[vf[i][id1]]) {
					ids.push_back(vf[j][id0]); id0++;
				}
				else {
					ids.push_back(vf[i][id1]); id1++;
				}
			}
			while (id0 < vf[j].size()) {
				ids.push_back(vf[j][id0]); id0++;
			}
			while (id1 < vf[i].size()) {
				ids.push_back(vf[i][id1]); id1++;
			}
			ll csum = 0;
			for (int id : ids) {
				csum += bt.sum(le[id], ri[id] + 1);
				bt.add(x[id], 1);
			}
			for (int id : ids)bt.add(x[id], -1);
			csum -= memo[i] + memo[j];
			ans += csum;
			//cout << j << " " << i << " " << csum << "\n";
		}
	}
	cout << ans << "\n";
}


signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}