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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<ll> a(n), b(n), c(n);
	rep(i, n) {
		cin >> a[i] >> b[i] >> c[i]; c[i] *= -1;
	}
	auto isparallel = [&](int i, int j) {
		return a[i] * b[j] == a[j] * b[i];
	};
	auto ist = [&](int i, int j, int k)->bool {
		if (a[i] == 0)swap(i, k);
		if (a[j] == 0)swap(j, k);
		//cout << i << " " << j << " " << k << "\n";
		if (a[k] != 0) {
			ll x1 = b[j] * a[i] * a[k] - b[i] * a[j] * a[k];
			ll y1 = c[j] * a[i] * a[k] - c[i] * a[j] * a[k];
			ll x2 = b[k] * a[i] * a[j] - b[i] * a[j] * a[k];
			ll y2 = c[k] * a[i] * a[j] - c[i] * a[j] * a[k];
			
			__int128 z1 = __int128(x1) * __int128(y2);
			__int128 z2 = __int128(x2) * __int128(y1);
			return z1 == z2;
		}
		else {
			ll x1 = b[j] * a[i] - b[i] * a[j];
			ll y1 = c[j] * a[i] - c[i] * a[j];
			ll x2 = b[k]; ll y2 = c[k];
			__int128 z1 = __int128(x1) * __int128(y2);
			__int128 z2 = __int128(x2) * __int128(y1);
			return z1 == z2;
			
		}
	};
	mt19937 mt(time(0));
	vector<vector<int>> ans;
	map<vector<int>, bool> chked[6];
	function<bool(vector<int>, int)> can = [&](vector<int> v, int c)->bool {
		if (c >= v.size()) {
			rep(i, v.size()) {
				ans.push_back({ v[i] });
			}
			return true;
		}
		if (chked[c][v])return false;
		chked[c][v] = true;
		int d = (v.size() + c - 1) / c;
		uniform_int_distribution<> ud(0, v.size() - 1);
		rep(aa, 25) {
			int l = ud(mt), r = ud(mt);
			while (l == r)r = ud(mt);
			if (isparallel(l, r))continue;
			vector<int> ids;
			vector<int> rests;
			rep(i, v.size()) {
				if (i == l || i == r) {
					ids.push_back(v[i]);
				}
				else {
					if (!isparallel(i, l) && !isparallel(i, r) && ist(v[i], v[l], v[r])) {
						ids.push_back(v[i]);
					}
					else {
						rests.push_back(v[i]);
					}
				}
			}
			if (ids.size() >= d) {
				if (can(rests, c - 1)) {
					ans.push_back(ids); return true;
				}
			}
		}
		return false;
	};
	vector<int> ori(n); rep(i, n)ori[i] = i;
	if (can(ori, k)) {
		cout << "YES\n";
		cout << ans.size() << "\n";
		rep(i, ans.size()) {
			if (ans[i].size() == 1) {
				cout << ans[i][0] + 1 << " " << -1 << "\n";
			}
			else {
				cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << "\n";
			}
		}
	}
	else {
		cout << "NO\n";
	}
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