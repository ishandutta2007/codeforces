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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

vector<bool> tra;
string t;
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
	bool valid(int sz) {
		scc();
		rep(i, sz) {
			if (trans[i] == trans[i + sz])return false;
		}
		return true;
	}
	bool merge(vector<int> &le, vector<int> &ri) {
		rep(i, le.size()) {
			if (le[i] < 0)le[i] = ri[i];
			else if(ri[i]>=0){
				if (le[i] != ri[i])return false;
			}
		}
		return true;
	}
	vector<int> decide(int sz, int id) {
		vector<int> res(sz, -1);
		int z = trans[id];
		queue<int> q;
		q.push(z);
		vector<bool> used(mk, false);
		used[z] = true;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			rep(i, ori[v].size()) {
				int rid = ori[v][i];
				int c = rid / sz; rid %= sz;
				if (res[rid]<0) {
					res[rid] = c;
				}
				else {
					if (res[rid] != c)return {};
				}
			}
			rep(j, fG[v].size()) {
				int to = fG[v][j];
				if (used[to])continue;
				used[to] = true;
				q.push(to);
			}
		}
		return res;
	}
	bool valid(vector<int> &ans, vector<int> &cols) {
		int sz = ans.size();
		rep(i, ans.size()) {
			int goa = t[i] - 'a';
			if (ans[i] < 0) {
				int chk = cols[i];
				for (int j = goa + 1; j < tra.size(); j++) {
					if (chk >= 0 && chk != (int)tra[j])continue;
					vector<int> nd = decide(sz, i + tra[j] * sz);
					vector<int> cop = cols;
					if (merge(cop, cols))return true;
				}
				if (chk >= 0 && chk != (int)tra[goa])return false;
				vector<int> nd = decide(sz, i + tra[goa] * sz);
				vector<int> cop = cols;
				if (!merge(cop, cols))return false;
			}
			else {
				int sta = ans[i];
				if (sta < goa)return false;
				else if (sta > goa)return true;
			}
		}
		return true;
	}
	bool upd(int sz,int i,int col, vector<int> &ans,vector<int> &cols) {
		vector<int> d = decide(sz, i+sz*col);
		if (d.empty())return false;
		//cout << "hello" << endl;
		vector<int> cop = cols;
		if (!merge(cop, d)) {
			return false;
		}
		if (valid(ans, cop)) {
			cols = cop; return true;
		}
		return false;
	}
};

int sz;
int n, m;

void solve() {
	string s; cin >> s;
	sz = s.size();
	tra.resize(sz);
	rep(i, sz) {
		tra[i] = (s[i] == 'V');
	}
	cin >> n >> m;
	graph g(2 * n);
	rep(i, m) {
		int p1, p2; char c1, c2;
		cin >> p1 >> c1 >> p2 >> c2;
		p1--; p2--;
		int id = (c1 == 'V');
		int to = (c2 == 'V');
		g.add_edge(p1 + n * id, p2 + n * to);
		g.add_edge(p2 + n * (to ^ 1), p1 + n * (id ^ 1));
	}
	cin >> t;
	if (!g.valid(n)) {
		cout << -1 << endl; return;
	}
	vector<int> ans(n,-1);
	vector<int> cols(n,-1);
	int id = 0;
	rep(i, n) {
		if (ans[i]>=0)continue;
		//cout << "hello" << endl;
		rep(j, sz) {
			if (id == 0 && j < (t[i] - 'a'))continue;
			int col = (s[j] == 'V');
			if (g.upd(n, i, col, ans, cols)) {
				vector<int> copans = ans;
				copans[i] = j;
				if (g.valid(copans, cols)) {
					ans[i] = j;
					if (j > (t[i] - 'a'))id = 1;
					break;
				}
			}
		}
		if (ans[i] < 0) {
			cout << -1 << endl; return;
		}
		//cout << ans[i] << endl;
	}
	string fans;
	rep(i, n) {
		fans.push_back('a' + ans[i]);
	}
	cout << fans << endl;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	solve();
	//stop
	return 0;
}