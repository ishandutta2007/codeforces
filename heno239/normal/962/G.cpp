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
constexpr ll mod = 998244353;
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

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
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
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
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
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

using mP = pair<modint, modint>;
//-----------------------------------

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
	int slx, sly, srx, sry;
	cin >> slx >> sry >> srx >> sly;
	int n; cin >> n;
	vector<int> x(n), y(n);
	rep(i, n)cin >> x[i] >> y[i];
	vector<int> vx,vy;
	vx.push_back(slx);
	vx.push_back(srx);
	vy.push_back(sly);
	vy.push_back(sry);
	rep(i, n) {
		vx.push_back(x[i]);
		vy.push_back(y[i]);
	}
	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	sort(all(vy));
	vy.erase(unique(all(vy)), vy.end());
	rep(i, n) {
		x[i] = lower_bound(all(vx), x[i]) - vx.begin();
		y[i] = lower_bound(all(vy), y[i]) - vy.begin();
	}
	slx = lower_bound(all(vx), slx) - vx.begin();
	srx = lower_bound(all(vx), srx) - vx.begin();
	sly = lower_bound(all(vy), sly) - vy.begin();
	sry = lower_bound(all(vy), sry) - vy.begin();
	vector<int> pre(vy.size(), -1);
	vector<int> nid(vy.size());
	vector<bool> exi(vy.size());
	int tmp = 0;
	vector<pair<int, P>> vp;
	rep(i, n) {
		int ni = (i + 1 == n ? 0 : i + 1);
		if (y[i] == y[ni]) {
			vp.push_back({ y[i],{min(x[i],x[ni]),max(x[i],x[ni])} });
		}
	}
	sort(all(vp));
	uf u(1000000);
	int ans = 0;
	//cout << sly << " " << sry << "\n";
	Rep(x, slx, srx) {
		fill(all(exi), false);
		vector<int> vy;
		rep(i, vp.size()) {
			if (vp[i].second.first <= x && x + 1 <= vp[i].second.second) {
				vy.push_back(vp[i].first);
				//cout << "? " << x<<" "<<vp[i].first << "\n";
			}
		}
		assert(vy.size() % 2 == 0);
		rep(i, vy.size() / 2) {
			Rep(y, vy[2 * i], vy[2 * i + 1]) {
				//cout << "? " << x<<" "<<y << "\n";
				exi[y] = true;
			}
		}
		Rep(y, sly, sry){
			if (exi[y]) {
				if (pre[y] >= 0) {
					//cout << "nande\n";
					nid[y] = pre[y];
				}
				else if (y > sly && exi[y - 1]) {
					nid[y] = nid[y - 1];
				}
				else {
					nid[y] = tmp; tmp++;
				}
				if (y > sly && exi[y - 1]) {
					if (!u.same(nid[y], nid[y - 1])) {
						u.unite(nid[y], nid[y - 1]);
						ans--;
					}
				}
			}
			else {
				nid[y] = -1;
			}
		}
		swap(nid, pre);
	}
	ans += tmp;
	cout << ans << "\n";
	//cout << tmp << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}