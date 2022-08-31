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
const ld pi = acos(-1.0);

ll mod_pow(ll a, ll n, ll m = mod) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
const int max_n = 10000;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

vector<P> b4 = { { 2,3 },{ 1,2 },{ 3,4 },{ 1,3 },{ 2,4 },{ 1,4 } };
vector<P> b44 = { {1,1},{4,4},{2,3},{3,2},{1,2},{2,1},{3,4},{4,3},{1,3},{3,1},{2,4},{4,2},{1,4},{4,1},{2,2},{3,3} };
vector<P> b5 = { {1,2},{1,3},{1,4},{2,3},{2,5},{3,5},{1,5},{3,4},{2,4},{4,5} };
vector<P> ans0(int n) {
	if (n == 4) {
		return b4;
	}
	vector<P> res = ans0(n - 4);
	int le = n - 4;
	rep(i, 6) {
		res.push_back({ le + b4[i].first,le + b4[i].second });
	}
	int d = n / 4;
	rep(i, d - 1) {
		int l = 4 * i;
		rep(j, 16) {
			res.push_back({ l + b44[j].first,le + b44[j].second });
		}
	}
	return res;
}
vector<P> ans1(int n) {
	if (n == 5) {
		return b5;
	}
	vector<P> res = ans1(n - 4);
	int d = n / 4;
	int le = n - 4;
	rep(i, d - 1) {
		int l = 4 * i + 1;
		rep(j, 16) {
			res.push_back({ l + b44[j].first,le + b44[j].second });
		}
	}
	rep(i, b5.size()) {
		int l = b5[i].first;
		int r = b5[i].second;
		if (l == 1) {
			res.push_back({ 1,le + r - 1 });
		}
		else {
			res.push_back({ le + l - 1,le + r - 1 });
		}
	}
	return res;
}
void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << "YES\n"; return;
	}
	if (n % 4 == 2 || n % 4 == 3) {
		cout << "NO\n"; return;
	}
	cout << "YES\n";
	if (n % 4 == 0) {
		vector<P> ans = ans0(n);
		rep(i, ans.size()) {
			int l = ans[i].first, r = ans[i].second;
			cout << l << " " << r << "\n";
		}
	}
	else {
		vector<P> ans = ans1(n);
		rep(i, ans.size()) {
			int l = ans[i].first, r = ans[i].second;
			cout << l << " " << r << "\n";
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}