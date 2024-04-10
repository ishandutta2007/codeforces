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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
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

const int max_n = 1<<18;
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
using mP = pair<modint, modint>;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

vector<P> t[1 << 17];

vector<int> vs[1 << 17];

vector<int> G[1 << 17];
vector<int> loc[1 << 17];

int ans[1 << 17];


queue<vector<int>> q;
queue<int> dep;
bool exi[1<<17];
void yaru(vector<int> v,int col) {
	if (v.empty())return;
	//
	for (int id : v)exi[id] = true;
	int g; int sz = v.size();

	function<int(int, int)> s_root = [&](int id, int fr)->int {
		int res = 1;
		int ma = 0;
		for (int to : G[id]) {
			if (to == fr)continue;
			if (!exi[to])continue;
			int nex = s_root(to, id);
			ma = max(ma, nex);
			res += nex;
		}
		if (ma <= sz / 2 && sz - res <= sz / 2)g = id;
		return res;
	};
	s_root(v[0], -1);
	//

	ans[g] = col;




	vector<vector<int>> chs;
	vector<int> nexs;
	function<void(int, int)> search_next = [&](int id, int fr) {
		if (!exi[id])return;
		nexs.push_back(id);
		for (int to : G[id]) {
			if (to == fr)continue;
			search_next(to, id);
		}
	};
	//
	for (int to : G[g]) {
		search_next(to, g);
		if (nexs.empty())continue;
		q.push(nexs);
		dep.push(col + 1);
		chs.push_back(nexs);
		nexs.clear();
	}

	//

	for (int id : v)exi[id] = false;
}

void uoo(int n) {
	vector<int> ori(n); rep(i, n)ori[i] = i;
	q.push(ori); dep.push(1);
	while (!q.empty()) {
		vector<int> v = q.front(); q.pop();
		int col = dep.front(); dep.pop();
		yaru(v,col);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	rep(i, n-1) {
		t[i].push_back({ i + 1,-1 });
		t[i + 1].push_back({ i,-1 });
	}
	t[0].push_back({ n - 1,-1 });
	t[n - 1].push_back({ 0,-1 });
	rep(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		t[a].push_back({ b,i });
		t[b].push_back({ a,i });
	}
	if (m == 0) {
		cout << 1 << endl; return;
	}
	rep(i, n)sort(all(t[i]));
	int tmp = m;
	for (int i = n - 1; i >= 0; i--) {
		int ri = -1;
		rep(j, t[i].size()) {
			if (t[i][j].first < i)ri = j;
			else break;
		}
		for (int j = ri; j > 0; j--) {
			int l = t[i][j - 1].first;
			if (t[i][j - 1].second >= 0) {
				loc[t[i][j - 1].second].push_back(tmp);
			}
			vs[tmp].push_back(i);
			int cur = t[i][j].first;
			if (t[i][j].second >= 0) {
				loc[t[i][j].second].push_back(tmp);
			}
			vs[tmp].push_back(cur);
			while (cur > l) {
				if (t[cur][0].second >= 0) {
					loc[t[cur][0].second].push_back(tmp);
				}
				cur = t[cur][0].first;
				vs[tmp].push_back(cur);
			}
			tmp--;
		}
	}
	rep(i, m) {
		assert(loc[i].size() == 2);
		int l = loc[i][0], r = loc[i][1];
		G[l].push_back(r);
		G[r].push_back(l);
		//cout << l << " " << r << endl;
	}
	uoo(m+1);
	rep(i, m+1) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}