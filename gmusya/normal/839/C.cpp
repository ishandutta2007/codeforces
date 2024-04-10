#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <ctime>

#define ll long long
#define dl double long
#define graph vector <vector <int>> 
#define read_edge(g) int u, v; cin >> u >> v; u--; v--; g[u].push_back(v); g[v].push_back(u);
#define read_graph(g) forin(i, m) { read_edge(g) }
#define all_graph(g, n) graph g(n); read_graph(g)
#define all(a) a.begin(), a.end()
#define forin(i, n) for (int i = 0; i < n; i++)
#define fsp(n) fixed << setprecision(n)

using namespace std;

const ll llINF = 8e18, MAX_LL = (1ll << 63) - 1, llMOD = 1e9 + 7;
const int INF = 1e9, MAX_INT = (1ll << 31) - 1;
const dl EPS = 1e-10, PI = acos(-1);

void dfs(int u, int p, graph &g, vector <bool> &used, vector <dl> &c, vector <ll> &d, dl &ans) {
	used[u] = true;
	if (u != 0) {
		d[u] = d[p] + 1;
		if (p == 0)
			c[u] = c[p] / g[p].size();
		else
			c[u] = c[p] / (g[p].size() - 1);
		if (g[u].size() == 1)
			ans += c[u] * d[u];
	}
	forin(i, g[u].size())
		if (!used[g[u][i]])
			dfs(g[u][i], u, g, used, c, d, ans);
}

int main() {
	ll n, m;
	cin >> n;
	m = n - 1;
	vector <dl> c(n);
	vector <ll> d(n);
	d[0] = 0;
	c[0] = 1;
	dl ans = 0;
	vector <bool> used(n);
	all_graph(g, n);
	dfs(0, 0, g, used, c, d, ans);
	cout << fsp(10) << ans;
	return 0;
}