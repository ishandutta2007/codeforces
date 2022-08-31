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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

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
	vector<int> x(n), y(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
	}
	uf u(n + 1);
	vector<pair<ll, P>> v;
	vector<ll> c(n), k(n);
	rep(i, n) {
		cin >> c[i];
		v.push_back({ c[i],{n,i} });
	}
	rep(i, n) {
		cin >> k[i];
	}
	rep(i, n) {
		Rep(j, i + 1, n) {
			ll cost = (k[i] + k[j])*(abs(x[i] - x[j]) + abs(y[i] - y[j]));
			v.push_back({ cost,{i,j} });
		}
	}
	sort(v.begin(), v.end());

	vector<int> p;
	vector<P> con;
	ll sum = 0;
	rep(i, v.size()) {
		int l = v[i].second.first, r = v[i].second.second;
		if (u.same(l, r))continue;
		u.unite(l, r);
		sum += v[i].first;
		if (l == n) {
			p.push_back(r);
		}
		else {
			con.push_back({ l,r });
		}
	}
	cout << sum << endl;
	cout << p.size() << endl;
	rep(i, p.size()) {
		if (i > 0)cout << " ";
		cout << p[i] + 1;
	}
	cout << endl;
	cout << con.size() << endl;
	rep(i, con.size()) {
		cout << con[i].first + 1 << " " << con[i].second + 1 << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}