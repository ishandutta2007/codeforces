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
void coutarray(vector<T> &v) {
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
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


bool comp(P a, P b) {
	if (a.second != b.second)return a.second > b.second;
	return a.first < b.first;
}

#define ftt function<T(T,T)>
#define ftu function<T(T,U,int,int)>
#define fuu function<U(U,U)>

template<typename T>
struct BIT {
private:
	vector<T> node; int n;
public:
	BIT() { ; }
	void init(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, T w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	T sum(int a) {
		T ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	T sum(int a, int b) {
		return sum(b) - sum(a);
	}
};
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
	SegT() { ; }
	void init(vector<T> ori, T _et, U _eu, ftt _f, ftu _g, fuu _h) {
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
		assert(k == le+n - 1);
		eval(k, l, r);
		if (comp(x, node[k]))return le;
		while (k > 0) {
			int mem = k;
			k = (k - 1) / 2;
			if (2 * k + 1 == mem) {
				r += r-l;
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
			}
		}
		return k - (n - 1);
	}
};

//cnt*w
SegT<ll, ll> st[18];
//cnt*v
BIT<ll> stcnt[18];
//true value
SegT<ll, ll> stmi[18];

void solve() {
	int n, q; cin >> n >> q;
	vector<ll> a(n), w(n), v(n);
	rep(i, n) {
		cin >> a[i] >> w[i] >> v[i];
	}
	auto comp = [&](int i, int j) {
		if (v[i] != v[j])return v[i] > v[j];
		if (w[i] != w[j])return w[i] < w[j];
		return i < j;
	};
	vector<int> tra(n); rep(i, n)tra[i] = i;
	sort(all(tra), comp);
	vector<int> rev(n);
	rep(i, n)rev[tra[i]] = i;
	{
		vector<ll> na(n), nw(n), nv(n);
		rep(i, n) {
			na[i] = a[tra[i]];
			nw[i] = w[tra[i]];
			nv[i] = v[tra[i]];
		}
		swap(a, na);
		swap(w, nw);
		swap(v, nv);
	}
	auto compa = [&](ll a, ll b) {return a <= b; };
	auto compb = [&](ll a, ll b) {return a >= b; };
	rep(j, 18) {
		stcnt[j].init(n);
		vector<ll> orist(n+1);
		vector<ll> oristmi(n,INF);
		rep(i, n) {
			orist[i + 1] += orist[i];
			if (w[i] < (1 << j)) {
				orist[i + 1] += a[i] * w[i];
				stcnt[j].add(i, a[i] * v[i]);
			}
			if (w[i] >= (1 << j) && (1 << (j + 1)) > w[i]&&a[i]>0) {
				oristmi[i] = orist[i] + w[i];
			}
		}
		auto fa = [&](ll a, ll b) {return max(a, b); };
		auto g = [&](ll a, ll b, int k, int r) {return a + b; };
		auto h = [&](ll a, ll b) {return a + b; };
		auto fb = [&](ll a, ll b) {return min(a, b); };
		st[j].init(orist, -INF, 0, fa, g, h);
		stmi[j].init(oristmi, INF, 0, fb, g, h);
	}
	auto query = [&](ll x) {
		ll res = 0;
		int loc = 0;
		int chk = 59;
		while (loc < n && x > 0) {
			int pre = loc;
			while ((x & (1ll << chk))==0)chk--;
			chk = min(chk, 17);
			ll nw = st[chk].query(loc,loc+1);
			int nex = stmi[chk].searchloc(loc, nw + x, compb);
			ll valmi;
			if (nex >= n)valmi = INF;
			else valmi = st[chk].query(nex, nex + 1) - st[chk].query(loc, loc + 1) + w[nex];
			if (valmi <= x) {
				ll nx = x - valmi;
				int nloc = nex + 1;
				res += stcnt[chk].sum(loc, nloc) + v[nex];
				x = nx;
				loc = nloc;
			}
			else {
				ll dif = x - (1 << chk);
				int nloc = st[chk].searchloc(loc, nw + dif + 1, compa);
				nloc = min(nloc, n);
				int nex = nloc - 1;
				assert(nex >= 0 && nex < n);
				x -= st[chk].query(nex, nex + 1) - nw;
				res += stcnt[chk].sum(loc, nex);
				ll num = x / w[nex]; num = min(num, a[nex]);
				x -= num * w[nex];
				res += num * v[nex];
				loc = nloc;
			}
			assert(pre < loc);
		}
		assert(x >= 0);
		return res;
	};
	rep(i, q) {
		int typ; cin >> typ;
		if (typ == 1) {
			ll ad;
			int id; cin >> ad >> id; id--; id = rev[id];
			
			rep(j, 18) {
				//st,stcnt,stmiunder
				if (w[id] < (1 << j)) {
					st[j].add(ad*w[id],id + 1, n + 1);
					stcnt[j].add(id, ad * v[id]);
					stmi[j].add(ad * w[id], id + 1, n);
				}
				else if (w[id] < (1 << (j + 1))) {
					if (a[id] == 0) {
						ll val = w[id] + st[j].query(id, id + 1);
						stmi[j].update(id, val);
					}
				}
			}
			a[id] += ad;

		}
		else if (typ == 2) {
			ll ad;
			int id; cin >> ad >> id; id--; id = rev[id];
			ad *= -1;

			rep(j, 18) {
				//st,stcnt,stmiunder
				if (w[id] < (1 << j)) {
					st[j].add(ad * w[id], id + 1, n + 1);
					stcnt[j].add(id, ad * v[id]);
					stmi[j].add(ad * w[id], id + 1, n);
				}
				else if (w[id] < (1 << (j + 1))) {
					if (a[id]+ad == 0) {
						stmi[j].update(id, INF);
					}
				}
			}
			a[id] += ad;
		}
		else{
			ll x; cin >> x;
			cout << query(x) << "\n";
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}