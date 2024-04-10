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

ll mod_pow(ll a, ll n, ll m = mod) {
	a %= m;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}

//x,yax+by=gcd(a,b)
int extgcd(int a, int b, int& x, int& y) {
	int d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}

int calc(int a, int b, int m,int g) {
	int s, t;
	extgcd(a, m, s, t);
	int v = b / g;
	ll res = s;
	res *= v;
	res = (res%m + m) % m;
	return res;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> ds;
	rep1(i, m) {
		if (m%i == 0) {
			ds.push_back(i);
			ds.push_back(m / i);
		}
	}
	sort(all(ds));
	ds.erase(unique(all(ds)), ds.end());
	vector<int> trans(m+1);
	rep(i, ds.size())trans[ds[i]] = i;
	vector<vector<int>> loc(ds.size());

	vector<bool> exi(m+1, true);
	rep(i, n) {
		int x; cin >> x; if (x == 0)x = m;
		exi[x] = false;
	}
	rep1(i, m) {
		if (exi[i]) {
			int g = gcd(m, i);
			loc[trans[g]].push_back(i);
		}
	}
	vector<int> dp(ds.size());
	vector<int> nex(ds.size());
	per(i, (int)ds.size()) {
		int ma = 0; nex[i] = ds.size();
		Rep(j, i + 1, ds.size()) {
			if (ds[j] % ds[i] == 0) {
				if (ma < dp[j]) {
					ma = dp[j];
					nex[i] = j;
				}
			}
		}
		dp[i] = ma + loc[i].size();
	}

	int las = 1;
	int memo = 1;
	vector<int> ans;
	int id = 0;
	while (id<ds.size()) {
		for (int t : loc[id]) {
			//cout << "?? " << las << " " << t << "\n";
			ans.push_back(calc(las, t, m,memo));
			las = t; memo = ds[id];
		}
		id = nex[id];
	}
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	solve();
	stop
		return 0;
}