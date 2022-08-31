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

const int max_n = 500;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
		par.resize(n, 0);
		ran.resize(n, 1);
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
			ran[y] += ran[x];
		}
		else {
			par[y] = x;
			ran[x] += ran[y];
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

const int mn = 300005;
vector<int> loc[mn];
vector<int> v[mn];
pair<vec, vec> ch[mn];
int memo[mn];

struct edge {
	int to; bool h;
};

bool de[mn];
int col[mn];
vector<edge> G[mn];
void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<bool> b(n);
	rep(i, n) {
		b[i] = (s[i] == '1');
	}
	rep(i, k) {
		int len; cin >> len;
		rep(j, len) {
			int a; cin >> a; a--;
			loc[a].push_back(i);
			v[i].push_back(a);
		}
	}

	/*map<P, bool> mp;
	rep(i, n) {
		if (loc[i].size() == 2) {
			int l = loc[i][0], r = loc[i][1];
			if (l > r)swap(l, r);
			if (mp[{l, r}])continue;
			mp[{l, r}] = true;
			bool h = false;
			if (s[i] == '0')h = true;
			G[l].push_back({ r,h,i });
			G[r].push_back({ l,h,i });
		}
	}*/
	uf u(k);
	rep(i, k) {
		ch[i].first.push_back(i);
	}
	int ans = 0;
	rep(i, n) {
		if (loc[i].size() == 0) {
			//?
		}
		else if (loc[i].size() == 1) {
			int id = loc[i][0];
			int p = u.find(id);
			if (de[p]) {
				//don't exist
			}
			else {
				ans -= min(ch[p].first.size(), ch[p].second.size());
				queue<int> q;
				q.push(id); de[id] = true;
				col[id] = (!b[i]);
				//if (col[id])ans++;
				vector<int> ids;
				while (!q.empty()) {
					int v = q.front(); q.pop();
					ids.push_back(v);
					for (edge e : G[v]) {
						if (de[e.to])continue;
						de[e.to] = true;
						col[e.to] = col[v];
						if (e.h)col[e.to] = !col[e.to];
						q.push(e.to);
					}
				}
				for (int z : ids) {
					if (col[z]) {
						ans++;
					}
					for (int l : v[z]) {
						if (col[z])b[l] = !b[l];
						if (loc[l][0] == z)loc[l].erase(loc[l].begin());
						else loc[l].erase(loc[l].begin() + 1);
					}
				}
			}
		}
		else {
			int l = loc[i][0], r = loc[i][1];
			if (u.same(l, r)) {
				//?
			}
			else {
				bool f = false;
				if (!b[i]) {
					f = !f;
				}
				G[l].push_back({ r,f });
				G[r].push_back({ l,f });
				if (memo[l] != memo[r]) {
					f = !f;
				}
				int lp = u.find(l);
				ans -= min(ch[lp].first.size(), ch[lp].second.size());


				int rp=u.find(r);
				ans -= min(ch[rp].first.size(), ch[rp].second.size());
				
				u.unite(lp, rp);
				int p = u.find(lp);
				int fr = p ^ lp^rp;
				int to = p;
				for (int id : ch[fr].first) {
					if (f) {
						ch[to].second.push_back(id);
						memo[id] = 1;
					}
					else {
						ch[to].first.push_back(id);
					}
				}
				for (int id : ch[fr].second) {
					if (f) {
						ch[to].first.push_back(id);
						memo[id] = 0;
					}
					else {
						ch[to].second.push_back(id);
					}
				}
				ans += min(ch[to].first.size(), ch[to].second.size());
			}
		}
		cout << ans << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f(); init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}