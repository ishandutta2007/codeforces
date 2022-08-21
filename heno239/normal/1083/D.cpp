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
const int max_n = 100;
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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<int> nex(n), pre(n);
	map<int, int> mp;
	rep(i, n) {
		if (mp.find(a[i]) == mp.end()) {
			pre[i] = -1;
		}
		else {
			pre[i] = mp[a[i]];
		}
		mp[a[i]] = i;
	}
	mp.clear();
	per(i, n) {
		if (mp.find(a[i]) == mp.end()) {
			nex[i] = n;
		}
		else {
			nex[i] = mp[a[i]];
		}
		mp[a[i]] = i;
	}
	modint ans = 0;
	function<void(int,int)> yaru = [&](int l, int r) {
		if (l + 1 == r) {
			ll cl = l - pre[l]-1;
			ll cr = nex[l] - l-1;
			ans += cl * cr;
			return;
		}
		int m = (l + r) / 2;
		yaru(l, m); yaru(m, r);
		vector<int> x1, y1, x2, y2;
		int nl = m, nr = n - m;
		for (int i = m; i < r; i++) {
			if (pre[i] >= m)break;
			nl = min(nl, m-1 - pre[i]);
			nr = min(nr, nex[i] - m);
			x1.push_back(nl);
			y1.push_back(nr);
		}
		nl = m, nr = n - m;
		for (int i = m - 1; i >= l; i--) {
			if (nex[i] < m)break;
			nl = min(nl, m - 1 - pre[i]);
			nr = min(nr, nex[i] - m);
			x2.push_back(nl);
			y2.push_back(nr);
		}
		vector<ll> rx2(x2.size() + 1);
		rep(i, x2.size())rx2[i + 1] = rx2[i] + x2[i];
		vector<ll> ry2(x2.size() + 1);
		rep(i, x2.size())ry2[i + 1] = ry2[i] + y2[i];
		vector<ll> rxy2(x2.size() + 1);
		rep(i, x2.size())rxy2[i + 1] = rxy2[i] + (ll)(i+1) * y2[i];
		vector<ll> rx2y2(x2.size() + 1);
		rep(i, x2.size())rx2y2[i + 1] = rx2y2[i] + (ll)x2[i] * y2[i];
		vector<ll> rx(x2.size() + 1);
		rep(i, x2.size())rx[i + 1] = rx[i] + (i+1);

		modint mem = ans;
		rep(i, x1.size()) {
			int le = -1, ri = x2.size();
			while (ri - le > 1) {
				int mid = (le + ri) / 2;
				if (y2[mid] <= i)ri = mid;
				else le = mid;
			}
			ri = min(ri, x1[i]);
			//x1[i]<=x2[i] for [0,r1)
			//x1[i]>x2[i] for [r1,ri)
			int l1 = -1, r1 = ri;
			while (r1 - l1 > 1) {
				int mid = (l1 + r1) / 2;
				if (x2[mid] < x1[i])r1 = mid;
				else l1 = mid;
			}
			//y1[i]<=y2[i] for [0,r2)
			//y1[i]>y2[i] for [r2,ri)
			int l2 = -1, r2 = ri;
			while (r2 - l2 > 1) {
				int mid = (l2 + r2) / 2;
				if (y2[mid] < y1[i])r2 = mid;
				else l2 = mid;
			}
			int y = i;
			//x1[i]<=x2[i]&&y1[i]<=y2[i]
			//sum of (x1[i]-x-1)(y1[i]-y-1)
			if (0 < min(r1, r2)) {
				int rs = min(r1, r2);
				ans += (ll)x1[i] * (y1[i] - (y+1)) * rs;
				ans += -(ll)(y1[i] - (y+1)) * rx[rs];
			}
			//x1[i]>x2[i]&&y1[i]<=y2[i]
			//sum of (x2[i]-x-1)(y1[i]-y-1)
			if (r1 < r2) {
				ans += (y1[i] - (y+1)) * (rx2[r2] - rx2[r1]);
				ans += -(y1[i] - (y+1)) * (rx[r2] - rx[r1]);
			}
			//x1[i]<=x2[i]&&y1[i]>y2[i]
			//sum of (x1[i]-x-1)(y2[i]-y-1)
			if (r2 < r1) {
				ans += x1[i] * (ry2[r1] - ry2[r2]);
				ans += -(ll)x1[i] * (y+1) * (r1 - r2);
				ans += -(rxy2[r1] - rxy2[r2]);
				ans += (y+1) * (rx[r1] - rx[r2]);
			}
			//x1[i]>x2[i]&&y1[i]>y2[i]
			//sum of (x2[i]-x-1)(y2[i]-y-1)
			if (max(r1, r2) < ri) {
				int ls = max(r1, r2);
				ans += rx2y2[ri] - rx2y2[ls];
				ans += -(y+1) * (rx2[ri] - rx2[ls]);
				ans += -(rxy2[ri] - rxy2[ls]);
				ans += (y+1) * (rx[ri] - rx[ls]);
			}
		}
		//cout << l << " " << r << " " << ans - mem << "\n";
	};
	yaru(0, n);
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