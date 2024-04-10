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
const ll mod = 998244353;
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

bool issame[3001][3001];
modint dp[3001][3001];

modint dp2[3001][3001];
void solve() {
	string s, t; cin >> s >> t;
	int n = s.size();
	int m = t.size();
	/*if (n == 1) {
		if (s == t)cout << "2\n";
		else cout << "0\n";
		return;
	}*/
	per(i, n + 1) {
		per(j, m + 1) {
			if (i == n || j == m)issame[i][j] = true;
			if (!issame[i][j])continue;
			if (i - 1 >= 0 && j - 1 >= 0 && s[i - 1] == t[j - 1]) {
				issame[i - 1][j - 1] = true;
			}
		}
	}
	//after
	dp[1][0] = 2;
	rep1(i, n - 1) {
		//right
		dp[i + 1][m] += dp[i][m];
		//left
		dp[i + 1][0] += dp[i][0];
		rep(j, m) {
			//right
			dp[i + 1][j] += dp[i][j];
			//left
			if (s[i] == t[m-1-j]) {
				dp[i + 1][j + 1] += dp[i][j];
			}
		}
	}
	modint ans = 0; rep1(i, n)ans += dp[i][m];

	rep(i, n + 1)rep(j, m + 1)dp[i][j] = 0;
	//first character in T
	rep(i, m)if (t[i] == s[0]) {
		dp[1][i] += 2;
		/*if (i == 0) {
			if (issame[0][0]) {
				ans += 2 * (n - m + 1);
			}
		}
		else if (i == n - 1) {
			dp2[1][m - 1] += 2;
		}
		else {
			dp[1][i] += 2;
		}*/
	}
	rep1(i, m - 1) {
		for (int j = 1; j <= m; j++) {
			int opj = m - i - j;
			if (opj <= 0)break;
			if (s[i] == t[j - 1]) {
				dp[i + 1][j - 1] += dp[i][j];
			}
			if (s[i] == t[m - opj]) {
				dp[i + 1][j] += dp[i][j];
			}
		}
	}
	rep1(i, m) {
		int le = m - i;
		if (issame[i][i]) {
			ans += dp[i][0] * (modint)(n - m + 1);
		}
		if (m != 1) {
			dp2[i][m - i] += dp[i][m - i];
		}
	}
	rep(i, n){
		rep(j, m) {
			//right
			dp2[i + 1][j] += dp2[i][j];
			//left
			if (j > 0 && s[i] == t[j - 1])dp2[i + 1][j - 1] += dp2[i][j];
		}
		ans += dp2[i][0];
	}
	ans += dp2[n][0];
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//experi();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}