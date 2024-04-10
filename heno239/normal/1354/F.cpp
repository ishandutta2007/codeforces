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

void chmin(ll &a, ll b) {
	a = min(a, b);
}
void chmax(ll &a, ll b) {
	a = max(a, b);
}
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

ll dp[76][76];
int pre[76][76];
void solve() {
	int n, k; cin >> n >> k;
	dp[0][0] = 0;
	vector<pair<P, int>> vs;
	vector<P> v;
	rep(i, n) {
		int a, b; cin >> a >> b;
		v.push_back({ b,a });
		vs.push_back({ {b,a},i });
	}
	sort(all(v));
	sort(all(vs));
	vector<int> trans(n);
	rep(i, n)trans[i] = vs[i].second;

	if (k == 1) {
		ll ma = -INF;
		int chk;
		rep(i, v.size()) {
			if (v[i].second > ma) {
				ma = v[i].second;
				chk = i;
			}
		}
		cout << 1 << "\n";
		cout << trans[chk] + 1 << "\n";
		return;
	}

	ll ma = -INF;

	vector<int> out;


	rep(er, n) {
		vector<P> cv = v;
		cv.erase(cv.begin() + er);
		rep(i, n)rep(j, k)dp[i][j] = -INF;
		dp[0][0] = 0;
		rep(i, n - 1){
			ll a = cv[i].second;
			ll b = cv[i].first;
			
			rep(j, k) {
				//take
				if (j < k-1) {
					ll nd = dp[i][j] + j * b + a;
					if (nd > dp[i + 1][j + 1]) {
						dp[i + 1][j + 1] = nd;
						pre[i + 1][j + 1] = j;
					}
				}
				//not take
				if (n - 2 - i >= k - 1 - j) {
					ll nd = dp[i][j] + (k - 1) * b;
					if (nd > dp[i + 1][j]) {
						dp[i + 1][j] = nd;
						pre[i + 1][j] = j;
					}
				}
			}
		}
		int cur = k-1;
		vector<int> summo;
		for (int i = n-1; i > 0; i--) {
			if (pre[i][cur] != cur) {
				summo.push_back(i - 1);
			}
			cur = pre[i][cur];
		}
		/*cout << "era" << "\n";
		rep(i, n - 1){
			rep(j, k) {
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}*/
		//cout << "?? " << dp[n - 1][k - 1] << "\n";
		//cout << "?? " << cur << "\n";
		reverse(all(summo));
		vector<bool> exi(n);
		for (int id : summo) {
			if (id >= er)exi[id + 1] = true;
			else exi[id] = true;
		}
		exi[er] = true;
		vector<int> d;
		rep(i, n)if (!exi[i])d.push_back(i);

		vector<int> ans;
		rep(i, summo.size()) {
			int id = summo[i];
			if (id >= er)id++;
			ans.push_back(trans[id] + 1);
		}

		rep(i, d.size()) {
			int id = d[i];
			ans.push_back(trans[id] + 1);
			ans.push_back(-(trans[id] + 1));
		}

		ans.push_back(trans[er] + 1);
		ll sum = dp[n - 1][k - 1] + (k - 1)*(ll)v[er].first + v[er].second;
		if (sum> ma) {
			ma = sum;
			out = ans;
		}
		//cout << er << " " << sum << "\n";
	}

	cout << out.size() << "\n";
	rep(i, out.size()) {
		if (i > 0)cout << " ";
		cout << out[i];
	}
	cout << "\n";

}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	int t; cin >> t;
	rep(i, t)solve();
	//solve();
	stop
		return 0;
}