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

ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % mod;
		x = x * x % mod; n >>= 1;
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
modint operator^(modint a, int n) {
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



P query(vector<int> v) {
	if (v.empty())return { -1,mod };
	cout << "? " << v.size() << " ";
	rep(i, v.size()) {
		if (i > 0)cout << " ";
		cout << v[i] + 1;
	}
	cout << endl;
	P res;
	cin >> res.first >> res.second;
	res.first--;
	return res;
}

void finquery(int a, int b) {
	cout <<"! "<< a + 1 << " " << b + 1 << endl;
	string res; cin >> res;
	if (res[0] == 'I')exit(0);
}


vector<int> G[1000];

int dep[1000];
int par[1000];
void dfs(int id, int fr) {
	par[id] = fr;
	for (int to : G[id])if (to != fr) {
		dep[to] = dep[id] + 1;
		dfs(to, id);
	}
}


void solve() {
	int n; cin >> n; rep(i, n)G[i].clear();
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<int> ori;
	rep(i, n)ori.push_back(i);

	P p = query(ori);
	int root = p.first;
	int sum = p.second;
	dep[root] = 0;
	dfs(root, -1);
	int le=(sum-1)/2; int ri = sum + 1;
	int ans1;
	while (ri - le > 1) {
		int m = (le + ri) / 2;
		vector<int> qs;
		rep(i, n)if (dep[i] == m)qs.push_back(i);
		P p = query(qs);
		if (p.second == sum) {
			le = m;
			ans1 = p.first;

		}
		else {
			ri = m;
		}
	}
	vector<bool> ban(n, false);
	int cur = ans1;
	while (cur!=root) {
		ban[cur] = true;
		cur = par[cur];
	}
	int rest = sum - le;
	vector<int> ids;
	rep(i, n)if (!ban[i] && dep[i] == rest)ids.push_back(i);
	int ans2;
	if (ids.size() == 1) {
		ans2 = ids[0];
	}
	else {
		P p = query(ids);
		ans2 = p.first;
	}
	finquery(ans1, ans2);
}



signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}