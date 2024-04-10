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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
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

const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init() {
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

const int mn = 500;
int dp[201][201][mn+1];
struct status {
	int i, j, k;
};
status pre[201][201][mn + 1];
char prec[201][201][mn + 1];
void solve() {
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	rep(i, n + 1)rep(j, m + 1)rep(k,mn) {
		dp[i][j][k] = mod;
	}
	dp[0][0][0] = 0;
	rep(i, n + 1) {
		rep(j, m + 1) {
			rep(k, mn) {
				if (dp[i][j][k] == mod)continue;
				//'('
				int ni = i, nj = j;
				if (i < n&&s[i] == '(')ni++;
				if (j < m&&t[j] == '(')nj++;
				if (dp[i][j][k] + 1 < dp[ni][nj][k + 1]) {
					dp[ni][nj][k + 1] = dp[i][j][k] + 1;
					pre[ni][nj][k + 1] = { i,j,k };
					prec[ni][nj][k + 1] = '(';
				}
				//')'
				if (k > 0) {
					int ni = i, nj = j;
					if (i < n&&s[i] == ')')ni++;
					if (j < m&&t[j] == ')')nj++;
					if (dp[i][j][k] + 1 < dp[ni][nj][k - 1]) {
						dp[ni][nj][k - 1] = dp[i][j][k] + 1;
						pre[ni][nj][k - 1] = { i,j,k };
						prec[ni][nj][k - 1] = ')';
					}
				}
			}
		}
	}
	int mi = mod;
	int ci, cj, ck;
	rep(i, mn) {
		if (dp[n][m][i] + i < mi) {
			mi = dp[n][m][i] + i;
			ci = n, cj = m, ck = i;
		}
	}
	string ans;
	rep(i, ck)ans.push_back(')');
	while (ci > 0 || cj > 0 || ck > 0) {
		ans.push_back(prec[ci][cj][ck]);
		status &s = pre[ci][cj][ck];
		ci = s.i, cj = s.j, ck = s.k;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}