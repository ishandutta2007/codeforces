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
constexpr ll mod = 1000000007;
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
	vector<int> parcost;
	vector<P> mem;
	vector<bool> united;
public:
	ufundo(int n) {
		par.resize(n, 0);
		parcost.resize(n, 0);
		sz.resize(n, 1);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return find(par[x]);
	}
	int findcost(int x) {
		if (par[x] == x)return 0;
		else return (parcost[x] ^ findcost(par[x]));
	}
	void unite(int x, int y,int d) {
		d ^= findcost(x);
		d ^= findcost(y);
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
			parcost[x] = d;
		}
		else {
			par[y] = x; sz[x] += sz[y];
			mem.push_back({ y,x });
			parcost[y] = d;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int getsize(int k) {
		return sz[k];
	}
	void undo() {
		assert(mem.size());
		P p = mem.back(); mem.pop_back();
		bool b = united.back(); united.pop_back();
		if (!b)return;
		int x = p.first, y = p.second;
		par[x] = x;
		sz[y] -= sz[x];
	}
	int dist(int x, int y) {
		return findcost(x) ^ findcost(y);
	}
};



template<typename T,int c>
struct bss {
	vector<T> bs;
	vector<int> ads;
	//const int c = 30;
	void add(T x) {
		int cur = c - 1;
		rep(i, bs.size()) {
			while (!(bs[i] & ((T)1 << cur)))cur--;
			if (x >= ((T)1<<(cur+1))) {
				ads.push_back(i);
				bs.insert(bs.begin() + i, x);
				return;
			}
			if (x & ((T)1 << cur))x ^= bs[i];
		}
		if (x > 0) {
			ads.push_back(bs.size());
			bs.push_back(x);
			return;
		}
		ads.push_back(-1);
	}
	//minimum value with x
	T query(T x) {
		int cur = c - 1;
		rep(i, bs.size()) {
			while (!(bs[i] & ((T)1 << cur)))cur--;
			if (x & ((T)1 << cur))x ^= bs[i];
		}
		return x;
	}
	void rollback(int num=1) {
		rep(_, num) {
			assert(ads.size());
			int id = ads.back(); ads.pop_back();
			if (id >= 0)bs.erase(bs.begin() + id);
		}
	}
};

vector<pair<P, int>> ad[1 << 20];
void solve(){
	int n, m; cin >> n >> m;
	vector<int> sa(m), sb(m), sd(m);
	rep(i, m) {
		cin >> sa[i] >> sb[i] >> sd[i];
		sa[i]--; sb[i]--;
	}
	int q; cin >> q;
	vector<int> t(q), x(q), y(q), d(q);
	rep(i, q) {
		cin >> t[i];
		cin >> x[i] >> y[i]; x[i]--; y[i]--;
		if (t[i] == 1)cin >> d[i];
	}
	function<void(int,int,int,int,int,int,int,int)> addseg= [&](int a,int b,int x, int y,int d,int k,int l,int r) {
		//cout << "? " << k << " " <<l<<" "<<r<<" "<< x << " " << y << " " << d << "\n";
		if (r <= a || b<=l)return;
		if (a <= l && r <= b) {
			//cout << "? " << k << " " << x << " " << y << " " << d << "\n";
			ad[k].push_back({ {x,y},d });
		}
		else {
			int m = (l + r) / 2;
			addseg(a, b,x,y, d, 2 * k + 1, l, m);
			addseg(a, b,x,y, d, 2 * k + 2, m, r);
		}
	};
	map<P, int> mp;
	rep(i, m) {
		mp[{sa[i], sb[i]}] = i;
	}
	rep(i, q) {
		if (t[i] == 1) {
			mp[{x[i], y[i]}] = i + m;
		}
		else if (t[i] == 2) {
			int pre = mp[{x[i], y[i]}];
			if (pre < m) {
				addseg(0,i,sa[pre], sb[pre], sd[pre],0,0,q);
			}
			else {
				addseg(pre - m, i, x[pre - m], y[pre - m], d[pre - m], 0, 0, q);
			}
			mp.erase({ x[i],y[i] });
		}
		else {
			//
		}
	}
	for (auto p : mp) {
		int pre = p.second;
		if (pre < m) {
			addseg(0, q, sa[pre], sb[pre], sd[pre], 0, 0, q);
		}
		else {
			addseg(pre - m, q, x[pre - m], y[pre - m], d[pre - m], 0, 0, q);
		}
	}
	vector<int> ans;
	ufundo u(n);
	bss<int,30> b;


	function<void(int, int, int)> yaru = [&](int k, int l, int r) {
		int cnt = 0;
		int cnt2 = 0;
		for (auto p : ad[k]) {
			int x = p.first.first;
			int y = p.first.second;
			int d = p.second;
			if (u.same(x, y)) {
				d ^= u.dist(x, y);
				b.add(d);
				cnt++;
			}
			else {
				cnt2++;
				u.unite(x, y, d);
			}
		}
		if (l + 1 == r) {
			if (t[l] == 3) {
				assert(u.same(x[l], y[l]));
				int d = u.dist(x[l], y[l]);
				ans.push_back(b.query(d));
			}
		}
		else{
			yaru(2 * k + 1, l, (l + r) / 2);
			yaru(2 * k + 2, (l + r) / 2, r);
		}

		b.rollback(cnt);
		rep(_, cnt2) {
			u.undo();
		}
	};
	yaru(0,0, q);
	rep(i, ans.size())cout << ans[i] << "\n";
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