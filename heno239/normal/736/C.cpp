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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

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

const int max_n = 1 << 20;
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}


modint dp[100][21][42][4];
modint cop[21][42][4];
int k, s;
void merge(int r, int c, bool f) {
	rep(i, k +1)rep(j, s + 2)rep1(l, 3)cop[i][j][l] = 0;
	if (f) {
		rep(x2, k + 1)rep(y2, s + 1)rep1(z2, 3) {
			bool valid = true;
			if (z2 & 1) {
				if (x2 >= k)valid = false;
			}
			if (z2 & 2) {
				if (y2 >s)valid = false;
			}
			if (valid) {
				cop[0][0][2] += dp[c][x2][y2][z2];
				cop[min(k, x2 + 1)][min(s+1, y2 + 1)][z2] += dp[c][x2][y2][z2];
			}
		}

	}
	else {
		rep(x2, k+1)rep(y2, s + 2)rep1(z2,3){
			bool valid = true;
			if (z2 & 1) {
				if (x2 >= k)valid = false;
			}
			if (z2 & 2) {
				if (y2 > s)valid = false;
			}
			if (!valid)continue;
			if (dp[c][x2][y2][z2] == (modint)0)continue;
			rep(x1, k + 1)rep(y1, s + 2)rep1(z1, 3) {
				
					int nz = 0;
					int nx1 = -1, nx2 = -1;
					if (z1 & 1) {
						nx1 = x1;
						if (z2 & 2) {
							if (y2 + x1 < k) {
								nx1 = -1;
							}
						}
					}
					if (z2 & 1) {
						nx2 = x2 + 1;
						if (z1 & 2) {
							if (x2 + y1 < k) {
								nx2 = -1;
							}
						}
					}
					int nx;
					if (nx1 < 0 && nx2 < 0) {
						nx = 0;
					}
					else {
						nz |= 1;
						nx = max(nx1, nx2);
					}
					int ny = -1;
					if ((z1 & 2) && (z2 & 2)) {
						if (y1 + y2 <= s) {
							ny = min(y1, y2 + 1);
						}
						else {
							ny = max(y1, y2 + 1);
						}
					}
					else {
						if (z1 & 2)ny = y1;
						if (z2 & 2)ny = y2 + 1;
					}
					if (ny < 0)ny = 0;
					else {
						nz |= 2;
					}
					/*if (x1 == 0 && y1 == 0 && z1 == 2 && x2 == 0 && y2 == 0 && z2 == 2) {
						cout << nx << " " << ny << " " << nz <<" "<<dp[r][x1][y1][z1]<<" "<<dp[c][x2][y2][z2]<<"\n";
					}*/
					cop[nx][ny][nz] += dp[r][x1][y1][z1] * dp[c][x2][y2][z2];
			}
		}
	}
	rep(i, k+1)rep(j, s + 2)rep1(l,3)dp[r][i][j][l] = cop[i][j][l];
}


vector<int> G[100];
void dfs(int id, int fr) {
	dp[id][0][0][1] = 1;
	dp[id][0][0][2] = 1;
	bool f = true;
	for (int to : G[id])if (to != fr) {
		dfs(to, id);
		merge(id, to, f); f = false;
		/*cout << "start " << id << "\n";
		rep(i, k + 1)rep(j, s + 2)rep(z, 4) {
			cout << i << " " << j << " " << z << " " << dp[id][i][j][z] << "\n";
		}*/
	}
	/*cout << "start " << id << "\n";
	rep(i, k+1)rep(j, s + 2)rep(z,4) {
		cout << i << " " << j << " " <<z<<" "<< dp[id][i][j][z] << "\n";
	}*/
}
void solve() {
	int n; cin >> n >> k;
	s = 2 * k;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	//cout << "?? " << s << "\n";
	modint ans = 0;
	dfs(0, -1);
	rep(i, k + 1)rep(j, s + 2)rep(z, 4) {
		if (z & 1)continue;
		if (j <= k) {
			ans += dp[0][i][j][z];
		}
	}
	cout << ans << "\n";
}





signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;

}