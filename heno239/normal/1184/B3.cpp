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
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = 100000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
#include<cstring>
struct edge { int to; ll cap;int rev; };
vector<edge> G[100000];
bool used[100000];
void add_edge(int from, int to, ll cap) {
	G[from].push_back(edge{ to, cap, (int)G[to].size() });
	G[to].push_back(edge{ from, 0, (int)G[from].size() - 1 });
}
ll dfs(int v, int t, ll f) {
	if (v == t)return f;
	used[v] = true;
	for (int i = 0; i < (int)G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
ll max_flow(int s, int t) {
	ll flow = 0;
	for (;;) {
		memset(used, 0, sizeof(used));
		ll f = dfs(s, t, INF);
		if (f == 0)return flow;
		flow += f;
	}
}

int distr[101][101];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			if (i == j)distr[i][j] = 0;
			else distr[i][j] = mod;
		}
	}
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		distr[a][b] = distr[b][a] = 1;
	}
	rep(k, n) {
		rep(i, n) {
			rep(j, n) {
				distr[i][j] = min(distr[i][j], distr[i][k] + distr[k][j]);
			}
		}
	}
	int nl, nr, nrel; cin >> nl >> nr >> nrel;
	vector<int> xl(nl), a(nl), f(nl), p(nl);
	vector<int> xr(nr), b(nr), g(nr);
	rep(i, nl) {
		cin >> xl[i] >> a[i] >> f[i] >> p[i]; xl[i]--;
	}
	rep(i, nr) {
		cin >> xr[i] >> b[i] >> g[i]; xr[i]--;
	}
	vector<P> rel(nrel);
	rep(i, nrel) {
		int u, v; cin >> u >> v; u--; v--;
		rel[i] = { u,v };
	}
	vector<vector<P>> vb(n);
	rep(i, nr) {
		vb[xr[i]].push_back({ b[i],g[i] });
	}
	vector<vector<int>> bb(n), hg(n);
	rep(i, n) {
		sort(vb[i].begin(), vb[i].end());
		bb[i].resize(vb[i].size());
		hg[i].resize(vb[i].size()+1);
		int ma = -2*mod;
		rep(j, (int)vb[i].size()) {
			bb[i][j] = vb[i][j].first;
			hg[i][j] = ma;
			ma = max(ma, vb[i][j].second);
		}
		hg[i][vb[i].size()] = ma;
	}
	vector<bool> cant(nl,false);
	vector<ll> val(nl);
	rep(i, nl) {
		int maval = -2*mod;
		rep(j, n) {
			int d = distr[xl[i]][j];
			if (d > f[i])continue;
			int id = upper_bound(bb[j].begin(), bb[j].end(), a[i]) - bb[j].begin();
			maval = max(maval, hg[j][id]);
		}
		if (maval == -2 * mod) {
			cant[i] = true;
		}
		val[i] = (ll)maval - (ll)p[i];
		//cout << "hello" << endl;
		//cout << i << " " << val[i] << endl;
	}
	vector<bool> exi(nl,false);
	rep(i, nrel) {
		int u = rel[i].first, v = rel[i].second;
		exi[u] = exi[v] = true;
	}
	vector<int> ids;
	vector<int> trans(nl);
	ll ans = 0;
	rep(i, nl) {
		if (!exi[i]) {
			ans += max((ll)0, val[i]);
		}
		else {
			trans[i] = ids.size();
			ids.push_back(i);
		}
	}
	int s = ids.size(); int t = s + 1;
	rep(i, ids.size()) {
		int id = ids[i];
		ll cost = val[id];
		if (cost < 0) {
			add_edge(s, i,-cost);
			add_edge(i, t, 0);
		}
		else {
			add_edge(s, i, 0);
			add_edge(i, t, cost);
		}
		if (cant[id]) {
			add_edge(s, i, INF);
		}
	}
	rep(i, nrel) {
		int u = rel[i].first, v = rel[i].second;
		u = trans[u], v = trans[v];
		add_edge(v, u, INF);
	}
	ll sum = 0;
	rep(i, ids.size()) {
		if (val[ids[i]] >= 0) {
			sum += val[ids[i]];
		}
	}
	ll z = max_flow(s, t);
	//cout << z << endl;
	sum -= z;
	ans += sum;
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
	//stop
	return 0;
}