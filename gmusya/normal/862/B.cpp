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
#define read_edge(g) int u, v; cin >> u >> v; u--; v--; g[u].push_back(v); g[v].push_back(u)
#define read_graph(g) forin(i, m) { read_edge(g); }
#define all_graph(g, n) graph g(n); read_graph(g)
#define all(a) a.begin(), a.end()
#define forin(i, n) for (int i = 0; i < n; i++)

using namespace std;

const ll llINF = 8e18, MAX_LL = (1ll << 63) - 1, llMOD = 1e9 + 7;
const int INF = 1e9, MAX_INT = (1ll << 31) - 1;
const dl EPS = 1e-10, PI = acos(-1);

void dfs(int u, graph &g, vector <ll> &color) {
	forin(i, g[u].size()) {
		if (color[g[u][i]] == -1) {
			color[g[u][i]] = 1 - color[u];
			dfs(g[u][i], g, color);
		}
	}
}

int main() {
	int cnt1 = 0, cnt2 = 0;
	bool tf = true;
	ll n, m, cnt = 0;
	cin >> n;
	m = n - 1;
	all_graph(g, n);
	vector <ll> color(n, -1);
	color[0] = 0;
	dfs(0, g, color);
	if (!tf)
		cout << "-1";
	else {
		vector <int> red, blue;
		forin(i, n) {
			if (color[i] == 1) 
				red.push_back(i);
			else
				blue.push_back(i);
		}
		forin(i, red.size())
			cnt1 += g[red[i]].size();
		forin(i, blue.size())
			cnt2 += g[blue[i]].size();
		cout << red.size() * blue.size() - cnt1;
	}
	return 0;
}