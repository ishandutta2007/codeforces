#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
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
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
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
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 2;
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

int dp[19][1 << 18];
P pre[19][1 << 18];
int score[18];
bool can[1 << 18][18];
void solve() {
	int n,m; cin >> n >> m;
	vector<vector<int>> G(n);
	vector<vector<int>> rG(n);
	rep(i, m) {
		int x, y, c; cin >> x >> y >> c;
		x--; y--;
		G[x].push_back(y);
		rG[y].push_back(x);
		score[x] += c;
		score[y] -= c;
	}
	rep(i, (1 << n)) {
		rep(j, n) {
			if (i & (1 << j))continue;
			bool valid = true;
			for (int to : G[j]) {
				if (i & (1 << to))continue;
				valid = false;
			}
			can[i][j] = valid;
		}
	}

	queue<int> q;
	vector<int> cnt(n);
	vector<int> ids;
	rep(i, n) {
		cnt[i] = G[i].size();
		if (cnt[i] == 0)q.push(i);
	}
	while (!q.empty()) {
		int v = q.front(); q.pop();
		ids.push_back(v);
		for (int to : rG[v]) {
			cnt[to]--;
			if (cnt[to] == 0) {
				q.push(to);
			}
		}
	}
	reverse(all(ids));
	//for (int id : ids)cout << id << "\n";

	rep(i, n + 1)rep(j, (1 << n))dp[i][j] = mod;
	dp[0][0] = 0;

	rep(i, n) {
		vector<int> cop(1 << n);
		vector<int> p(1 << n);
		rep(j, (1 << n)) {
			cop[j] = dp[i][j];
			p[j] = j;
		}
		for (int id : ids) {
			rep(j, (1 << n)) {
				if (j & (1 << id))continue;
				if (can[j][id]) {
					int nj = j ^ (1 << id);
					if (cop[nj] > cop[j] + i * score[id]) {
						cop[nj] = cop[j] + i * score[id];
						p[nj] = p[j];
					}
				}
			}
		}
		rep(j, (1 << n)) {
			dp[i + 1][j] = cop[j];
			pre[i + 1][j] = { i,p[j] };
		}
	}
	int mi = mod;
	int t = 0, chk = 0;
	rep(i, n + 1) {
		if (mi > dp[i][(1 << n) - 1]) {
			mi = dp[i][(1 << n) - 1];
			t = i;
			chk = (1 << n) - 1;
		}
	}
	//cout << mi << "\n";
	vector<int> ans(n, 0);
	while (chk > 0) {
		//cout << t << " " << chk << "\n";
		int nex = pre[t][chk].second;
		int dif = nex ^ chk;
		rep(j, n)if (dif & (1 << j))ans[j] = t;
		t = pre[t][chk].first;
		chk = nex;
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}