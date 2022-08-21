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
mP operator+(mP a, mP b) {
	return { a.first + b.first,a.second + b.second };
}
mP operator+=(mP& a, mP b) {
	a = a + b; return a;
}
mP operator-(mP a, mP b) {
	return { a.first - b.first,a.second - b.second };
}
mP operator-=(mP& a, mP b) {
	a = a - b; return a;
}

mt19937 mt(time(0));

const string drul = "DRUL";
string senw = "SENW";
//DRUL,or SENW
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------

using mp = map<int, int>;
vector<mp> mkmap(int ad, int num, int a,int f) {
	vector<mp> res(2);
	rep(i, (1 << (num - 1)))rep(las, 2) {
		int tmp = 0;
		vector<int> v(num);
		rep(j, num)v[j] = j+ad;
		modint sum = 0;
		int coef = f;
		while (v.size() > 1) {
			vector<int> nv;
			for (int j = 0; j < v.size(); j += 2) {
				bool b = false;
				if (i & (1 << tmp))b = true;
				tmp++;
				if (b) {
					nv.push_back(v[j + 1]);
					sum += v[j] * mod_pow(a, coef);
				}
				else {
					nv.push_back(v[j]);
					sum += (v[j+1]) * mod_pow(a, coef);
				}
			}
			swap(v, nv);
			coef = coef / 2 + 1;
		}
		if (las)sum += v[0] * mod_pow(a, 1);
		else sum += v[0] * mod_pow(a, 2);
		res[las][sum] = i;
	}
	return res;
}
vector<int> mkans(int num, int cl, int cr,int id) {
	int tmp = 0;
	vector<int> vl(num / 2);
	rep(i, num / 2)vl[i] = i;
	vector<int> vr(num / 2);
	rep(i, num / 2)vr[i] = i + num / 2;
	vector<int> res(num);
	int coef = num / 2 + 1;
	while (vl.size() > 1) {
		vector<int> nv;
		for (int i = 0; i < vl.size(); i += 2) {
			bool b = false;
			if (cl & (1 << tmp))b = true; tmp++;
			if (b) {
				nv.push_back(vl[i + 1]);
				res[vl[i]] = coef;
			}
			else {
				nv.push_back(vl[i]);
				res[vl[i + 1]] = coef;
			}
		}
		swap(nv, vl);
		coef = coef / 2 + 1;
	}
	coef = num / 2 + 1;
	tmp = 0;
	while (vr.size() > 1) {
		vector<int> nv;
		for (int i = 0; i < vr.size(); i += 2) {
			bool b = false;
			if (cr & (1 << tmp))b = true; tmp++;
			if (b) {
				nv.push_back(vr[i + 1]);
				res[vr[i]] = coef;
			}
			else {
				nv.push_back(vr[i]);
				res[vr[i + 1]] = coef;
			}
		}
		swap(nv, vr);
		coef = coef / 2 + 1;
	}
	if (id) {
		res[vl[0]] = 1;
		res[vr[0]] = 2;
	}
	else {
		res[vl[0]] = 2;
		res[vr[0]] = 1;
	}
	return res;
}
void solve() {
	int k, a, h; cin >> k >> a >> h;
	int n = (1 << k);
	int ff = n / 2 + 1;
	vector<mp> lmp = mkmap(1, n / 2, a, ff);
	vector<mp> rmp = mkmap(1 + n / 2, n / 2, a, ff);
	rep(i, 2) {
		int ti = i ^ 1;
		for (auto p : lmp[i]) {
			int obj = h - p.first;
			if (obj < 0)obj += mod;
			if (rmp[ti].find(obj) != rmp[ti].end()) {
				vector<int> ans = mkans(n, p.second, rmp[ti][obj], i);
				coutarray(ans);
				return;
			}
		}
	}
	cout << -1 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init_f();
	//init();
	//expr();
	//while(true)
	//int t; cin >> t;rep(i,t)
	solve();
	return 0;
}