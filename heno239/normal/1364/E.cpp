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
#include<chrono>
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
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


map<P, bool> mp;
map<P, int> memo;
int query(int i, int j) {
	if (i > j) {
		swap(i, j);
	}
	if (mp[{i, j}])return memo[{i, j}];
	mp[{i, j}] = true;
	cout << "? " << i + 1 << " " << j + 1 << endl;
	int res; cin >> res;
	assert(res >= 0);
	return memo[{i, j}]=res;
}

const int cs = 6;

int sup = 2047;
void solve() {
	int n; cin >> n;

	mt19937 mt(time(0));
	uniform_int_distribution<> uf(0, n - 1);

	int c1, c2;
	int s;
	while (1) {
		int a = uf(mt);
		int b = a;
		while (b == a)b = uf(mt);
		int r = query(a, b);
		int cnt = 0;
		rep(i, 11)if (r&(1 << i))cnt++;
		if (cnt <= cs) {
			c1 = a, c2 = b; s = r; break;
		}
	}

	vector<bool> ban(n, false);
	while (true) {
		int cnt = 0;
		rep(i, 11)if (s&(1 << i))cnt++;
		if (cnt == 1)break;

		rep(i, n)if (!ban[i]) {
			if (i == c1||i==c2)continue;
			int r = query(c1, i);
			bool valid = true;
			rep(j, 11) {
				if (!(s&(1 << j))) {
					if (r&(1 << j))valid = false;
				}
			}
			if (!valid) {
				ban[i] = true;
				continue;
			}
			else if (r < s) {
				c2 = i; s = r; break;
			}
			r = query(c2, i);
			valid = true;
			rep(j, 11) {
				if (!(s&(1 << j))) {
					if (r&(1 << j))valid = false;
				}
			}
			if (!valid) {
				ban[i] = true;
				continue;
			}
			else if (r < s) {
				c1 = i; s = r; break;
			}
		}
	}
	int loc0;
	while (1) {
		int a = uf(mt);
		while (a == c1 || a == c2)a = uf(mt);
		int r1 = query(a, c1);
		int r2 = query(a, c2);
		if (r1 == r2)continue;
		if (r1 < r2)loc0 = c1;
		else loc0 = c2;
		break;
	}
	vector<int> ans(n,0);
	rep(i, n) {
		if (i == loc0)continue;
		ans[i] = query(loc0, i);
	}
	cout << "!";
	rep(i, n) {
		cout << " " << ans[i];
	}
	cout << endl;
}



signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(6);
	//init_f();
	//init();
	//int t; cin >> t;rep(i,t)
	solve();
		return 0;
}