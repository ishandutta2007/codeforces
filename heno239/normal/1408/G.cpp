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

const int max_n = 1 << 19;
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
	vector<int> par, ran,sz,cnt;
public:
	uf(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		sz.resize(n, 1);
		cnt.resize(n, 0);
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
		cnt[x]++;
		if (x == y) {
			return;
		}
		if (ran[x] < ran[y]) {
			par[x] = y; 
			sz[y] += sz[x];
			cnt[y] += cnt[x];
		}
		else {
			par[y] = x;
			sz[x] += sz[y];
			cnt[x] += cnt[y];
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	bool isclique(int x) {
		x = find(x);
		//cout << "? " <<x<<" "<< sz[x] << " " << cnt[x] << "\n";
		return sz[x] * (sz[x] - 1) / 2 == cnt[x];
	}
};
vector<int> G[3000];
int par[3000];
int find_par(int x) {
	if (par[x] == x)return x;
	else return par[x] = find_par(par[x]);
}

using poly = vector<modint>;
poly merge(poly a, poly b) {
	poly res(a.size() + b.size() - 1);
	rep(i, a.size())rep(j, b.size()) {
		res[i + j] += a[i] * b[j];
	}
	return res;
}

vector<bool> isc(3000);
int n;
poly dfs(int id) {
	if (id < n) {
		return { 0,1 };
	}
	poly res = { 1 };
	for (int to : G[id]){
		res = merge(res, dfs(to));
	}
	if(isc[id])res[1] += 1;
	return res;
}

void solve() {
	rep(i, 3000)par[i] = i;
	cin >> n;
	vector<vector<int>> a(n,vector<int>(n));
	vector<pair<int, P>> vs;
	rep(i, n) {
		rep(j, n) {
			cin >> a[i][j];
			if(i<j)vs.push_back({ a[i][j],{i,j} });
		}
	}
	int tmp = n;
	sort(all(vs));
	uf u(3000);
	rep(i, vs.size()) {
		int le = vs[i].second.first;
		int ri = vs[i].second.second;
		u.unite(le, ri);
		int pl = find_par(le);
		int pr = find_par(ri);
		if (pl != pr) {
			G[tmp].push_back(pl); par[pl] = tmp;
			G[tmp].push_back(pr); par[pr] = tmp;
			tmp++;
		}
		if (u.isclique(le)) {
			le = find_par(le);
			isc[le] = true;
			//cout << "? " << le << "\n";
		}
	}
	poly p = dfs(tmp - 1);
	vector<modint> ans(n + 1);
	rep1(i, n) {
		if (i < p.size())ans[i] = p[i];
		else ans[i] = 0;
	}
	rep1(i, n) {
		if (i > 1)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}