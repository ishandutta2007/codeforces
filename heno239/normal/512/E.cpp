#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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
constexpr ll mod = 1000000009;
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


vector<pair<P, P>> calc(vector<P> es) {
	int n = es.size() + 3;
	vector<vector<bool>> exi(n, vector<bool>(n, false));
	for (P p : es) {
		exi[p.first][p.second] = exi[p.second][p.first] = true;
	}
	rep(i, n) {
		int ni = i + 1; if (ni == n)ni = 0;
		exi[i][ni] = exi[ni][i] = true;
	}
	vector<pair<P, P>> res;
	while (true) {
		vector<int> vs;
		for (int i = 1; i < n; i++)if (exi[0][i])vs.push_back(i);
		int chk = -1;
		for (int j = 0; j < (int)vs.size() - 1; j++) {
			if (vs[j + 1] != vs[j] + 1) {
				chk = j; break;
			}
		}
		if (chk < 0)break;
		assert(exi[vs[chk]][vs[chk + 1]]);
		int las = vs[chk + 1] - 1;
		while (!exi[vs[chk]][las])las--;
		res.push_back({ {vs[chk],vs[chk + 1]},{0,las} });
		exi[vs[chk]][vs[chk + 1]] = exi[vs[chk + 1]][vs[chk]] = false;
		exi[0][las] = exi[las][0] = true;
	}
	return res;
}


void solve() {
	int n; cin >> n;
	vector<P> e1, e2;
	rep(i, n - 3) {
		int a, b; cin >> a >> b; a--; b--;
		e1.push_back({ a,b });
	}
	rep(i, n - 3) {
		int a, b; cin >> a >> b; a--; b--;
		e2.push_back({ a,b });
	}
	vector<P> ans;
	vector<pair<P, P>> o1 = calc(e1);
	vector<pair<P, P>> o2 = calc(e2);
	rep(i, o1.size()) {
		ans.push_back(o1[i].first);
	}
	per(i, (int)o2.size()) {
		ans.push_back(o2[i].second);
	}
	cout << ans.size() << "\n";
	for (P p : ans) {
		cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}