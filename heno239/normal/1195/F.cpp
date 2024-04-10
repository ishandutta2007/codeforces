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


struct BIT {
private:
	vector<ll> node, node2; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0); node2.resize(n, 0);
	}
	//0-indexed
	void add(int a, int b, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += -a * w;
		for (int i = b; i < n; i |= i + 1)node[i] += b * w;
		for (int i = a; i < n; i |= i + 1)node2[i] += w;
		for (int i = b; i < n; i |= i + 1)node2[i] += -w;
	}
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i &(i + 1)) - 1)ret += node[i];
		for (int i = a - 1; i >= 0; i = (i &(i + 1)) - 1)ret += a * node2[i];
		return ret;
	}
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

int gcd(int a, int b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}
void solve() {
	int n; cin >> n;
	vector<vector<P>> v;
	rep(i, n) {
		int k; cin >> k;
		vector<int> x(k), y(k);
		rep(j, k) {
			cin >> x[j] >> y[j];
		}
		x.push_back(x[0]);
		y.push_back(y[0]);

		vector<P> vc;
		rep(j, k) {
			int dx = x[j + 1] - x[j];
			int dy = y[j + 1] - y[j];
			int g = gcd(dx, dy);
			dx /= g;
			dy /= g;
			vc.push_back({ dx,dy });
		}
		v.push_back(vc);
	}

	vector<P> vs;
	for (vector<P> p: v) {
		for (P pp : p) {
			vs.push_back(pp);
		}
	}
	sort(all(vs));
	vs.erase(unique(all(vs)), vs.end());

	vector<vector<int>> cols(n);
	rep(i, n) {
		rep(j, v[i].size()) {
			int loc = lower_bound(all(vs), v[i][j]) - vs.begin();
			cols[i].push_back(loc);
		}
	}
	vector<int> pre(vs.size(),-1);

	int q; cin >> q;
	vector<vector<P>> qs(n);
	rep(i, q) {
		int l, r; cin >> l >> r; l--; r--;
		qs[r].push_back({ l,i });
	}

	BIT bt(n);
	vector<int> ans(q);
	rep(i, n) {
		for (int col : cols[i]) {
			bt.add(pre[col] + 1, i + 1, 1);
			pre[col] = i;
		}
		for (P p : qs[i]) {
			int le = p.first;
			int id = p.second;
			ans[id] = bt.sum(le, le + 1);
		}
	}

	rep(i, q) {
		cout << ans[i] << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//int t; cin >> t;rep(i,t)
	solve();
	stop
		return 0;
}