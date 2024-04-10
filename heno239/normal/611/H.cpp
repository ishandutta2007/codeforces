#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
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
const int max_n = 1 << 2;
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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

using mP = pair<modint, modint>;
//-----------------------------------

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
	vector<P> calcr(int len, int s) {
		vector<P> res;
		rep(i, len) {
			for (edge e : v[i])if (e.to < s) {
				rep(_, mod - e.cap) {
					res.push_back({ i,e.to });
				}
			}
		}
		return res;
	}
};

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


vector<P> ad[7][7];
int g[7][7];
void solve(){
	int n; cin >> n;
	vector<int> a(n - 1), b(n - 1);
	rep(i, n - 1) {
		string sa, sb; cin >> sa >> sb;
		a[i] = sa.size();
		b[i] = sb.size();
	}
	vector<int> v[7];
	rep1(i, n) {
		int sz = to_string(i).size();
		v[sz].push_back(i);
	}
	rep(i, n - 1) {
		g[min(a[i], b[i])][max(a[i], b[i])]++;
	}

	int sup = 1;
	rep1(i, 6)if (v[i].size())sup = i;

	rep1(i, sup) {
		int cnt = g[i][i];
		if (cnt >= v[i].size()) {
			cout << -1 << "\n"; return;
		}
		rep(_, cnt) {
			int las1 = v[i].back(); v[i].pop_back();
			int las2 = v[i].back();
			ad[i][i].push_back({ las1,las2 });
		}
	}
	//cout << "hello\n";
	//[1,sup]
	vector<P> vp;
	rep1(i, sup)Rep1(j, i + 1, sup)if (g[i][j] > 0) {
		vp.push_back({ i,j });
	}
	int len = vp.size();
	rep(i, (1 << len)) {
		vector<P> ps;
		rep(j, len) {
			if (i & (1 << j))ps.push_back(vp[j]);
		}
		if (ps.size() != sup - 1)continue;
		uf u(sup + 1);
		bool valid = true;
		for (P p : ps) {
			if (u.same(p.first, p.second)) {
				valid = false;
			}
			u.unite(p.first, p.second);
		}
		if (valid) {
			//cout << "imas\n";
			int cop[7][7];
			rep1(i, sup)Rep1(j, i + 1, sup) {
				cop[i][j] = g[i][j];
			}
			for (P p : ps) {
				cop[p.first][p.second]--;
			}
			vector<int> rest(sup + 1);
			rep1(i, sup)rest[i] = v[i].size()-1;
			Dinic dc(sup +1+ vp.size()+2);
			int sta = sup +1+ vp.size();
			int goa = sta + 1;
			//int zsum = 0;
			rep(i, vp.size()) {
				int a = vp[i].first;
				int b = vp[i].second;
				dc.addedge(sta, i, cop[a][b]);
				//zsum += cop[a][b];
				dc.addedge(i, a + vp.size(), mod);
				dc.addedge(i, b + vp.size(), mod);
			}
			int sum = 0;
			rep1(i, sup) {
				dc.addedge(i+vp.size(),goa, rest[i]);
				sum += rest[i];
			}
			int f = dc.max_flow(sta, goa);
			//cout << "waa " << f << " " << sum << "\n";
			if (f != sum)continue;
			//ok!
			vector<P> pp = dc.calcr(vp.size(), sta);
			assert(pp.size() == sum);
			vector<int> king(sup + 1);
			rep1(i, sup) {
				king[i] = v[i].back(); v[i].pop_back();
			}
			for (P p : ps) {
				int a = p.first, b = p.second;
				ad[a][b].push_back({ king[a],king[b] });
			}
			for (P p : pp) {
				int a = vp[p.first].first;
				int b = vp[p.first].second;
				int c = p.second-vp.size();
				if (b == c) {
					assert(v[b].size());
					ad[a][b].push_back({ king[a],v[b].back() });
					v[b].pop_back();
				}
				else {
					assert(v[a].size());
					ad[a][b].push_back({ king[b],v[a].back() });
					v[a].pop_back();
				}
			}

			vector<P> anss;
			rep(i, n - 1) {
				bool sw = false;
				if (a[i] > b[i]) {
					sw = true;
					swap(a[i], b[i]);
				}
				assert(ad[a[i]][b[i]].size());
				anss.push_back(ad[a[i]][b[i]].back());
				ad[a[i]][b[i]].pop_back();
				if (sw)swap(a[i], b[i]);
				if (to_string(anss.back().first).size() != a[i]) {
					swap(anss.back().first, anss.back().second);
				}
			}
			rep(i, n - 1) {
				cout << anss[i].first << " " << anss[i].second << "\n";
			}
			return;
		}
	}
	//cout << "nande\n";
	cout << -1 << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}