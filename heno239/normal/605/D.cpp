#pragma GCC target("avx2")
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

int sz = (1 << 18);
set<P> node[1 << 19];
void add(int i,int j,int id) {
	int k = (i + sz - 1);
	node[k].insert({ j,id });
	while (k > 0) {
		k = (k - 1) / 2;
		node[k].insert({ j,id });
	}
}
void del(int i, int j, int id) {
	int k = (i + sz - 1);
	node[k].erase({ j,id });
	while (k > 0) {
		k = (k - 1) / 2;
		node[k].erase({ j,id });
	}
}
struct ste {
	int k, l, r;
};
vector<int> all_search(int lx, int ly) {
	vector<int> res;
	vector<ste> vs;
	vs.push_back({ 0,0,sz });
	int a = lx, b = sz;
	while (!vs.empty()) {
		ste s = vs.back(); vs.pop_back();
		if (s.r <= a || b <= s.l)continue;
		if (a <= s.l && s.r <= b) {
			P p = { ly,-1 };
			node[s.k].insert(p);
			auto itr = node[s.k].find(p); itr++;
			node[s.k].erase(p);
			while (itr != node[s.k].end()) {
				res.push_back((*itr).second);
				itr++;
			}
		}
		else {
			vs.push_back({ 2 * s.k + 1,s.l,(s.l + s.r) / 2 });
			vs.push_back({ 2 * s.k + 2,(s.l + s.r) / 2,s.r });
		}
	}
	return res;
}

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	rep(i, n)cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<int> vx, vy;
	rep(i, n) {
		vx.push_back(a[i]);
		vx.push_back(c[i]);
		vy.push_back(b[i]);
		vy.push_back(d[i]);
	}
	vx.push_back(0);
	vy.push_back(0);
	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	sort(all(vy));
	vy.erase(unique(all(vy)), vy.end());
	rep(i, n) {
		a[i] = lower_bound(all(vx), a[i]) - vx.begin();
		b[i] = lower_bound(all(vy), b[i]) - vy.begin();
		c[i] = lower_bound(all(vx), c[i]) - vx.begin();
		d[i] = lower_bound(all(vy), d[i]) - vy.begin();
		add(c[i], d[i], i);
	}
	vector<int> nex(n);
	nex[n - 1] = -1;
	vector<int> dist(n,mod);
	dist[n - 1] = 0;
	queue<int> q; q.push(n - 1);
	del(c[n - 1], d[n - 1], n - 1);
	while (!q.empty()) {
		int id = q.front(); q.pop();
		vector<int> nexs = all_search(a[id], b[id]);
		for (int to : nexs) {
			dist[to] = dist[id] + 1;
			nex[to] = id;
			del(c[to], d[to], to);
			q.push(to);
		}
	}
	int mi = mod;
	int chk = -1;
	rep(i, n) {
		if (a[i] == 0 && b[i] == 0) {
			if (dist[i] < mi) {
				mi = dist[i];
				chk = i;
			}
		}
	}
	if (chk < 0) {
		cout << -1 << "\n";
	}
	else {
		cout << mi+1 << "\n";
		vector<int> ans;
		while (chk != n - 1) {
			ans.push_back(chk);
			chk = nex[chk];
		}
		ans.push_back(chk);
		rep(i, ans.size()) {
			if (i > 0)cout << " ";
			cout << ans[i] + 1;
		}
		cout << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	solve();
	return 0;
}