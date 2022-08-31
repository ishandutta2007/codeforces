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
const ll INF = mod * mod;
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
vector<edge> G[50000];
bool used[50000];
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
			ll d = dfs(e.to, t, min(f, e.cap));
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

bool mp[200][200];
struct segm {
	int lx, ly, rx, ry;
};
void solve() {
	ll n, m; cin >> n >> m;
	vector<int> vx, vy;
	vector<segm > v;
	rep(i, m) {
		int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
		rx++; ry++;
		vx.push_back(lx); vx.push_back(rx);
		vy.push_back(ly); vy.push_back(ry);
		v.push_back({ lx,ly,rx,ry });
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()),vx.end());
	map<int, int> mx, my;
	rep(i, vx.size())mx[vx[i]] = i;
	sort(vy.begin(), vy.end());
	vy.erase(unique(vy.begin(), vy.end()),vy.end());
	rep(i, vy.size())my[vy[i]] = i;
	rep(i, m) {
		int lx = mx[v[i].lx], rx = mx[v[i].rx];
		int ly = my[v[i].ly], ry = my[v[i].ry];
		for (int j = lx; j < rx; j++) {
			for (int k = ly; k < ry; k++) {
				mp[j][k] = true;
			}
		}
	}
	/*rep(i, vx.size()) {
		cout << vx[i] << " ";
	}
	cout << endl;
	rep(i, vy.size()) {
		cout << vy[i] << " ";
	}
	cout << endl;*/
	int xsz = vx.size() - 1;
	int ysz = vy.size() - 1;
	int s = xsz + ysz; int t = s + 1;
	rep(i, xsz) {
		add_edge(s, i, vx[i+1]-vx[i]);
		add_edge(i, t, 0);
	}
	rep(i, ysz) {
		add_edge(s, i + xsz, 0);
		add_edge(i + xsz, t, vy[i + 1] - vy[i]);
	}
	rep(i, xsz) {
		rep(j, ysz) {
			if (mp[i][j]) {
				add_edge(i, j + xsz, INF/10);
			}
			else {
				add_edge(j + xsz, i, 0);
			}
		}
	}
	ll ans = max_flow(s, t);
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}