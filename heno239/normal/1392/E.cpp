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
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
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
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m) {
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

int mex(vector<int> v) {
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	rep(i, v.size())if (i != v[i])return i;
	return v.size();
}
ll a[25][25];
void solve() {
	int n; cin >> n;
	rep(i, n)rep(j, n)a[i][j] = 0;
	rep1(j, n - 1) {
		a[0][j] = 1LL << (j - 1);
	}
	rep1(i, n - 1) {
		per(j, n - 1) {
			vector<int> v;
			rep(k, j)v.push_back(1);
			rep(k, i)v.push_back(0);
			rep(k, n - 1 - j)v.push_back(1);
			rep(k, n - 1 - i)v.push_back(0);
			ll sum = 0;
			ll x = 0;
			int cx = 0, cy = 0;
			rep(k, v.size()) {
				if (v[k]) {
					x += ((1ll << k));
					cy++;
				}
				else {
					cx++;
				}
				sum += a[cx][cy];
			}
			a[i][j] = x - sum;
		}
	}
	rep(i, n) {
		rep(j, n) {
			if (j > 0)cout << " ";
			cout << a[i][j];
		}
		cout << endl;
	}
	int q; cin >> q;
	rep(i, q) {
		ll z; cin >> z;
		int cx = 1, cy = 1;
		vector<P> ans;
		ans.push_back({ 1,1 });
		rep(j, 2 * (n - 1)) {
			if (z & (1ll << j)) {
				cy++;
			}
			else {
				cx++;
			}
			ans.push_back({ cx,cy });
		}
		rep(i, ans.size()) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
}




signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}