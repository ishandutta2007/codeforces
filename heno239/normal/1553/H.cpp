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

int exi[1 << 22];
int k;
void addf(int x) {
	int cur = 0;
	per(i, k) {
		if (x & (1 << i))cur = 2 * cur + 2;
		else cur = 2 * cur + 1;
		exi[cur] = true;
	}
}
int query(int loc, int t, int x) {
	if (!exi[2 * loc + 1] || !exi[2 * loc + 2])return mod;
	int c = 0;
	if (x & (1 << t))c = 1;
	//find mi
	int cop = 2 * loc + 1 + (c^1);
	int suml = 1 << t;
	per(i, t) {
		int c = 0;
		if (x & (1 << i))c ^= 1;
		if (exi[2 * cop + 1 + c]) {
			cop = 2 * cop + 1 + c;
		}
		else {
			suml += (1 << i);
			cop = 2 * cop + 1 + (c ^ 1);
		}
	}
	cop = 2 * loc + 1 + c;
	int sumr = 0;
	per(i, t) {
		int c = 0;
		if (x & (1 << i))c ^= 1;
		if (exi[2 * cop + 1 + (c ^ 1)]) {
			sumr += (1 << i);
			cop = 2 * cop + 1 + (c ^ 1);
		}
		else {
			cop = 2 * cop + 1 + c;
		}
	}
	/*if (t == 2 && x == 0) {
		cout << suml << " " << sumr << "\n";
	}*/
	
	return suml - sumr;
}

void solve(){
	int n; cin >> n >> k;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	exi[0] = true;
	rep(i, n) {
		addf(a[i]);
	}
	vector<int> ans(1 << k, mod);
	vector<int> nds; nds.push_back(0);
	per(i, k) {
		//[0,1<<(i+1))
		rep(j, (1 << (i+1))) {
			int val = mod;
			for(int loc:nds){
				val = min(val, query(loc, i, j));
			}
			//cout << i << " " << j << " " << val << "\n";
			for (int z = j; z < (1 << k); z += (1 << (i + 1))) {
				ans[z] = min(ans[z], val);
			}
		}

		vector<int> nextnds;
		for (int nd : nds) {
			rep(j, 2) {
				if (exi[2 * nd + 1 + j])nextnds.push_back(2 * nd + 1 + j);
			}
		}
		swap(nds, nextnds);
	}
	rep(i, (1 << k)) {
		if (i > 0)cout << " "; cout << ans[i];
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}