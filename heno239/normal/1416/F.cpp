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
			while ((f = dfs(s, t, 1LL << 62)) > 0)flow += f;
		}
	}
	vector<vector<edge>> take() {
		return v;
	}
};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

string dis = "LRDU";
char trans(int i, int j, int x, int y) {
	if (i == x) {
		if (j > y)return 'L';
		else return 'R';
	}
	else {
		if (i > x)return 'U';
		else return 'D';
	}
}
void solve() {
	int h, w; cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h)rep(j, w) {
		cin >> a[i][j];
	}
	vector<vector<bool>> b(h, vector<bool>(w,false));
	rep(i, h)rep(j, w) {
		rep(d, 4) {
			int x = i + dx[d];
			int y = j + dy[d];
			if (x < 0 || y < 0 || x == h || y == w)continue;
			if (a[x][y] < a[i][j])b[i][j] = true;
		}
	}
	int s = h * w;
	int t = s + 1;
	int xs = t + 1;
	int xt = xs + 1;
	Dinic dc(h*w+4);
	//dc.addedge(xs, s, mod);
	//dc.addedge(t, xt, mod);
	rep(i, h)rep(j, w) {
		int id = (i + j) % 2;
		int cur = i * w + j;
		if (b[i][j]) {
			if (id == 0) {
				dc.addedge(s, cur, 1);
				//dc.addedge(s, xt, 0);
				//dc.addedge(xs, cur, 0);
			}
			else {
				dc.addedge(cur, t, 1);
				//dc.addedge(cur,xt,0);
				//dc.addedge(xs,t,0);
			}
		}
		else {
			if (id == 0) {
				//dc.addedge(s, cur, 0);
				dc.addedge(s, xt, 1);
				dc.addedge(xs, cur, 1);
			}
			else {
				//dc.addedge(cur, t, 0);
				dc.addedge(cur,xt,1);
				dc.addedge(xs,t,1);
			}
		}
		if (id == 0) {
			rep(d, 4) {
				int x = i + dx[d];
				int y = j + dy[d];
				if (x < 0 || y < 0 || x == h || y == w)continue;
				int to = x * w + y;
				if (a[i][j] == a[x][y]) {
					dc.addedge(cur, to, 1);
				}
			}
		}
	}
	int f = dc.max_flow(xs, xt);
	f += dc.max_flow(s, xt);
	f += dc.max_flow(xs, t);
	f += dc.max_flow(s, t);
	vector<vector<edge>> g = dc.take();
	vector<vector<char>> mp(h, vector<char>(w,'?'));
	vector<vector<int>> ansval(h, vector<int>(w));
	rep(i, h)rep(j, w) {
		int id = (i + j) % 2;
		int cur = i * w + j;
		if (!b[i][j]) {
			if (id == 0) {
				for (edge e : g[cur]) {
					if (e.to == xs) {
						if (e.cap == 0) {
							cout << "NO" << "\n"; return;
						}
					}
					else {
						if (e.cap == 0) {
							int nx = e.to / w;
							int ny = e.to % w;
							mp[i][j] = trans(i, j, nx, ny);
							mp[nx][ny] = trans(nx, ny, i, j);
							ansval[i][j] = 1;
							ansval[nx][ny] = a[i][j] - 1;
						}
					}
				}
			}
			else {
				for (edge e : g[cur]) {
					if (e.to == xt) {
						if (e.cap == 1) {
							cout << "NO" << "\n"; return;
						}
					}
				}
			}
		}
		else {
			if (id == 0) {
				for (edge e : g[cur]) {
					if (e.to != s) {
						if (e.cap == 0) {
							int nx = e.to / w;
							int ny = e.to % w;
							mp[i][j] = trans(i, j, nx, ny);
							mp[nx][ny] = trans(nx, ny, i, j);
							ansval[i][j] = 1;
							ansval[nx][ny] = a[i][j] - 1;
						}
					}
				}
			}
		}
	}
	rep(i, h)rep(j, w) {
		if (mp[i][j] != '?')continue;
		assert(b[i][j]);
		rep(d, 4) {
			int x = i + dx[d];
			int y = j + dy[d];
			if (x < 0 || y < 0 || x == h || y == w)continue;
			if (a[i][j] > a[x][y]) {
				mp[i][j] = trans(i, j, x, y);
				ansval[i][j] = a[i][j] - a[x][y];
			}
		}
	}
	cout << "YES\n";
	rep(i, h){
		rep(j, w) {
			if (j > 0)cout << " ";
			cout << ansval[i][j];
		}
		cout << "\n";
	}
	rep(i, h) {
		rep(j, w) {
			if (j > 0)cout << " ";
			cout << mp[i][j];
		}
		cout << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
		solve();
	return 0;
}