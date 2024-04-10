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


int max_n;
const int mn = 100000;
struct edge {
	int to, cap; ll cost; int rev; int id;
};
vector<edge> G[mn];
P par[mn];
ll dist[mn];
void add_edge(int from, int to, int cap, ll cost, int id = -1) {
	G[from].push_back({ to,cap,cost,(int)G[to].size(),id });
	G[to].push_back({ from,0,-cost,(int)G[from].size() - 1,id });
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
ll minimum_cost_flow(int s, int t, int k) {
	ll ret = 0;
	rep(i, k) {
		LP z = minimum_road(s, t);
		if (z.first < 0)return -1;
		if (k - i <= z.second) {
			ret += z.first*(k - i); break;
		}
		i += z.second - 1;
		ret += z.first*z.second;
	}
	return ret;
}
void solve() {
	int n, m, e, r, b; cin >> n >> m >> e >> r >> b;
	string s, t; cin >> s >> t;
	int sta = n + m; int goa = sta + 1;
	int fsta = sta + 2, fgoa = goa + 2;
	max_n = fgoa + 1;
	int rc = 0, lc = 0;
	rep(i, n) {
		if (s[i] == 'R') {
			add_edge(sta, i, 1, 0); rc++;
			add_edge(fsta, i, mod, 0);
		}
		else if (s[i] == 'B') {
			add_edge(i, goa, 1, 0); lc++;
			add_edge(i, fgoa, mod, 0);
		}
		else {
			add_edge(fsta, i, mod, 0);
			add_edge(i, fgoa, mod, 0);
		}
	}
	rep(i, m) {
		if (t[i] == 'R') {
			add_edge(i + n, fgoa, mod, 0);
			add_edge(i + n, goa, 1, 0); lc++;
		}
		else if (t[i] == 'B') {
			add_edge(fsta, i + n, mod, 0);
			add_edge(sta, i + n, 1, 0); rc++;
		}
		else {
			add_edge(i + n, fgoa, mod, 0);
			add_edge(fsta, i + n, mod, 0);
		}
	}
	rep(i, e) {
		int u, v; cin >> u >> v; u--; v--;
		add_edge(u, v + n, 1, r, i);
		add_edge(v + n, u, 1, b, i + e);
	}
	add_edge(sta, fgoa, lc,0);
	add_edge(fsta, goa, rc, 0);
	add_edge(fgoa, fsta, mod, 0);
	int c = minimum_cost_flow(sta, goa, lc+rc);
	if (c < 0) {
		cout << -1 << endl; return;
	}
	string ans;
	ans.resize(e, 'U');
	rep(i, n) {
		rep(j, G[i].size()) {
			edge &ed = G[i][j];
			if (ed.cap == 0 && ed.id >= 0 && ed.id<e) {
				ans[ed.id] = 'R';
			}
			if (ed.cap == 1 && ed.id >= e) {
				ans[ed.id - e] = 'B';
			}
		}
	}

	cout << c << endl;
	cout << ans << endl;


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