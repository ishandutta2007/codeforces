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
#define all_graph(g, n) graph g(n); read_graph(g);
#define all(a) a.begin(), a.end()
#define forin(i, n) for (int i = 0; i < n; i++)

using namespace std;

const ll llINF = 8e18, MAX_LL = (1ll << 63) - 1, llMOD = 1e9 + 7;
const int INF = 1e9, MAX_INT = (1ll << 31) - 1;
const dl EPS = 1e-10, PI = acos(-1);

void dfs(int u, graph &g, vector <bool> &used, vector <ll> &c, ll &ans) {
	used[u] = true;
	ans = min(ans, c[u]);
	forin(i, g[u].size())
		if (!used[g[u][i]])
			dfs(g[u][i], g, used, c, ans);
}

int main() {
	ll n, m, cnt = 0;
	cin >> n >> m;
	vector <ll> c(n);
	vector <bool> used(n);
	forin(i, n)
		cin >> c[i];
	all_graph(g, n);
	forin(i, n)
		if (!used[i]) {
			ll temp_ans = INF;
			dfs(i, g, used, c, temp_ans);
			cnt += temp_ans;
		}
	cout << cnt;
	return 0;
}