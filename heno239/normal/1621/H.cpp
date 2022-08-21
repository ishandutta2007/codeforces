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

struct edge {
	int to, cost;
};

int par[1 << 18][18];
int parcost[1 << 18];

int curp[1 << 18][26];
int curf[1 << 18][26];
void solve(){
	int n; cin >> n;
	vector<vector<edge>> G(n);
	rep(i, n - 1) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	int k; cin >> k; string s; cin >> s;
	vector<int> p(k), f(k);
	rep(i, k)cin >> p[i];
	rep(i, k)cin >> f[i];
	int t; cin >> t;
	int q; cin >> q;
	vector<int> typ(q); vector<char> alf(q); vector<int> x(q);
	rep(i, q) {
		cin >> typ[i];
		if (typ[i] != 3)cin >> alf[i];
		cin >> x[i];
	}

	vector<ll> dep(n);
	function<void(int, int)> initdfs = [&](int id, int fr) {
		par[id][0] = fr;
		for (edge e : G[id])if (e.to != fr) {
			dep[e.to] = dep[id] + e.cost;
			parcost[e.to] = e.cost;
			initdfs(e.to, id);
		}
	};
	initdfs(0, -1);

	rep(j, 17) {
		rep(i, n) {
			if (par[i][j] < 0)par[i][j + 1] = -1;
			else par[i][j + 1] = par[par[i][j]][j];
		}
	}
	rep(j, k) {
		curf[0][j] = f[j];
		curp[0][j] = p[j];
	}
	vector<vector<int>> qs(n);
	rep(i, q) {
		rep(j, k) {
			curf[i + 1][j] = curf[i][j];
			curp[i + 1][j] = curp[i][j];
		}
		if (typ[i] == 1) {
			curp[i + 1][alf[i] - 'A'] = x[i];
		}
		else if (typ[i] == 2) {
			curf[i + 1][alf[i] - 'A'] = x[i];
		}
		else{
			qs[x[i]-1].push_back(i);
		}
	}
	auto findpar = [&](int id) {
		per(j, 18) {
			if (par[id][j] >= 0 && s[par[id][j]] == s[id])id = par[id][j];
		}
		return id;
	};
	auto calccost = [&](ll num, ll cf, ll cp) {
		if (cp / cf < num)return cp;
		return min(cf * num, cp);
	};
	vector<ll> ans(q);
	function<set<int>(int, int)> dfs = [&](int id, int fr) {
		set<int> res;
		res.insert(dep[id] % t);
		for (edge e : G[id])if (e.to != fr) {
			set<int> nex = dfs(e.to, id);
			if (s[e.to] == s[id]) {
				if (res.size() < nex.size())swap(res, nex);
				for (int val : nex)res.insert(val);
			}
		}
		//answer
		for (int loc : qs[id]) {
			vector<pair<P, ll>> vp;
			int cur = par[findpar(id)][0];
			while (cur >= 0) {
				int col = s[cur] - 'A';
				int pp = findpar(cur);
				ll len = dep[cur] - dep[pp];
				if (pp != 0)len += parcost[pp];
				ll num = len / t;
				ll rr = len % t;
				if (rr > 0) {
					int ad = dep[cur] % t;
					//(ad-rr,ad]
					if (ad - rr + 1 < 0) {
						//vp.push_back({ {ad-rr+1,ad+1},calccost(num+1,curf[loc][col],curp[loc][col]) });
						vp.push_back({ {0,ad + 1},calccost(num + 1,curf[loc][col],curp[loc][col]) });
						vp.push_back({ {ad - rr + 1 + t,t},calccost(num + 1,curf[loc][col],curp[loc][col]) });
					}
					else {
						vp.push_back({ {ad - rr + 1,ad + 1},calccost(num+1,curf[loc][col],curp[loc][col]) });
					}
					//vp.push_back({ { ad + 1,ad - rr + 1 + t }, calccost(num, curf[loc][col], curp[loc][col] });
					if (ad + 1 == t) {
						vp.push_back({ { 0,t - rr }, calccost(num, curf[loc][col], curp[loc][col]) });
					}
					else {
						if (ad + 1 + t-rr > t) {
							vp.push_back({ { ad+1,t }, calccost(num, curf[loc][col], curp[loc][col]) });
							vp.push_back({ { 0,ad+1-rr }, calccost(num, curf[loc][col], curp[loc][col]) });
						}
						else {
							vp.push_back({ { ad+1,ad+1+t-rr }, calccost(num, curf[loc][col], curp[loc][col]) });
						}
					}
				}
				else {
					vp.push_back({ {0,t},calccost(num,curf[loc][col],curp[loc][col]) });
				}
				cur = par[pp][0];
			}
			vector<int> locs;
			locs.push_back(0);
			locs.push_back(t);
			for (auto p : vp) {
				locs.push_back(p.first.first);
				locs.push_back(p.first.second);
			}
			sort(all(locs));
			locs.erase(unique(all(locs)), locs.end());
			vector<ll> cost(locs.size());
			for (auto p:vp) {
				int le = lower_bound(all(locs), p.first.first) - locs.begin();
				int ri = lower_bound(all(locs), p.first.second) - locs.begin();
				cost[le] += p.second;
				cost[ri] -= p.second;
			}
			ans[loc] = INF;
			rep(i, locs.size() - 1) {
				cost[i + 1] += cost[i];
				int le = locs[i];
				int ri = locs[i + 1];
				auto itr = res.lower_bound(le);
				if (itr != res.end() && (*itr) < ri) {
					chmin(ans[loc], cost[i]);
				}
			}
		}



		//
		return res;
	};
	dfs(0, -1);
	rep(i, q)if(typ[i]==3)cout << ans[i] << "\n";
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