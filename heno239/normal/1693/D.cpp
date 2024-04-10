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
constexpr ll mod = 998244353;
//constexpr ll mod = 1000000007;
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
	//if (x == 0)return 0;
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
bool operator<(modint a, modint b) { return a.n < b.n; }
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
/*const int mn = 100005;
bool isp[mn];
vector<int> ps;
void init() {
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
		}
	}
}*/

//[,val)
template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}

//[val,)
template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;
mP operator+(mP a, mP b) {
	return { a.first + b.first,a.second + b.second };
}
mP operator+=(mP& a, mP b) {
	a = a + b; return a;
}
mP operator-(mP a, mP b) {
	return { a.first - b.first,a.second - b.second };
}
mP operator-=(mP& a, mP b) {
	a = a - b; return a;
}

mt19937 mt(time(0));

const string drul = "DRUL";
string senw = "SENW";
//DRUL,or SENW
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------

bool isdecinc2(vector<int> p) {
	rep(i, p.size())Rep(j, i + 1, p.size())Rep(k, j + 1, p.size())Rep(l, k + 1, p.size()) {
		if (p[i] > p[j] && p[i]<p[l] && p[k]>p[l])return false;
		if (p[i]<p[j] && p[i]>p[l] && p[k] < p[l])return false;
	}
	return true;
}
bool isdecinc(vector<int> p) {
	set<P> st;
	st.insert({ -mod,mod });
	rep(i, p.size()) {
		set<P> nst;
		for (auto pp : st) {
			if (pp.first < p[i]) {
				nst.insert({ p[i],pp.second });
			}
			if (pp.second > p[i]) {
				nst.insert({ pp.first,p[i] });
			}
		}
		swap(st, nst);
	}
	return st.size();
}
void expr() {
	for (int n = 2; n <= 10; n++) {
		cout << "hello " << n << "\n";
		vector<int> p(n); rep(i, n)p[i] = i;
		do {
			if (isdecinc2(p)!=isdecinc(p)) {
				coutarray(p);
			}
		} while (next_permutation(all(p)));
	}
}

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
	//kf(x,node[y+sz-1])truey
	int searchloc(int le, T x, function<bool(T, T)> comp) {
		int  k = le + sz - 1;
		if (comp(x, node[k]))return le;
		x = f(x, node[k]);
		while (k > 0) {
			int mem = k;
			k = (k - 1) / 2;
			if (2 * k + 1 == mem) {
				if (comp(x, node[2 * k + 2])) {
					k = 2 * k + 2; break;
				}
				x = f(x, node[2 * k + 2]);
			}
		}
		if (k == 0)return sz;
		while (k < sz - 1) {
			if (comp(x, node[2 * k + 1])) {
				k = 2 * k + 1;
			}
			else {
				x = f(x, node[2 * k + 1]);
				k = 2 * k + 2;
			}
		}
		return k - (sz - 1);
	}
};

vector<int> calc_rs(vector<int> p) {
	int n = p.size();
	vector<int> a(n), b(n);
	vector<P> vp;
	rep(i, n) {
		while (vp.size() && vp.back().first > p[i]) {
			int to = vp.back().second;
			vp.pop_back();
			a[to] = i;
		}
		vp.push_back({ p[i],i });
	}
	while (vp.size()) {
		int to = vp.back().second;
		vp.pop_back();
		a[to] = n;
	}
	per(i, n) {
		while (vp.size() && vp.back().first < p[i]) {
			int to = vp.back().second;
			vp.pop_back();
			b[to] = i;
		}
		vp.push_back({ p[i],i });
	}
	while (vp.size()) {
		int to = vp.back().second;
		vp.pop_back();
		b[to] = -1;
	}
	vector<vector<P>> pa(n),pb(n);
	rep(i, n) {
		pa[p[i]].push_back({ i,a[i] });
		pb[p[i]].push_back({ i,b[i] });
	}
	auto f = [&](int a, int b) {
		return min(a, b);
	};
	SegT<int> st(n, n, f);
	vector<int> res(n);
	per(i, n) {
		for (auto p : pa[i]) {
			int id = p.first;
			res[id] = st.query(p.second + 1, n);
		}
		for (auto p : pb[i]) {
			int id = p.first;
			if(p.second>=0)st.update(p.second, id);
		}
	}
	return res;
}
void solve() {
	int n; cin >> n;
	vector<int> p(n);
	rep(i, n)cin >> p[i];
	rep(i, n) {
		p[i]--;
	}
	vector<int> r1 = calc_rs(p);
	rep(i, n)p[i] = n - 1 - p[i];
	vector<int> r2 = calc_rs(p);
	ll ans = 0;
	int cr = n;
	per(i, n) {
		chmin(cr, r1[i]);
		chmin(cr, r2[i]);
		ans += cr - i;
		//cout << i << " " << cr << "\n";
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}