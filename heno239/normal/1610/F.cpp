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
const ll mod = 1000000007;
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-4;
const ld pi = acosl(-1.0);

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


struct edge {
	int to, id;
};
bool operator<(edge a, edge b) {
	if (a.to != b.to)return a.to < b.to;
	return a.id < b.id;
}
bool operator==(edge a, edge b) {
	return a.to == b.to && a.id == b.id;
}
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<edge>> G[2];
	rep(i, 2)G[i].resize(n);
	int cnt = 0;
	vector<int> deg(n);
	vector<P> mem;
	vector<int> memw;
	rep(i, m) {
		int a, b, w; cin >> a >> b >> w; a--; b--;
		deg[a] += w;
		deg[b] += w;
		G[w - 1][a].push_back({ b,i });
		G[w - 1][b].push_back({ a,i });
		mem.push_back({ a,b });
		memw.push_back(w);
	}
	rep(i, n)if (deg[i] % 2) {
		cnt++;
	}
	vector<P> ansp(m, { -1,-1 });
	vector<char> ans(m, '0');

	vector<vector<edge>> g[2];
	rep(j, 2)g[j].resize(n);
	rep(j, 2) {
		vector<set<edge>> st(n);
		rep(i, n)for (edge e : G[j][i]) {
			st[i].insert(e);
		}
		vector<bool> used(n);
		vector<int> curv;
		vector<int> curid;
		curid.push_back(-5);
		function<int(int)>dfs = [&](int id)->int {
			if (st[id].empty())return -1;
			used[id] = true;
			curv.push_back(id);
			auto itr = st[id].begin();
			int res = -1;
			//cout << id << "\n";
			while (itr != st[id].end()) {
				edge e = *itr; itr++;
				if (e.id == curid.back())continue;
				//cout << id << " " << e.to << "\n";
				if (used[e.to]) {
					ansp[e.id] = { id,e.to };
					st[id].erase(e);
					st[e.to].erase({ id,e.id });
					res = e.to;
					break;
				}
				else {
					curid.push_back(e.id);
					int z = dfs(e.to);
					curid.pop_back();
					if (z < 0) {
						g[j][id].push_back(e);
						g[j][e.to].push_back({ id,e.id });
						st[id].erase(e);
						st[e.to].erase({ id,e.id });
					}
					else {
						ansp[e.id] = { id,e.to };
						st[id].erase(e);
						st[e.to].erase({ id,e.id });
						if (z != id) {
							res = z; break;
						}
					}
				}
				itr = st[id].lower_bound(e);
			}
			used[id] = false;
			curv.pop_back();
			return res;
		};
		rep(i, n)dfs(i);
		rep(i, n)assert(st[i].empty());
	}

	int cnte = 0;
	rep(i, m) {
		if (ansp[i] == P{-1, -1})cnte++;
	}
	int re = 0;
	rep(j, 2)rep(i, n)re += g[j][i].size();
	assert(cnte * 2 == re);

	vector<vector<int>> fg(2 * n);
	rep(i, n) {
		fg[i].push_back(i + n);
		fg[i + n].push_back(i);
	}
	vector<vector<int>> cur[2];
	rep(j, 2) {
		vector<bool> used(n);
		rep(i, n) {
			if (used[i])continue;
			if (g[j][i].empty())continue;
			function<vector<int>(int,int)> dfs=[&](int id,int fr)->vector<int> {
				used[id] = true;
				vector<int> res;
				for (edge e : g[j][id]) {
					if (e.to == fr)continue;
					vector<int> nr = dfs(e.to, id);
					nr.push_back(e.id);
					ansp[e.id] = { e.to,id };
					bool fin = false;
					if (res.size())fin = true;
					if (id == i && g[j][i].size() % 2 && e == g[j][id].back())fin = true;
					if (!fin) {
						swap(res, nr);
					}
					else {
						per(i, nr.size()) {
							int z = nr[i];
							res.push_back(z);
							swap(ansp[z].first, ansp[z].second);
						}
						cur[j].push_back(res);
						int le = ansp[res[0]].first;
						int ri = ansp[res.back()].second;
						if (j) {
							le += n, ri += n;
						}
						fg[le].push_back(ri);
						fg[ri].push_back(le);
						res.clear();
					}
				}
				return res;
			};
			assert(dfs(i, -1).empty());
		}
	}
	vector<int> col(2 * n,1);
	vector<bool> used(2 * n);
	rep(i, 2 * n) {
		if (used[i])continue;
		queue<int> q;
		q.push(i); used[i] = true;
		while (!q.empty()) {
			int id = q.front(); q.pop();
			for (int to : fg[id]) {
				if (used[to]) {
					assert(col[to] == col[id] * -1);
				}
				else {
					used[to] = true;
					q.push(to);
					col[to] = -col[id];
				}
			}
		}
	}
	rep(j, 2) {
		rep(i, cur[j].size()) {
			int le = ansp[cur[j][i][0]].first;
			if (j)le += n;
			if (col[le] != 1) {
				for (int id : cur[j][i]) {
					swap(ansp[id].first, ansp[id].second);
				}
			}
		}
	}
	string las;
	rep(i, m) {
		//cout << ansp[i].first << " " << ansp[i].second << "\n";
		P z = mem[i]; P rz = { z.second,z.first };
		P rrz = { -1,-1 };
		assert(ansp[i] != rrz);
		assert(ansp[i] == z || ansp[i] == rz);
		if (ansp[i] == mem[i])las.push_back('1');
		else las.push_back('2');
	}
	/*rep(j, 2) {
		cout << "hello " << j << "\n";
		for (vector<int> v : cur[j]) {
			rep(i, v.size())cout << v[i] << " "; cout << "\n";
		}
	}*/
	cout << cnt << "\n";
	cout << las << "\n";
	vector<int> t(n);
	rep(i, m) {
		int l = mem[i].first, r = mem[i].second;
		if (las[i] == '2')swap(l, r);
		t[l] += memw[i];
		t[r] -= memw[i];
	}
	//rep(i, n)cout << t[i] << "\n";
	rep(i, n)if (deg[i] % 2) {
		assert(abs(t[i]) == 1);
	}
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