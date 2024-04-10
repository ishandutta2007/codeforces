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
const int max_n = 1 << 2;
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

void solve() {
	int n, m; cin >> n >> m;
	vector<ll> x(n), t(n);
	rep(i, n)cin >> x[i] >> t[i];
	vector<int> p(m), b(m);
	rep(i, m)cin >> p[i] >> b[i];
	vector<P> vp;
	rep(i, m) {
		vp.push_back({ p[i],b[i] });
	}
	sort(all(vp));
	vector<LP> ans(n);
	rep(i, n)ans[i].second = t[i];
	vector<P> pp(n);
	rep(i, n)pp[i] = { x[i],i };
	sort(all(pp));
	set<P> st;

	set<LP> rs;
	int ma = -1;
	rep(i, pp.size()) {
		int id = pp[i].second;
		int r = x[id] + t[id];
		if (ma >= r)continue;
		ma = r;
		rs.insert({ r,id });
	}

	rep(i, m) {
		auto itr = rs.lower_bound({ p[i],-1 });
		if (itr == rs.end()) {
			st.insert({ p[i],i });
		}
		else {
			st.insert({ p[i],i });
			int id = (*itr).second;
			while (true) {
				auto itr2 = st.lower_bound({ x[id],-1 });
				if (itr2 != st.end() && (*itr2).first - x[id] <= t[id]) {
					int ad = b[(*itr2).second];
					ans[id].first++;
					ans[id].second += ad;
					t[id] += ad;
					st.erase(itr2);
				}
				else break;
			}
			ll nr = x[id] + t[id];
			vector<LP> ers;
			while (true) {
				if (itr == rs.end() || (*itr).first > nr)break;
				ers.push_back(*itr);
				itr++;
			}
			for (auto p : ers)rs.erase(p);
			rs.insert({ nr,id });
		}
	}
	/*int loc = 0;
	rep(i, pp.size()) {
		int id = pp[i].second;
		ll len = t[id];
		int cnt = 0;
		while (loc < vp.size() && vp[loc].first < pp[i].first)loc++;
		while (loc < vp.size()) {
			if (vp[loc].first - pp[i].first <= len) {
				cnt++;
				len += vp[loc].second; loc++;
			}
			else break;
		}
		ans[id] = { cnt,len };
	}*/
	rep(i, n)cout << ans[i].first << " " << ans[i].second << "\n";
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