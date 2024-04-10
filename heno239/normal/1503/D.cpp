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
constexpr ll mod = 998244353;
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
const ld eps = 1e-6;
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
const int max_n = 1 << 21;
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

ll calc(vector<P> v) {
	if (v.size() <= 1)return 0;
	int loc = 0;
	int ma = v[0].first + v[0].second;
	ll res = 0;
	while (loc < v.size()) {
		while (loc < v.size() && v[loc].first <= ma) {
			ma = max(ma, v[loc].first + v[loc].second);
			loc++;
		}
		if (loc < v.size()) {
			res += v[loc].first - ma;
			ma = max(ma, v[loc].first + v[loc].second);
			loc++;
		}
	}
	return res;
}
void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	rep(i, n)cin >> a[i] >> b[i];
	int cnt = 0;
	vector<int> loc(2 * n + 1);
	rep(i, n) {
		loc[a[i]] = loc[b[i]] = i;
	}
	vector<bool> used(n);
	vector<int> omote(n+2);
	omote[0] = 0;
	omote[n + 1] = 2 * n + 1;

	
	vector<int> szs;
	vector<int> ads;
	//[le,ri)
	int le = 1, ri = n+1;
	while (le < ri) {
		szs.push_back(ri - le);
		int cnt = 0;

		int nex = n - (ri - le) + 1;
		queue<P> ql, qr;
		int sloc = loc[nex];
		if (used[sloc]) {
			cout << -1 << "\n"; return;
		}
		qr.push({ nex,sloc });
		used[sloc] = true;
		while (ql.size() || qr.size()) {
			if (qr.size()) {
				P p = qr.front(); qr.pop();
				int id = p.second;
				int val = a[id];
				if (b[id] != p.first) {
					cnt++; val = b[id];
				}
				omote[ri - 1] = val;
				if (omote[ri - 1] >= omote[ri]) {
					cout << -1 << "\n"; return;
				}
				for (int i = omote[ri]-1; i >omote[ri-1]; i--) {
					if (!used[loc[i]]) {
						ql.push({ i,loc[i] });
						used[loc[i]] = true;
					}
				}
				ri--;
			}
			else {
				P p = ql.front(); ql.pop();
				int id = p.second;
				int val = a[id];
				if (b[id] != p.first) {
					cnt++; val = b[id];
				}
				omote[le] = val;
				if (omote[le - 1] >= omote[le]) {
					cout << -1 << "\n"; return;
				}
				for (int i = omote[le - 1] + 1; i < omote[le]; i++) {
					if (!used[loc[i]]) {
						qr.push({ i,loc[i] });
						used[loc[i]] = true;
					}
				}
				le++;
			}
		}
		ads.push_back(cnt);
	}
	rep(i, omote.size() - 1) {
		if (omote[i] > omote[i + 1]) {
			cout << -1 << "\n"; return;
		}
	}
	int pre = 0;
	int ans = 0;
	per(i, ads.size()) {
		//cout << ads[i] << " " << szs[i] << "\n";
		int dif = szs[i] - pre;
		ans += min(dif - ads[i], ads[i]);
		pre = szs[i];
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