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

struct Seg22T {
private:
	vector<modint> node; int sz;
	vector<int> vy;
public:
	modint f(modint a, modint b) {
		return a * b;
	}
	void add(int y) {
		vy.push_back(y);
	}
	void complete() {
		sort(vy.begin(), vy.end());
		vy.erase(unique(vy.begin(), vy.end()), vy.end());
		int n = vy.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, 1);
	}
	void update(int k, ll c) {
		k = lower_bound(vy.begin(), vy.end(), k) - vy.begin();
		k += sz - 1;
		node[k] = f(node[k], c);
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	modint query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return 1;
		if (a <= l && r <= b)return node[k];
		else {
			modint vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			modint vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	modint query(int a, int b) {
		a = lower_bound(vy.begin(), vy.end(), a) - vy.begin();
		b = lower_bound(vy.begin(), vy.end(), b) - vy.begin();
		return query(a, b, 0, 0, sz);
	}
};

struct Seg2T {
private:
	int sz;
	vector<Seg22T> node;
public:
	modint f(modint a, modint b) {
		return a * b;
	}
	Seg2T(vector<P> v,int n) {
		//int n = v.size();
		sz = 1; while (sz < n)sz *= 2; node.resize(sz * 2 - 1);
		rep(i, v.size()) {
			int k = v[i].first, y = v[i].second;
			k += sz - 1;
			node[k].add(y);
			while (k > 0) {
				k = (k - 1) / 2;
				node[k].add(y);
			}
		}
		rep(i, 2 * sz - 1)node[i].complete();
	}
	void update(int x, int y, ll c) {
		x += sz - 1;
		node[x].update(y, c);
		while (x) {
			x = (x - 1) / 2;
			node[x].update(y, c);
		}
	}
	modint query(int a, int b, int x, int y, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return 1;
		else if (a <= l && r <= b)return node[k].query(x, y);
		else {
			modint vl = query(a, b, x, y, k * 2 + 1, l, (l + r) / 2);
			modint vr = query(a, b, x, y, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};



template<typename T>
struct SegT {
private:
	int sz; vector<T> node;
	T init_c;
	function<T(T, T)> f;
public:
	SegT(vector<T> v, T _init_c, function<T(T, T)> _f) {
		init_c = _init_c; f = _f;
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int n, T _init_c, function<T(T, T)> _f) {
		init_c = _init_c; f = _f;
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	void update(int k, T a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

bool isp[1 << 18];
vector<int> chp[1 << 18];
vector<int> ps;
void init() {
	fill(isp + 2, isp + 200001, true);
	for (int i = 2; i <= 200000; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		chp[i].push_back(i);
		for (int j = 2 * i; j <= 200000; j += i) {
			chp[j].push_back(i);
			isp[j] = false;
		}
	}
}

const int b = 120;
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<array<int, b>> ori(n);
	vector<P> vs;
	vector<int>memo(ps.size(),-1);

	vector<modint> vals;
	rep(i, n) {
		for (int p : chp[a[i]]) {
			int cnt = 0;
			int cop = a[i];
			while (cop % p == 0) {
				cop /= p; cnt++;
			}
			int loc = lower_bound(all(ps), p) - ps.begin();
			if (loc < b) {
				ori[i][loc] = cnt;
			}
			else {
				vs.push_back({ i,memo[loc] });
				vals.push_back(p);
				memo[loc] = i;
			}
		}
	}
	Seg2T upst(vs,n);
	rep(i, vs.size()) {
		upst.update(vs[i].first, vs[i].second, vals[i]);
	}
	
	array<int, b> init_c = {};
	auto f = [&](array<int, b> x, array<int, b> y) {
		rep(i, b)x[i] = max(x[i], y[i]);
		return x;
	};
	SegT<array<int, b>> st(ori, init_c, f);

	int q; cin >> q;
	int las = 0;
	rep(i, q) {
		int x, y; cin >> x >> y;
		int l = (las + x) % n;
		int r = (las + y) % n;
		if (l > r)swap(l, r);
		modint ans = 1;
		array<int, b> ar = st.query(l, r + 1);
		rep(j, b)rep(k, ar[j])ans *= ps[j];
		ans *= upst.query(l, r + 1, -1, l);
		cout << ans << "\n";
		las = ans;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}