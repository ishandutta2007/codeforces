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

bool isok(int x, int y) {
	string sx = to_string(x);
	string sy = to_string(y);
	rep(i, sx.size() - sy.size() + 1) {
		string u = sx.substr(i, sy.size());
		if (u == sy)return true;
	}
	return false;
}
void expr() {
	/*rep1(x, 42)rep1(y, 42) {
		int g = gcd(x, y);
		if (x / g < 10 && y / g < 10) {
			for (int cx = x/g, cy = y/g; cx < 10 && cy < 10; cx += x/g, cy += y/g) {
				if (isok(x, cx) && isok(y, cy)) {
					ans += 1; break;
				}
			}
		}
	}
	cout << ans << "\n";*/
}

modint dp[105][10][10][2][1 << 8];

void solve() {
	modint ans = 0;
	
	string s; cin >> s;
	reverse(all(s));
	int n = s.size();
	
	rep1(x, 9)Rep1(y, x + 1, 9) {
		int g = gcd(x, y);
		if (g != 1)continue;
		int cx = x, cy = y;
		vector<int> vl, vr;
		while (cx < 10 && cy < 10) {
			vl.push_back(cx);
			vr.push_back(cy);
			cx += x; cy += y;
		}
		vector<int> tl(10, -1), tr(10, -1);
		rep(i, vl.size())tl[vl[i]] = i;
		rep(i, vr.size())tr[vr[i]] = vl.size() + i;
		int sz = 2 * vl.size();
		rep(i, n + 1)rep(j, 10)rep(k, 10)rep(l, 2)rep(m, (1 << sz)) {
			dp[i][j][k][l][m] = 0;
		}
		dp[0][0][0][0][0] = 1;
		rep(i, n){
			int c = s[i] - '0';
			rep(j, 10)rep(k, 10)rep(l, 2)rep(m, (1 << sz)) {
				modint val = dp[i][j][k][l][m];
				if (val == (modint)0)continue;
				rep(ad, 10) {
					int ni = i + 1;
					int nj = (j + ad * x) / 10;
					int nk = (k + ad * y) / 10;
					int rj = (j + ad * x) % 10;
					int rk = (k + ad * y) % 10;
					int nl = l;
					if (rk < c)nl = 0;
					else if (rk == c)nl = l;
					else nl = 1;
					int nm = m;
					if (tl[rj] >= 0)nm |= (1 << tl[rj]);
					if (tr[rk] >= 0)nm |= (1 << tr[rk]);
					dp[ni][nj][nk][nl][nm] += val;
				}
			}
		}
		modint sum = 0;
		rep(m, (1 << sz)) {
			bool valid = false;
			rep(j, vl.size()) {
				int s = (1 << j) + (1 << (j + vl.size()));
				if ((m & s) == s)valid = true;
			}
			if (valid)sum += dp[n][0][0][0][m];
		}
		ans += (modint)2 * sum;
	}

	modint num = 0;
	per(i, n) {
		int c = s[i] - '0';
		num = num * (modint)10 + (modint)c;
	}
	ans += num;
	//cout << num << "\n";
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}