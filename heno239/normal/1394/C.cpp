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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

int calc(int x1, int y1, int x2, int y2) {
	if (x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	if (y1 <= y2)return max(x2 - x1, y2 - y1);
	else return x2 - x1 + y1 - y2;
}
bool valid(int x, int y) {
	if (x < 0 || y < 0)return false;
	if (x == 0 && y == 0)return false;
	return true;
}
void solve() {
	int n; cin >> n;
	vector<int> x(n),y(n);
	rep(i, n) {
		string s; cin >> s;
		int c1 = 0, c2 = 0;
		for (char c : s) {
			if (c == 'B')c1++;
			else c2++;
		}
		x[i] = c1, y[i] = c2;
	}
	//x
	int lx = -1, rx = 500001;
	int ans = mod;
	int ansx, ansy;
	while (rx - lx > 1) {
		int mx = (lx + rx) / 2;
		int ly = -1, ry = 500001;

		int mma = mod;
		int py;
		while (ry - ly > 1) {
			int my = (ly + ry) / 2;
			int cx = mx,cy= my;
			int clma = 0, crma = 0;
			//cout << cx << " " << cy << "\n";
			rep(i, n) {
				if (cy>=y[i]) {
					clma = max(clma, calc(cx, cy, x[i], y[i]));
				}
				else {
					crma = max(crma, calc(cx, cy, x[i], y[i]));
				}
			}
			if (ans > max(clma, crma) && valid(cx, cy)) {
				ans = max(clma, crma);
				ansx = cx, ansy = cy;
			}
			if (mma > max(clma, crma)) {
				mma = max(clma, crma);
				py = my;
			}
			if (clma > crma) {
				ry = my;
			}
			else {
				ly = my;
			}
		}
		int clma = 0, crma = 0;
		int cx = mx, cy = py;
		rep(i, n) {
			if (cx>=x[i]) {
				clma = max(clma, calc(cx, cy, x[i], y[i]));
			}
			else {
				crma = max(crma, calc(cx, cy, x[i], y[i]));
			}
		}
		if (clma > crma) {
			rx = mx;
		}
		else {
			lx = mx;
		}
		//cout << mx << " " << clma << " " << crma << "\n";
	}

	for (int dx = -5; dx <= 5; dx++) {
		for (int dy = -5; dy <= 5; dy++) {
			int cx = dx + ansx;
			int cy = dy + ansy;
			if (valid(cx, cy)) {
				int ma = 0;
				rep(i, n) {
					ma = max(ma, calc(cx, cy, x[i], y[i]));
				}
				if (ma < ans) {
					ans = ma;
					ansx = cx;
					ansy = cy;
				}
			}
		}
	}
	//cout << lx << "\n";
	string out;
	rep(i, ansx)out.push_back('B');
	rep(i, ansy)out.push_back('N');
	cout << ans << "\n";
	cout << out << "\n";
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