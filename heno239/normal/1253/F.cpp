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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
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

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


ll ans[1 << 19];
vector<P> querys[1 << 17];

struct uf {
private:
	vector<int> par, num;
	vector<set<int>> st;
public:
	uf(int n) {
		par.resize(n, 0);
		num.resize(n, 1);
		st.resize(n);
		rep(i, n) {
			par[i] = i;
			st[i].insert(i);
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y,ll d) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (num[x] > num[y])swap(x, y);
		par[x] = y;
		for (int v : st[x]) {
			for (P p : querys[v]) {
				if (st[y].find(p.first) != st[y].end()) {
					ans[p.second] = d;
				}
			}
		}
		for (int v : st[x])st[y].insert(v);
		num[y] += num[x];
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

struct edge {
	int to, cost;
};
vector<edge> G[1 << 17];

ll dist[1 << 17];
int id[1 << 17];

void solve() {
	int n, m, k, q; cin >> n >> m >> k >> q;
	rep(i, m) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	fill(dist, dist + n, INF);
	priority_queue<LP, vector<LP>, greater<LP>> que;
	rep(i, k) {
		dist[i] = 0;
		id[i] = i;
		que.push({ 0,i });
	}
	while (!que.empty()) {
		LP p = que.top(); que.pop();
		int v = p.second;
		if (dist[v] < p.first)continue;
		for (auto&& e : G[v]) {
			ll nd = p.first + e.cost;
			if (nd < dist[e.to]) {
				dist[e.to] = nd;
				id[e.to] = id[v];
				que.push({ nd,e.to });
			}
		}
	}
	vector<pair<ll, P>> v;
	rep(i, n) {
		for (auto&& e : G[i]) {
			if (i > e.to)continue;
			v.push_back({ dist[i] + dist[e.to] + e.cost,{i,e.to} });
		}
	}
	sort(v.begin(), v.end());
	rep(i, q) {
		int a, b; cin >> a >> b; a--; b--;
		querys[a].push_back({ b,i });
		querys[b].push_back({ a,i });
	}
	uf u(n);
	rep(i, v.size()) {
		int l = v[i].second.first;
		int r = v[i].second.second;
		if (u.same(l, r))continue;
		u.unite(l, r, v[i].first);
	}
	rep(i, q) {
		cout << ans[i] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}