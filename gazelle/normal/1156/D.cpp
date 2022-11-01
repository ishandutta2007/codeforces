#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
#include<cassert>
using namespace std;
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

vector<vector<pint>> graph;
vector<lint> g1, g2;
vector<lint> sz1, sz2;

lint dfs1(int pos, vector<bool>& used, int g) {
	lint ret = 1;
	g1[pos] = g;
	used[pos] = true;
	REP(i, graph[pos].size()) {
		if(used[graph[pos][i].first]) continue;
		if(graph[pos][i].second == 0) continue;
		ret += dfs1(graph[pos][i].first, used, g);
	}
	return ret;
}

lint dfs2(int pos, vector<bool>& used, int g) {
	lint ret = sz1[g1[pos]];
	g2[pos] = g;
	used[pos] = true;
	REP(i, graph[pos].size()) {
		if(used[graph[pos][i].first]) continue;
		if(graph[pos][i].second == 1) continue;
		ret += dfs2(graph[pos][i].first, used, g);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	graph.resize(n);
	g1.resize(n); g2.resize(n);
	REP(i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		graph[a].pb({b, c});
		graph[b].pb({a, c});
	}
	int g = 0;
	vector<bool> used(n, false);
	REP(i, n) {
		if(used[i]) continue;
		sz1.pb(dfs1(i, used, g));
		g++;
	}
	g = 0;
	used.assign(n, false);
	REP(i, n) {
		if(used[i]) continue;
		sz2.pb(dfs2(i, used, g));
		g++;
	}
	lint ans = 0;
	REP(i, n) ans += sz2[g2[i]];
	cout << ans - n << endl;
	return 0;
}
/* --------------------------------------- */