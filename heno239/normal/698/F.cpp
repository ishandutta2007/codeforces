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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
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

const int sup = 1000005;
bool isp[sup];
int trans[sup];
vector<int> ps;
void init() {
	fill(isp + 2, isp + sup, true);
	fill(trans + 1, trans + sup, 1);
	for (int i = 2; i < sup; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		trans[i] *= i;
		for (int j = 2*i; j < sup; j += i) {
			isp[j] = false;
			trans[j] *= i;
		}
	}
}
void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	rep1(i, n)cin >> a[i];
	vector<int> rev(n + 1);
	rep1(i, n)if (a[i] > 0)rev[a[i]] = i;
	bool valid = true;
	int le = -1;
	modint ad = 1;
	vector<int> cc(n + 1);
	rep1(i, n)if (a[i] == 0) {
		cc[trans[i]]++;
	}
	rep1(i, n)ad *= fact[cc[i]];
	rep(i, ps.size()) {
		int p = ps[i];
		if (p * p > n) {
			le = i; break;
		}
		for (int j = p; j <= n; j += p) {
			if (rev[j] > 0) {
				if (rev[j] % p)valid = false;
			}
		}
		for (int j = p; j <= n; j += p) {
			if (a[j] > 0) {
				if (a[j] % p)valid = false;
				while (a[j] % p == 0)a[j] /= p;
			}
		}
	}
	if (!valid) {
		cout << 0 << "\n"; return;
	}
	vector<vector<int>> vs(1001);
	vector<int> cnt(1001);
	auto tra = [&](int x) {
		if (x == 1)return 1;
		else return n / x;
	};
	cnt[1]++;
	if (a[1] > 0) {
		if (tra(a[1]) != 1)valid = false;
		vs[1].push_back(a[1]);
	}
	//cout << "hel\n";
	//cout << valid << "\n";
	for (int i = le; i < ps.size(); i++) {
		int p = ps[i];
		if (p > n)break;
		int loc = n / p;
		cnt[loc]++;
		vector<int> cur;
		for (int j = p; j <= n; j += p) {
			if (a[j] > 0) {
				if (loc != tra(a[j]))valid = false;
				cur.push_back(a[j]);
			}
		}
		sort(all(cur));
		cur.erase(unique(all(cur)), cur.end());
		if (cur.size() >= 2)valid = false;
		if (cur.size())vs[loc].push_back(cur[0]);
	}
	if (!valid) {
		cout << 0 << "\n"; return;
	}
	//cout << "hello\n";
	modint ans = 1;
	rep(i, 1001) {
		if (cnt[i] == 0)continue;
		sort(all(vs[i]));
		int len = vs[i].size();
		vs[i].erase(unique(all(vs[i])), vs[i].end());
		if ((int)vs[i].size() != len) {
			cout << 0 << "\n"; return;
		}
		ans *= fact[cnt[i] - vs[i].size()];
	}
	//cout << ad << " " << ans << "\n";
	ans *= ad;
	cout << ans << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	init_f();
	init();
	//expr();
	//int t; cin >> t;rep(i, t)
	solve();
	return 0;
}