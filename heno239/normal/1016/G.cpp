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
constexpr ll mod = 998244353;
//constexpr ll mod = 1000000007;
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
	//if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
/*const int mn = 100005;
bool isp[mn];
vector<int> ps;
void init() {
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
		}
	}
}*/

//[,val)
template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}

//[val,)
template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;

const string drul = "DRUL";
//DRUL
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------


ll lcd(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
template <typename T>
void fwt(vector<T>& f) {
	int n = f.size();
	for (int i = 1; i < n; i <<= 1) {
		for (int j = 0; j < n; j++) {
			if ((j & i) == 0) {
				f[j | i] += f[j];
			}
		}
	}
}
template <typename T>
void ifwt(vector<T>& f) {
	int n = f.size();
	for (int i = 1; i < n; i <<= 1) {
		for (int j = 0; j < n; j++) {
			if ((j & i) == 0) {
				f[j | i] -= f[j];
			}
		}
	}
}

void solve() {
	int n; ll x, y; cin >> n >> x >> y;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	if (y % x) {
		cout << 0 << "\n"; return;
	}
	vector<LP> ps;
	ll cop = y;
	for (int i = 2; i <= 1000000; i++) {
		if (cop % i == 0) {
			int cnt = 0;
			while (cop % i == 0) {
				cop /= i; cnt++;
			}
			ps.push_back({ i,cnt });
		}
	}
	ll k = sqrt(round(cop));
	if (k * k == cop && k > 1) {
		ps.push_back({ k,2 });
	}
	vector<int> le(ps.size());
	cop = x;
	rep(i, ps.size()) {
		ll p = ps[i].first;
		while (cop % p == 0) {
			cop /= p; le[i]++;
		}
	}
	vector<LP> lev;
	rep(i, n) {
		if (a[i] % x)continue;
		ll v = gcd(a[i], y);
		int t = 0;
		rep(j, ps.size()) {
			ll p = ps[j].first;
			int cnt = 0;
			while (v % p == 0) {
				v /= p; cnt++;
			}
			if (cnt == le[j])t |= (1 << j);
		}
		lev.push_back({ v,t });
	}
	vector<LP> riv;
	rep(i, n) {
		if (y % a[i])continue;
		ll v = lcd(x, a[i]);
		int t = 0;
		rep(j, ps.size()) {
			ll p = ps[j].first;
			int cnt = 0;
			while (v % p == 0) {
				v /= p; cnt++;
			}
			if (cnt == ps[j].second)t |= (1 << j);
		}
		riv.push_back({ v,t });
	}
	vector<ll> vl, vr;
	for (auto p : lev)vl.push_back(p.first);
	for (auto p : riv)vr.push_back(p.first);
	sort(all(vl)); vl.erase(unique(all(vl)), vl.end());
	sort(all(vr)); vr.erase(unique(all(vr)), vr.end());
	ll ans = 0;
	rep(i, vl.size())rep(j, vr.size())if (vr[j] % vl[i] == 0) {
		vector<ll> cl(1 << ps.size());
		vector<ll> cr(1 << ps.size());
		for (auto p : lev)if (p.first == vl[i])cl[p.second]++;
		for (auto p : riv)if (p.first == vr[j])cr[p.second]++;
		fwt(cl); fwt(cr);
		rep(i, (1 << ps.size())) {
			cl[i] *= cr[i];
		}
		ifwt(cl);
		ans += cl.back();
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}