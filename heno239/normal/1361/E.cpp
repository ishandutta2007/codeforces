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

void chmin(int &a, int b) {
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


void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
	}
	int chk = -1;
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<> ut(0, n - 1);
	rep(t, 100) {
		int v = ut(mt);
		vector<bool> used(n, false);
		vector<bool> exi(n, false);
		bool valid = true;
		function<void(int)> dfs = [&](int id)->void {
			exi[id] = true;
			used[id] = true;
			for (int to : G[id]) {
				if (!used[to]) {
					dfs(to);
				}
				else {
					if (!exi[to])valid = false;
				}
			}
			exi[id] = false;
		};
		dfs(v);
		rep(i, n)if (!used[i])valid = false;
		if (valid) {
			chk = v; break;
		}
	}
	if (chk < 0) {
		cout << -1 << "\n"; return;
	}
	int root = chk;
	vector<int> tos(n,-1);

	vector<bool> used(n, false);
	vector<int> par(n);
	par[root] = -1;

	stack<int> stid;
	function<multiset<int>(int)> dfs = [&](int id)->multiset<int> {
		multiset<int> res;
		used[id] = true;
		vector<int> ads;
		for (int to : G[id]) {
			if (!used[to]) {
				par[to] = id;
				multiset<int> nex=dfs(to);
				if (res.size() < nex.size())swap(res, nex);
				for (int id : nex)res.insert(id);
			}
			else {
				res.insert(to);
			}
		}
		while (res.find(id) != res.end())res.erase(res.find(id));
		if (res.size() == 1) {
			tos[id] = *res.begin();
			stid.push(id);
		}
		return res;
	};
	dfs(root);
	vector<int> anss;
	//cout << "? " << root << "\n";
	vector<bool> can(n, false);
	while (!stid.empty()) {
		int id = stid.top(); stid.pop();
		//cout << "! " << id << "\n";
		if (tos[id] == root)can[id] = true;
		else if (can[tos[id]])can[id] = true;
	}
	rep(i, n) {
		if (can[i])anss.push_back(i);
	}
	anss.push_back(root);
	sort(all(anss));
	if (anss.size() * 5 < n) {
		cout << -1 << "\n"; return;
	}
	//cout << anss.size() << "\n";
	rep(i, anss.size()) {
		if (i > 0)cout << " ";
		cout << anss[i] + 1;
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	stop
		return 0;
}