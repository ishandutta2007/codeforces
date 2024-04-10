#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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
typedef double ld;
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


int n, s;
string ope[1 << 18];
int y[1 << 18], v[1 << 18];
struct Data {
	map<int, ll> mp;
	multiset<ll>vals;
	ll ad;
};
Data dfs(int &loc,int sx,ll sval) {
	Data res;
	res.mp[sx] = sval;
	res.vals.insert(sval);
	res.ad = 0;
	while (loc < n&&ope[loc]!="end") {
		if (ope[loc] == "set") {
			res.ad += v[loc];
			if (y[loc] != s) {
				ll nval = *res.vals.begin() - v[loc];
				if (res.mp.find(y[loc]) == res.mp.end()) {
					res.mp[y[loc]] = nval;
					res.vals.insert(nval);
				}
				else {
					if (res.mp[y[loc]] > nval) {
						res.vals.erase(res.vals.find(res.mp[y[loc]]));
						res.vals.insert(nval);
						res.mp[y[loc]] = nval;
					}
				}
			}
			loc++;
		}
		else {
			int c = y[loc];
			if (res.mp.find(c) != res.mp.end()) {
				loc++;
				Data nex = dfs(loc, c, res.mp[c]+res.ad);
				//assert(ope[loc] == "end");
				loc++;
				ll memo = nex.mp[c]+nex.ad;
				
				if (res.mp.size() < nex.mp.size())swap(res, nex);
				for (LP p : nex.mp) {
					int ind = p.first;
					ll val = p.second + nex.ad - res.ad;
					if (res.mp.find(ind) == res.mp.end()) {
						res.mp[ind] = val;
						res.vals.insert(val);
					}
					else {
						if (res.mp[ind] > val) {
							res.vals.erase(res.vals.find(res.mp[ind]));
							res.vals.insert(val);
							res.mp[ind] = val;
						}
					}
				}
				memo -= res.ad;
				res.vals.erase(res.vals.find(res.mp[c]));
				res.vals.insert(memo);
				res.mp[c] = memo;
			}
			else {
				int tmp = 1;
				loc++;
				while (true) {
					if (ope[loc] == "end")tmp--;
					else if (ope[loc] == "if")tmp++;
					if (tmp == 0)break;
					loc++;
				}
				loc++;
			}
		}
	}
	return res;
}
void solve() {
	cin >> n >> s;
	rep(i, n) {
		cin >> ope[i];
		if (ope[i] == "set")cin >> y[i] >> v[i];
		else if (ope[i] == "if")cin >> y[i];
	}
	int loc = 0;
	Data res = dfs(loc, 0, 0);
	assert(loc == n);
	ll ans = *res.vals.begin() + res.ad;
	//cout << res.ad << "\n";
	//cout << res.mp[2] << "\n";
	cout << ans << "\n";
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