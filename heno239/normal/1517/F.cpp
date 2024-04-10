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
const int max_n = 1 << 16;
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

struct Data {
	//yes
	vector<modint> dp;
	//no
	vector<modint> dp2;
};
//a is root side
Data merge(Data a, Data b,int d) {
	Data res;
	res.dp.resize(max(a.dp.size(), b.dp.size() + 1));
	res.dp2.resize(max(a.dp.size(), b.dp.size() + 1));
	rep(i, a.dp2.size())rep(j, b.dp2.size()) {
		res.dp2[min(i, j+1)] += a.dp2[i] * b.dp2[j];
	}
	rep(i, a.dp.size())rep(j, b.dp2.size()) {
		modint val = a.dp[i] * b.dp2[j];
		if (i + (j + 1) <= d) {
			res.dp2[j + 1] += val;
		}
		else {
			res.dp[i] += val;
		}
	}
	rep(i, a.dp2.size())rep(j, b.dp.size()) {
		modint val = a.dp2[i] * b.dp[j];
		if (i + j + 1 <= d) {
			res.dp2[i] += val;
		}
		else {
			res.dp[j+1] += val;
		}
	}
	rep(i, a.dp.size())rep(j, b.dp.size()) {
		modint val = a.dp[i] * b.dp[j];
		res.dp[max(i, j + 1)] += val;
	}
	for (int j = d; j < res.dp.size(); j++) {
		res.dp[j] = 0;
	}
	for (int j = d + 1; j < res.dp2.size(); j++) {
		res.dp[0] += res.dp2[j];
		res.dp2[j] = 0;
	}
	return res;
}

void solve() {
	int n; cin >> n;
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int s = n / 2 + 1;
	vector<modint> memo(n+1);
	for (int d = 1; d <=n; d++) {
		function<Data(int, int)> dfs = [&](int id, int fr)->Data {
			Data res;
			res.dp.push_back(1);
			res.dp2.push_back(1);
			for (int to : G[id])if (to != fr) {
				Data nex = dfs(to, id);
				res = merge(res, nex, d);
			}
			return res;
		};
		Data res = dfs(0, -1);
		//rep(i, res.dp.size())memo[d] += res.dp[i];
		rep(i, res.dp2.size())memo[d] += res.dp2[i];
		/*if (d == 1) {
			rep(i, res.dp.size())cout << res.dp[i] << " " << res.dp2[i] << "\n";
		}*/
	}
	/*auto mostfar = [&](int v) {
		vector<bool> used(n);
		used[v] = true;
		int res = v;
		queue<int> q; q.push(v);
		while (!q.empty()) {
			int id = q.front(); q.pop();
			res = id;
			for (int to : G[id])if (!used[to]) {
				used[to] = true;
				q.push(to);
			}
		}
		return res;
	};
	int l = mostfar(0);
	int r = mostfar(l);
	vector<int> dist(n, mod);
	dist[l] = 0;
	queue<int> q; q.push(l);
	while (!q.empty()) {
		int id = q.front(); q.pop();
		for (int to : G[id]) {
			if (dist[to] > dist[id] + 1) {
				dist[to] = dist[id] + 1;
				q.push(to);
			}
		}
	}*/

	//rep(i, s + 1)cout << memo[i] << "\n";
	modint ans = 0;
	for (int d = 1; d < n; d++) {
		modint num = memo[d + 1] - memo[d];
		//cout << d << " " << num << "\n";
		ans += num * (modint)d;
	}
	ans += n;
	ans -= 1;
	ans /= mod_pow(2, n);
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	solve();
	return 0;
}