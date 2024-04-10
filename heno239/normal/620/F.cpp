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
const ll mod = 1000000007;
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
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int rx[1 << 20];
int ans =0;
int node[2][1 << 21];
void init() {
	rep(i, (1 << 21) - 1) {
		node[0][i] = mod;
		node[1][i] = -1;
	}
	rx[0] = 0;
	rep(i, (1 << 20) - 1) {
		rx[i + 1] = rx[i] ^ i;
	}
}
int f(int id, int a, int b) {
	if (id == 0)return min(a, b);
	return max(a, b);
}
struct ste {
	int id, k, val,ans,pre;
};
vector<ste> memo;
int query(int id, int x, int val) {
	int k = 0;
	int res = 0;
	per(i, 20) {
		int nk = 2 * k + 2;
		if (x & (1 << i))nk = 2 * k + 1;
		if (f(id,node[id][nk], val) == node[id][nk]) {
			res += (1 << i);
			k = nk;
		}
		else {
			k = 4 * k + 3 - nk;
		}
	}
	assert(k >= (1 << 20) - 1);
	return res;
}
void add(int id, int k, int val) {
	memo.push_back({ id,k,val,ans,node[id][k+(1<<20)-1] });
	k += (1 << 20) - 1;
	node[id][k] = f(id,node[id][k], val);
	while (k > 0) {
		k = (k - 1) / 2;
		node[id][k] = f(id,node[id][2 * k + 1], node[id][2 * k + 2]);
	}
	k = memo.back().k;
	ans = max(ans, query(id^1, k, val));
}
void add(int val) {
	add(0, rx[val], val);
	add(1, rx[val + 1], val);
}
void rev(int num=-1) {
	if (num < 0)num = memo.size()/2;
	num *= 2;
	rep(i, num) {
		ste s = memo.back(); memo.pop_back();
		ans = s.ans;
		node[s.id][s.k + (1 << 20) - 1] = s.pre;
		s.k += (1 << 20) - 1;
		while (s.k > 0) {
			s.k = (s.k - 1) / 2;
			node[s.id][s.k] = f(s.id,node[s.id][2 * s.k + 1], node[s.id][2 * s.k + 2]);
		}
	}
}

const int bl = 200;
void solve() {
	int n, q; cin >> n >> q;
	vector<int>a(n);
	rep(i, n)cin >> a[i];
	init();
	vector<int> l(q), r(q);
	vector<int> ansval(q);
	vector<vector<P>> b((n + bl - 1) / bl);
	rep(i, q) {
		cin >> l[i] >> r[i]; l[i]--; r[i]--;
		if (r[i] - l[i] + 1 <= bl) {
			for (int j = l[i]; j <= r[i]; j++) {
				add(a[j]);
			}
			ansval[i] = ans;
			rev();
		}
		else {
			b[l[i] / bl].push_back({ r[i],i });
		}
	}
	rep(i, b.size()) {
		sort(all(b[i]));
		int loc = bl * (i + 1);
		rep(j, b[i].size()) {
			while (loc <= b[i][j].first) {
				add(a[loc]); loc++;
			}
			int id = b[i][j].second;
			for (int x = bl * (i + 1) - 1; x >= l[id]; x--) {
				add(a[x]);
			}
			ansval[id] = ans;
			rev(bl * (i + 1) - l[id]);
		}
		rev();
	}
	rep(i, q)cout << ansval[i] << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}