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
const int max_n = 1 << 18;
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


vector<ll> t42;
ll calc(ll x) {
	int id = lower_bound(all(t42), x) - t42.begin();
	return t42[id] - x;
}
struct SegT {
private:
	int n; vector<LP> node,lazy;
	vector<bool> issame;
public:
	SegT(vector<ll> ori) {
		int sz = ori.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, { INF,0 });
		lazy.resize(2 * n - 1, { 0,0 });
		issame.resize(2 * n - 1, false);
		rep(i, sz) {
			node[i + n - 1] = { calc(ori[i]),ori[i] };
			issame[i + n - 1] = true;
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	LP f(LP a, LP b) {
		return min(a, b);
	}
	LP h(LP a, LP b) {
		if (a.first != 0)return a;
		return { b.first,b.second + a.second };
	}
	void eval(int k, int l, int r) {
		if (lazy[k].first != 0) {
			issame[k] = true;
			node[k].first = calc(lazy[k].first);
			node[k].second = lazy[k].first;
		}
		node[k].first -= lazy[k].second;
		node[k].second += lazy[k].second;
		if (r - l > 1) {
			lazy[2 * k + 1] = h(lazy[k], lazy[2 * k + 1]);
			lazy[2 * k + 2] = h(lazy[k], lazy[2 * k + 2]);
		}
		lazy[k] = { 0,0 };
	}
	void add(LP x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = h(lazy[k],x); eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
			if (issame[2 * k + 1] && issame[2 * k + 2] && node[2 * k + 1].second == node[2 * k + 2].second) {
				issame[k] = true;
			}
			else {
				issame[k] = false;
			}
		}
	}
	void erase_negative(int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (node[k].first < 0) {
			if (issame[k]) {
				node[k].first = calc(node[k].second);
			}
			else {
				erase_negative(2 * k + 1, l, (l + r) / 2);
				erase_negative(2 * k + 2, (l + r) / 2, r);
				node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
				if (issame[2 * k + 1] && issame[2 * k + 2] && node[2 * k + 1].second == node[2 * k + 2].second) {
					issame[k] = true;
				}
				else {
					issame[k] = false;
				}
			}
		}
	}
	LP query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return { INF,0 };
		if (a <= l && r <= b)return node[k];
		else {
			LP vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			LP vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};


void solve() {
	t42.push_back(1);
	rep(i, 10)t42.push_back(t42.back() * 42);
	int n, q; cin >> n >> q;
	vector<ll> t(n);
	rep(i, n)cin >> t[i];
	SegT st(t);
	rep(i, q) {
		int typ; cin >> typ;
		if (typ == 1) {
			int v; cin >> v; v--;
			LP p = st.query(v, v + 1);
			st.erase_negative();
			cout << p.second << "\n";
		}
		else if (typ == 2) {
			int l, r, x; cin >> l >> r >> x; l--;
			LP p = { x,0 };
			st.add(p, l, r);
			st.erase_negative();
		}
		else {
			int l, r, x; cin >> l >> r >> x; l--;
			LP p = { 0,x };
			while (true) {
				st.add(p, l, r);
				st.erase_negative();
				LP res = st.query(0, n);
				if (res.first > 0)break;
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	solve();
	return 0;
}