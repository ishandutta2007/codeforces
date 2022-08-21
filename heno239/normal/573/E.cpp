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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
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

struct CHT {
	vector<LP> v;
	vector<LP> memo;
	int l;
	bool check(LP a, LP b, LP c) {
		return (b.first - a.first) * (c.second - b.second) >= (b.second - a.second) * (c.first - b.first);
	}
	//
	void build(vector<LP> a) {
		l = 0;
		//sort(a.begin(),a.end());
		rep(i, (int)a.size()) {
			while (v.size() >= 2 && check(v[v.size() - 2], v[v.size() - 1], a[i]))v.pop_back();
			v.push_back(a[i]);
		}
	}
	//
	void build() {
		rep(i, (int)memo.size()) {
			while (v.size() >= 2 && check(v[v.size() - 2], v[v.size() - 1], memo[i]))v.pop_back();
			v.push_back(memo[i]);
		}
		memo.clear();
	}
	void add(LP a) {
		memo.push_back(a);
	}
	//x
	ll f(LP a, ll x) {
		return a.first * x + a.second;
	}
	ll query(ll x) {
		while (l + 1 < v.size() && f(v[l], x) > f(v[l + 1], x))l++;
		return f(v[l], x);
	}
	void init() {
		v.clear(); l = 0; memo.clear();
	}
};

const int sup = 110000;
const int b = 300;
const int d = (sup + b - 1) / b;

ll ad[d];
int coef[d];
CHT cht[d];
vector<P> v[d];
ll val[d][b];

//maximum value and index
LP query() {
	ll ma = -INF;
	int chk = -1;
	for (int i = 0; i < d; i++) {
		if (v[i].size()) {
			ll val = -cht[i].query(coef[i])+ad[i];
			if (val > ma) {
				ma = val; chk = i;
			}
		}
	}
	ll memo = ma;
	ma = -INF;
	int loc = -1;
	rep(j, v[chk].size()) {
		int ind = v[chk][j].second;
		ll ax = v[chk][j].first;
		ll s = val[chk][ind];
		s += coef[chk] * ax + ad[chk];
		if (ma < s) {
			ma = s;
			loc = ind;
		}
	}
	assert(memo == ma);
	return { ma,loc + b * chk };
}
//delete index k
void del(int k) {
	int chk = k / b;
	int ind = k % b;
	ll memo;
	rep(j, v[chk].size())if (v[chk][j].second == ind) {
		memo = v[chk][j].first;
		v[chk].erase(v[chk].begin() + j); break;
	}
	vector<LP> c(v[chk].size());
	rep(j, v[chk].size()) {
		int i = v[chk][j].second;
		ll ax = v[chk][j].first;
		val[chk][i] += coef[chk] * ax + ad[chk];
		if (i < ind) {
			val[chk][i] += memo;
		}
		else {
			val[chk][i] += ax;
		}
		c[j] = { -v[chk][j].first,-val[chk][i] };
	}
	coef[chk] = ad[chk] = 0;
	cht[chk].init();
	cht[chk].build(c);

	for (int i = 0; i < chk; i++)ad[i] += memo;
	for (int i = chk + 1; i < d; i++)coef[i] += 1;
}

void solve() {
	int n; cin >> n;
	vector<ll> a(n); rep(i, n)cin >> a[i];
	rep(i, n) {
		val[i / b][i % b] = a[i];
	}
	rep(i, d) {
		ad[i] = 0; coef[i] = 0;
		rep(j, b)if (i*b+j<n) {
			v[i].push_back({ a[i * b + j],j });
		}
		sort(all(v[i]));
		vector<LP> c;
		rep(j, v[i].size()) {
			c.push_back({ -v[i][j].first,-val[i][v[i][j].second] });
		}
		cht[i].build(c);
	}
	ll ans = 0;
	ll sum = 0;
	rep(i, n) {
		LP p = query();
		int ind = p.second;
		ll va = p.first;
		sum += va;
		del(ind);
		ans = max(ans, sum);
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}