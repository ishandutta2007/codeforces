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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
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
const int max_n = 1 << 21;
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

P merge(P a, P b) {
	if (a.second <= b.second)return a;
	else return b;
}
void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> a(k, vector<int>(n));
	rep(i, k)rep(j, n)cin >> a[i][j];
	vector<P> swaped;
	rep(i, k) {
		int mem = -1;
		rep(j, n) {
			if (a[i][j] == 0) {
				if (mem >= 0) {
					cout << -1 << "\n"; return;
				}
				else {
					mem = j;
				}
			}
		}
		if (mem < i) {
			cout << -1 << "\n"; return;
		}
		if (i != mem) {
			swaped.push_back({ i,mem });
			rep(j, k) {
				swap(a[j][i], a[j][mem]);
			}
		}
	}
	if (k == 1) {
		vector<vector<int>> vs(n);
		vector<int> par(n);
		rep(j, n) {
			vs[a[0][j]].push_back(j);
		}
		vector<P> ans;
		if (vs[0] != vector<int>{0}) {
			cout << -1 << "\n"; return;
		}
		rep1(i, n - 1) {
			if (vs[i].size()) {
				if (vs[i - 1].empty()) {
					cout << -1 << "\n"; return;
				}
				for (int id : vs[i]) {
					ans.push_back({ vs[i - 1][0],id });
				}
			}
		}
		vector<int> trans(n);
		rep(i, n)trans[i] = i;
		for (P p : swaped)swap(trans[p.first], trans[p.second]);
		rep(i, n - 1) {
			cout << trans[ans[i].first] + 1 << " " << trans[ans[i].second] + 1 << "\n";
		}
		return;
	}
	rep(i, k) {
		if (a[i][i] != 0) {
			cout << -1 << "\n"; return;
		}
		rep(j, n)if (i != j) {
			if (a[i][j] == 0) {
				cout << -1 << "\n"; return;
			}
		}
	}
	//nearest found vertive,distance
	vector<P> par(n);
	rep(i, n) {
		par[i] = { 0,a[0][i] };
	}
	vector<bool> ded(n);
	ded[0] = true;
	for (int i = 1; i < k; i++) {
		int d = a[0][i];
		vector<int> mem(d + 1, -1);
		rep(j, n) {
			if (a[0][j] + a[i][j] == d) {
				if (mem[a[0][j]] >= 0) {
					cout << -1 << "\n"; return;
				}
				mem[a[0][j]] = j;
			}
		}
		//cout << "hello\n";
		for (int j = 1; j < d; j++)if (mem[j] < 0) {
			cout << -1 << "\n"; return;
		}
		vector<bool> chked(n);
		mem[0] = 0; mem[d] = i;
		chked[0] = chked[i] = true;
		for (int j = 1; j <= d; j++) {
			P np = { mem[j - 1],1 };
			int id = mem[j];
			ded[id] = true;
			par[id] = merge(par[id], np);
			chked[id] = true;
		}
		//cout << "hello\n";
		rep(j, n)if (!chked[j]) {
			if (a[0][j] - a[i][j] == d) {
				P np = { i,a[i][j] };
				par[j] = merge(par[j], np);
			}
			else if (a[i][j] - a[0][j] == d) {
				P np = { 0,a[0][j] };
				par[j] = merge(par[j], np);
			}
			else {
				int r = a[0][j] + a[i][j] - d;
				if (r % 2 == 0 && r >= 0) {
					int u = a[0][j] - r / 2;
					if (u > 0 && u < d) {
						P np = { mem[u],r / 2 };
						par[j] = merge(par[j], np);
					}
					else {
						cout << -1 << "\n"; return;
					}
				}
				else {
					cout << -1 << "\n"; return;
				}
			}
		}
	}
	//cout << "hello\n";
	map<P, int> mp;
	rep(j, n)if(!ded[j]) {
		mp[par[j]] = j;
	}
	vector<vector<int>> G(n);
	vector<P> ans;
	for (int i = 1; i < n; i++) {
		P p = par[i];
		if (p.second == 1) {
			G[p.first].push_back(i);
			G[i].push_back(p.first);
			ans.push_back({ i,p.first });
		}
		else {
			if (mp.find({ p.first,p.second - 1 }) == mp.end()) {
				cout << -1 << "\n"; return;
			}
			else {
				int to = mp[{p.first, p.second - 1}];
				G[i].push_back(to);
				G[to].push_back(i);
				ans.push_back({ i,to });
			}
		}
	}
	rep(i, k) {
		vector<int> dist(n, mod);
		queue<int> q;
		q.push(i); dist[i] = 0;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int to : G[v]) {
				if (dist[to] > dist[v] + 1) {
					dist[to] = dist[v] + 1;
					q.push(to);
				}
			}
		}
		rep(j, n) {
			if (a[i][j] != dist[j]) {
				cout << -1 << "\n"; return;
			}
		}
	}
	vector<int> trans(n);
	rep(i, n)trans[i] = i;
	for (P p : swaped)swap(trans[p.first], trans[p.second]);
	rep(i, n - 1) {
		cout << trans[ans[i].first] + 1 << " " << trans[ans[i].second] + 1 << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();

	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}