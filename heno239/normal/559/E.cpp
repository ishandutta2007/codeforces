//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
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



void solve() {
	int n; cin >> n;
	vector<int> a(n), x(n);
	rep(i, n)cin >> x[i] >> a[i];
	vector<int> vx;
	rep(i, n) {
		vx.push_back(x[i]);
		vx.push_back(x[i] - a[i]);
		vx.push_back(x[i] + a[i]);
	}
	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	vector<int> l(n), r(n);
	vector<int> loc(n);
	rep(i, n) {
		l[i] = lower_bound(all(vx), x[i] - a[i]) - vx.begin();
		r[i] = lower_bound(all(vx), x[i] + a[i]) - vx.begin();
		loc[i] = lower_bound(all(vx), x[i]) - vx.begin();
	}
	vector<int> dp(vx.size());

	vector<vector<int>> ids(vx.size());
	rep(i, n) {
		ids[lower_bound(all(vx), x[i]) - vx.begin()].push_back(i);
	}
	vector<vector<int>> ok(vx.size(), vector<int>(vx.size()));
	rep(i, vx.size()) {
		Rep(j, i + 1, vx.size()) {
			Rep1(k, i, j)dp[k] = 0;
			int ri = i;
			int cur = i;
			while (cur <= ri) {
				for (int id : ids[cur]) {
					if (r[id] <= j)ri = max(ri, r[id]);
				}
				cur++;
			}
			dp[ri] = 1;
			for (int k = i; k < j; k++) {
				if (!dp[k])continue;
				rep(t, n) {
					if (loc[t] <= j && l[t] >= i && loc[t] > k && l[t] <= k) {
						int cur = k + 1;
						int ri = loc[t];
						while (cur <= ri) {
							for (int id : ids[cur])if(id!=t) {
								if (r[id] <= j)ri = max(ri, r[id]);
							}
							cur++;
						}
						dp[ri] = 1;
					}
				}
			}
			ok[i][j] = dp[j];
		}
	}
	vector<int> sdp(vx.size() + 1);
	rep(i, vx.size()) {
		sdp[i + 1] = max(sdp[i + 1], sdp[i]);
		Rep(j, i + 1, vx.size())if (ok[i][j]) {
			sdp[j + 1] = max(sdp[j + 1], sdp[i] + vx[j] - vx[i]);
		}
	}
	//rep(i, vx.size())cout << vx[i] << "\n";
	cout << sdp[vx.size()] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init(); cout << ps.size() << "\n";
	//expr();
	//gene();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}