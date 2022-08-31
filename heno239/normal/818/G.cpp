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
constexpr ll mod = 998244353;
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
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

template<typename T>
struct mcf {
private:
	struct edge {
		int to, cap; T cost; int rev;
	};
	vector<vector<edge>> G;
	vector<P> par;
	vector<T> dist;
	T inf = mod;
public:
	mcf(int n) {
		G.resize(n);
		par.resize(n);
		dist.resize(n);
	}
	void add_edge(int from, int to, int cap, T cost) {
		G[from].push_back({ to,cap,cost,(int)G[to].size() });
		G[to].push_back({ from,0,-cost,(int)G[from].size() - 1 });
	}
	pair<T, int> minimum_road(int s, int t) {
		fill(all(par), P{ -1,-1 });
		fill(all(dist), inf);
		dist[s] = 0;
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
		q.push({ 0,s });
		while (!q.empty()) {
			pair<T, int> p = q.top(); q.pop();
			int id = p.second;
			if (id == t)continue;
			if (p.first > dist[id])continue;
			rep(j, G[id].size()) {
				if (G[id][j].cap > 0) {
					int to = G[id][j].to;
					T nd = p.first + G[id][j].cost;
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
	T minimum_cost_flow(int s, int t, int k) {
		T ret = 0;
		rep(i, k) {
			pair<T, int> z = minimum_road(s, t);
			if (z.first < 0)return -1;
			if (k - i <= z.second) {
				ret += z.first * (k - i); break;
			}
			i += z.second - 1;
			ret += z.first * z.second;
		}
		return ret;
	}
};

int pre7[5005];
int pre1[5005];
int pre_1[5005];
int pre0[5005];
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	mcf<int> mc(4 * n + 2);
	int s = 4 * n;
	int t = 4 * n + 1;
	rep(i, n) {
		pre7[i] = pre1[i] = pre_1[i] = pre0[i] = -1;
		rep(j, i) {
			if (a[j] % 7 == a[i] % 7)pre7[i] = j;
			if (a[j] == a[i] + 1)pre1[i] = j;
			if (a[j] == a[i] - 1)pre_1[i] = j;
			if (a[j] == a[i])pre0[i] = j;
		}
	}
	rep(i, n) {
		mc.add_edge(4 * i, 4 * i + 1, 1, 0);
		mc.add_edge(s, 4 * i, 4, i);
		mc.add_edge(4 * i + 1, t, 4, n - 1 - i);
		mc.add_edge(4 * i + 1, 4 * i + 2, 4, 0);
		mc.add_edge(4 * i + 1, 4 * i + 3, 4, 0);
		if (pre7[i] >= 0) {
			mc.add_edge(4 * pre7[i] + 2, 4 * i, 4, i - pre7[i] - 1);
		}
		if (pre1[i] >= 0) {
			mc.add_edge(4 * pre1[i] + 3, 4 * i, 4, i - pre1[i] - 1);
		}
		if (pre_1[i] >= 0) {
			mc.add_edge(4 * pre_1[i] + 3, 4 * i, 4, i - pre_1[i] - 1);
		}
		if (pre7[i] >= 0) {
			mc.add_edge(4 * pre7[i] + 2, 4 * i + 2, 4,i - pre7[i]);
		}
		if (pre0[i] >= 0) {
			mc.add_edge(4 * pre0[i] + 3, 4 * i + 3, 4, i - pre0[i]);
		}
	}
	mc.add_edge(s, t, 4, n);
	int ans = 4 * n - mc.minimum_cost_flow(s,t,4);
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	//init_f();
	//init();
	//while(true)
	//expr();
	//init();
	//int t; cin >> t; rep(i,t)
	solve();
	return 0;
}