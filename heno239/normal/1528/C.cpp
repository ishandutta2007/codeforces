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
const ld eps = 1e-8;
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
const int max_n = 1 << 1;
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

struct SegT {
private:
	int n; vector<int> node, lazy;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, -1);
		lazy.resize(2 * n - 1, -2);
	}
	int f(int a, int b) {
		return max(a, b);
	}
	void eval(int k, int l, int r) {
		if (lazy[k] == -2) {
			return;
		}
		node[k] = lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] = lazy[k];
			lazy[2 * k + 2] = lazy[k];
		}
		lazy[k] = -2;
	}
	void add(int x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a) {
		int k = 0, l = 0, r = n;
		while (k < n - 1) {
			eval(k, l, r);
			int m = (l + r) / 2;
			if (a < m) {
				k = 2 * k + 1; r = m;
			}
			else {
				k = 2 * k + 2; l = m;
			}
		}
		eval(k, l, r);
		return node[k];
	}
};
void solve() {
	int n; cin >> n;
	vector<vector<int>> g(n), h(n);
	rep1(i, n - 1) {
		int p; cin >> p; p--;
		g[p].push_back(i);
	}
	rep1(i, n - 1) {
		int p; cin >> p; p--;
		h[p].push_back(i);
	}
	vector<int> trans(n), ri(n);
	int tmp = 0;
	function<void(int)> dfs = [&](int id) {
		trans[id] = tmp; tmp++;
		for (int to : h[id]) {
			dfs(to);
		}
		ri[id] = tmp;
	};
	dfs(0);
	int ans = 0;
	SegT st(n);
	int cnt = 0;
	function<void(int)> ansdfs = [&](int id) {
		int col = st.query(trans[id]);
		int mem = -1;
		if (col >= 0) {
			mem = col;
			st.add(-1, trans[mem], ri[mem]);
			cnt--;
		}
		cnt++;
		st.add(id, trans[id], ri[id]);
		ans = max(ans, cnt);
		for (int to : g[id]) {
			ansdfs(to);
		}
		cnt--;
		st.add(-1, trans[id], ri[id]);
		if (mem >= 0) {
			st.add(mem, trans[mem], ri[mem]);
			cnt++;
		}
	};
	ansdfs(0);
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	int t; cin >> t;rep(i, t)
	solve();
	return 0;
}