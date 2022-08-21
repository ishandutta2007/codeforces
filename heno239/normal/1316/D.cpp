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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n, ll m) {
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
using mP = pair<modint, modint>;

string sdir = "RDLU";
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int x[1000][1000], y[1000][1000];

bool used[1000][1000];
char ans[1000][1000];
void solve() {
	int n;
	scanf(" %d", &n);
	//cin >> n;
	rep(i, n)rep(j, n) {
		scanf(" %d %d", &x[i][j], &y[i][j]);
		//cin >> x[i][j] >> y[i][j];
		x[i][j]--; y[i][j]--;
	}
	queue<P> q;
	rep(i, n)rep(j, n) {
		if (x[i][j] >= 0) {
			if (x[i][j] == i && y[i][j] == j) {
				ans[i][j] = 'X';
				q.push({ i,j });
				used[i][j] = true;
			}
			/*else {
				int d = -1;
				rep(k, 4) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx == n || ny == n)continue;
					if (x[nx][ny] == x[i][j] && y[nx][ny] == y[i][j]) {
						d = k;
					}
				}
				if (d < 0) {
					printf("INVALID\n");
					return;
				}
				ans[i][j] = sdir[d];
			}*/
		}
	}
	while (!q.empty()) {
		P p = q.front(); q.pop();
		rep(k, 4) {
			int nx = p.first + dx[k];
			int ny = p.second + dy[k];
			if (nx < 0 || ny < 0 || nx == n || ny == n)continue;
			if (x[nx][ny]!=x[p.first][p.second]||y[nx][ny]!=y[p.first][p.second])continue;
			if (used[nx][ny])continue;
			ans[nx][ny] = sdir[k ^ 2];
			q.push({ nx,ny });
			used[nx][ny] = true;
		}
	}
	rep(i, n)rep(j, n) {
		if (used[i][j])continue;
		if (x[i][j] >= 0)continue;
		int d = -1;
		rep(k, 4) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx < 0 || ny < 0 || nx == n || ny == n)continue;
			if (x[nx][ny]<0) {
				d = k;
			}
		}
		if (d < 0) {
			printf("INVALID\n");
			return;
		}
		ans[i][j] = sdir[d];
		queue<P> q; q.push({ i,j }); used[i][j] = true;
		while (!q.empty()) {
			P p = q.front(); q.pop();
			rep(k, 4) {
				int nx = p.first + dx[k];
				int ny = p.second + dy[k];
				if (nx < 0 || ny < 0 || nx == n || ny == n)continue;
				if (x[nx][ny] >= 0)continue;
				if (used[nx][ny])continue;
				ans[nx][ny] = sdir[k ^ 2];
				q.push({ nx,ny });
				used[nx][ny] = true;
			}
		}
	}
	rep(i, n)rep(j, n)if (!used[i][j]) {
		printf("INVALID\n");
		return;
	}
	printf("VALID\n");
	rep(i, n) {
		rep(j, n) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
}


signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//stop
		return 0;
}