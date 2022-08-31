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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;


set<int> st[1 << 17];
struct uf {
private:
	vector<int> par, ran;
public:
	void init(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
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
			for (auto itr = st[x].begin(); itr != st[x].end(); itr++) {
				st[y].insert(*itr);
			}
		}
		else {
			par[y] = x;
			for (auto itr = st[y].begin(); itr != st[y].end(); itr++) {
				st[x].insert(*itr);
			}
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

set<P> xG[1 << 17];

uf u;
void add(int i,int to, int x) {
	xG[i].insert({ x,-1 });
	auto itr = xG[i].find(P{ x,-1 });
	itr++;
	if (itr != xG[i].end()) {
		P p = *itr;
		if (p.first == x) {
			u.unite(to, p.second);
		}
	}
	xG[i].erase({ x,-1 });
	xG[i].insert({ x,to });
}

void solve() {
	int n, m, c, q; cin >> n >> m >> c >> q;
	u.init(n);
	rep(i, m) {
		int a, b, x; cin >> a >> b >> x; a--; b--;
		xG[a].insert({ x,b });
		xG[b].insert({ x,a });
		st[a].insert(b); st[b].insert(a);
	}
	rep(i, n) {
		for (auto itr = xG[i].begin(); itr != xG[i].end(); itr++) {
			P le = *itr; itr++; if (itr == xG[i].end())break;
			P ri = *itr; itr--;
			if (le.first == ri.first) {
				u.unite(le.second, ri.second);
			}
		}
	}
	rep(i, q) {
		char t; cin >> t;
		if (t == '?') {
			int a, b; cin >> a >> b; a--; b--;
			int p = u.find(a);
			if (p == u.find(b) || st[p].count(b)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		else {
			int a, b, x; cin >> a >> b >> x;
			a--; b--;
			add(a, b, x); add(b, a, x);
			int pa = u.find(a), pb = u.find(b);
			st[pa].insert(b); st[pb].insert(a);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}