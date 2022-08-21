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
//#include<atcoder/dsu>
//#include<atcoder/fenwicktree>
//#include<atcoder/math>
//#include<atcoder/maxflow>

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
const ld eps = 1e-8;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (x >= m)x %= m;
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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}

struct edge {
	int to, col;
};

void solve() {
	int n,m; cin >> n>>m;
	vector<vector<edge>> rG(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		int c; cin >> c;
		rG[b].push_back({ a,c });
	}

	vector<int> dist(n, mod);
	queue<int> q; q.push(n - 1); dist[n - 1] = 0;
	vector<bool> colered(n, false);
	vector<int> col(n);
	int tmp = 0;
	while (!q.empty()) {
		tmp++;
		int len = q.size();
		vector<P> vs;
		vector<int> nex;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (edge e : rG[v]) {
				if (dist[e.to] == mod) {
					if (colered[e.to]) {
						if (col[e.to] == e.col) {
							nex.push_back(e.to);
						}
					}
					else {
						vs.push_back({ e.to,e.col });
					}
				}
			}
		}
		sort(all(nex));
		nex.erase(unique(all(nex)), nex.end());
		sort(all(vs));
		vs.erase(unique(all(vs)), vs.end());
		rep(i, vs.size()) {
			P p = vs[i];
			int id = p.first;
			if (i + 1 < vs.size() && vs[i].first == vs[i + 1].first) {
				colered[id] = true;
				col[id] = 0;

				nex.push_back(id);
				i++;
				continue;
			}
			colered[id] = true;
			col[id] = p.second ^ 1;
		}
		for (int id : nex) {
			dist[id] = tmp; q.push(id);
		}
	}
	int d = dist[0];
	if (d == mod)d = -1;
	cout << d << "\n";
	string ans; ans.resize(n);
	rep(i, n) {
		ans[i] = '0' + col[i];
	}
	cout << ans << "\n";
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