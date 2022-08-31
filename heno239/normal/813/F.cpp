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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct ste {
	int a, b;
	bool united,bip;
};
struct ufundo {
private:
	bool isbip;
	vector<int> par, sz;
	vector<int> parcost;
	vector<ste> mem;
public:
	ufundo(int n) {
		par.resize(n, 0);
		sz.resize(n, 1);
		parcost.resize(n, 0);
		rep(i, n) {
			par[i] = i;
		}
		isbip =true;
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return find(par[x]);
	}
	int dist_par(int x) {
		if (par[x] == x)return 0;
		else return dist_par(par[x])^parcost[x];
	}
	int get_par(int x) {
		return par[x];
	}
	void unite(int x, int y) {
		int mx = x, my = y;
		int z = dist_par(mx) ^ dist_par(my);
		x = find(x), y = find(y);
		if (x == y) {
			mem.push_back({ x,y,false,isbip });
			if (z == 0)isbip = false;
			return;
		}
		if (sz[x] < sz[y]) {
			parcost[x] = 1 ^ z;
			par[x] = y; sz[y] += sz[x];
			mem.push_back({ x,y,true,isbip });
		}
		else {
			parcost[y] = 1 ^ z;
			par[y] = x; sz[x] += sz[y];
			mem.push_back({ y,x,true,isbip });
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int getsize(int k) {
		return sz[k];
	}
	void undo(int num=1) {
		assert(mem.size()>=num);
		rep(i, num) {
			ste s = mem.back(); mem.pop_back();
			isbip = s.bip;
			if (!s.united)continue;
			par[s.a] = s.a;
			parcost[s.a] = 0;
			sz[s.b] -= sz[s.a];
		}
	}
	void allundo() {
		undo(mem.size());
	}
	bool query() {
		return isbip;
	}
};

const int bl = 100;
void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(q), b(q);
	rep(i, q) {
		cin >> a[i] >> b[i]; a[i]--; b[i]--;
	}
	vector<pair<P, P>> seg;
	map<P, int> mp;
	rep(i, q) {
		P p = { a[i],b[i] };
		if (mp.find(p) != mp.end()) {
			int pre = mp[p];
			seg.push_back({ {pre,i},p });
			mp.erase(p);
		}
		else {
			mp[p] = i;
		}
	}
	for (auto p : mp) {
		seg.push_back({ {p.second,q},p.first });
	}
	vector<int> ans(q);
	ufundo u(n);
	
	for (int l = 0; l < q; l += bl) {
		u.allundo();
		int r = min(q, l + bl);
		vector<vector<P>> ad(r - l);
		vector<vector<P>> del(r - l);
		//[l,r)
		rep(i, seg.size()) {
			int le = seg[i].first.first;
			int ri = seg[i].first.second;
			int a = seg[i].second.first;
			int b = seg[i].second.second;
			le = max(le, l);
			ri = min(ri, r);
			if (le < ri) {
				if (le == l && ri == r) {
					u.unite(a, b);
				}
				else {
					ad[le - l].push_back({ a,b });
					if (ri < r)del[ri - l].push_back({ a,b });
				}
			}
		}
		set<P> ce;
		rep(i, r - l) {
			for (P p : ad[i])ce.insert(p);
			for (P p : del[i])ce.erase(p);
			for (P p : ce) {
				u.unite(p.first, p.second);
			}
			//cout << "? " << i + l << " " << ce.size() << "\n";
			ans[i + l] = u.query();
			u.undo(ce.size());
		}
	}
	rep(i, q) {
		if (ans[i])cout << "YES\n";
		else cout << "NO\n";
	}
	
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}