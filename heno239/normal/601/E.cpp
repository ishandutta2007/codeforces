#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

int sz = (1 << 15);
vector<P> node[1 << 16];
int dp[(1 << 15) - 1 + 30000][1001];
void add(int a, int b, P x, int k = 0, int l = 0, int r = sz) {
	if (l >= b || r <= a)return;
	if (a <= l && r <= b) {
		node[k].push_back(x);
	}
	else {
		add(a, b, x, 2 * k + 1, l, (l + r) / 2);
		add(a, b, x, 2 * k + 2, (l + r) / 2, r);
	}
}
int k, q;
void complete() {
	//cout << "? "<< q << "\n";
	rep(i, (1 << 15) - 1 + q) {
		if (i > 0) {
			rep(j, 1001)dp[i][j] = dp[(i - 1) / 2][j];
		}
		for (P p : node[i]) {
			//cout << i << " " << p.first << " " << p.second << "\n";
			per(j, 1001) {
				if (j + p.first <= 1000) {
					dp[i][j + p.first] = max(dp[i][j + p.first], dp[i][j] + p.second);
				}
			}
		}
	}
}
void solve() {
	int n; cin >> n >> k;
	vector<P> wv(n);
	rep(i, n) {
		cin >> wv[i].second >> wv[i].first;
	}
	cin >> q;
	vector<int> le(n + q), ri(n + q, q);
	wv.resize(n + q, { 0,0 });
	vector<bool> bans(q);
	vector<int> trans(n + q);
	rep(i, n)trans[i] = i;
	int tmp = 0;
	rep(i, q) {
		int typ; cin >> typ;
		if (typ == 1) {
			int v, w; cin >> v >> w;
			wv[i + n] = { w,v };
			le[i + n] = i;
			trans[n + tmp] = i + n; tmp++;
		}
		else if (typ == 2) {
			int x; cin >> x; x--;
			x = trans[x];
			ri[x] = i;
		}
		else {
			bans[i] = true;
		}
	}
	rep(i, n + q) {
		if (wv[i] != P{ 0, 0 }) {
			//cout << "?? " << le[i] << " " << ri[i] << "\n";
			//cout << "? " << i << " " << wv[i].first<<" "<<wv[i].second << "\n";
			add(le[i], ri[i], wv[i]);
		}
	}
	complete();
	rep(i, q)if (bans[i]) {
		ll p = 10000019;
		modint t = 1;
		modint ans = 0;
		for (int m = 1; m <= k; m++) {
			//cout << "?? " << dp[(1 << 15) - 1 + i][m] << "\n";
			ans += (modint)dp[(1 << 15) - 1 + i][m] * t;
			t *= p;
		}
		cout << ans << "\n";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i,t)
	solve();
	return 0;
}