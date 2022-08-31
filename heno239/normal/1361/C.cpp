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

struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
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


struct edge {
	int to, id;
};
void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	int ans = 0;
	per(i, 21) {
		if (i == 0)continue;
		int k = 1 << i;
		uf u(k+1);
		vector<int> cnt(k, 0);
		rep(j, n) {
			cnt[a[j] % k]++;
			cnt[b[j] % k]++;
			u.unite(a[j] % k, b[j] % k);
		}
		bool valid = true;
		rep(j, k) {
			if (cnt[j] % 2) {
				valid = false; break;
			}
		}
		int tmp = 0;
		rep(j,k) {
			if (cnt[j] == 0)continue;
			if (!u.same(j, k)) {
				u.unite(j, k);
				tmp++;
			}
		}
		if (tmp > 1)valid = false;
		if (valid) {
			ans = i; break;
	    }
	}
	int k = (1 << ans);
	rep(i, n) {
		a[i] %= k; b[i] %= k;
	}
	vector<vector<edge>> G(k);
	rep(i, n) {
		G[a[i]].push_back({ b[i],i });
		G[b[i]].push_back({ a[i],i });
	}
	vector<bool> used(n);
	int cur = a[0];
	vector<int> vs;
	vector<int> es;
	while (true) {
		while (G[cur].size()&&used[G[cur].back().id]) {
			G[cur].pop_back();
		}
		if (G[cur].empty())break;
		vs.push_back(G[cur].back().to);
		es.push_back(G[cur].back().id);
		used[G[cur].back().id] = true;

		int nex = G[cur].back().to;
		G[cur].pop_back();
		cur = nex;
	}
	vector<int> avs, aes;
	while (vs.size()) {
		int v = vs.back();
		while (G[v].size() && used[G[v].back().id]) {
			G[v].pop_back();
		}
		if (G[v].empty()) {
			avs.push_back(vs.back());
			aes.push_back(es.back());
			vs.pop_back();
			es.pop_back();
			continue;
		}
		int cur = v;
		while (true) {
			while (G[cur].size() && used[G[cur].back().id]) {
				G[cur].pop_back();
			}
			if (G[cur].empty())break;
			vs.push_back(G[cur].back().to);
			es.push_back(G[cur].back().id);
			used[G[cur].back().id] = true;

			int nex = G[cur].back().to;
			G[cur].pop_back();
			cur = nex;
		}
	}
	assert(avs.size() == n);
	assert(aes.size() == n);
	int sta = a[0];
	vector<int> ansid;
	per(i, n) {
		int id = aes[i];
		if (sta == a[id]) {
			ansid.push_back(2 * id);
			ansid.push_back(2 * id + 1);
			sta = b[id];
		}
		else {
			ansid.push_back(2 * id + 1);
			ansid.push_back(2 * id);
			sta = a[id];
		}
	}
	cout << ans << "\n";
	rep(i, 2 * n) {
		if (i > 0)cout << " ";
		cout << ansid[i] + 1;
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	solve();
	stop
		return 0;
}