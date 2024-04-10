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

int dp[76][76][76][2];
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	rep(i, n + 1)rep(j, n + 1)rep(k, n + 1) {
		rep(l, 3) {
			dp[i][j][k][l] = mod;
		}
	}
	int acv = 0, ack = 0;
	for (char c : s) {
		if (c == 'V')acv++;
		else if (c == 'K')ack++;
	}
	dp[0][0][0][0] = 0;
	vector<int> memo;
	rep(i, n) {
		rep(cv, i + 1)rep(ck, i + 1) {
			if (cv + ck > i)break;
			if (cv > acv || ck > ack)break;
			int celse = i - cv - ck;
			if (celse > n-acv-ack)continue;
			memo.clear();
			int tmpv = 0, tmpk = 0, tmpe = 0;
			rep(x, n) {
				if (s[x] == 'V') {
					if (tmpv >= cv)memo.push_back(0);
					tmpv++;
				}
				else if (s[x] == 'K') {
					if (tmpk >= ck)memo.push_back(1);
					tmpk++;
				}
				else{
					if (tmpe >= celse)memo.push_back(2);
					tmpe++;
				}
			}
			//add v
			if (cv < acv) {
				int costv = 0;
				rep(t, memo.size()) {
					if (memo[t] == 0)break;
					costv++;
				}
				rep(t, 2) {
					dp[i + 1][cv + 1][ck][1] = min(dp[i + 1][cv + 1][ck][1], dp[i][cv][ck][t] + costv);
				}
			}
			//add k
			if (ck < ack) {
				int costk = 0;
				rep(t, memo.size()) {
					if (memo[t] == 1)break;
					costk++;
				}
				dp[i + 1][cv][ck+1][0] = min(dp[i + 1][cv][ck+1][0], dp[i][cv][ck][0] + costk);
			}
			//add else
			if (celse < n - acv - ack) {
				int coste = 0;
				rep(t, memo.size()) {
					if (memo[t] == 2)break;
					coste++;
				}
				if (i == 2 && cv == 1 && ck == 1) {
					
					//cout << "hello " << coste << "\n";
					//for (int t : memo)cout << t << "\n";
				}
				rep(t, 2) {
					dp[i + 1][cv][ck][0] = min(dp[i + 1][cv][ck][0], dp[i][cv][ck][t] + coste);
				}
			}
		}
	}
	//cout << dp[2][1][1][1] << "\n";
	//cout << dp[3][1][1][0] << "\n";
	int ans = min(dp[n][acv][ack][0], dp[n][acv][ack][1]);
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