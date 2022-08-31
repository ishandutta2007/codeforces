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

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void solve() {
	int n, m, k, s; cin >> n >> m >> k >> s;
	vector<int> a(n), b(n);
	rep(i, n)cin >> a[i]; rep(i, n)cin >> b[i];
	vector<int> v[2];
	vector<P> vp[2];
	rep(i, m) {
		int t; int c; cin >> t >> c; t--;
		v[t].push_back(c);
		vp[t].push_back({ c,i });
	}
	vector<int> mia(n + 1), mib(n + 1);
	mia[0] = mod, mib[0] = mod;
	vector<P> miap(n + 1), mibp(n + 1);
	miap[0] = { mod,-1 }; mibp[0] = { mod,-1 };
	rep(i, n) {
		mia[i + 1] = min(mia[i], a[i]);
		mib[i + 1] = min(mib[i], b[i]);
		miap[i + 1] = min(miap[i], { a[i],i });
		mibp[i + 1] = min(mibp[i], { b[i],i });
	}
	rep(i, 2) {
		sort(all(v[i]));
		sort(all(vp[i]));
	}
	vector<ll>  rv[2];
	rep(i, 2) {
		rv[i].resize(v[i].size() + 1);
		rep(j, v[i].size()) {
			rv[i][j + 1] = rv[i][j] + v[i][j];
		}
	}
	auto can = [&](int x) {
		ll cost[2] = { mia[x],mib[x] };
		rep(i, k + 1) {
			int c[2] = { i,k - i };
			ll sum = 0;
			rep(j, 2) {
				if (c[j] >= rv[j].size())sum = INF;
				else {
					sum += rv[j][c[j]] * cost[j];
				}
			}
			if (sum <= s)return true;
		}
		return false;
	};
	if (!can(n)) {
		cout << -1 << "\n"; return;
	}
	int l = 0, r = n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (can(m))r = m;
		else l = m;
	}
	//r ko
	ll cost[2] = { mia[r],mib[r] };
	int costid[2] = { miap[r].second,mibp[r].second };
	vector<P> ans;
	rep(i, k + 1) {
		int c[2] = { i,k - i };
		ll sum = 0;
		rep(j, 2) {
			if (c[j] >= rv[j].size())sum = INF;
			else {
				sum += rv[j][c[j]] * cost[j];
			}
		}
		if (sum <= s) {
			rep(j, 2) {
				rep(t, c[j]) {
					ans.push_back({ vp[j][t].second,costid[j] });
				}
			}
			break;
		}
	}
	cout << r << "\n";
	for (P p : ans)cout << p.first + 1 << " " << p.second + 1 << "\n";
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