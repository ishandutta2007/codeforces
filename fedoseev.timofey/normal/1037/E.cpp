#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

set <int> g[N];
bool good[N];
int cur;

int k;

void process(int u) {
	if (good[u]) {
		good[u] = 0;;
		--cur;
		vector <int> to_process;
		for (auto v : g[u]) {
			if (g[v].size() == k) {
				to_process.push_back(v);
			}
			g[v].erase(u);
		}
		g[u].clear();
		for (auto v : to_process) process(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m >> k;
	cur = n;
	vector <pair <int, int>> e(m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		e[i] = {u, v};
		g[u].insert(v);
		g[v].insert(u);
	}
	reverse(e.begin(), e.end());
	for (int i = 0; i < n; ++i) good[i] = 1;
	for (int i = 0; i < n; ++i) {
		if (g[i].size() < k) process(i);
	}
	vector <int> ans;
	for (auto p : e) {
		ans.push_back(cur);
		g[p.first].erase(p.second);
		g[p.second].erase(p.first);
		if (g[p.first].size() < k) process(p.first);
		if (g[p.second].size() < k) process(p.second);
	}
	reverse(ans.begin(), ans.end());
	for (auto e : ans) {
		cout << e << '\n';
	}
}