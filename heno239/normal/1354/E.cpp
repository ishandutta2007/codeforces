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
void chmax(int &a, int b) {
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

bool can[5001][5001];
bool pre[5001][5001];

vector<int> G[5000];
void solve() {
	int n, m; cin >> n >> m;
	int c[3];
	rep(i, 3)cin >> c[i];
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<vector<int>> v[2];
	vector<bool> used(n);
	vector<int> col(n);
	rep(i, n) {
		if (used[i])continue;
		vector<int> ids[2];
		queue<int> q; q.push(i);
		used[i] = true;
		while (!q.empty()) {
			int id = q.front(); q.pop();
			ids[col[id]].push_back(id);
			for (int to : G[id]) {
				if (used[to]) {
					if (col[to] == col[id]) {
						cout << "NO\n"; return;
					}
					continue;
				}
				used[to] = true;
				col[to] = col[id] ^ 1;
				q.push(to);
			}
		}
		rep(j, 2)v[j].push_back(ids[j]);
	}
	can[0][0] = true;
	rep(i, v[0].size()) {
		rep(j, n + 1) {
			if (can[i][j]) {
				can[i + 1][j + v[0][i].size()] = true;
				pre[i + 1][j + v[0][i].size()] = 0;

				can[i + 1][j + v[1][i].size()] = true;
				pre[i + 1][j + v[1][i].size()] = 1;
			}
		}
	}
	if (!can[v[0].size()][c[1]]) {
		cout << "NO\n"; return;
	}
	int cur = c[1];
	vector<int> ans(n,-1);
	for (int i = v[0].size(); i > 0; i--) {
		for (int id : v[pre[i][cur]][i-1]) {
			ans[id] = 1;
		}
		cur -= v[pre[i][cur]][i - 1].size();
	}
	rep(i, n) {
		if (ans[i] < 0) {
			if (c[0] > 0) {
				ans[i] = 0; c[0]--;
			}
			else {
				ans[i] = 2;
			}
		}
	}
	cout << "YES\n";
	rep(i, n) {
		cout << ans[i] + 1;
	}
	cout << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t;
	//rep(i, t)solve();
	solve();
	stop
		return 0;
}