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
const ld pi = acos(-1.0);


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
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 18;
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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct LiChaoTree {
	int sz;
	struct Node {
		int l, r;
		Node* chl; Node* chr;
		LP val;
		Node(int l, int r) :l(l), r(r) {
			val = { 0,INF };
			chl = chr = NULL;
		}
	};
	Node* root;
	LiChaoTree() {
		int max_n = 1e6 + 1;
		sz = 1;
		while (sz < max_n)sz <<= 1;
		root = new Node(-sz, sz);
	}
	ll calc(LP a, int x) {
		return a.first*x + a.second;
	}
	void add(Node* node, LP a) {
		if (!node)return;
		int l = node->l, r = node->r;
		int m = (l + r) / 2;
		//
		if (calc(node->val, m) > calc(a, m))swap(node->val, a);
		if (r - l == 1)return;
		//
		if (calc(node->val, l) > calc(a, l)) {
			if (!node->chl)node->chl = new Node(l, m);
			add(node->chl, a);
		}
		else if (calc(node->val, r) > calc(a, r)) {
			if (!node->chr)node->chr = new Node(m, r);
			add(node->chr, a);
		}
	}
	void add(LP a) {
		add(root, a);
	}
	ll query(int x) {
		ll ret = INF;
		Node* node = root;
		while (node) {
			ret = min(ret, calc(node->val, x));
			int m = (node->l + node->r) / 2;
			if (x < m) {
				node = node->chl;
			}
			else {
				node = node->chr;
			}
		}
		return ret;
	}
};

struct Data {
	LiChaoTree lt;
	vector<LP> es;
};
void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	vector<ll> ans(n);
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	function<Data(int,int)> dfs = [&](int id, int fr)->Data {
		int num = G[id].size();
		if (fr >= 0)num--;
		if (num == 0) {
			ans[id] = 0;
			Data res;
			LP p = { b[id],0 };
			res.lt.add(p);
			res.es.push_back(p);
			return res;
		}
		Data res;
		vector<LP> adds;
		for (int to : G[id])if (to != fr) {
			Data nex = dfs(to, id);
			if (nex.es.size() > res.es.size()) {
				swap(nex, res);
			}
			for (LP p : nex.es) {
				adds.push_back(p);
			}
		}
		for (LP p : adds) {
			res.lt.add(p);
			res.es.push_back(p);
		}
		ans[id] = res.lt.query(a[id]);
		LP p = { b[id],ans[id] };
		res.lt.add(p);
		res.es.push_back(p);
		return res;
	};
	dfs(0, -1);
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(6);
	init_f();
	//init();
	//int t; cin >> t;rep(i,t)
	solve();
	stop
		return 0;
}