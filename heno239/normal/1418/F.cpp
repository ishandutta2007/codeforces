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
constexpr ll mod = 1000000009;
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

modint calc(int n, int s) {
	if (n == 0 && s == 0)return 1;
	else if (n == 0)return 0;
	return comb(n - 1 + s + s, s) - comb(n - 1 + s + s, s - 1);
}

vector<int> ch[1 << 18];
void init() {
	rep1(i, (1 << 18) - 1) {
		for (int j = i; j < (1 << 18); j += i) {
			ch[j].push_back(i);
		}
	}
}
int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
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
};


int cnt[1 << 18];
void solve() {
	ll n, m; cin >> n >> m;
	ll l, r; cin >> l >> r;
	auto f = [&](P a, P b) {return max(a, b); };
	SegT<P> st(m + 1, { 0,0 }, f);
	ll locl = m, locr = m;
	rep1(i, n) {
		while (locl > 0 && locl * i >= l) {
			for (int d : ch[locl]) {
				cnt[d]++;
				st.update(d, { cnt[d],d });
			}
			locl--;
		}
		while (locr > 0 && locr * i > r) {
			for (int d : ch[locr]) {
				cnt[d]--;
				st.update(d, { cnt[d],d });
			}
			locr--;
		}
		//cout << "?? " << i << " " << locl << " " << locr << "\n";
		vector<int> ds = ch[i];
		bool exi = false;
		ll x1, y1, x2, y2;
		for (int d : ds) {
			ll le = (i + 1 + d - 1) / d;
			ll ri = n / d;
			le = max(le, 1ll);
			ri = min(ri, m);
			if (le > ri)continue;
			ll chk = -1;
			P p = st.query(le, ri + 1);
			if (p.first == 0)continue;
			else {
				chk = p.second;
			}
			if (chk < 0)continue;
			x1 = i;
			x2 = d * chk;
			y1 = chk * (locl / chk + 1);
			y2 = x1 * y1 / x2;
			exi = true; break;
		}
		if (!exi)cout << -1 << "\n";
		else cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
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