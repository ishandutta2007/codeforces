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


struct SegT {
private:
	int sz; vector<ll> node;
	const ll init_c = -INF;
public:
	void init(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	ll f(ll a, ll b) {
		return max(a, b);
	}
	void update(int k, ll a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<ll> d(n - 1);
	ll sum = 0;
	rep(i, n-1) {
		d[i] = a[i + 1] - a[i];
		sum += abs(d[i]);
	}

	SegT st[5];
	rep(i, 5)st[i].init(n);
	auto upd=[&](int i) {
		ll ald = 0;
		if (i > 0)ald += abs(d[i - 1]);
		if (i< n - 1)ald += abs(d[i]);

		if (i == 0) {
			/*st[0].update(i, -INF);
			st[2].update(i, -INF);
			st[4].update(i, -INF);*/
			st[1].update(i, d[0] - ald);
			st[3].update(i, -d[0] - ald);
		}
		else if (i == n - 1) {
			/*st[0].update(i, -INF);
			st[2].update(i, -INF);
			st[4].update(i, -INF);*/
			st[1].update(i,-d[n-2] - ald);
			st[3].update(i, d[n-2] - ald);
		}
		else {
			/*st[1].update(i,-INF);
			st[3].update(i,-INF)*/
			st[0].update(i, -d[i - 1] + d[i] - ald);
			st[2].update(i, abs(d[i-1]+d[i]) - ald);
			st[4].update(i, d[i - 1] - d[i] - ald);
		}
	};
	rep(i, n) {
		upd(i);
	}
	int q; cin >> q;
	rep(aa, q) {
		int t, l, r, x; cin >> t >> l >> r >> x; l--; r--;
		if (t == 1) {
			ll ans = -INF;
			rep(i, 5) {
				ll val = st[i].query(l, r + 1);
				val += (ll)(i - 2)*x;
				ans = max(ans, val + sum);
			}
			cout << ans << "\n";
		}
		else {
			if (l > 0) {
				sum -= abs(d[l - 1]);
				d[l - 1] += x;
				sum += abs(d[l - 1]);
				upd(l - 1);
				upd(l);
			}
			if (r < n - 1) {
				sum -= abs(d[r]);
				d[r] -= x;
				sum += abs(d[r]);
				upd(r);
				upd(r + 1);
			}
		}
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