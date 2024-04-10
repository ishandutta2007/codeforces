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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m=mod) {
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

map<vector<int>, bool> used;
map<vector<int>, int> memo;
int grandy(vector<int> v) {
	if (v.empty())return 0;
	if (used[v])return memo[v];
	used[v] = true;
	int ma = v.back();
	vector<int> ts;
	rep1(i, ma) {
		vector<int> nex;
		rep(j, v.size()) {
			if (v[j] >= i)nex.push_back(v[j] - i);
			else nex.push_back(v[j]);
		}
		sort(all(nex));
		nex.erase(unique(all(nex)), nex.end());
		ts.push_back(grandy(nex));
	}
	sort(all(ts));
	ts.erase(unique(all(ts)),ts.end());
	int res = ts.size();
	rep(i, ts.size())if (ts[i] != i) {
		res = i; break;
	}
	return memo[v] = res;
}
const int mn = 1000000000;
bool isp[40000];
vector<int> ps;
void init() {
	fill(isp + 2, isp + 40000, true);
	for (int i = 2; i*i <=mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < 40000; j += i)isp[j] = false;
	}
}
void solve() {
	int n; cin >> n;
	vector<P>vs;
	rep(i, n) {
		int a; cin >> a;
		for (int p : ps) {
			if (a % p == 0) {
				int cnt = 0;
				while (a % p == 0) {
					cnt++; a /= p;
				}
				vs.push_back({ p,cnt });
			}
		}
		if (a > 1)vs.push_back({ a,1 });
	}
	sort(all(vs));
	int z = 0;
	rep(i, vs.size()) {
		vector<int> x;
		x.push_back(vs[i].second);
		while (i + 1 < vs.size() && vs[i].first == vs[i + 1].first) {
			i++; x.push_back(vs[i].second);
		}
		x.erase(unique(all(x)), x.end());
		z ^= grandy(x);
	}
	if (z) {
		cout << "Mojtaba\n";
	}
	else {
		cout << "Arpa\n";
	}
}





signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}