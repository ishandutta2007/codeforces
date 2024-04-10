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

int dp[1 << 8][2][19][19];
int nex[1 << 8][2][19][19];
void solve() {
	int h, w, a, b; cin >> h >> w >> a >> b;
	rep(i, (1 << w))rep(j, 2)rep(k, 19)rep(l, 19) {
		dp[i][j][k][l] = -mod;
	}
	rep(i, (1 << w))rep(j, 2) {
		dp[i][j][0][0] = 0;
	}
	rep(i, h)rep(j, w) {
		bool b = false;
		if (i == 0 || j == 0 || i == h - 1 || j == w - 1)b = true;
		rep(s, (1 << w))rep(t, 2)rep(x, 19)rep(y, 19) {
			nex[s][t][x][y] = -mod;
		}

		rep(s, (1 << w))rep(t, 2)rep(x, 19)rep(y, 19) {
			if (dp[s][t][x][y] < 0)continue;
			rep(v, 4) {
				int ns = s * 2 + v / 2;
				int nt = v % 2;
				int nx = x;
				int ny = y;
				int val = dp[s][t][x][y];
				if (!b) {
					if (v == 0 && t == 1 && (s&(1 << w - 1)!=0)) {
						nx++;
					}
					if (v == 3 && t == 0 && (s&(1 << w - 1) == 0)) {
						ny++;
					}
				}
				else {
					if (v == 0 && t == 1 && (s&(1 << w - 1)!=0)) {
						val++;
					}
				}
				nex[ns][nt][nx][ny] = max(nex[ns][nt][nx][ny], val);
			}
		}


		rep(s, (1 << w))rep(t, 2)rep(x, 19)rep(y, 19) {
			dp[s][t][x][y] = nex[s][t][x][y];
		}
	}
}

void solve2() {
	int x[2], y[2];
	rep(i, 2)cin >> x[i];
	rep(i, 2)cin >> y[i];
	rep(i, 2)rep(j, 2) {
		if (x[i] == y[j]) {
			int s = x[i ^ 1] + y[j ^ 1];
			if (s == x[i]) {
				cout << "YeS\n"; return;
			}
		}
	}
	cout << "nO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//experi();
	int t; cin >> t; rep(i, t)solve2();
	//solve();
	stop
		return 0;
}