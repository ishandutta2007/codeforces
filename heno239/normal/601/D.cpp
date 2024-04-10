#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
constexpr ll mod =1000000007;
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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}

bool isp(int x) {
	int k = sqrt(x);
	for (int i = 2; i <= k + 10; i++) {
		if (x != i&&x % i == 0)return false;
	}
	return true;
}
mt19937 mt(time(0));

int find_prime(int lx, int rx) {
	uniform_int_distribution<> ud(lx, rx);
	int res = ud(mt);
	while (!isp(res))res++;
	return res;
}
const ll t1 = find_prime(500000000, 900000000);
const ll t2 = find_prime(500000000, 900000000);
const ll m1 = find_prime(1000000000, 1100000000);
const ll m2 = find_prime(1000000000, 1100000000);

struct Data {
	set<LP> st;
	ll p1, p2, ad1, ad2;
};


void solve() {
	//cout << t1 << " " << t2 << " " << m1 << " " << m2 << "\n";
	int n; cin >> n;
	vector<int> c(n);
	rep(i, n)cin >> c[i];
	string s; cin >> s;
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	auto merge = [&](Data& a, Data& b) {
		bool bs = false;
		if (a.st.size() < b.st.size()) {
			swap(a, b); bs = true;
		}
		ll invp1 = mod_pow(a.p1, m1 - 2, m1);
		ll invp2 = mod_pow(a.p2, m2 - 2, m2);
		for (LP val : b.st) {
			ll val1 = (b.p1 * val.first + b.ad1)%m1;
			val1 = (val1 + m1 - a.ad1) * invp1 % m1;
			ll val2 = (b.p2 * val.second + b.ad2) % m2;
			val2 = (val2 + m2 - a.ad2) * invp2 % m2;
			a.st.insert({ val1,val2 });
		}
		//if (bs)swap(a, b);
	};
	vector<int> vals;
	function<Data(int, int)> dfs = [&](int id, int fr) {
		Data res;
		int v = (s[id] - 'a')+1;
		res.st.insert({v,v});
		res.p1 = 1, res.p2 = 1, res.ad1 = 0, res.ad2 =0;
		for (int to : G[id])if (to != fr) {
			Data nex = dfs(to, id);
			nex.ad1 = (nex.ad1 * t1 + v) % m1;
			nex.p1 = nex.p1 * t1 % m1;
			nex.ad2 = (nex.ad2 * t2 + v) % m2;
			nex.p2 = nex.p2 * t2 % m2;
			//cout << id << " " << nex.p1*(*nex.st.begin()).first%m1 << " " << nex.ad1 << "\n";
			merge(res, nex);
		}
		vals.push_back(res.st.size() + c[id]);
		//cout << id << " " << res.p1<<" "<<res.ad1<< "\n";
		return res;
	};
	dfs(0, -1);
	sort(all(vals));
	int ma = vals.back();
	int ans2 = 0;
	rep(i, vals.size())if (vals[i] == ma)ans2++;
	cout << ma << "\n";
	cout << ans2 << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i,t)
	solve();
	return 0;
}