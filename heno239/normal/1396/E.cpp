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

const int max_n = 1000;
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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}

int g;
vector<int> G[1 << 17];
int find_g(int n, int id, int fr) {
	int res = 1; int ma = 0;
	for (int to : G[id])if (to != fr) {
		int nex = find_g(n, to, id);
		ma = max(ma, nex);
		res += nex;
	}
	if (ma <= n / 2 && n - res <= n / 2)g = id;
	return res;
}
void solve() {
	int n; ll k; cin >> n >> k;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	find_g(n, 0, -1);
	vector<int>par(n);
	vector<int> depth(n);

	ll mi = 0;
	ll ma = 0;
	function<bool(int, int)> dfs = [&](int id, int fr)->bool {
		bool res = true;
		int c = 0;
		par[id] = fr;
		for (int to : G[id])if (to != fr) {
			depth[to] = depth[id] + 1;
			if (dfs(to, id))c++;
		}
		mi += 2 * (c / 2);
		if (c % 2) {
			res = false; mi++;
		}
		ma += depth[id];
		return res;
	}; dfs(g, -1);
	if (k < mi || ma < k) {
		cout << "NO\n"; return;
	}
	ll dif = ma - k;
	if (dif % 2) {
		cout << "NO\n"; return;
	}
	//cout << dif << "\n";

	vector<set<P>> st;
	set<P> cur;
	function<void(int, int)> calc = [&](int id, int fr) {
		cur.insert({ depth[id],id });
		for (int to : G[id])if (to != fr) {
			calc(to, id);
		}
	};
	priority_queue<P> q;
	for (int to : G[g]) {
		cur.clear();
		calc(to, g);
		st.push_back(cur);
		q.push({ cur.size(),st.size() - 1 });
	}
	vector<set<int>> exis(n);
	rep(i, n) {
		if (par[i] >= 0) {
			exis[par[i]].insert(i);
		}
	}
	vector<P> ans;
	while (dif > 0) {
		P p = q.top(); q.pop();
		if(p.first-2>0)q.push({ p.first - 2,p.second });
		int id = p.second;
		int las = (*st[id].rbegin()).second;
		if (2 * (depth[las] - 1) >= dif) {
			P cur = { dif / 2 + 1,-1 };
			st[id].insert(cur);
			auto itr = st[id].find(cur);
			itr++;
			int z = (*itr).second;
			st[id].erase(cur);
			ans.push_back({ z,par[z] });
			st[id].erase({ depth[z],z });
			st[id].erase({ depth[par[z]],par[z] });
			break;
		}
		else {
			P r = *st[id].rbegin();
			int z = r.second;
			int pa = par[z];
			if (exis[pa].size() >= 2) {
				int le = (*exis[pa].begin());
				exis[pa].erase(exis[pa].begin());
				int ri = (*exis[pa].begin());
				exis[pa].erase(exis[pa].begin());
				ans.push_back({ le,ri });
				st[id].erase({ depth[le], le });
				st[id].erase({ depth[ri],ri });
			}
			else {
				exis[pa].erase(z);
				exis[par[pa]].erase(pa);
				ans.push_back({ z,pa });
				st[id].erase({ depth[z],z });
				st[id].erase({ depth[pa],pa });
			}
			dif -= 2 * (depth[las] - 1);
		}
	}
	//cout << ans.size() << "\n";
	while (q.size()>=2) {
		P pl = q.top(); q.pop();
		P pr = q.top(); q.pop();
		if (pl.first - 1 > 0) {
			q.push({ pl.first - 1,pl.second });
		}
		if (pr.first - 1 > 0) {
			q.push({ pr.first - 1,pr.second });
		}
		int idl = pl.second, idr = pr.second;
		int vl = (*st[idl].rbegin()).second;
		int vr = (*st[idr].rbegin()).second;
		ans.push_back({ vl,vr });
		st[idl].erase({ depth[vl],vl });
		st[idr].erase({ depth[vr],vr });
	}
	P p = q.top();//assert(p.first==1)
	int id = p.second;
	id = (*st[id].begin()).second;
	ans.push_back({ g,id });
	cout << "YES\n";
	rep(i, ans.size()) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f(); 
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}