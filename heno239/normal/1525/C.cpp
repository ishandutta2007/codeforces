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
typedef double ld;
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
const int max_n = 1 << 1;
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
	int n, m; cin >> n >> m;
	vector<int> x(n);
	rep(i, n)cin >> x[i];
	vector<char> c(n);
	rep(i, n)cin >> c[i];
	set<int> st;
	rep(i, n)st.insert(i);
	vector<int> ans(n, -1);
	auto calc = [&](int i, int j) {
		if (x[i] > x[j])swap(i, j);
		int dif = x[j] - x[i];
		if (c[i] == 'R' && c[j] == 'L') {
			return dif / 2;
		}
		else if (c[i] == 'L' && c[j] == 'L') {
			dif += 2 * x[i];
			return dif / 2;
		}
		else if (c[i] == 'R' && c[j] == 'R') {
			dif += 2 * (m - x[j]);
			return dif / 2;
		}
		else {
			dif += 2 * x[i] + 2 * (m - x[j]);
			return dif / 2;
		}
	};
	rep(t, 2) {
		vector<P> vp;
		rep(i, n)if (x[i] % 2 == t) {
			vp.push_back({ x[i],i });
		}
		sort(all(vp));
		vector<int> vs;
		vector<char> cs;
		rep(i, vp.size()) {
			int id = vp[i].second;
			vs.push_back(x[id]);
			cs.push_back(c[id]);
		}
		vector<int> cur;
		rep(i, vp.size()) {
			int id = vp[i].second;
			if (cs[i] == 'L') {
				if (cur.empty()) {
					cur.push_back(id);
				}
				else {
					int las = cur.back(); cur.pop_back();
					ans[las] = ans[id] = calc(las, id);
				}
			}
			else {
				cur.push_back(id);
			}
		}
		while (cur.size() >= 2) {
			int las2 = cur.back(); cur.pop_back();
			int las = cur.back(); cur.pop_back();
			ans[las] = ans[las2] = calc(las, las2);
		}
		if (cur.size()) {
			ans[cur[0]] = -1;
		}
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	int t; cin >> t;rep(i, t)
	solve();
	return 0;
}