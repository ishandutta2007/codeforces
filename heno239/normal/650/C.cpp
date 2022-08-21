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
#include<array>
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
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m) {
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

struct uf {
private:
	vector<int> par, ran;
public:
	void init(int n) {
		par.clear();
		ran.clear();
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> ans(n, vector<int>(m));
	vector<int> mh(n, 0);
	vector<int> mw(m, 0);
	vector<pair<int, P>> vs;
	rep(i, n)rep(j, m) {
		cin >> a[i][j];
		vs.push_back({ a[i][j],{i,j} });
	}


	sort(all(vs));
	vector<pair<P, int>> memo;
	vector<int> score;
	uf u;
	vector<int> idh(n, -1), idw(m, -1);
	rep(i, vs.size()) {
		int le = i;
		while (i + 1 < vs.size() && vs[i].first == vs[i + 1].first) {
			i++;
		}
		memo.clear();
		int len = i - le + 1;
		u.init(len);
		score.clear(); score.resize(len);

		for (int j = le; j <= i; j++) {
			int x = vs[j].second.first, y = vs[j].second.second;
			if (idh[x] >= 0) {
				u.unite(idh[x], j - le);
			}
			if (idw[y] >= 0) {
				u.unite(idw[y], j - le);
			}
			idh[x] = idw[y] = j - le;
		}
		for (int j = le; j <= i; j++) {
			int x = vs[j].second.first, y = vs[j].second.second;
			int val = max(mh[x], mw[y]) + 1;
			int p = u.find(j - le);
			score[p] = max(score[p], val);
		}


		for (int j = le; j <= i; j++) {
			int x = vs[j].second.first, y = vs[j].second.second;
			int p = u.find(j - le);
			int val = score[p];
			ans[x][y] = val;
			mh[x] = max(mh[x], val);
			mw[y] = max(mw[y], val);
			idh[x] = idw[y] = -1;
		}
	}
	rep(i, n){
		rep(j, m) {
			if (j > 0)cout << " ";
			cout << ans[i][j];
		}
		cout << "\n";
	}
}

signed main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}