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
void coutarray(vector<T> &v) {
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
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct CHT {
	vector<LP> v;
	vector<LP> memo;
	int l = 0;
	bool check(LP a, LP b, LP c) {
		//return __int128(b.first - a.first) * __int128(c.second - b.second) >= __int128(b.second - a.second) * __int128(c.first - b.first);
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
	//
	void build() {
		sort(all(memo));
		per(i, (int)memo.size()) {
			while (v.size() >= 2 && check(v[v.size() - 2], v[v.size() - 1], memo[i]))v.pop_back();
			v.push_back(memo[i]);
		}
		memo.clear();
	}
	void subadd(LP a) {
		memo.push_back(a);
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
		while (l + 1 < v.size() && f(v[l], x) > f(v[l + 1], x))l++;
		return f(v[l], x);
	}
};

CHT cht[1 << 20];
vector<P> vq[1 << 20];
int sz = 1 << 19;
ll ans[1 << 19];
void add(LP val,int a, int b, int k = 0, int l = 0, int r = -1) {
	if (r < 0)r = sz;
	if (r <= a || b <= l)return;
	else if (a <= l && r <= b) {
		cht[k].subadd(val);
	}
	else {
		add(val,a, b, k * 2 + 1, l, (l + r) / 2);
		add(val,a, b, k * 2 + 2, (l + r) / 2, r);
	}
}
void addquery(int i, int x) {
	int k = i + sz - 1;
	vq[k].push_back({ x,i });
	while (k > 0) {
		k = (k - 1) / 2;
		vq[k].push_back({ x,i });
	}
}
void complete() {
	rep(i, 2 * sz - 1) {
		if (cht[i].memo.empty())continue;
		sort(all(vq[i]));
		cht[i].build();
		rep(j, vq[i].size()) {
			int id = vq[i][j].second;
			ans[id] = min(ans[id], cht[i].query(vq[i][j].first));
		}
	}
}

void solve() {
	int n; cin >> n;
	rep(i, n)ans[i] = 3 * INF;
	vector<int> typ(n);
	vector<int> ri(n,n);
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> typ[i];
		if (typ[i] == 1) {
			cin >> a[i] >> b[i];
			a[i] *= -1; b[i] *= -1;
		}
		else if (typ[i] == 2) {
			int id; cin >> id; id--;
			ri[id] = i;
		}
		else {
			cin >> a[i];
		}
	}
	rep(i, n) {
		if (typ[i] == 1) {
			add({ a[i],b[i] }, i, ri[i]);
		}
		else if (typ[i] == 3) {
			addquery(i, a[i]);
		}
	}
	complete();
	rep(i, n) {
		if (typ[i] == 3) {
			if (ans[i] == 3 * INF) {
				cout << "EMPTY SET" << "\n";
			}
			else {
				cout << -ans[i] << "\n";
			}
		}
	}
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