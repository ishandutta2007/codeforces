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
constexpr ll mod = 998244353;
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
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x%mod;
		x = x * x%mod; n >>= 1;
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

constexpr ll m1 = 1128651217;
constexpr ll m2 = 1068651217;
random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<> ud1(0, m1-1);
uniform_int_distribution<> ud2(0, m2 - 1);

ll hash1[1 << 17];
ll hash2[1 << 17];
void init() {
	rep(i, (1 << 17)) {
		hash1[i] = ud1(mt);
		hash2[i] = ud2(mt);
	}
}

const int mn = 1 << 17;
struct edge {
	int to;
};
using Data = pair<LP,int>;
vector<edge> G[mn];
vector<int> ids[mn];
vector<Data> memo[mn];
int root;

Data merge(Data a, Data b) {
	Data res;
	//
	res.first.first = a.first.first*b.first.first%m1;
	res.first.second = a.first.second*b.first.second%m2;
	res.second = max(a.second, b.second);
	//
	return res;
}


map<LP, int> cnt;


void add_hash(LP p) {
	int val = cnt[p];
	cnt[p]++;
}
void erase_hash(LP p) {
	int val = cnt[p];
	cnt[p]--;
	if (cnt[p] == 0)cnt.erase(p);
}

LP subch[1 << 17];
Data dfs(int id, int fr) {
	Data res;
	//
	//initialize
	res = { {1,1},0 };
	//
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		Data nex = dfs(e.to, id);
		//
		//update with edge
		//
		res = merge(res, nex);
		ids[id].push_back(e.to);
		memo[id].push_back(nex);
	}
	//
	//update for return
	res.second++;
	res.first.first += hash1[res.second];
	if (res.first.first >= m1)res.first.first -= m1;
	res.first.second += hash2[res.second];
	if (res.first.second >= m2)res.first.second -= m2;

	if(id!=0)cnt[res.first]++;
	subch[id] = res.first;
	//
	return res;
}


int num[1 << 17];
LP parhash[1 << 17];
void invdfs(int id, int fr, Data pre) {
	vector<Data> v;
	for (Data d : memo[id])v.push_back(d);
	if (fr >= 0)v.push_back(pre);
	int len = v.size();
	//
	//calcurate id's ans
	Data pd = { {1,1},0 };
	for (Data d : v) {
		pd = merge(pd, d);
	}
	pd.second++;
	parhash[id] = pd.first;
	parhash[id].first += hash1[pd.second];
	if (parhash[id].first >= m1)parhash[id].first -= m1;
	parhash[id].second += hash2[pd.second];
	if (parhash[id].second >= m2)parhash[id].second -= m2;
	
	add_hash(parhash[id]);
	
	num[id] = cnt.size();

	erase_hash(parhash[id]);
	//
	vector<Data> le(len + 1);
	vector<Data> ri(len + 1);
	//
	Data init_c = { {1,1},0};
	//
	le[0] = init_c;
	rep(i, len) {
		le[i + 1] = merge(le[i], v[i]);
	}
	ri[len] = init_c;
	per(i, len) {
		ri[i] = merge(ri[i + 1], v[i]);
	}
	rep(i, ids[id].size()) {
		int to = ids[id][i];
		Data d = merge(le[i], ri[i + 1]);

		//
		//update for return
		d.second++;
		d.first.first += hash1[d.second];
		if (d.first.first >= m1)d.first.first -= m1;
		d.first.second += hash2[d.second];
		if (d.first.second >= m2)d.first.second -= m2;
		//

		add_hash(d.first);
		erase_hash(subch[to]);

		invdfs(to, id, d);

		erase_hash(d.first);
		add_hash(subch[to]);
	}
}
void yaru() {
	dfs(root, -1);
	invdfs(root, -1, { {1,1},0 });
}



void solve() {
	int n; cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back({ b });
		G[b].push_back({ a });
	}
	yaru();
	int ma = -1; int ans = 0;
	rep(i, n) {
		//cout << "? " << i << " " << num[i] << "\n";
		if (ma < num[i]) {
			ma = num[i]; ans = i;
		}
	}
	cout << ans + 1 << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	init();
	//int t; cin >> t; rep(i, t)
	solve();
	stop
		return 0;
}