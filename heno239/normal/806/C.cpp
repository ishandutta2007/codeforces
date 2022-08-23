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
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m) {
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
modint operator^(modint a, int n) {
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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void solve(){
	int n; cin >> n;
	vector<ll> a(n);
	vector<int> cnt(40);
	
	vector<ll> rest;
	rep(i,n){
		cin >> a[i];
		bool f = false;
		rep(j, 40) {
			if (a[i] == (1ll << j)) {
				cnt[j]++; f = true;
			}
		}
		if (!f) {
			rest.push_back(a[i]);
		}
	}

	auto can = [&](int m) {
		vector<ll> v = rest;
		int cur = m;
		rep(aa, cnt[0] - cur)v.push_back(1);

		vector<int> x;
		rep(j, 39) {
			if (cnt[j + 1] >= cur) {
				rep(aa, cnt[j + 1] - cur)v.push_back((1ll << j + 1));

			}
			else {
				rep(aa, cur - cnt[j + 1])x.push_back(j);
				cur = cnt[j + 1];
			}
		}
		rep(aa, cur)x.push_back(39);
		sort(all(v),greater<ll>());
		sort(all(x), greater<int>());
		if (v.size() > x.size()) {
			return false;
		}
		rep(j, v.size()) {
			if (v[j] < 2 * (1ll << x[j])) {
				//
			}
			else {
				return false;
			}
		}
		return true;
	};
	if (!can(cnt[0])) {
		cout << -1 << "\n";
	}
	else {
		int le = -1, ri = cnt[0];
		while (ri - le > 1) {
			int m = (le + ri) / 2;
			if (can(m))ri = m;
			else le = m;
		}
		for (int i = ri; i <= cnt[0]; i++) {
			if (i > ri)cout << " ";
			cout << i;
		}
		cout << "\n";
	}
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
//	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}