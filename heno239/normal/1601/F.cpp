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

const ll mm = 998244353;
ll solvetle(ll n) {
	vector<string> s(n);
	rep(i, n)s[i] = to_string(i+1);
	sort(all(s));
	modint ans = 0;
	//modint cc[4] = {};
	rep(i, n) {
		ll val = i + 1 - stoi(s[i]);
		if (val < 0)val += mm;
		ans += val;
		//cc[s[i].size()] += val;
	}
	//rep1(i, 3)cout << "! " << cc[i] << "\n";
	return ans;
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

ll n;
int len;
ll t10[14];
void ad1(ll &x, modint& ans,ll& cur,bool isadd) {
	if(isadd)ans += cur;
	int sz = to_string(x).size();
	ll num = 0;
	for (int ad = 1; sz + ad <= len; ad++) {
		ll le = x * t10[ad];
		ll ri = (x + 1) * t10[ad]; ri = min(ri, n + 1);
		//[le,ri)
		if (le < ri)num += ri - le;
	}
	ll cop = x;
	while (cop % 10 == 9) {
		num++; cop /= 10;
	}
	//if (x == 19)cout << "/ " << num << "\n";
	cur += num;
	cur %= mm;
	x++;
}

ll ad[14][13][2];
modint val[14][13][2];
void init() {
	t10[0] = 1;
	rep(i, 13)t10[i + 1] = t10[i] * 10;
	for (int c = 1; c <= len; c++) {
		ll x = 0;
		for (int y = len - c; y >= 0; y--) {
			x += t10[y];
		}
		x--;
		//cout << c << " " << x <<" "<<t10[len-c]<< "\n";
		ad[c][1][0] = 9 * x;
		val[c][1][0] = 45 * x;
		for (int i = 2; i < len; i++) {
			ll adc = 0;
			rep(j, 10) {
				val[c][i][0] += (modint)adc * (modint)t10[i - 1]+val[c][i-1][0];
				adc += ad[c][i - 1][0];
				if (j == 9)ad[c][i][0] = adc;
				//+1
				adc += i - 1;
				adc +=x;
			}
		}
		if (c < len) {
			ll x = 0;
			for (int y = len - c-1; y >= 0; y--) {
				x += t10[y];
			}
			x--;
			ad[c][1][1] = 9 * x;
			val[c][1][1] = 45 *x;
			for (int i = 2; i < len; i++) {
				ll adc = 0;
				rep(j, 10) {
					val[c][i][1] += (modint)adc * (modint)t10[i - 1] + val[c][i - 1][1];
					adc += ad[c][i - 1][1];
					if (j == 9)ad[c][i][1] = adc;
					//+1
					adc += i - 1;
					adc += x;
				}
			}
		}
	}
}
void solve() {
	cin >> n;
	len = to_string(n).size();
	init();
	modint ans = 0;
	for (int c = 1; c <= len; c++) {
		ll le = t10[c - 1];
		ll ri = t10[c];
		ri = min(ri, n + 1);
		modint sum = 0;
		ll cur = c - le; cur %= mm; if (cur < 0)cur += mm;
		while (le < ri) {
			bool upd = false;
			for (int cc = len - 1; cc > 0; cc--) {
				bool valid = true;
				if (le % t10[cc])valid = false;
				ll cl = le * t10[len - c];
				ll cr = (le + t10[cc]) * t10[len - c];
				if (cl <= n && n < cr - 1)valid = false;
				int ste = 0;
				if (n < cl)ste = 1;
				if (ad[c][cc][ste] + cur >= mm)valid = false;
				if (le + t10[cc] > ri)valid = false;
				if (valid) {
					//cout << le << " wow " << ste << "\n";
					//cout << cur << "\n";
					//cout << val[c][cc][ste] << " " << ad[c][cc][ste] << "\n";
					sum += (modint)t10[cc] * (modint)cur;
					sum += val[c][cc][ste];
					cur += ad[c][cc][ste];
					le += t10[cc] - 1;
					//cout << le<<" "<<cur<<" "<<sum << "\n";
					ad1(le, sum, cur, false);
					upd = true;
					break;
				}
			}
			if (!upd) {
				ad1(le, sum, cur, true);
			}
			//cout << le << " " << cur << "\n";
		}
		//cout << sum << "\n";
		//cout << "? " << sum << "\n";
		ans += sum;
	}
	cout << ans << "\n";
	//cout << solvetle(n) << "\n";


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