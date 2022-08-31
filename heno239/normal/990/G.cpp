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
struct ufundo {
private:
	vector<int> par, sz;
	vector<P> mem;
	vector<bool> united;
public:
	ufundo(int n) {
		par.resize(n, 0);
		sz.resize(n, 1);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			mem.push_back({ x,y });
			united.push_back(false);
			return;
		}
		united.push_back(true);
		if (sz[x] < sz[y]) {
			par[x] = y; sz[y] += sz[x];
			mem.push_back({ x,y });
		}
		else {
			par[y] = x; sz[x] += sz[y];
			mem.push_back({ y,x });
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int getsize(int k) {
		return sz[find(k)];
	}
	void undo(int num) {
		rep(_, num) {
			assert(mem.size());
			P p = mem.back(); mem.pop_back();
			bool b = united.back(); united.pop_back();
			if (!b)return;
			int x = p.first, y = p.second;
			par[x] = x;
			sz[y] -= sz[x];
		}
	}
};


const int mn = 200001;
bool isp[mn];
int meb[mn];
void init() {
	fill(meb + 1, meb + mn, 1);
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		meb[i] *= -1;
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
			meb[j] *= -1;
			if ((j / i) % i == 0)meb[j] = 0;
		}
	}
}
template<typename T>
vector<T> gcdconv(vector<T>& v) {
	//assert(v.size()==mn)
	vector<T> res(v.size());
	rep1(i, res.size() - 1) {
		T val = 0;
		for (int j = 1; j * i < res.size(); j++) {
			if (meb[j] == 0)continue;
			val += (T)meb[j] * v[j * i];
		}
		res[i] = val;
	}
	return res;
}

vector<int> loc[mn + 1];

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	rep(i, n)loc[a[i]].push_back(i);
	vector<vector<int>> G(n);
	rep(i, n-1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<bool> exi(mn);
	vector<ll> ori(mn);
	ufundo u(n);
	rep1(i, mn - 1) {
		int tmp = 0;
		for (int j = i; j < mn; j += i) {
			for (int id : loc[j]) {
				exi[id] = true;
				ori[i]++;
				for (int to : G[id])if (exi[to]) {
					int cl = u.getsize(id);
					int cr = u.getsize(to);
					ori[i] += (ll)cl * cr;
					u.unite(id, to);
					tmp++;
				}
			}
		}
		for (int j = i; j < mn; j += i) {
			for (int id : loc[j]) {
				exi[id] = false;
			}
		}
		//if(ori[i]>0)cout << "? " << i << " " << ori[i] << "\n";
		u.undo(tmp);
	}
	vector<ll> res = gcdconv(ori);
	rep1(i, mn - 1) {
		if (res[i] > 0) {
			cout << i << " " << res[i] << "\n";
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}