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
const ll mod = 998244353;
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

ll dot(LP a, LP b) {
	return a.first * b.first + a.second * b.second;
}
ll cross(LP a, LP b) {
	return a.first * b.second - a.second * b.first;
}
ll norm2(LP a) {
	return a.first * a.first + a.second * a.second;
}
int ccw(LP a, LP b, LP c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	if (cross(b, c) > 0)return 1;//counter clockwise
	if (cross(b, c) < 0)return -1;//clockwise
	if (dot(b, c) < 0)return 2;//c--a--b on line
	if (norm2(b) < norm2(c))return -2;//a--b--c on line
	return 0;//a--c--b on line
}

bool valid(ll a1, ll b1, ll a2, ll b2, ll m, ll t, ll h) {
	return t * (a2 - a1) * b1 + (m - t * a1) * (b2 - b1) >= h * (a2 - a1);
}
void solve() {
	int q; ll m; cin >> q >> m;
	set<LP> st;
	st.insert({ 0,0 });
	auto prev = [&](auto itr) {
		if (itr == st.begin())return st.end();
		return --itr;
	};
	auto nex = [&](auto itr) {
		if (itr == st.end())return st.end();
		return ++itr;
	};
	auto add = [&](LP p) {
		st.insert(p);
		auto itr = st.find(p);
		if (prev(itr) != st.end() && nex(itr) != st.end()) {
			LP pre = *prev(itr);
			LP ne = *nex(itr);
			if (ccw(pre, p, ne) != -1) {
				st.erase(p); return;
			}
		}
		while (prev(itr) != st.end() && prev(prev(itr)) != st.end()) {
			LP p1 = *prev(prev(itr));
			LP p2 = *prev(itr);
			if (ccw(p1, p2, p) != -1) {
				st.erase(p2);
			}
			else break;
		}
		while (nex(itr) != st.end() && nex(nex(itr)) != st.end()) {
			LP p1 = *nex(itr);
			LP p2 = *nex(nex(itr));
			if (ccw(p, p1, p2) != -1) {
				st.erase(p1);
			}
			else break;
		}
	};
	auto query = [&](int t, int h)->bool {
		ll x = (m + t - 1) / t;
		auto itr = st.lower_bound(LP{ x,-1 });
		if (itr == st.end()) {
			LP p = *--st.end();
			return p.second * t >= h;
		}
		else {
			LP p1 = *prev(itr);
			LP p2 = *itr;
			return valid(p1.first, p1.second, p2.first, p2.second, m, t, h);
		}
	};
	int las = 0;
	const int mm = 1000000;
	rep(i, q) {
		int typ; cin >> typ;
		int a, b; cin >> a >> b;
		a = (a + las) % mm + 1;
		b = (b + las) % mm + 1;
		if (typ == 1) {
			add({ b,a });
		}
		else {
			bool f = query(a,b);
			if (f) {
				cout << "YES\n";
				las = i + 1;
			}
			else {
				cout << "NO\n";
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
	//while(true)
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}