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
struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
void solve() {
	int n; cin >> n;
	vector<int> x(n), y(n), a(n);
	rep(i, n) {
		cin >> x[i] >> y[i] >> a[i]; a[i]--;
	}
	int chk = -1;
	rep(i, n) {
		if (a[i] != i) {
			chk = i;
		}
	}
	if (chk < 0) {
		cout << 0 << "\n";
		return;
	}
	vector<int> trans(n);
	vector<bool> used(n);
	int tmp = 0;
	rep(i, n)if (!used[i]) {
		vector<int> ids;
		int cur = i;
		used[cur] = true; ids.push_back(cur);
		cur = a[cur];
		while (cur != i) {
			ids.push_back(cur); used[cur] = true;
			cur = a[cur];
		}
		for (int id : ids)trans[id] = tmp;
		tmp++;
	}
	uf u(tmp);
	vector<pair<ld, int>> vp;
	rep(i, n) {
		if (i != chk) {
			int dx = x[i] - x[chk];
			int dy = y[i] - y[chk];
			ld t = atan2l(dy, dx);
			vp.push_back({ t,i });
		}
	}
	//cout << "! " << chk << "\n";
	sort(all(vp));
	ld ma = -1;
	int loc = -1;
	rep(i, vp.size()) {
		int ni = (i + 1) % vp.size();
		ld dt = vp[ni].first - vp[i].first;
		if (ni == 0)dt += 2 * pi;
		if (ma < dt) {
			ma = dt; loc = ni;
		}
	}
	rep(j, loc) {
		vp.push_back(vp[j]);
	}
	vp.erase(vp.begin(), vp.begin() + loc);
	vector<P> ans;
	rep(i, vp.size()-1) {
		int le = vp[i].second;
		int ri = vp[i + 1].second;
		if (!u.same(trans[le], trans[ri])) {
			ans.push_back({ le,ri });
			swap(a[le], a[ri]);
			u.unite(trans[le], trans[ri]);
		}
	}
	//rep(i, n)cout << a[i] << "\n";
	int cur = a[chk];
	vector<P> adp;
	rep(i, n - 1) {
		//cout << "?! " << cur << "\n";
		assert(cur != chk);
		ans.push_back({ chk,cur });
		adp.push_back({ chk,cur });
		cur = a[cur];
	}
	for (P p : adp) {
		swap(a[p.first], a[p.second]);
	}
	rep(i, n)assert(a[i] == i);
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";

	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	solve();
	return 0;
}