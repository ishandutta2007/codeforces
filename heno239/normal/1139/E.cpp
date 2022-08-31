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

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
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

vector<int> loc[5005];
void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		loc[a[i]].push_back(i);
	}
	vector<int> c(n);
	rep(i, n) {
		cin >> c[i]; c[i]--;
	}
	int d; cin >> d;
	vector<int> k(d);
	vector<int> del(n, mod);
	rep(i, d) {
		cin >> k[i]; k[i]--;
		del[k[i]] = i;
	}
	vector<int> ans;
	int cur = 0;
	int s = 5000 + m; int t = s + 1;
	rep(i, m) {
		add_edge(s, i+5000, 1);
	}
	rep(i, 5000) {
		add_edge(i, t, 1);
	}
	rep(i, n) {
		if (del[i] == mod && a[i] == 0) {
			add_edge(5000 + c[i],a[i], 1);
		}
	}
	int mf = 0;
	for (int i = d-1; i >= 0; i--) {
		while (true) {
			mf += max_flow(s, t);
			if (mf == cur + 1) {
				cur++;
				rep(j, loc[cur].size()) {
					int id = loc[cur][j];
					if (del[id] > i) {
						add_edge(5000 + c[id], a[id], 1);
					}
				}
			}
			else break;
		}
		ans.push_back(cur);
		if (cur >= a[k[i]]) {
			add_edge(5000 + c[k[i]], a[k[i]], 1);
		}
	}
	reverse(ans.begin(), ans.end());
	//cout << "ans is" << endl;
	rep(i, d) {
		cout << ans[i] << endl;
	}
	//cout << mf << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}