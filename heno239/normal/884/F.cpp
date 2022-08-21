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

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> b(n); rep(i, n)cin >> b[i];
	vector<int> alf(26);
	rep(i, n) {
		alf[s[i] - 'a']++;
	}
	int sta =n / 2 + 26;
	int goa = sta + 1;
	mcf<int> mc(goa + 1);
	rep(i, n / 2) {
		mc.add_edge(i, goa, 2, 0);
	}
	rep(i, 26) {
		mc.add_edge(sta, i + n / 2, alf[i], 0);
		char c = 'a' + i;
		rep(j, n / 2) {
			int cost = 0;
			if (s[j] == c && s[n - 1 - j] == c) {
				cost = max(b[j], b[n - 1 - j]);
			}
			else if (s[j] == c) {
				cost = b[j];
			}
			else if (s[n - 1 - j] == c) {
				cost = b[n - 1 - j];
			}
			mc.add_edge(i + n / 2, j, 1, 100 - cost);
		}
	}
	int ans = mc.minimum_cost_flow(sta, goa, n);
	ans = -(ans - 100 * n);
	cout << ans << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(8);
	//init_f();
	//init();
	//while(true)
	//expr();
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}