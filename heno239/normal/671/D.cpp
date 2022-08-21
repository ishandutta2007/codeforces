//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
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
const int max_n = 1 << 1;
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

struct Data {
	multiset<LP> st;
	multiset<ll> vals;
	ll ad;
};
void merge(Data& a, Data& b) {
	if (a.st.size() > b.st.size())swap(a, b);
	//cout << a.vals.size() << "\n";
	ll mia = *a.vals.begin()+a.ad;
	ll mib = *b.vals.begin() + b.ad;
	b.ad += mia;
	for (LP p : a.st) {
		ll val = p.second + a.ad + mib;
		b.st.insert({ p.first,val - b.ad });
		b.vals.insert(val - b.ad);
	}
}
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> dep(n, mod);
	queue<int> q;
	q.push(0); dep[0] = 0;
	while (!q.empty()) {
		int id = q.front(); q.pop();
		for (int to : G[id])if (dep[to] == mod) {
			dep[to] = dep[id] + 1;
			q.push(to);
		}
	}
	vector<int> cnt(n);
	vector<vector<P>> ad(n);
	rep(i, m) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		ad[a].push_back({ dep[b],c });
		//cout << a << " " << dep[b] << "\n";
		cnt[a]++; cnt[b]--;
	}
	function<void(int, int)> validfs = [&](int id, int fr) {
		for (int to : G[id])if (to != fr) {
			validfs(to, id);
			cnt[id] += cnt[to];
		}
	};
	validfs(0, -1);
	rep1(i, n - 1)if (cnt[i] == 0) {
		cout << -1 << "\n"; return;
	}
	function<Data(int, int)> dfs = [&](int id, int fr)->Data {
		Data res;
		res.ad = 0;
		for (P p : ad[id]) {
			res.st.insert(p);
			res.vals.insert(p.second);
		}
		res.st.insert({ dep[id],0 });
		res.vals.insert(0);
		//cout << id << " " << res.st.size() << "\n";
		for (int to : G[id])if (to != fr) {
			Data nex = dfs(to, id);
			while ((*--nex.st.end()).first > dep[id]) {
				LP p = *--nex.st.end();
				nex.vals.erase(nex.vals.find(p.second));
				nex.st.erase(--nex.st.end());
			}
			//cout << "? " << id <<" "<<res.vals.size()<< "\n";
			merge(nex, res);
		}
		return res;
	};
	Data a = dfs(0, -1);
	ll ans = *a.vals.begin() + a.ad;
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init(); cout << ps.size() << "\n";
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}