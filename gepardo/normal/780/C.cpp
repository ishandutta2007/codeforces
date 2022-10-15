#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>

using namespace std;

int main() {
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
    #else
		ios_base::sync_with_stdio(false);
    #endif // DEBUG
    int n; cin >> n;
    vector< vector<int> > g(n);
    int ans = 0;
    for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
    }
    vector<int> color(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        int cV, cP;
        if (p < 0) {
			color[v] = 1;
			cV = color[v];
			cP = -1;
        } else {
			cV = color[v];
			cP = color[p];
        }
        vector<int> sons;
        for (int to: g[v]) {
			if (to != p) {
				sons.push_back(to);
			}
        }
        vector<int> cols;
        for (int i = 1; cols.size() < sons.size(); i++) {
			if (i != cV && i != cP) {
                cols.push_back(i);
			}
        }
        int ptr = 0;
        for (int to: sons) {
			color[to] = cols[ptr++];
			dfs(to, v);
        }
    };
    dfs(0, -1);
	for (int i = 0; i < n; i++) {
		ans = max(ans, color[i]);
	}
	cout << ans << "\n";
	for (int i = 0; i < n; i++) {
		cout << color[i] << " ";
	}
	cout << endl;
	return 0;
}