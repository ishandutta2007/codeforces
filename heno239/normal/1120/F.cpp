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

struct CHT {
	vector<LP> v;
	int l=0;
	bool check(LP a, LP b, LP c) {
		return (b.first - a.first) * (c.second - b.second) >= (b.second - a.second) * (c.first - b.first);
	}
	//
	void build(vector<LP> a) {
		l = 0;
		sort(a.begin(), a.end());
		per(i, (int)a.size()) {
			while (v.size() >= 2 && check(v[v.size() - 2], v[v.size() - 1], a[i]))v.pop_back();
			v.push_back(a[i]);
		}
	}
	void add(LP a) {
		while (v.size() >= 2 && check(v[v.size() - 2], v[v.size() - 1], a))v.pop_back();
		v.push_back(a);
		l = min(l, (int)v.size() - 1);
	}
	//x
	ll f(LP a, ll x) {
		return a.first * x + a.second;
	}
	ll query(ll x) {
		if (l >= v.size())return 2 * INF;
		while (l + 1 < v.size() && f(v[l], x) > f(v[l + 1], x))l++;
		return f(v[l], x);
	}
};

int trans(char c) {
	return c == 'P' ? 0 : 1;
}
ll cnt[1 << 17][2];
ll rcnt[1 << 17][2];
ll mi[1 << 17][2];
void solve() {
	int n; ll c, d; cin >> n >> c >> d;
	vector<ll> t(n + 1);
	vector<char> p(n);
	rep(i, n)cin >> t[i] >> p[i]; cin >> t[n];
	rep(i, n) {
		rep(j, 2) {
			cnt[i + 1][j] = cnt[i][j];
			rcnt[i + 1][j] = rcnt[i][j];
		}
		int id = trans(p[i]);
		cnt[i + 1][id] += 1;
		rcnt[i + 1][id] += t[i];
	}
	CHT cht[2];
	rep(j, 2)mi[0][j] = 2*INF;
	rep(i, n) {
		int id = trans(p[i]);
		ll cur = i * d;
		//only c
		ll x = t[i];
		ll val = cht[id ^ 1].query(x);
		val += c*x * cnt[i][id^1] - c*rcnt[i][id^1] + cnt[i][id]*d;
		cur = min(cur, val);
		//with d
		int loc = lower_bound(all(t), t[i] - d / c)- t.begin();
		//[0,loc)
		val = 0;
		val += mi[loc][id ^ 1];
		val += d * cnt[i][id] + x*c + x * c * (cnt[i][id ^ 1] - cnt[loc][id ^ 1]) - c * (rcnt[i][id ^ 1] - rcnt[loc][id ^ 1]) + d * cnt[loc][id ^ 1];
		cur = min(cur, val);
		
		//dp[i]=cur
		//update cht
		ll cop = 0;
		cop = cur - d * cnt[i][id ^ 1]+c*rcnt[i][id];
		ll coef = -cnt[i][id] * c;
		cht[id].add({ coef,cop });
		//update mi
		rep(j, 2) {
			mi[i + 1][j] = mi[i][j];
		}
		cop = cur - d * cnt[i][id ^ 1] - x*c - d * cnt[i + 1][id];
		chmin(mi[i + 1][id], cop);

		//cout << i << " " << cur << "\n";
	}
	ll ans = n * d;
	rep(id, 2) {
		int i = n;
		ll cur = 2*INF;
		//only c
		ll x = t[i];
		ll val = cht[id ^ 1].query(x);
		val += c * x * cnt[i][id ^ 1] - c * rcnt[i][id ^ 1] + cnt[i][id] * d;
		cur = min(cur, val);
		//cout << "? " << id << " " << cur << "\n";
		//with d
		int loc = lower_bound(all(t), t[i] - d / c) - t.begin();
		//[0,loc)
		val = 0;
		val += mi[loc][id ^ 1];
		val += d * cnt[i][id] + x*c + x * c * (cnt[i][id ^ 1] - cnt[loc][id ^ 1]) - c * (rcnt[i][id ^ 1] - rcnt[loc][id ^ 1]) + d * cnt[loc][id ^ 1];
		cur = min(cur, val);
		
		ans = min(ans, cur);
		//cout << "? " << id << " " << cur << "\n";
	}
	cout << ans << "\n";
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