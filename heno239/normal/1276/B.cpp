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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

struct uf {
private:
	vector<int> par, ran,cnt;
public:
	uf(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		cnt.resize(n, 1);
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
			par[x] = y; cnt[y] += cnt[x];
		}
		else {
			par[y] = x;
			cnt[x] += cnt[y];
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int comp(int x) {
		x = find(x);
		return cnt[x];
	}
};
void solve() {
	int n, m, a, b; cin >> n >> m >> a >> b; a--; b--;
	vector<vector<int>> G(n);
	uf u(n);
	rep(i, m) {
		int x, y; cin >> x >> y; x--; y--;
		G[x].push_back(y);
		G[y].push_back(x);
		if (x != a && x != b && y != a && y != b) {
			u.unite(x, y);
		}
	}
	ll le = 0, ri = 0;
	map<int, bool> mpa,mpb;
	rep(i, G[a].size()) {
		int to = G[a][i];
		to = u.find(to);
		mpa[to] = true;
	}
	rep(i, G[b].size()) {
		int to = G[b][i];
		to = u.find(to);
		mpb[to] = true;
	}
	mpa[a] = mpa[b] = mpb[a] = mpb[b] = true;
	for (auto&& p : mpa) {
		int id = p.first;
		if (mpb[id])continue;
		le += u.comp(id);
	}
	for (auto&& p : mpb) {
		int id = p.first;
		if (mpa[id])continue;
		ri += u.comp(id);
	}
	cout << le * ri << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	//stop
	return 0;
}