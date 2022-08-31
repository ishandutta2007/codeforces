
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

vector<int> merge(vector<int> a, vector<int> b) {
	int ida = 0, idb = 0;
	vector<int> res;
	while (ida < a.size() || idb < b.size()) {
		if (idb == b.size()) {
			res.push_back(a[ida]); ida++;
		}
		else if (ida == a.size()) {
			res.push_back(b[idb]); idb++;
		}
		else {
			if (a[ida] < b[idb]) {
				res.push_back(a[ida]); ida++;
			}
			else {
				res.push_back(b[idb]); idb++;
			}
		}
	}
	return res;
}
void solve() {
	int n, c; cin >> n >> c;
	vector<int> p(n), s(n);
	rep(i, n)cin >> p[i];
	rep(i, n)cin >> s[i];
	ll ans = 0;
	vector<int> b(n);
	rep(i, n) {
		ans += min(p[i], s[i]);
		b[i] = p[i]-s[i];
	}
	vector<int> cur;
	auto add = [&](ll val) {
		ll ad = 0;
		rep(i, cur.size()) {
			ad += min(cur[i], c);
		}
		if (val + ad <= 0) {
			ans += ad;
			rep(i, cur.size()) {
				int m = min(cur[i], c);
				cur[i] -= m;
			}
			return;
		}
		if (cur.empty()) {
			cur.push_back(val); return;
		}
		if (cur.back() <= val) {
			cur.push_back(val); return;
		}
		if (val < 0)ans += -val;
		vector<ll> rcur(cur.size() + 1);
		rep(i, cur.size())rcur[i + 1] = rcur[i] + cur[i];
		int le = -1, ri = cur.back() + 1;
		while (ri - le > 1) {
			int m = (le + ri) / 2;
			ll ad = 0;
			int id1 = lower_bound(all(cur), m) - cur.begin();
			int id2 = lower_bound(all(cur), m + c) - cur.begin();
			ad += rcur[id2] - rcur[id1] - (ll)m * (id2 - id1);
			ad += (ll)(cur.size() - id2) * c;
			if (ad + val >= m) {
				le = m;
			}
			else {
				ri = m;
			}
		}
		int m = le;
		ad = 0;
		int id1 = lower_bound(all(cur), m) - cur.begin();
		int id2 = lower_bound(all(cur), m + c) - cur.begin();
		ad += rcur[id2] - rcur[id1] - (ll)m * (id2 - id1);
		ad += (ll)(cur.size() - id2) * c;
		vector<int> v1, v2, v3;
		rep(i, id1)v1.push_back(cur[i]);
		Rep(i, id1, id2)v1.push_back(m);
		Rep(i, id2, cur.size()) {
			v1.push_back(cur[i]-c);
		}
		v3.push_back(ad + val);
		ll dif = ad + val - m; dif--; if (dif < 0)dif = 0;
		rep(i, dif) {
			v3[0]--;
			v2.push_back(v1[id1 + i] + 1);
		}
		if (dif > 0) {
			v1.erase(v1.begin() + id1, v1.begin() + id1 + dif);
		}
		cur = merge(v1, v2);
		cur = merge(cur, v3);
		//sort(all(cur));
	};
	rep(i, n) {
		add(b[i]);
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
	//int t; cin >> t;rep(i, t)
	solve();
	return 0;
}