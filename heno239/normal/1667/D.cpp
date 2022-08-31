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

const string drul = "DRUL";
//DRUL
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------

#define ftt function<T(T,T)>
#define ftu function<T(T,U,int,int)>
#define fuu function<U(U,U)>

template<typename T, typename U>
struct SegT {
private:
	int n;
	vector<T> node;
	vector<U> lazy;
	T et; U eu;
	ftt f;
	ftu g;
	fuu h;
public:
	SegT(vector<T> ori, T _et, U _eu, ftt _f, ftu _g, fuu _h) {
		int sz = ori.size();
		et = _et, eu = _eu; f = _f, g = _g, h = _h;
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, et);
		lazy.resize(2 * n - 1, eu);
		rep(i, sz) {
			node[i + n - 1] = ori[i];
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int sz, T _et, U _eu, ftt _f, ftu _g, fuu _h) {
		et = _et, eu = _eu; f = _f, g = _g, h = _h;
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, et);
		lazy.resize(2 * n - 1, eu);
	}
	void eval(int k, int l, int r) {
		if (lazy[k] == eu)return;
		node[k] = g(node[k], lazy[k], l, r);
		if (r - l > 1) {
			lazy[2 * k + 1] = h(lazy[k], lazy[2 * k + 1]);
			lazy[2 * k + 2] = h(lazy[k], lazy[2 * k + 2]);
		}
		lazy[k] = eu;
	}
	void add(U x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = h(x, lazy[k]);
			eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return et;
		if (a <= l && r <= b)return node[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int loc, T x) {
		int k = 0, l = 0, r = n;
		stack<P> st;
		while (k < n - 1) {
			eval(k, l, r);
			st.push({ l,r });
			if (loc < (l + r) / 2) {
				k = 2 * k + 1;
				r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2;
				l = (l + r) / 2;
			}
		}
		eval(k, l, r);
		st.push({ l,r });
		node[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			st.pop();
			l = st.top().first, r = st.top().second;
			eval(2 * k + 1, l, (l + r) / 2);
			eval(2 * k + 2, (l + r) / 2, r);
			node[k] = f(node[2 * k + 1], node[2 * k + 2]);
		}
	}
	//kf(x,node[y+sz-1])truey
	int searchloc(int le, T x, function<bool(T, T)> comp) {
		int k = 0, l = 0, r = n;
		while (k < n - 1) {
			eval(k, l, r);
			int m = (l + r) / 2;
			if (le < m) {
				k = 2 * k + 1; r = m;
			}
			else {
				k = 2 * k + 2; l = m;
			}
		}
		assert(k == le + n - 1);
		eval(k, l, r);
		if (comp(x, node[k]))return le;
		//x=f(x,node[k]);
		while (k > 0) {
			int mem = k;
			k = (k - 1) / 2;
			if (2 * k + 1 == mem) {
				r += r - l;
			}
			else {
				l -= r - l;
			}
			if (2 * k + 1 == mem) {
				eval(2 * k + 2, (l + r) / 2, r);
				if (comp(x, node[2 * k + 2])) {
					k = 2 * k + 2;
					l = (l + r) / 2;
					break;
				}
				//x=f(x,node[2*k+2]);
			}
		}
		if (k == 0)return n;
		while (k < n - 1) {
			eval(2 * k + 1, l, (l + r) / 2);
			eval(2 * k + 2, (l + r) / 2, r);
			if (comp(x, node[2 * k + 1])) {
				k = 2 * k + 1;
				r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2;
				l = (l + r) / 2;
				//x=f(x,node[2*k+1]);
			}
		}
		return k - (n - 1);
	}
};

using ar = array<int, 4>;
void solve() {
	
	int n; cin >> n;
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	auto f = [&](ar a, ar b) {
		ar res;
		rep(i, 4)res[i] = min(a[i], b[i]);
		return res;
	};
	auto g = [&](ar a, int x, int l, int r) {
		if (x & 1) {
			swap(a[0], a[1]);
			swap(a[2], a[3]);
		}
		if (x & 2) {
			swap(a[0], a[2]);
			swap(a[1], a[3]);
		}
		return a;
	};
	auto h = [&](int x, int y) {
		return x ^ y;
	};
	int tmp = 0;
	vector<int> par(n);
	vector<int> ids(n);
	vector<int> le(n), ri(n);
	vector<int> obj(n);
	bool valid = true;
	function<int(int, int)>dfs = [&](int id, int fr) {
		le[id] = tmp;
		for (int to : G[id])if (to != fr) {
			par[to] = id;
			ids[to] = tmp;
			tmp++;
		}
		int c[2] = {};
		c[0] = G[id].size() / 2;
		c[1] = (1 + G[id].size()) / 2;
		ri[id] = tmp;
		for (int to : G[id])if (to != fr) {
			int v=dfs(to, id);
			c[v]--;
		}
		if (c[0] < 0 || c[1] < 0) {
			valid = false;
		}
		int res;
		if (c[0] == 1) {
			res = 0;
		}
		else {
			res = 1;
		}
		return obj[id] = res;
	};
	dfs(0, -1);
	if (!valid) {
		cout << "NO\n"; return;
	}
	assert(tmp == n - 1);
	vector<ar> ori(n - 1);
	rep(i, n) {
		if (i == 0)continue;
		rep(j, 4)ori[ids[i]][j] = mod;
		int x = 0;
		if ((G[i].size() + obj[i]) % 2)x |= 1;
		if ((G[par[i]].size() + obj[i]) % 2)x |= 2;
		ori[ids[i]][x] = i;
	}
	SegT<ar, int> st(ori, { mod,mod,mod,mod }, 0, f, g, h);
	vector<P> ansp;
	auto upd = [&](int v) {
		if(v>0)st.add(1, ids[v], ids[v] + 1);
		if(le[v]<ri[v])st.add(2, le[v], ri[v]);
	};
	rep(i, n - 1) {
		ar p = st.query(0, n - 1);
		assert(p[0] < mod);
		/*if (p[0] == mod) {
			cout << "NO\n"; return;
		}*/
		//cout << "? " << id << "\n";
		int id = p[0];
		int loc = ids[id];
		st.update(loc, { mod,mod,mod,mod });
		ansp.push_back({ id,par[id] });
		upd(id);
		upd(par[id]);
	}
	cout << "YES\n";
	rep(i, n - 1) {
		cout << ansp[i].first + 1 << " " << ansp[i].second + 1 << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}