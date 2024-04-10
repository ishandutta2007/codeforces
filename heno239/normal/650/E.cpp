#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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

const int max_n = 1 << 10;
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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
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
void solve() {
	int n; cin >> n;
	vector<set<P>> st1(n), st2(n);
	vector<pair<P, P>> ans;
	uf u(n);
	queue<int> que;
	auto upd = [&](int a1, int b1, int a2, int b2) {
		//cout << "?? " << a1 << " " << b1 << " " << a2 << " " << b2 << "\n";
		if (a1 != a2 || b1 != b2) {
			ans.push_back({ {a1,b1},{a2,b2} });
		}
		int p1 = u.find(a2), p2 = u.find(b2);
		u.unite(p1, p2);
		int p = u.find(p1);
		int x = p1 ^ p2 ^ p;
		if (st1[p].size() < st1[x].size())swap(st1[x], st1[p]);
		if (st2[p].size() < st2[x].size())swap(st2[x], st2[p]);
		for (P id : st1[x])st1[p].insert(id);
		for (P id : st2[x])st2[p].insert(id);
		int q1 = u.find(a1), q2 = u.find(b1);
		st1[q1].erase({ a1,b1 });
		st1[q2].erase({ b1,a1 });

		st2[p].erase({ a2,b2 });
		st2[p].erase({ b2,a2 });
		//cout << "?? " << p<<" "<<x <<" "<<u.find(p)<<" "<<u.find(x)<< "\n";
		//cout << p << " " << a2 << " " << b2 << "\n";
		que.push(q1);
		que.push(q2);
		que.push(p);
	};
	vector<P> e1, e2;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--; if (a > b)swap(a, b);
		e1.push_back({ a,b });
		st1[a].insert({ a,b });
		st1[b].insert({ b,a });
	}
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--; if (a > b)swap(a, b);
		e2.push_back({ a,b });
		st2[a].insert({ a,b });
		st2[b].insert({ a,b });
	}
	sort(all(e1));
	for (P p : e2) {
		int id = lower_bound(all(e1), p) - e1.begin();
		if (id < e1.size() && e1[id] == p) {
			upd(p.first, p.second, p.first, p.second);
		}
	}
	rep(i, n){
		que.push(i);
	}
	while (!que.empty()) {
		int v = que.front(); que.pop();
		if (v != u.find(v))continue;
		if (st1[v].size() != 1)continue;
		//cout << "! "<<v << "\n";
		P p1 = *st1[v].begin();
		P p2 = *st2[v].begin();
		//cout << "? " << v <<" "<<u.find(v)<< " " << p2.first << " " << p2.second << "\n";
		upd(p1.first, p1.second, p2.first, p2.second);
	}
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
		int x1 = ans[i].first.first;
		int y1 = ans[i].first.second;
		int x2 = ans[i].second.first;
		int y2 = ans[i].second.second;
		x1++; y1++; x2++; y2++;
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
	}
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