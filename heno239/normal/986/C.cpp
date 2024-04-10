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
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m) {
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
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


const int MAX_V = 1<<22;
int n;
int V;
vector<int>vs;
bool used[MAX_V];
int cmp[MAX_V];

bool exi[MAX_V];
void dfs(int v) {
	used[v] = true;
	if (exi[v]) {
		if (!used[V - 1 - v])dfs(V - 1 - v);
	}
	rep(j, n)if (v & (1 << j)) {
		if (!used[v ^ (1 << j)])dfs(v ^ (1 << j));
	}
	vs.push_back(v);
}
void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	if (exi[V - 1 - v]) {
		if (!used[V - 1 - v])rdfs(V - 1 - v, k);
	}
	rep(j, n) {
		if ((v & (1 << j)) == 0) {
			if (!used[v ^ (1 << j)])rdfs(v^(1<<j), k);
		}
	}
}
int scc() {
	fill(used, used + V, false);
	vs.clear();
	rep(v, V) {
		if (!used[v])dfs(v);
	}
	fill(used, used + V, false);
	int k = 0;
	per(i, (int)vs.size()) {
		if (!used[vs[i]])rdfs(vs[i], k ++);
	}
	return k;
}
void solve() {
	int m; cin >> n >> m;
	vector<int> a(m);
	rep(i, m) {
		cin >> a[i];
		exi[a[i]] = true;
	}
	/*rep(i, (1 << n)) {
		rep(j, n)if (i & (1 << j)) {
			int to = i ^ (1 << j);
			add_edge(i, to);
		}
	}*/
	V = (1 << n);
	scc();
	vector<bool> b(1 << n);
	rep(i, m) {
		//cout << i << " " << cmp[i] << "\n";
		b[cmp[a[i]]] = true;
	}

	int ans = 0;
	rep(i, 1 << n)if (b[i])ans++;
	cout << ans << "\n";
}






signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
//	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}