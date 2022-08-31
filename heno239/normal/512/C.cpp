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

#include<cstring>
struct edge { int to, cap, rev; };
vector<edge> G[100000];
bool used[100000];
void add_edge(int from, int to, int cap) {
	G[from].push_back(edge{ to, cap, (int)G[to].size() });
	G[to].push_back(edge{ from, 0, (int)G[from].size() - 1 });
}
int dfs(int v, int t, int f) {
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
int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, mod);
		if (f == 0)return flow;
		flow += f;
	}
}

bool isp[1 << 15];
void init() {
	fill(isp, isp + (1 << 15), true);
	Rep(i, 2, (1 << 15)) {
		if (!isp[i])continue;
		for (int j = 2 * i; j < (1<<15); j += i) {
			isp[j] = false;
		}
	}
}

int cod[100], cev[100];

void solve() {
	init();
	int n; cin >> n;
	vector<P> od, ev;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		if (a[i] % 2)od.push_back({ a[i],i });
		else ev.push_back({ a[i],i });
	}
	if (n % 2 || od.size() != ev.size()) {
		cout << "Impossible" << endl; return;
	}
	int d = n / 2;
	vector<P> v;
	rep(i, d) {
		rep(j, d) {
			//cout << od[i] + ev[j] << endl;
			if (isp[od[i].first + ev[j].first]) {
				v.push_back({ i,j });
				cod[i]++; cev[j]++;
				//cout << i << " " << j << endl;
			}
		}
	}
	rep(i, d) {
		if (cod[i] < 2 || cev[i] < 2) {
			cout << "Impossible" << endl; return;
		}
	}
	int s = 2 * d; int t = s + 1;
	rep(i, d) {
		add_edge(s, i, cod[i] - 2);
		add_edge(i + d, t, cev[i] - 2);
	}
	rep(i, v.size()) {
		add_edge(v[i].first, v[i].second + d, 1);
	}
	int f = max_flow(s, t);
	v.clear();
	rep(i, d) {
		rep(j, G[i].size()) {
			int to = G[i][j].to;
			if (to == s)continue;
			if (G[i][j].cap) {
				v.push_back({ i,to - d });
			}
		}
	}

	vector<bool> aused(200);
	vector<vector<int>> ans;
	vector<vector<int>> g(n);
	rep(i, v.size()) {
		int le = v[i].first, ri = v[i].second;
		le = od[le].second; ri = ev[ri].second;
		g[le].push_back(ri);
		g[ri].push_back(le);
		//cout << le+1 << " " << ri+1 << endl;
	}
	rep(i, n) {
		//cout << g[i].size() << endl;
		if (g[i].size() != 2) {
			cout << "Impossible" << endl; return;
		}
	}
	rep(i, n) {
		if (aused[i])continue;
		int cur = i;
		vector<int> nex;
		nex.push_back(cur);
		aused[cur] = true;
		while (true) {
			int to1 = g[cur][0], to2 = g[cur][1];
			if (aused[to1] && aused[to2])break;
			if (!aused[to1]) {
				cur = to1;
			}
			else {
				cur = to2;
			}
			aused[cur] = true; nex.push_back(cur);
		}
		ans.push_back(nex);
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].size();
		rep(j, ans[i].size()) {
			cout << " ";
			cout << ans[i][j] + 1;
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}