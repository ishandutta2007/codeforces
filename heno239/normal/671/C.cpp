//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
	int n; vector<LP> node;
	vector<int>lazy;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, {0,0});
		lazy.resize(2 * n - 1, -1);
	}
	LP f(LP a, LP b) {
		LP res;
		res.first = max(a.first, b.first);
		res.second = a.second + b.second;
		return res;
	}
	void eval(int k, int l, int r) {
		if (lazy[k] < 0)return;
		node[k] = { lazy[k],(ll)lazy[k] * (r - l) };
		if (r - l > 1) {
			lazy[2 * k + 1] = lazy[k];
			lazy[2 * k + 2] = lazy[k];
		}
		lazy[k] = -1;
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
	LP query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return { 0,0 };
		if (a <= l && r <= b)return node[k];
		else {
			LP vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			LP vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	int find_loc(int x) {
		int k = 0, l = 0, r = n;
		eval(k, l, r);
		if (node[k].first <= x)return -1;
		while (k < n - 1) {
			int m = (l + r) / 2;
			eval(2 * k + 1, l, m);
			eval(2 * k + 2, m, r);
			if (node[2 * k + 2].first > x) {
				k = 2 * k + 2;
				l = m;
			}
			else {
				k = 2 * k + 1;
				r = m;
			}
		}
		return k - (n - 1);
	}
};


const int sup = 200020;

P miid[sup];
P maid[sup];
void addmi(P& p, int val) {
	if (val < p.first) {
		p.second = p.first;
		p.first = val;
	}
	else if(val<p.second){
		p.second = val;
	}
}
void addma(P& p, int val) {
	if (val > p.first) {
		p.second = p.first;
		p.first = val;
	}
	else if (val > p.second) {
		p.second = val;
	}
}
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	rep(i, sup) {
		miid[i] = { n,n };
		maid[i] = { -1,-1 };
	}
	rep(i, n) {
		addmi(miid[a[i]], i);
		addma(maid[a[i]], i);
	}
	vector<vector<P>> ads(n);
	for (int c = 1; c < sup; c++) {
		P pmi = { n,n };
		P pma = { -1,-1 };
		for (int i = c; i < sup; i += c) {
			addmi(pmi, miid[i].first);
			addmi(pmi, miid[i].second);
			addma(pma, maid[i].first);
			addma(pma, maid[i].second);
		}
		if (pmi.second == n)continue;
		if (pmi.second + 1 < n) {
			ads[pmi.second + 1].push_back({ n,c });
		}
		ads[0].push_back({ pma.second,c });
		if (pmi.first + 1 < n) {
			ads[pmi.first + 1].push_back({ pma.first,c });
		}
	}
	SegT st(n);
	ll ans = 0;
	rep(i, n) {
		for (P p : ads[i]) {
			int r = p.first;
			int c = p.second;
			//cout << "? " << i<<" "<<r << " " << c << "\n";
			int z = st.find_loc(c);
			//cout << "? " << z << "\n";
			//[z+1,n)
			if (z+1<r) {
				st.add(c, z + 1,r);
			}
		}
		ll ss = st.query(i, n).second;
		//cout << i << " " << ss << "\n";
		ans += ss;
	}
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init(); cout << ps.size() << "\n";
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}