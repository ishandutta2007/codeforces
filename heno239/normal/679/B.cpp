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
const int max_n = 1 << 16;
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


void solve() {
	vector<ll> v;
	for (ll i = 1; i <= 100000; i++) {
		v.push_back(i * i * i);
	}
	vector<int> mem(v.size());
	vector<ll> mamem(v.size());
	mem[0] = 0;
	for (int i = 1; i < mem.size(); i++) {
		mem[i] = mem[i - 1];
		ll val =v[i] - 1;
		int ad = 0;
		while (val > 0) {
			int id = upper_bound(all(v), val) - v.begin(); id--;
			mem[i] = max(mem[i], ad + mem[id]);
			ad++;
			val -= v[id];
		}
		mem[i] = max(mem[i], ad);
		val = v[i] - 1;
		ll s = 0;
		ad = 0;
		while (val > 0) {
			int id = upper_bound(all(v), val) - v.begin(); id--;
			if (mem[i] == ad + mem[id]) {
				mamem[i] = max(mamem[i], s + mamem[id]);
			}
			ad++;
			val -= v[id];
			s += v[id];
		}
		if (mem[i] == ad) {
			mamem[i] = max(mamem[i], s);
		}
	}
	auto calc1 = [&](ll x) {
		int res = 0;
		int ad = 0;
		while (x > 0) {
			int id = upper_bound(all(v), x) - v.begin(); id--;
			res = max(res, ad + mem[id]);
			ad++; x -= v[id];
		}
		res = max(res, ad);
		return res;
	};
	vector<int> ansl(1006);
	auto calc2 = [&](int x) {
		return ansl[x];
	};
	for (int x = 1; x <= 1005; x++) {
		int res = 0;
		int cop = x;
		per(i, v.size()) {
			while (cop >= v[i]) {
				cop -= v[i]; res++;
			}
		}
		ansl[x] = res;
		//ansl[x] = max(ansl[x], ansl[x - 1]);
		//cout << x << " " << ansl[x] << "\n";
	}
	/*rep1(i, 1000) {
		if (calc1(i) != calc2(i)) {
			cout << "?! "<<i<<"\n";
		}
	}*/
	ll x; cin >> x;
		ll cnt = calc1(x);
		ll ans2 = 0;
		int ad = 0;
		ll s = 0;
		while (x > 0) {
			int id = upper_bound(all(v), x) - v.begin(); id--;
			if (ad + mem[id] == cnt) {
				ans2 = max(ans2, mamem[id] + s);
			}
			ad++; x -= v[id]; s += v[id];
		}
		if (ad == cnt)ans2 = max(ans2, s);
		cout << cnt << " " << ans2 << "\n";
}
signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	//while(cin>>n,n)
	//solve();
	//expr();
	//init();
	solve();
	return 0;
}