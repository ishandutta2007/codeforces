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
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
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
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct range_tree {
private:
	int sz = 1;
	vector<vector<int>> node;
	vector<vector<int>> lh, rh;
public:
	range_tree(vector<int> v) {
		int n = v.size();
		while (sz < n)sz *= 2;
		node.resize(sz * 2 - 1);
		rep(i, n) {
			node[i + sz - 1].push_back(v[i]);
		}
		lh.resize(2 * sz - 1), rh.resize(2 * sz - 1);
		per(i, sz - 1) {
			int id1 = 0, id2 = 0;
			vector<int>& a = node[2 * i + 1];
			vector<int>& b = node[2 * i + 2];
			while (id1 < a.size() || id2 < b.size()) {
				int mi = mod;
				if (id1 < a.size())mi = min(mi, a[id1]);
				if (id2 < b.size())mi = min(mi, b[id2]);
				int m1 = id1, m2 = id2;
				while (id1 < a.size() && mi == a[id1]) {
					node[i].push_back(a[id1]); id1++;
					lh[i].push_back(m1);
					rh[i].push_back(m2);
				}
				while (id2 < b.size() && mi == b[id2]) {
					node[i].push_back(b[id2]); id2++;
					lh[i].push_back(m1);
					rh[i].push_back(m2);
				}
			}
			lh[i].push_back(a.size());
			rh[i].push_back(b.size());
		}
	}
	struct tquery {
		int loc, k, l, r;
	};
	ll query(ll x, int a, int b) {
		int loc = lower_bound(all(node[0]), x) - node[0].begin();
		stack<tquery> st;
		st.push({ loc,0,0,sz });
		ll res = 0;
		while (!st.empty()) {
			tquery tq = st.top(); st.pop();
			if (tq.r <= a || b <= tq.l)continue;
			if (a <= tq.l && tq.r <= b) {
				res += tq.loc;
			}
			else {
				st.push({ lh[tq.k][tq.loc],2 * tq.k + 1,tq.l,(tq.l + tq.r) / 2 });
				st.push({ rh[tq.k][tq.loc],2 * tq.k + 2,(tq.l + tq.r) / 2,tq.r });
			}
		}
		return res;
	}
};

vector<int> loc[1 << 17];
void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	rep(i, n)loc[a[i]].push_back(i);
	vector<int> nex(n,n);
	rep(i, (1 << 17)) {
		rep(j, loc[i].size()) {
			if (j + k < loc[i].size()) {
				nex[loc[i][j]] = loc[i][j + k];
			}
		}
	}
	range_tree rt(nex);
	auto query = [&](int l, int r) {
		int res = r - l - rt.query(r, l, r);
		return res;
	};
	int q; cin >> q;
	int last = 0;
	rep(i, q) {
		int l, r; cin >> l >> r;
		l = ((l + last) % n);
		r = ((r + last) % n);
		if (l > r)swap(l, r);
		int ans = query(l, r + 1);
		cout << ans << "\n";
		last = ans;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}