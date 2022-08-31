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
struct edge { int to; ll cap; int rev; };
struct Dinic {
private:
	int n;
	vector<vector<edge>> v;
	vector<int> dist, iter;
public:
	Dinic(int sz) :n(sz), v(sz), dist(sz), iter(sz) {}

	void addedge(int from, int to, ll cap) {
		int x = v[to].size(), y = v[from].size();
		v[from].push_back({ to,cap,x });
		v[to].push_back({ from,0,y });
	}

	void bfs(int s) {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		dist[s] = 0;
		q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			rep(i, v[x].size()) {
				edge& e = v[x][i];
				if (e.cap > 0 && dist[e.to] < 0) {
					dist[e.to] = dist[x] + 1;
					q.push(e.to);
				}
			}
		}
	}

	ll dfs(int x, int t, ll f) {
		if (x == t)return f;
		for (int& i = iter[x]; i < (int)v[x].size(); ++i) {
			edge& e = v[x][i];
			if (e.cap > 0 && dist[x] < dist[e.to]) {
				ll d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					v[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	ll max_flow(int s, int t) {
		ll flow = 0;
		while (1) {
			bfs(s);
			if (dist[t] < 0)return flow;
			fill(iter.begin(), iter.end(), 0);
			ll f;
			while ((f = dfs(s, t, INF)) > 0)flow += f;
		}
	}
};

bool isvalid(vector<P> v) {
	P ori = { 1,0 };
	rep(i, v.size()) {
		if (v[i].first % 2 == 0 && v[i].second % 2 == 0)ori = v[i];
	}
	assert(ori.first % 2 == 0);
	rep(i, v.size()) {
		int dist =max( abs(ori.first - v[i].first),abs(ori.second - v[i].second));
		if (dist > 1)return false;
	}
	return true;
}
void solve() {
	int n; cin >> n;
	vector<ll> x(n), y(n), w(n);
	rep(i, n)cin >> x[i] >> y[i] >> w[i];
	int s = 2*n, t = 2*n + 1;
	map<P, int> mp;
	rep(i, n)mp[{x[i], y[i]}] = i;
	Dinic dc(t + 1);
	rep(i, n) {
		if (y[i] % 2 == 0) {
			if (x[i] % 2 == 0) {
				dc.addedge(i, i + n, w[i]);
				P p = { x[i],y[i] };
				p.second--;
				if (mp.find(p) != mp.end()) {
					dc.addedge(i + n, mp[p] + n, INF);
				}
				p.second += 2;
				if (mp.find(p) != mp.end()) {
					dc.addedge(i + n, mp[p] + n, INF);
				}
			}
			else {
				dc.addedge(s, i, w[i]);
				P p = { x[i],y[i] };
				p.first--;
				if (mp.find(p) != mp.end()) {
					dc.addedge(i, mp[p], INF);
				}
				p.first += 2;
				if (mp.find(p) != mp.end()) {
					dc.addedge(i, mp[p], INF);
				}
			}
		}
		else {
			if (x[i] % 2 == 0) {
				dc.addedge(i + n, i, w[i]);
				P p = { x[i],y[i] };
				p.first--;
				if (mp.find(p) != mp.end()) {
					dc.addedge(i, mp[p], INF);
				}
				p.first += 2;
				if (mp.find(p) != mp.end()) {
					dc.addedge(i, mp[p], INF);
				}
			}
			else {
				dc.addedge(i, t, w[i]);
			}
		}
	}

	ll ans = 0;
	rep(i, n)ans += w[i];
	ans -= dc.max_flow(s, t);
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