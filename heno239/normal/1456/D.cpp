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

const int max_n = 1 << 17;
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

ll dp2[5002];
bool pre[5002];
void solve() {
	int n; cin >> n;
	vector<ll> t(n), x(n);
	rep(i, n)cin >> t[i] >> x[i];
	rep(i, n)dp2[i] = INF;
	ll le = INF, ri = -INF;
	bool isfin = false;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (abs(x[i]) <= t[i]) {
				dp2[i] = abs(x[i]);
			}
			else {
				isfin = true; break;
			}
			ll lx = min(x[i], 0ll);
			ll rx = max(x[i], 0ll);
			ll dif = t[i] - abs(x[i]);
			le = min(le, lx - dif / 2);
			ri = max(ri, rx + dif / 2);
		}
		else {
			ll nt = t[i - 1] + abs(x[i] - x[i - 1]);
			//cout << i << " " << nt << "\n";
			if (nt <= t[i]) {
				dp2[i] = nt;
			}
			if (le <= x[i] && x[i] <= ri) {
				pre[i] = true;
			}
			if (nt > t[i]) {
				isfin = true; break;
			}
			ll lx = min(x[i], x[i - 1]);
			ll rx = max(x[i], x[i - 1]);
			ll dif = t[i] - nt;
			le = min(le, lx - dif / 2);
			ri = max(ri, rx + dif / 2);
		}
	}
	if (!isfin) {
		cout << "YES\n"; return;
	}
	for (int i = 0; i < n; i++) {
		if (dp2[i] <= t[i]) {
			ll le = INF, ri = -INF;
			bool isfin = false;
			for (int j = i + 1; j < n; j++) {
				if (j == i + 1) {
					ll nt = dp2[i] + abs(x[j] - x[j - 1]);
					if (nt <= t[j]) {
						dp2[j] = min(dp2[j], max(nt, t[j - 1]));
					}
					else {
						isfin = true;
						break;
					}
					ll lx = x[j] - (t[j] - t[j - 1]);
					ll rx = x[j] + (t[j] - t[j - 1]);
					ll lx2 = x[j - 1] - (t[j - 1] - dp2[i]);
					ll rx2 = x[j - 1] + (t[j - 1] - dp2[i]);
					if (lx2 >= lx) {
						lx = lx2 - (lx2 - lx) / 2;
					}
					if (rx2 <= rx) {
						rx = rx2 + (rx - rx2) / 2;
					}
					le = min(le, lx);
					ri = max(ri, rx);
				}
				else {
					ll nt = t[j - 1] + abs(x[j] - x[j - 1]);
					if (nt <= t[j]) {
						dp2[j] = min(dp2[j], nt);
					}
					if (le <= x[j] && x[j] <= ri) {
						pre[j] = true;
					}
					if (nt > t[j]) {
						isfin = true;
						break;
					}
					ll lx = min(x[j], x[j - 1]);
					ll rx = max(x[j], x[j - 1]);
					ll dif = t[j] - nt;
					lx -= dif / 2;
					rx += dif / 2;
					le = min(le, lx);
					ri = max(ri, rx);
				}
			}
			if (!isfin) {
				cout << "YES\n"; return;
			}
		}
		if (pre[i]) {
			ll le = INF, ri = -INF;
			bool isfin = false;
			for (int j = i + 1; j < n; j++) {
				if (j == i + 1) {
					ll nt = t[j-2] + abs(x[j] - x[j-2]);
					if (nt <= t[j]) {
						dp2[j] = min(dp2[j], max(nt, t[j - 1]));
					}
					else {
						isfin = true; break;
					}
					ll lx = x[j] - (t[j] - t[j - 1]);
					ll rx = x[j] + (t[j] - t[j - 1]);
					ll lx2 = x[j - 2] - (t[j - 1] - t[j-2]);
					ll rx2 = x[j - 2] + (t[j - 1] - t[j-2]);
					if (lx2 >= lx) {
						lx = lx2 - (lx2 - lx) / 2;
					}
					if (rx2 <= rx) {
						rx = rx2 + (rx - rx2) / 2;
					}
					le = min(le, lx);
					ri = max(ri, rx);
				}
				else {
					ll nt = t[j - 1] + abs(x[j] - x[j - 1]);
					if (nt <= t[j]) {
						dp2[j] = min(dp2[j], nt);
					}
					if (le <= x[j] && x[j] <= ri) {
						pre[j] = true;
					}
					if (nt > t[j]) {
						isfin = true;
						break;
					}
					ll lx = min(x[j], x[j - 1]);
					ll rx = max(x[j], x[j - 1]);
					ll dif = t[j] - nt;
					lx -= dif / 2;
					rx += dif / 2;
					le = min(le, lx);
					ri = max(ri, rx);
				}
			}
			if (!isfin) {
				cout << "YES\n"; return;
			}
		}
	}
	cout << "NO\n";
	//cout << pre[2] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}