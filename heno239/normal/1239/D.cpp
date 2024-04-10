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
const ll mod = 1000000007;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

struct graph {
private:
	int n;
	vector<vector<int>> G, rG;
	vector<bool> used;
	vector<int> vs;

	int mk;
	vector<vector<int>> fG;
	vector<vector<int>> ori;
	vector<int> trans;
public:
	graph(int sz) {
		n = sz;
		G.resize(n);
		rG.resize(n);
		used.resize(n);

		fG.resize(n);
		trans.resize(n, -1);
		ori.resize(n);
	}
	void add_edge(int a, int b) {
		G[a].push_back(b);
		rG[b].push_back(a);
	}
	void dfs(int v) {
		used[v] = true;
		rep(i, G[v].size()) {
			if (!used[G[v][i]])dfs(G[v][i]);
		}
		vs.push_back(v);
	}
	void rdfs(int v, int k) {
		used[v] = true;
		queue<int> q; q.push(v);
		vector<int> c;
		while (!q.empty()) {
			int id = q.front(); q.pop();
			ori[k].push_back(id);
			rep(j, rG[id].size()) {
				int to = rG[id][j];
				if (used[to]) {
					if (trans[to] >= 0)c.push_back(trans[to]);
					continue;
				}
				used[to] = true; q.push(to);
			}
		}
		sort(c.begin(), c.end());
		int len = unique(c.begin(), c.end()) - c.begin();
		rep(i, len) {
			fG[c[i]].push_back(k);
		}
		rep(i, ori[k].size()) {
			trans[ori[k][i]] = k;
		}
	}
	void scc() {
		fill(used.begin(), used.end(), false);
		rep(i, n) {
			if (!used[i])dfs(i);
		}
		fill(used.begin(), used.end(), false);
		int k = 0;
		per(i, (int)vs.size()) {
			if (!used[vs[i]]) {
				rdfs(vs[i], k); k++;
			}
		}
		mk = k;
	}
	bool valid() {
		int len = n / 2;
		rep(i, len) {
			if (trans[i] == trans[i + len])return false;
		}
		return true;
	}
	void query() {
		vector<bool> used(2 * n);
		vector<bool> out(2 * n);
		vector<int> ansle,ansri;
		int c[2] = {};
		per(i, mk) {
			int cc[2] = {};
			bool v = false;
			rep(j, ori[i].size()) {
				if (used[ori[i][j]])v = true;
				int id = ori[i][j];
				if (id >= n / 2)cc[1]++;
				else cc[0]++;
			}
			if (c[0] + cc[0] == n / 2 || c[1] + cc[1] == n / 2)v = true;
			rep(j, fG[i].size()) {
				int to = fG[i][j];
				if (out[to])v = true;
			}
			if (v) {
				out[i] = true; continue;
			}
			rep(j, ori[i].size()) {
				int id = ori[i][j];
				used[id] = true;
				if (id >= n / 2) {
					ansri.push_back(id - n / 2);
					used[id - n/2] = true;
					c[1]++;
				}
				else {
					ansle.push_back(id);
					used[id + n / 2] = true;
					c[0]++;
				}
			}
		}
		if (ansle.size() + ansri.size() != n/2) {
			cout << "No\n";
			return;
		}
		cout << "Yes" << "\n";
		sort(ansle.begin(), ansle.end());
		sort(ansri.begin(), ansri.end());
		cout << ansle.size() << " " << ansri.size() << "\n";
		rep(i, ansle.size()) {
			if (i > 0)cout << " ";
			cout << ansle[i] + 1;
		}
		cout << "\n";
		rep(i, ansri.size()) {
			if (i > 0)cout << " ";
			cout << ansri[i] + 1;
		}
		cout << "\n";
	}
};

void solve() {
	int n, m; cin >> n >> m;
	graph g(2 * n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--; b += n;
		if (a + n == b)continue;
		g.add_edge(a, b-n);
		g.add_edge(b, a+n);
	}
	g.scc();
	if (!g.valid()) {
		cout << "No" << "\n";
	}
	else {
		g.query();
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	int t; cin >> t;
	rep(aa, t) {
		solve();
	}
	//stop
	return 0;
}