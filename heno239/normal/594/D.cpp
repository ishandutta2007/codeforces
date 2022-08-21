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

struct SegT {
private:
	int sz; vector<vector<P>> node;
	vector<vector<modint>> rnode;
	const P init_c = { mod,mod };
public:
	SegT(vector<P> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1);
		rnode.resize(2 * sz - 1);
		rep(i, n) {
			node[i + sz - 1] = { v[i] };
			rnode[i + sz - 1] = { v[i].second,1 };
		}
		per(i, sz - 1) {
			node[i].resize(node[2 * i + 1].size() + node[2 * i + 2].size());
			int id1 = 0, id2 = 0;
			rep(j, node[i].size()) {
				if (id2 == node[2 * i + 2].size()) {
					node[i][j] = node[2 * i + 1][id1]; id1++;
				}
				else if (id1 == node[2 * i + 1].size()) {
					node[i][j] = node[2 * i + 2][id2]; id2++;
				}
				else {
					if (node[2 * i + 1][id1] < node[2 * i + 2][id2]) {
						node[i][j] = node[2 * i + 1][id1]; id1++;
					}
					else {
						node[i][j] = node[2 * i + 2][id2]; id2++;
					}
				}
			}
			rnode[i].resize(node[i].size() + 1);
			rnode[i].back() = 1;
			per(j, (int)node[i].size()) {
				rnode[i][j] = rnode[i][j+1]*(modint)node[i][j].second;
			}
		}
	}
	modint query(int x,int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return 1;
		else if (a <= l && r <= b) {
			int id = lower_bound(all(node[k]), P{ x,-1 }) - node[k].begin();
			return rnode[k][id];
		}
		else {
			modint vl = query(x,a, b, k * 2 + 1, l, (l + r) / 2);
			modint vr = query(x,a, b, k * 2 + 2, (l + r) / 2, r);
			return vl * vr;
		}
	}
};

const int mn = 1000005;
bool isp[mn];
vector<int> ps;
void init() {
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
		}
	}
}

int cnt[168][200001];
modint res[168];
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<modint> rpro(n + 1);
	rpro[0] = 1;
	rep(i, n) {
		rpro[i + 1] = rpro[i] * (modint)a[i];
	}
	init();
	rep(i, 168)rep(j, n) {
		cnt[i][j + 1] = cnt[i][j];
		while (a[j] % ps[i] == 0) {
			a[j] /= ps[i]; cnt[i][j + 1]++;
		}
	}
	vector<int> r(n);
	map<int, int> las;
	per(i, n) {
		if (a[i] > 1) {
			if (las.find(a[i]) == las.end()) {
				r[i] = n;
			}
			else {
				r[i] = las[a[i]];
			}
			las[a[i]] = i;
		}
		else {
			r[i] = n;
		}
	}
	vector<P> ori(n);
	rep(i, n) {
		if (a[i] > 1) {
			ori[i] = { r[i],(modint)(a[i] - 1) / (modint)a[i] };
		}
		else {
			ori[i] = { r[i],1 };
		}
	}
	SegT st(ori);
	
	rep(j, 168) {
		res[j] = (modint)(ps[j] - 1) / (modint)ps[j];
	}
	int q; cin >> q;
	rep(i, q) {
		int l, r; cin >> l >> r; l--; r--; r++;
		modint ans = rpro[r] / rpro[l];
		ans *= st.query(r, l, r);
		//cout << "!? " << ans << "\n";
		rep(j, 168) {
			int cc = cnt[j][r] - cnt[j][l];
			if (cc > 0) {
				//cout << "! " << j << "\n";
				ans *= res[j];
			}
		}
		cout << ans << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}