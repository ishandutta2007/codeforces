#pragma GCC target("avx2")
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
constexpr ll mod = 100000008;
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
const int max_n = 100;
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
	int n; cin >> n;
	vector<int> a(n), b(n), c(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	rep(i, n)cin >> c[i];
	vector<int> v;
	for (int val : a)v.push_back(val);
	for (int val : b)v.push_back(val);
	for (int val : c)v.push_back(val);
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	vector<int> la(v.size(),mod);
	vector<int> lb(v.size(),mod);
	vector<int> lc(v.size(),mod);
	rep(i, a.size()) {
		int id = lower_bound(all(v), a[i]) - v.begin();
		la[id] = min(la[id],i + 1);
	}
	rep(i, b.size()) {
		int id = lower_bound(all(v), b[i]) - v.begin();
		lb[id] = min(lb[id], i + 1);
	}
	rep(i, c.size()) {
		int id = lower_bound(all(v), c[i]) - v.begin();
		lc[id] = min(lc[id], i + 1);
	}
	int ra = 0, rb = 0, rc = 0;
	rep(i, v.size()) {
		if (lb[i] == mod && lc[i] == mod) {
			ra = max(ra, la[i]);
		}
		if (la[i] == mod && lc[i] == mod) {
			rb = max(rb, lb[i]);
		}
		if (la[i] == mod && lb[i] == mod) {
			rc = max(rc, lc[i]);
		}
	}

	set<P> st;
	multiset<int> stval;
	st.insert({ 0,2*mod });
	st.insert({ 2*mod,0 });
	stval.insert(0);
	//x->b,y->c
	auto add = [&](int x, int y) {
		P p = { x,-1 };
		st.insert(p);
		auto itr = st.find(p);
		itr++;
		P nex = *itr;
		st.erase(p);
		if (nex.first == x) {
			if (nex.second >= y)return;
			else {
				st.insert({ x,y });
				itr = st.find({ x,y });
				st.erase(nex);
				itr--;
				int val = (*itr).first + nex.second;
				stval.erase(stval.find(val));
				while (true) {
					if ((*itr).second <= y) {
						P mem = *itr;
						itr--;
						st.erase(mem);
						int val = (*itr).first + mem.second;
						stval.erase(stval.find(val));
					}
					else break;
				}
				val = (*itr).first + y;
				stval.insert(val);
			}
		}
		else {
			if (nex.second >= y)return;
			itr--;
			int val = (*itr).first + nex.second;
			stval.erase(stval.find(val));
			st.insert({ x,y });
			val = x + nex.second;
			stval.insert(val);
			while (true) {
				if ((*itr).second <= y) {
					P mem = *itr;
					itr--;
					st.erase(mem);
					int val = (*itr).first + mem.second;
					stval.erase(stval.find(val));
				}
				else break;
			}
			val = (*itr).first + y;
			stval.insert(val);
		}
	};

	vector<vector<P>> adbc(n-ra + 1);
	vector<vector<int>> adb(n - ra+1);
	vector<vector<int>> adc(n - ra + 1);
	rep(i, v.size()) {
		if (la[i] <= ra || lb[i] <= rb || lc[i] <= rc)continue;
		if (lc[i] == mod) {
			adb[la[i] - ra].push_back(lb[i] - rb);
		}
		else if (lb[i] == mod) {
			adc[la[i] - ra].push_back(lc[i] - rc);
		}
		else if (la[i] == mod) {
			add(lb[i] - rb, lc[i] - rc);
		}
		else {
			adbc[la[i] - ra].push_back({ lb[i] - rb,lc[i] - rc });
		}
	}
	int ans = 3 * n;
	for (int i = n-ra; i >= 0; i--) {
		int cost = ra + rb + rc + i + *stval.begin();
		ans = min(ans, cost);
		for (P p : adbc[i]) {
			add(p.first, p.second);
		}
		for (int valb : adb[i]) {
			add(valb, mod);
		}
		for (int valc : adc[i]) {
			add(mod,valc);
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}