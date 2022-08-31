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
	int n; cin >> n;
	ll s; cin >> s;
	if (s == (ll)n * (n + 1) / 2) {
		cout << "Yes\n";
		rep(i, n - 1) {
			if (i > 0)cout << " ";
			cout << i + 1;
		}
		cout << "\n"; return;
	}
	if (s > (ll)n * (n + 1) / 2) {
		cout << "No\n"; return;
	}
	if (s < (ll)2 * n - 1) {
		cout << "No\n"; return;
	}
	function<ll(ll,ll,ll)> calc = [&](ll rest, ll sup,ll num)->ll {
		if (rest == 0)return 0;
		if (sup == 0)return INF;
		ll res = rest;
		ll d = min(rest, sup);
		res += calc(rest - d, min(INF/n,d * num), num);
		return res;
	};
	int le = 1, ri = n;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		if (calc(n, 1, mid) <= s) {
			ri = mid;
		}
		else {
			le = mid;
		}
	}
	ll c = ri;
	vector<ll> cnt(n);
	ll r = n;
	ll sup = 1;
	rep(i, n) {
		if (r == 0)break;
		ll le = 0, ri = min(sup, r) + 1;
		while (ri - le > 1) {
			ll m = (le + ri) / 2;
			ll x = r + calc(r - m, min(INF/n, m * c), c);
			//cout << i << " " << m << " " << x << "\n";
			if (x <= s) {
				ri = m;
			}
			else {
				le = m;
			}
		}
		s -= r;
		cnt[i] = ri;
		r -= ri;
		sup = min(INF, ri * c);
		//cout << i << " " << ri << "\n";
	}
	int tmp = 1;
	vector<int> ans(n);
	vector<vector<int>> ids(n);
	ids[0].push_back(0);
	rep1(i, n - 1) {
		rep(j, cnt[i]) {
			ans[tmp] = ids[i - 1][j / c]; 
			ids[i].push_back(tmp);
			tmp++;
		}
	}
	cout << "Yes\n";
	rep1(i, n - 1) {
		if (i > 1)cout << " ";
		cout << ans[i]+1;
	}
	cout << "\n";
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