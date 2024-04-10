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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
#include<cstring>
struct edge { int to;ll cap, rev; };
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
int n, m;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep1(i, n) {
		ll v; cin >> v;
		add_edge(i, n + m + 1, v);
	}
	ll ans = 0;
	rep1(i, m) {
		int u, v; cin >> u >> v; ll c; cin >> c;
		add_edge(n + i, u, INF);
		add_edge(n + i, v, INF);
		add_edge(0, n + i, c);
		ans += c;
	}
	cout << ans - max_flow(0, n + m + 1) << endl;
	return 0;
}