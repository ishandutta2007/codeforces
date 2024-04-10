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
const ll mod = 1000000007;
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

void chmin(int &a, int b) {
	a = min(a, b);
}
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

typedef int tr;
//
bool func(tr a, tr b) {
	return a >= b;
}
//namin[0,k),...,min[i,i+k),...,min[n-k,n)
vector<tr> slide_minimum(vector<tr> a, int k) {
	//cout << "?? " << a.size() << " " << k << "\n";
	int n = a.size();
	vector<tr> res;
	vector<tr> deq(n);
	int s = 0, t = 0;
	rep(i, n) {
		while (s < t&&func(a[deq[t - 1]], a[i]))t--;
		deq[t++] = i;
		if (i - k + 1 >= 0) {
			res.push_back(a[deq[s]]);
			if (deq[s] == i - k + 1)s++;
		}
	}
	return res;
}

int dp[1 << 17][2];
int nex[1 << 17][2];
void solve() {
	int n, k; cin >> n >> k;
	vector<int> le(k), ri(k);
	rep(i, k) {
		cin >> le[i] >> ri[i];
	}

	rep(i, n+1)dp[i][0] =dp[i][1]= mod;
	dp[0][0] = 0;
	int cur = 0;
	rep(i, k) {
		int dif = le[i] - cur;
		per(j, n + 1) {
			if (j + dif <= n) {
				dp[j + dif][0] = dp[j][0];
			}
		}
		rep(j, dif) {
			dp[j][0] = mod;
		}

		rep(i, n + 1)rep(j, 2)nex[i][j] = mod;

		int len = ri[i] - le[i];
		//from 0

		//0 time
		rep(j, n + 1) {
			if (j + len <= n) {
				chmin(nex[j + len][0], dp[j][0]);
			}
		}
		//1 time
		vector<int> ori;
		rep(j, len)ori.push_back(mod);
		rep(j, n + 1)ori.push_back(dp[j][0]);
		vector<int> res = slide_minimum(ori, len+1);
		rep(j, n + 1) {
			chmin(nex[j][1], res[j]+1);
		}
		//2 time
		rep(j, n + 1) {
			chmin(nex[j][0], res[j] + 2);
		}

		//from 1

		//0 time
		rep(j, n + 1) {
			chmin(nex[j][1], dp[j][1]);
		}
		//1 time
		ori.clear();
		rep(j, len)ori.push_back(mod);
		rep(j, n + 1)ori.push_back(dp[j][1]);
		res = slide_minimum(ori, len + 1);
		rep(j, n + 1) {
			chmin(nex[j][0], res[j] + 1);
		}
		//2 time
		rep(j, n + 1) {
			chmin(nex[j][1], res[j] + 2);
		}

		rep(j, n + 1) {
			dp[j][0] = nex[j][0];
			dp[j][1] = nex[j][1];
		}

		//cout << dp[3][0] << "\n";
		cur = ri[i];
	}
	int dif = 2*n - cur;
	per(j, n + 1) {
		if (j + dif <= n) {
			dp[j + dif][0] = dp[j][0];
		}
	}
	rep(j, dif) {
		dp[j][0] = mod;
	}
	int ans = min(dp[n][0], dp[n][1]);
	if (ans >= mod) {
		cout << "Hungry\n";
	}
	else {
		cout << "Full\n";
		cout << ans << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	//init_f();
	//init();
	//experi();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}