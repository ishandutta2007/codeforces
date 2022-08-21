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
modint operator^(modint a, ll n) {
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void solve() {
	int n, m,k; cin >> n >> m>>k;
	vector<vector<int>> G(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> ids;
	vector<bool> used(n, false);
	used[0] = true;
	ids.push_back(0);
	queue<int> q;
	q.push(0);


	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int to : G[v]) {
			if (used[to])continue;
			ids.push_back(to);
			used[to] = true;
			q.push(to);
		}
	}

	ids.resize(k);
	vector<bool> exi(n);
	for (int id : ids)exi[id] = true;

	vector<int> col(n);
	vector<int> par(n);
	fill(all(used), false);
	used[0] = true;
	col[0] = 0;
	par[0] = -1;
	q.push(0);

	int c1 = -1, c2 = -1;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int to : G[v]) {
			if (!exi[to])continue;

			if (to == par[v])continue;
			if (used[to]) {
				c1 = v, c2 = to;
				while (!q.empty())q.pop();
				break;
			}
			used[to] = true;
			col[to] = col[v] ^ 1;
			par[to] = v;
			q.push(to);
		}
	}
	if (c1 >= 0) {
		vector<int> cyc0,cyc1;
		int cop = c1;
		while (cop > 0) {
			cyc0.push_back(cop);
			cop = par[cop];
		}
		cyc0.push_back(0);

		cop = c2;
		while (cop > 0) {
			cyc1.push_back(cop);
			cop = par[cop];
		}
		cyc1.push_back(0);
		
		int cp;
		while (cyc0.size() && cyc1.size() && cyc0.back() == cyc1.back()) {
			cp = cyc0.back();
			cyc0.pop_back();
			cyc1.pop_back();
		}

		vector<int> cyc = cyc0;
		cyc.push_back(cp);
		reverse(all(cyc));

		for (int id : cyc1) {
			cyc.push_back(id);
		}

		cout << 2 << "\n";
		cout << cyc.size() << "\n";
		rep(i, cyc.size()) {
			if (i > 0)cout << " ";
			cout << cyc[i] + 1;
		}
		cout << "\n";
	}
	else {
		vector<int> v0, v1;
		rep(i, n)if (exi[i]) {
			if (col[i] == 0)v0.push_back(i);
			else v1.push_back(i);
		}
		if (v0.size() > v1.size())swap(v0, v1);
		vector<int> ans = v1;
		ans.resize((k+1)/2);
		cout << 1 << "\n";
		rep(i, ans.size()) {
			if (i > 0)cout << " ";
			cout << ans[i] + 1;
		}
		cout << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(6);
	//init_f();
	//init();
	//int t; cin >> t;rep(i,t)
	solve();
	stop
		return 0;
}