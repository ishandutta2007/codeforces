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

int max_n;
const int mn = 100000;
struct edge {
	int to, cap; ll cost; int rev;
};
vector<edge> G[mn];
P par[mn];
ll dist[mn];
void add_edge(int from, int to, int cap, ll cost) {
	G[from].push_back({ to,cap,cost,(int)G[to].size() });
	G[to].push_back({ from,0,-cost,(int)G[from].size() - 1 });
	max_n = max({ max_n, from + 1, to + 1 });
}
void add_edge2(int from, int to, int cap, ll cost) {
	G[from].push_back({ to,cap,cost,-1 });
	//G[to].push_back({ from,0,-cost,(int)G[from].size() - 1 });
	max_n = max({ max_n, from + 1, to + 1 });
}
LP minimum_road(int s, int t) {
	fill(par, par + max_n, P{ -1,-1 });
	fill(dist, dist + max_n, INF);
	dist[s] = 0;
	priority_queue<LP, vector<LP>, greater<LP>> q; q.push({ 0,s });
	while (!q.empty()) {
		LP p = q.top(); q.pop();
		int id = p.second;
		if (id == t)continue;
		if (p.first > dist[id])continue;
		rep(j, G[id].size()) {
			if (G[id][j].cap > 0) {
				int to = G[id][j].to;
				ll nd = p.first + G[id][j].cost;
				if (nd < dist[to]) {
					dist[to] = nd;
					par[to] = { id,j };
					q.push({ dist[to],to });
				}
			}
		}
	}
	int cur = t;
	int f = mod;
	while (cur != s) {
		int p = par[cur].first, j = par[cur].second;
		if (p < 0)return { -1,-1 };
		f = min(f, G[p][j].cap);
		cur = p;
	}
	cur = t;
	while (cur != s) {
		int p = par[cur].first, j = par[cur].second;
		if (p < 0)return { -1,-1 };
		G[p][j].cap -= f;
		if (G[p][j].rev >= 0) {
			G[cur][G[p][j].rev].cap += f;
		}
		cur = p;
	}
	return { dist[t],f };
}
ll minimum_cost_flow(int s, int t, int k = mod) {
	ll ret = 0;
	rep(i, k) {
		LP z = minimum_road(s, t);
		if (z.first < 0)return ret;
		if (k - i <= z.second) {
			ret += z.first * (k - i); break;
		}
		i += z.second - 1;
		ret += z.first * z.second;
	}
	return ret;
}


void solve() {
	int n, m; cin >> n >> m;
	vector<int> d(n + 2 * m);
	rep(i, m) {
		int a, b, c, f; cin >> a >> b >> c >> f;
		a--; b--;
		int le = n + 2 * i;
		int ri = n + 2 * i + 1;
		//a->le
		add_edge(a, le, mod, 1);
		add_edge(le, a, f, 1);
		//ri->b
		add_edge(ri, b, mod, 1);
		add_edge(b, ri, f, 1);
		//le->ri
		add_edge(le, ri, c, 0);
		add_edge(le, ri, mod, 2);

		d[a] += -f;
		d[le] += f;
		d[ri] += -f;
		d[b] += f;
	}
	int sum = 0;
	int s = n + 2 * m;
	int t = s + 1;
	int sum2 = 0;
	int S = t + 1;
	int T = S + 1;
	rep(i, n + 2 * m) {
		if (d[i] > 0) {
			sum += abs(d[i]);
			add_edge(s, i, d[i], 0);
		}
		else if (d[i]< 0) {
			sum2+= abs(d[i]);
			add_edge(i, t, -d[i], 0);
		}
	}
	max_n = T + 1;
	add_edge(n - 1, 0, mod, 0);
	//cout << sum << " " << sum2 << "\n";
	int ans = 0;
	ans += minimum_cost_flow(s,t, sum);
	//assert(ans % 2 == 0);
//cout << ans << "\n";
	cout << ans/2  << "\n";
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