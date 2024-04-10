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

struct ste {
	int i, j, k;
};
int dp[16][16][1 << 15];
P memo[16][16][1 << 15];
ste pre[16][16][1 << 15];

vector<int> ch[1 << 15];
void init(int n) {
	rep(i, (1 << n)) {
		ch[i].clear();
		vector<int> v;
		rep(j, n) {
			if (i&(1 << j))continue;
			v.push_back(j);
		}
		int len = v.size();
		ch[i].push_back(0);
		rep(j, len) {
			int len = ch[i].size();
			rep(k, len) {
				ch[i].push_back(ch[i][k] ^ (1 << v[j]));
			}
		}
	}
}
int sum[1 << 15];
void solve() {
	int n; cin >> n; init(n);
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, (1 << n)) {
		sum[i] = 0;
		rep(j, n) {
			if (i&(1 << j)) {
				sum[i] += a[j];
			}
		}
	}
	rep(i, n + 1)rep(j, n + 1)rep(k, (1 << n)) {
		dp[i][j][k] = mod;
	}
	dp[0][0][0] = 0;
	vector<int> r;
	rep(i, n) {
		rep(j, i + 1) {
			rep(k, (1 << n)) {
				if (dp[i][j][k] == mod)continue;
				//take
				if (((k >> i) & 1) == 0) {
					//cout << i << " ? " << j << " " << k << "\n";
					int inf = dp[i][j][k];
					int nk = k ^ (1 << i);
					r.clear();
					rep(l, n) {
						if ((nk >> l) & 1)continue;
						r.push_back(l);
					}
					for (int to : ch[nk]) {
						if (inf < a[i] + sum[to]) {
							if (dp[i + 1][j + 1][nk^to] > a[i] + sum[to]) {
								dp[i + 1][j + 1][nk^to] = a[i] + sum[to];
								memo[i + 1][j + 1][nk^to] = { to,i };
								pre[i + 1][j + 1][nk^to] = { i,j,k };
							}
						}
					}
				}

				//not take
				if (dp[i + 1][j][k] > dp[i][j][k]) {
					dp[i + 1][j][k] = dp[i][j][k];
					pre[i + 1][j][k] = { i,j,k };
					memo[i + 1][j][k] = { 0,i };
				}
			}
		}
	}

	int ci = n, cj, ck=(1<<n)-1;
	rep(j, n+1) {
		if (dp[n][j][(1 << n) - 1]!=mod) {
			cj = j;
		}
	}
	//cout << "??? " << cj <<" "<<ck<<" "<<dp[n][cj][ck]<< "\n";
	vector<P> pairs;
	
	while (cj > 0) {
		P mem = memo[ci][cj][ck];
			rep(i, n) {
				if (mem.first&(1 << i)) {
					pairs.push_back({ i,mem.second });
				}
			}
		ste s = pre[ci][cj][ck];
		ci = s.i, cj = s.j, ck = s.k;
	}
	/*rep(i, pairs.size()) {
		cout << pairs[i].first << " ? " << pairs[i].second << "\n";
	}*/
	vector<P> ans;
	rep(i, pairs.size()) {
		int le = pairs[i].first, ri = pairs[i].second;
		ans.push_back({ le,ri });
		for (int j = i + 1; j < pairs.size(); j++) {
			if (pairs[j].first >= le)pairs[j].first--;
			if (pairs[j].second >= le)pairs[j].second--;
		}
	}
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
		int le = ans[i].first, ri = ans[i].second;
		cout << le+1 << " " << ri+1 << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//experi();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	//stop
		return 0;
}