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

const int max_n = 1 << 2;
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


//2DBIT
struct BIT {
private:
	vector<int> node; int n;
public:
	int f(int a, int b) {
		return a + b;
	}
	void init(int n_) {
		n = n_; node.resize(n, 0);
	}
	//[0,a)
	int query(int a) {
		int ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret = f(ret, node[i]);
		return ret;
	}
	void update(int a, int b) {
		for (int i = a; i < n; i |= i + 1)node[i] = f(node[i], b);
	}
};
struct BIT2 {
private:
	vector<BIT> node; int sz;
	vector<vector<int>> vy;
public:
	int f(int a, int b) {
		return a + b;
	}
	BIT2(int n) {
		sz = n; node.resize(n);
		vy.resize(n);
	}
	//
	void add(int x, int y) {
		for (int i = x; i < sz; i |= i + 1) {
			vy[i].push_back(y);
		}
	}
	//
	void complete() {
		rep(i, sz) {
			sort(vy[i].begin(), vy[i].end());
			vector<int> cop = vy[i];
			vy[i].erase(unique(vy[i].begin(), vy[i].end()), vy[i].end());
			int siz = vy[i].size();
			node[i].init(siz);
		}
	}
	int query(int x, int y) {
		int ret = 0;
		for (int i = x - 1; i >= 0; i = (i & (i + 1)) - 1) {
			int idy = lower_bound(vy[i].begin(), vy[i].end(), y) - vy[i].begin();
			ret = f(ret, node[i].query(idy));
		}
		return ret;
	}
	int query(int x1, int x2, int y) {
		return query(x2, y) - query(x1, y);
	}
	void update(int x, int y, int k) {
		for (int i = x; i < sz; i |= i + 1) {
			int idy = lower_bound(vy[i].begin(), vy[i].end(), y) - vy[i].begin();
			node[i].update(idy, k);
		}
	}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	int ma = 0;
	rep(i, n)ma = max(ma, a[i]);
	if (ma == 1) {
		cout << 1 << "\n"; return;
	}
	vector<vector<int>> loc(n + 3);
	rep1(i, n + 2)loc[i].push_back(-1);
	rep(i, n)loc[a[i]].push_back(i);
	rep1(i, n + 2)loc[i].push_back(n);
	BIT2 bt(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < loc[i].size() - 1; j++) {
			bt.add(loc[i][j],loc[i][j - 1]);
		}
	}
	bt.complete();
	for (int i = 1; i <= n+2; i++) {
		if (i > 1) {
			bool valid = false;
			for (int j = 0; j < loc[i].size() - 1; j++) {
				int l = loc[i][j];
				int r = loc[i][j + 1];
				int num = bt.query(l + 1, r, l + 1);
				if (num == i - 1) {
					valid = true; break;
				}
			}
			if (!valid) {
				cout << i << "\n"; break;
			}
		}
		for (int j = 1; j < loc[i].size() - 1; j++) {
			bt.update(loc[i][j], loc[i][j - 1], 1);
		}
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