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

const int max_n = 1 << 22;
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


void solve() {
	set<int> st;
	multiset<int> difs;
	auto add=[&](int x) {
		st.insert(x);
		auto itr = st.find(x);
		int cl = -1, cr = -1;
		if (itr != st.begin()) {
			itr--; cl = *itr; itr++;
		}
		if (itr != --st.end()) {
			itr++; cr = *itr; itr--;
		}
		if (cl >= 0 && cr >= 0) {
			difs.erase(difs.find(cr - cl));
		}
		if (cl >= 0) {
			difs.insert(x - cl);
		}
		if (cr >= 0) {
			difs.insert(cr - x);
		}
	};
	auto del = [&](int x) {
		auto itr = st.find(x);
		int cl = -1, cr = -1;
		if (itr != st.begin()) {
			itr--; cl = *itr; itr++;
		}
		if (itr != --st.end()) {
			itr++; cr = *itr; itr--;
		}
		if (cl >= 0 && cr >= 0) {
			difs.insert(cr - cl);
		}
		if (cl >= 0) {
			difs.erase(difs.find(x - cl));
		}
		if (cr >= 0) {
			difs.erase(difs.find(cr - x));
		}
		st.erase(x);
	};
	auto calc = [&]()->int {
		if (st.size()<=1)return 0;
		int mi = *st.begin();
		int ma = *st.rbegin();
		int d = *difs.rbegin();
		//cout << "?? " << mi << " " << ma << " " << d << "\n";
		return ma - mi - d;
	};
	int n, q; cin >> n >> q;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	sort(all(a));
	rep(i, n) {
		st.insert(a[i]);
		if (i > 0) {
			difs.insert(a[i] - a[i - 1]);
		}
	}
	cout << calc() << "\n";
	rep(i, q) {
		int t, x; cin >> t >> x;
		if (t == 0) {
			del(x);
		}
		else {
			add(x);
		}
		cout << calc() << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}